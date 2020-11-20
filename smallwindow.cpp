#include "smallwindow.h"
#include "widget.h"
#include "ui_smallwindow.h"

SmallWindow::SmallWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWindow)
{
    ui->setupUi(this);
    //隐藏标题栏，无框提示
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    connect(ui->btnBig,SIGNAL(clicked()),this,SLOT(changeBig()));//建立按钮窗口放大的信号和槽
}
SmallWindow::~SmallWindow()
{
    delete ui;
}

void SmallWindow::changeBig()
{
    emit this->back();
}

