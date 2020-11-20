#include "widget.h"
#include "ui_widget.h"
#include "ui_smallwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QSize>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <algorithm>
#include <QScrollBar>
int nowMusicTime = 0;
int sliderCmd = 0;
int sum = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //默认声音调节为隐藏
    ui->voiceSlider->hide();

    //默认风格窗口为隐藏
    ui->styleFrame->hide();

    //默认歌曲列表为隐藏
    ui->listSing->hide();

    //默认收藏歌曲列表为隐藏
    ui->listLove->hide();

    //初始化Widget::pauseFlag为0
    this->pauseFlag = 0;

    //初始化Widget::videoSound为0
    this->videoSound = 0;

    //初始化Widget::playMode为0
    this->playMode = 0;

    //初始化Widget::listSings为0
    this->listSings = 0;

    //初始化Widget::list2Sing为0
    this->list2Sing = 0;

    //初始化Widget::singContentSum为0
    this->singContentSum = 0;

    //初始化Widget::timeSum为0
    this->timeSum = 0;

    //创建一个无名管道
    pipe(fd);

    //隐藏标题栏，无框提示
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

    //启动Mplayer
    startMplayer();

    //初始化Mplayer
    mplayerInit();

    //创建当前时间线程
    createPthread();

    //默认获取01.MP3的歌词
    QString songName = "01";
    getSongContent(songName);

    //设置搜索栏的歌曲名
    int DefaultSing = rand()%sum;
    ui->editSing->setText(song[DefaultSing]);

    //设置关闭按钮，建立窗口关闭信号和槽
    connect(ui->btnClose,SIGNAL(clicked()),this, SLOT(close()));

    //建立下一曲信号和槽
    connect(ui->btnNext,SIGNAL(clicked()),this,SLOT(nextSong()));

    //建立上一曲信号和槽
    connect(ui->btnLast,SIGNAL(clicked()),this,SLOT(lastSong()));

    //建立歌曲暂停信号和槽
    connect(ui->btnPause,SIGNAL(clicked()),this,SLOT(setPauseSongPos()));

    //建立声音按钮信号和槽
    connect(ui->btnSound,SIGNAL(clicked()),this,SLOT(setVideoSound()));

    //建立歌曲列表信号和槽
    connect(ui->btnListSing,SIGNAL(clicked()),this,SLOT(setListSing()));

    //建立歌曲播放模式的信号和槽
    connect(ui->btnPlayMode,SIGNAL(clicked()),this,SLOT(setPlayMode()));

    //建立当前时间信号和槽
    connect(this,SIGNAL(sendTimePos(char *,char *)),this,SLOT(setLableTime(char *,char *)));

    //建立声音大小信号和槽
    connect(ui->voiceSlider,SIGNAL(valueChanged(int)),this,SLOT(voiceSliderChange(int)));

    //建立歌曲进度条的信号和槽
    connect(ui->progressBar,SIGNAL(sliderReleased()),this,SLOT(singSeek()));

    //建立歌曲快进获后退的信号和槽
    connect(ui->progressBar,SIGNAL(sliderMoved(int)),this,SLOT(sliderFunCmd()));

    //建立窗口变小的信号和槽
    connect(ui->btnSmall,SIGNAL(clicked()),this,SLOT(changeSmallWindow()));

    //建立窗口变大的信号和槽
    connect(&smallWindow,SIGNAL(back()),this,SLOT(changeBigWindow()));

    //建立窗口变Logo的信号和槽
    connect(ui->btnSmallLogo,SIGNAL(clicked()),this,SLOT(changeSmall2Window()));

    //建立Logo变窗口的信号和槽
    connect(&logo,SIGNAL(back()),this,SLOT(changeBig2Window()));

    //建立设置默认播放器风格的信号和槽
    connect(ui->btnSet,SIGNAL(clicked()),this, SLOT(showDefaultStyle()));

    //建立风格设置的按钮的信号和槽
    connect(ui->btnStyle,SIGNAL(clicked()),this, SLOT(showStyle()));

    //建立播放器风格1的信号和槽
    connect(ui->style1,SIGNAL(clicked()),this, SLOT(setWindowStyle1()));

    //建立播放器风格2的信号和槽
    connect(ui->style2,SIGNAL(clicked()),this,SLOT(setWindowStyle2()));

    //建立播放器风格3的信号和槽
    connect(ui->style3,SIGNAL(clicked()),this,SLOT(setWindowStyle3()));

    //建立搜索栏搜索的信号和槽
    connect(ui->btnSearch,SIGNAL(clicked()),this,SLOT(setSearchSing()));

    //建立歌曲列表信号和槽
    connect(ui->btnLocalMusic,SIGNAL(clicked()),this,SLOT(setListSing()));

    //建立喜欢歌曲的列表信号和槽
    connect(ui->btnLove,SIGNAL(clicked()),this,SLOT(setList2Sing()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startMplayer()
{
    //子进程中启动Mplayer
    pid_t pid = fork();
    if(pid == 0)
    {
        //fd[0]读段，fd[1]写段
        //将1重定义 无名管道写段fd[1]
        dup2(fd[1],1);
        execlp("mplayer","mplayer","-ac","mad","-slave",
               "-quiet","-idle","-input","file=./fifo_cmd",
               "./song/01.mp3",NULL);
    }
    else if(pid > 0)
    {

    }
}

void Widget::mplayerInit()
{
    this->currentIndex = 0;
    //创建一个命名管道
    mkfifo("fifo_cmd",0666);
    //以只写的方式打开
    this->fifo_fd = open("fifo_cmd",O_WRONLY);

    //查找目录1
    DIR *dir=NULL;
    dir = opendir("./song");
    if(dir == NULL)
    {
        perror("opendir");
        return;
    }

    while(1)
    {
        struct dirent *ret=NULL;
        ret = readdir(dir);
        if(ret == NULL)
            break;
        if(ret->d_type == DT_REG)
        {
            //查找MP3文件，并且将他们放入歌曲列表vector里面，建设链接
            if(strstr(ret->d_name,"mp3") > 0)
            {
                this->song.push_back(QString(ret->d_name));
                QListWidgetItem * item = new QListWidgetItem;
                item->setSizeHint(QSize(260, 40));
                ui->listSing->addItem(item);
                QWidget *itemQWidget = new QWidget;
                QHBoxLayout *layout=new QHBoxLayout;
                QPushButton *pushButton=new QPushButton(itemQWidget);
                layout->addWidget(pushButton);
                itemQWidget->setLayout(layout);
                pushButton->setText(QString(ret->d_name));
                pushButton->setStyleSheet("border-width: 0px;font-size:25px;outline:none;");
                ui->listSing->setItemWidget(item,itemQWidget);
                //返回按钮的内容，并且实现播放
                connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonObject()));
                sum++;
            }
            //设置歌曲数目到singSum控件
            QString QStrSum = QString::number(sum, 10);
            ui->singSum->setText(QStrSum);
        }
    }
    closedir(dir);

    //查找目录2
    DIR *dir2=NULL;
    dir2 = opendir("./Lovesong");
    if(dir2 == NULL)
    {
        perror("opendir");
        return;
    }

    while(1)
    {
        struct dirent *ret=NULL;
        ret = readdir(dir2);
        if(ret == NULL)
            break;
        if(ret->d_type == DT_REG)
        {
            //查找MP3文件，并且将他们放入歌曲列表vector里面，建设链接
            if(strstr(ret->d_name,"mp3") > 0)
            {
                this->song.push_back(QString(ret->d_name));
                QListWidgetItem * item = new QListWidgetItem;
                item->setSizeHint(QSize(260, 40));
                ui->listLove->addItem(item);
                QWidget *itemQWidget = new QWidget;
                QHBoxLayout *layout=new QHBoxLayout;
                QPushButton *pushButton=new QPushButton(itemQWidget);
                layout->addWidget(pushButton);
                itemQWidget->setLayout(layout);
                pushButton->setText(QString(ret->d_name));
                pushButton->setStyleSheet("border-width: 0px;font-size:25px;outline:none;");
                ui->listLove->setItemWidget(item,itemQWidget);
                //返回按钮的内容，并且实现播放
                connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonObject()));
            }
        }
    }
    closedir(dir2);
}

