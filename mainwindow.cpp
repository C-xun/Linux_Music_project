#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <QListWidgetItem>
mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    openFileLrc();
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::openFileLrc()
{
    this->currentIndex = 0;

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
            //查找lrc文件
            if(strstr(ret->d_name,"lrc") > 0)
            {
                this->songContent.push_back(QString(ret->d_name));
            }
        }
    }

    closedir(dir);
}

