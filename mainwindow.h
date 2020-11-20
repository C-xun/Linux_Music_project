#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    void openFileLrc(void);
    Ui::mainWindow *ui;
private:
    //定义一个命名管道的文件描述符
    int fifo_fd;
    //定义当前歌曲词下标
    int currentIndex;
    vector<QString> songContent;
};

#endif // MAINWINDOW_H