void *sendCmdFunc(void *arg)
{
    Widget *p = (Widget *)arg;
    while(1)
    {
        //写入歌曲时间总长度的指令
        char len[128] = "get_time_length\n";
        write(p->fifo_fd,len,strlen(len));
        if(p->pauseFlag%2 == 0)
        {
            //写入当前歌曲时间的指令
            char cmd[128] = "get_time_pos\n";
            //写入当前歌曲播放时间百分比的指令
            char pos[128] = "get_percent_pos\n";
            write(p->fifo_fd,pos,strlen(pos));
            write(p->fifo_fd,cmd,strlen(cmd));
            usleep(500*1000);//0.5s
        }
    }
}

void *recvPipeMsg(void *arg)
{
    char timeLen[128] = "";
    Widget *p = (Widget *)arg;
    while(1)
    {
        char msg[256] = "";
        read(p->fd[0],msg,sizeof(msg));
        //判断Mplayer回应的消息类型;else if继续判断其他回应
        //Mplayer回应的是当前的播放时间总长度
        if(strstr(msg,"ANS_LENGTH") != NULL)
        {
            sscanf(msg,"ANS_LENGTH=%s",timeLen);
        }
        //Mplayer回应的是当前的播放时间
        else if(strstr(msg,"ANS_TIME_POSITION") != NULL)
        {
            char time[128] = "";
            sscanf(msg,"ANS_TIME_POSITION=%s",time);
            //将获取的播放时间和总时间 通过信号 发送给主线程 更新QT的nowTime
            emit p->sendTimePos(time,timeLen);
        }
    }
}

