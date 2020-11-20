#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <vector>
#include <QString>
#include <pthread.h>
#include "smallwindow.h"
#include "logo.h"
#include "mainwindow.h"

using namespace std;


typedef struct song
{
    int myLrcTime;
    char myLrc[128];
}SONG;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
friend void *sendCmdFunc(void *arg);
friend void *recvPipeMsg(void *arg);
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //启动mplayer
    void startMplayer(void);
    //初始化mplayer
    void mplayerInit(void);
    //创建线程
    void createPthread(void);
    //判断是否暂停
    int pauseFlag;
    int videoSound;
    int listSings;
    int list2Sing;
    int playMode;
    int singContentSum;
    int timeSum;
    int singContentTime[256];
    void getSongContent(QString songName);
    SmallWindow smallWindow;
    Logo logo;
    mainWindow mainWindows;
private:
    Ui::Widget *ui;
    //定义一个命名管道的文件描述符
    int fifo_fd;
    //定于一个当前歌曲名的vector数组
    vector<QString> song;
    //定义当前歌曲下标
    int currentIndex;
    //定义当前时间线程id
    pthread_t tidGetTime;
    //定义一个接受无名管道的线程id
    pthread_t tidRecvPipe;
    //定义无名管道
    int fd[2];
    //定义一个歌词内容的vector
    vector<QString> songContent;
    //定义一个歌曲列表的vector
    vector<SONG> songLrcVct;
public slots:
    void nextSong(void);
    void lastSong(void);
    void playModeToNextSong();
    void setLableTime(char *time,char *timeLen);
    void voiceSliderChange(int value);
    void singSeek();
    void setVideoSound();
    void setListSing();
    void setList2Sing();
    void setPauseSongPos();
    void setPlayMode();
    void pushButtonObject();
    void sliderFunCmd();
    void clickedSingItem();
    void changeBigWindow(void);
    void changeSmallWindow(void);
    void changeBig2Window(void);
    void changeSmall2Window(void);
    void setWindowStyle1();
    void setWindowStyle2();
    void setWindowStyle3();
    void showStyle();
    void showDefaultStyle();
    void setSearchSing();
signals:
    void sendTimePos(char *time,char *timeLen);
};

#endif // WIDGET_H