void Widget::createPthread()
{
    //创建当前时间线程
    pthread_create(&tidGetTime,NULL,sendCmdFunc,this);
    //创建获取无名管道信息的线程
    pthread_create(&tidGetTime,NULL,recvPipeMsg,this);
}

void Widget::nextSong()
{

    this->currentIndex++;
    if(this->currentIndex == sum)
       currentIndex=0;
    //组切换歌曲的报文“loadfile file_name\n”
    char cmd[128] = "";
    int len = sprintf(cmd,"loadfile ./song/%s\n",
            song[currentIndex].toUtf8().data());
    QStringList list = song[currentIndex].split(".");
    QString singName = list[0];
    getSongContent(singName);
    //将下一曲指令写入管道
    write(fifo_fd,cmd,len);
    //根据音量进度条的值设置音量
    if(ui->voiceSlider->value()>=0)
    {
        int value = ui->voiceSlider->value();
        char cmd[128] = "";
        int len = sprintf(cmd,"volume %d 1",value);
        write(fifo_fd,cmd,len);
    }
}

void Widget::lastSong()
{
    this->currentIndex--;
    if(this->currentIndex < 0)
    {
        this->currentIndex=sum-1;
    }

    //组切换歌曲的报文“loadfile file_name\n”
    char cmd[128] = "";
    int len = sprintf(cmd,"loadfile ./song/%s\n",
            song[currentIndex].toUtf8().data());
    QStringList list = song[currentIndex].split(".");
    QString singName = list[0];
    getSongContent(singName);
    //将上一曲指令写入管道
    write(fifo_fd,cmd,len);
    //根据音量进度条的值设置音量
    if(ui->voiceSlider->value()>=0)
    {
        int value = ui->voiceSlider->value();
        char cmd[128] = "";
        int len = sprintf(cmd,"volume %d 1",value);
        write(fifo_fd,cmd,len);
    }
}

void Widget::playModeToNextSong()
{
    //设置随机播放
    if(this->playMode%4 == 0)
    {
        this->currentIndex = rand()%sum;
    }
    //设置循环播放
    else if(this->playMode%4 == 1)
    {
        this->currentIndex++;
        if(this->currentIndex == sum)
           currentIndex=0;
    }
    //设置单曲播放
    else if(this->playMode%4 == 2)
    {
        this->currentIndex = this->currentIndex;
    }
    //设置列表播放
    else if(this->playMode%4 == 3)
    {
        this->currentIndex++;
        if(this->currentIndex == sum)
        {
            currentIndex=0;
            char cmd[128] = "";
            int len = sprintf(cmd,"loadfile ./song/%s\n",
                    song[currentIndex].toUtf8().data());
            QStringList list = song[currentIndex].split(".");
            QString singName = list[0];
            getSongContent(singName);
            //将下一曲指令写入管道
            write(fifo_fd,cmd,len);
            //根据音量进度条的值设置音量
            if(ui->voiceSlider->value()>=0)
            {
                int value = ui->voiceSlider->value();
                char cmd[128] = "";
                int len = sprintf(cmd,"volume %d 1",value);
                write(fifo_fd,cmd,len);
            }
            //列表播放完进行暂停操作
            setPauseSongPos();
        }
    }
    char cmd[128] = "";
    int len = sprintf(cmd,"loadfile ./song/%s\n",
            song[currentIndex].toUtf8().data());
    QStringList list = song[currentIndex].split(".");
    QString singName = list[0];
    getSongContent(singName);
    //将下一曲指令写入管道
    write(fifo_fd,cmd,len);
    //根据音量进度条的值设置音量
    if(ui->voiceSlider->value()>=0)
    {
        int value = ui->voiceSlider->value();
        char cmd[128] = "";
        int len = sprintf(cmd,"volume %d 1",value);
        write(fifo_fd,cmd,len);
    }

}

void Widget::setLableTime(char *time,char *timeLen)
{
    int tmpTime = atoi(time);
    //根据时间进行歌词列表的更新
    if(tmpTime==singContentTime[singContentSum])
    {
        if(singContentSum > 0)
        {
            ui->singContentList->item(singContentSum-1)->setTextColor(QColor(255, 255, 255));  //播放完成的歌词恢复白色
        }
        ui->singContentList->item(singContentSum)->setTextColor(QColor(0, 170, 255));   //当前播放的歌词设置成烂色

        QString lyric = ui->singContentList->item(singContentSum)->text();
        smallWindow.ui->sing->setText(lyric);  //设置小窗口模式的歌词显示

        singContentSum++;
        ui->singContentList->verticalScrollBar()->setMinimum(0);  //设置进度条最小值
        ui->singContentList->verticalScrollBar()->setMaximum(timeSum*2);  //设置进度条最大值
        ui->singContentList->verticalScrollBar()->setValue(singContentSum-5);  //设置进度条的值
        if(singContentSum>=timeSum)
        {
            singContentSum = 0;
        }
    }
    //设置ui的nowTime标签的内容
    int timeLens = atoi(timeLen);
    char strTime[128]="";
    sprintf(strTime,"%02d:%02d/%02d:%02d",tmpTime/60,tmpTime%60,timeLens/60,timeLens%60);
    ui->nowTime->setText(QString(strTime));
    ui->progressBar->setMinimum(0);  //设置进度条最小值
    ui->progressBar->setMaximum(timeLens);  //设置进度条最大值
    ui->progressBar->setSingleStep(1);  //设置进度条步长
    nowMusicTime = tmpTime;
    if(sliderCmd%2 == 0)
    {
        ui->progressBar->setValue(tmpTime);
    }
    //当播放完毕自动进行下一曲
    if(tmpTime >= timeLens-1)
    {
        playModeToNextSong();
    }
}

void Widget::setPauseSongPos()
{
    this->pauseFlag++;
    //播放暂停指令写入管道
    char cmd[128]="pause\n";
    write(fifo_fd,cmd,strlen(cmd));
    //根据是否暂停设置暂停按钮图片
    if(pauseFlag%2 == 0)
    {
        this->ui->btnPause->setStyleSheet("border-image:url(:/suspend.png);");
    } else if(pauseFlag%2 == 1) {
        this->ui->btnPause->setStyleSheet("border-image:url(:/play.png);");
    }
}

void Widget::setPlayMode()
{
    this->playMode++;
    //设置随机播放的按钮图片
    if(this->playMode%4 == 0)
    {
        this->ui->btnPlayMode->setStyleSheet("border-image:url(:/play1.png);");
    }
    //设置顺序播放的按钮图片
    else if(this->playMode%4 == 1)
    {
        this->ui->btnPlayMode->setStyleSheet("border-image:url(:/play2.png);");
    }
    //设置单曲循环的按钮图片
    else if(this->playMode%4 == 2)
    {
        this->ui->btnPlayMode->setStyleSheet("border-image:url(:/play3.png);");
    }
    //设置列表播放的按钮图片
    else if(this->playMode%4 == 3)
    {
        this->ui->btnPlayMode->setStyleSheet("border-image:url(:/play4.png);");
    }
}

void Widget::voiceSliderChange(int value)
{
    //音量调节指令写入管道
    char cmd[128] = "";
    int len = sprintf(cmd,"volume %d 1",value);
    write(fifo_fd,cmd,len);
    //根据音量设置音量按钮图片
    if(value != 0&&ui->voiceSlider->value()==100)
    {
        this->ui->btnSound->setStyleSheet("border-image:url(:/sound.png);");
    }
    else if(value != 0&&ui->voiceSlider->value()>=50)
    {
        this->ui->btnSound->setStyleSheet("border-image:url(:/sound2.png);");
    }
    else if(value != 0&&ui->voiceSlider->value()>=0)
    {
        this->ui->btnSound->setStyleSheet("border-image:url(:/sound3.png);");
    }
    else if(value == 0) {
        this->ui->btnSound->setStyleSheet("border-image:url(:/sound1.png);");
    }
}

void Widget::singSeek()
{
    int time;
    time = ui->progressBar->value() - nowMusicTime;
    if(ui->progressBar->value()==ui->progressBar->maximum())
    {
        time = ui->progressBar->value() - nowMusicTime-3;
    }
    //歌曲快进快退指令写入管道
    char cmd[128] = "";
    int len = sprintf(cmd,"seek %d",time);
    write(fifo_fd,cmd,len);
    //调节歌词显示列表同步
    int i,j;
    for(i=0;i<timeSum;i++)
    {
        if(singContentTime[i]>ui->progressBar->value())
        {
            singContentSum = i;
            ui->singContentList->verticalScrollBar()->setValue(singContentSum-5);
            break;
        }
    }
    //调节歌词变色显示同步
    j = i-1;
    if(j>=0)
    {
        ui->singContentList->item(j)->setTextColor(QColor(0, 170, 255));
    }
    for(i=0;i<j;i++)
    {
        ui->singContentList->item(i)->setTextColor(QColor(255, 255, 255));
    }
    for(;j+1<timeSum;j++)
    {
        ui->singContentList->item(j+1)->setTextColor(QColor(255, 255, 255));
    }
    sliderCmd = 0;
}

void Widget::setVideoSound()
{
    //设置音量进度条是否显示
    this->videoSound++;
    if(this->videoSound%2 == 0)
    {
        ui->voiceSlider->hide();
    }
    else if(this->videoSound%2 == 1)
    {
        ui->voiceSlider->show();
    }
}

void Widget::setListSing()
{
    //设置歌曲列表是否显示
    this->listSings++;
    if(this->listSings%2 == 0)
    {
        ui->listSing->hide();
    }
    else if(this->listSings%2 == 1)
    {
        ui->listSing->show();
    }
}

void Widget::setList2Sing()
{
    //设置喜欢的歌曲列表是否显示
    this->list2Sing++;
    if(this->list2Sing%2 == 0)
    {
        ui->listLove->hide();
    }
    else if(this->list2Sing%2 == 1)
    {
        ui->listLove->show();
    }
}

void Widget::pushButtonObject(){
      QPushButton *pushButton  = (QPushButton*) sender();
      QString text = pushButton->text();
      QStringList list = text.split(".");
      QString singName = list[0];
      getSongContent(singName);
      char cmd[128] = "";
      int len = sprintf(cmd,"loadfile ./song/%s\n",text.toLatin1().data());
      //将下一曲指令写入管道
      write(fifo_fd,cmd,len);
      //根据音量进度条的值设置音量
      if(ui->voiceSlider->value()>=0)
      {
          int value = ui->voiceSlider->value();
          char cmd1[128] = "";
          int len = sprintf(cmd1,"volume %d 1",value);
          write(fifo_fd,cmd1,len);
      }
}

void Widget::sliderFunCmd()
{
    sliderCmd = 1;
}

void Widget::clickedSingItem()
{
    QPushButton *pushButton  = (QPushButton*) sender();
    QString text = pushButton->text();
    int tmp = text.toInt();
    int time;
    time = tmp - nowMusicTime;
    //歌曲快进快退指令写入管道
    char cmd[128] = "";
    int len = sprintf(cmd,"seek %d",time);
    write(fifo_fd,cmd,len);
    //调节歌词显示列表同步
    int i,j;
    for(i=0;i<timeSum;i++)
    {
        if(singContentTime[i]>tmp)
        {
            singContentSum = i;
            ui->singContentList->verticalScrollBar()->setValue(singContentSum-5);
            break;
        }
    }
    //调节歌词变色显示同步
    j = i-1;
    ui->singContentList->item(j)->setTextColor(QColor(0, 170, 255));
    for(i=0;i<j;i++)
    {
        ui->singContentList->item(i)->setTextColor(QColor(255, 255, 255));
    }
    for(;j+1<timeSum;j++)
    {
        ui->singContentList->item(j+1)->setTextColor(QColor(255, 255, 255));
    }
}

void Widget::changeBigWindow()
{
    //设置小窗口模式隐藏，大窗口模式显示
    smallWindow.hide();
    this->show();
}

void Widget::changeSmallWindow()
{
    //设置小窗口模式显示，大窗口模式隐藏
    this->hide();
    smallWindow.show();
}

void Widget::changeBig2Window()
{
    //设置Logo隐藏，大窗口模式显示
    logo.hide();
    this->show();
}

void Widget::changeSmall2Window()
{
    //设置Logo显示，大窗口模式隐藏
    this->hide();
    logo.show();
}

//设置播放器风格1
void Widget::setWindowStyle1()
{
    ui->stackedWidget->setStyleSheet("border-image: url(:/style1.jpg);background-color: transparent;");
    ui->singContentList->setStyleSheet("background-color: transparent;color:rgb(255, 255, 255);border-style: outset; border-width: 0px; "
                                       "border-color: transparent;border-image: url(:/transparent.png);");
    ui->styleFrame->setStyleSheet("border-image: url(:/transparent.png);background-color: transparent;");
    ui->listSing->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(50,104,194, 255), stop:1 rgba(7,208,255, 255));");
    ui->listLove->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(50,104,194, 255), stop:1 rgba(7,208,255, 255));");
    ui->styleFrame->hide();
}

//设置播放器风格2
void Widget::setWindowStyle2()
{
    ui->stackedWidget->setStyleSheet("border-image: url(:/style2.jpg);background-color: transparent;");
    ui->singContentList->setStyleSheet("background-color: transparent;color:rgb(255, 255, 255);border-style: outset; border-width: 0px; "
                                       "border-color: transparent;border-image: url(:/transparent.png);");
    ui->styleFrame->setStyleSheet("border-image: url(:/transparent.png);background-color: transparent;");
    ui->listSing->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(26,104,206,255), stop:1 rgba(42,214,228,255));");
    ui->listLove->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(26,104,206,255), stop:1 rgba(42,214,228,255));");
    ui->styleFrame->hide();
}

//设置播放器风格3
void Widget::setWindowStyle3()
{
    ui->stackedWidget->setStyleSheet("border-image: url(:/style3.jpg);background-color: transparent;");
    ui->singContentList->setStyleSheet("background-color: transparent;color:rgb(255, 255, 255);border-style: outset; border-width: 0px; "
                                       "border-color: transparent;border-image: url(:/transparent.png);");
    ui->styleFrame->setStyleSheet("border-image: url(:/transparent.png);background-color: transparent;");
    ui->listSing->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2,17,49, 255), stop:1 rgba(49,74,162, 255));");
    ui->listLove->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;"
                                "border-color: rgb(0, 170, 255);border-image: url(:/style1.png);background-color: qlineargradient(spread:pad, "
                                "x1:0, y1:0, x2:1, y2:0, stop:0 rgba(2,17,49, 255), stop:1 rgba(49,74,162, 255));");
    ui->styleFrame->hide();
}

//设置风格列表显示
void Widget::showStyle()
{
    ui->styleFrame->show();
}

//设置恢复默认的播放器风格
void Widget::showDefaultStyle()
{
    ui->stackedWidget->setStyleSheet("background-color: #212124;");
    ui->singContentList->setStyleSheet("background-color: transparent;color:rgb(255, 255, 255);border-style: outset;"
                                       " border-width: 0px; border-color: transparent;");
    ui->styleFrame->setStyleSheet("background-color: transparent;");
    ui->listSing->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;border-color: rgb(0, 170, 255);");
    ui->listLove->setStyleSheet("color:rgb(255, 255, 255);border-style: outset; border-width: 1px;border-color: rgb(0, 170, 255);");
}

//设置搜索歌曲功能
void Widget::setSearchSing()
{
    QString text = ui->editSing->text();
    QStringList list = text.split(".");
    QString singName = list[0];
    getSongContent(singName);
    char cmd[128] = "";
    int len = sprintf(cmd,"loadfile ./song/%s\n",text.toLatin1().data());
    //将下一曲指令写入管道
    write(fifo_fd,cmd,len);
    //根据音量进度条的值设置音量
    if(ui->voiceSlider->value()>=0)
    {
        int value = ui->voiceSlider->value();
        char cmd1[128] = "";
        int len = sprintf(cmd1,"volume %d 1",value);
        write(fifo_fd,cmd1,len);
    }
    //随机选择一歌曲放入editSing
    int DefaultSing = rand()%(int)song.size();
    ui->editSing->setText(song[DefaultSing]);
}

//根据时间进行歌词排序
bool myVectorSort(SONG sing1,SONG sing2)
{
    return sing1.myLrcTime < sing2.myLrcTime;
}

//获取当前播放歌曲的歌词内容
void Widget::getSongContent(QString songName)
{
    songLrcVct.clear();
    //获取当前歌曲的歌词
    char strLrc[128]="";
    sprintf(strLrc,"./song/%s.lrc",songName.toLatin1().data());
    int lrcFd = open(strLrc,O_RDONLY);
    char lrcBuf[5000]="";
    read(lrcFd,lrcBuf,sizeof(lrcBuf));
    char *chLyric[128]={lrcBuf,NULL};
    int row = 0;//文本行数
    while((chLyric[row] = (strtok(chLyric[row],"\r\n")))&& (++row));

    int i=0;
    for(i=0;i<4;i++)
    {
        char type[32]="";
        char msg[32]="";
        sscanf(chLyric[i],"[%[^:]:%[^]]",type,msg);
    }
    for(i=4;i<row;i++)
    {
        char *songLrc = chLyric[i];
        while(*songLrc == '[')
            songLrc += 10;
        char *timeLrc = chLyric[i];
        while(*timeLrc == '[')
        {
           SONG tmp;
           memset(&tmp,0,sizeof(tmp));
           int m = 0,s=0;
           sscanf(timeLrc,"[%d:%d", &m,&s);
           tmp.myLrcTime = m*60+s;
           strcpy(tmp.myLrc, songLrc);
           songLrcVct.push_back(tmp);
           timeLrc += 10;
        }
    }
    sort(songLrcVct.begin(),songLrcVct.end(),myVectorSort);
    //清空歌词列表
    while (ui->singContentList->count() > 0)
    {
        QListWidgetItem *item = ui->singContentList->takeItem(0);
        delete item;
    }
    timeSum = 0;singContentSum = 0;
    ui->singContentList->verticalScrollBar()->setValue(-5);
    //进行歌词的遍历，显示在歌词列表中，并且为每一首歌建立链接
    for(vector<SONG>::iterator it=songLrcVct.begin();it!=songLrcVct.end();it++)
    {
        QListWidgetItem * item = new QListWidgetItem;
        item->setSizeHint(QSize(380, 40));
        ui->singContentList->addItem(item);
        item->setText(QString::fromUtf8((*it).myLrc));

        QWidget *itemQWidget = new QWidget;
        QHBoxLayout *layout=new QHBoxLayout;
        QPushButton *pushButton=new QPushButton(itemQWidget);
        layout->addWidget(pushButton);
        itemQWidget->setLayout(layout);
        pushButton->setStyleSheet("border-width: 0px;font-size:18px;color: transparent;outline:none;");
        ui->singContentList->setItemWidget(item,itemQWidget);

        singContentTime[timeSum]=(*it).myLrcTime;
        pushButton->setText(QString::number(singContentTime[timeSum], 10));
        timeSum++;
        connect(pushButton,SIGNAL(clicked()),this,SLOT(clickedSingItem()));
    }
}
