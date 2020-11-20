#include "logo.h"
#include "ui_logo.h"

Logo::Logo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logo)
{
    ui->setupUi(this);
    //隐藏标题栏，无框提示
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    connect(ui->btnBig,SIGNAL(clicked()),this,SLOT(changeBig()));//建立按钮窗口放大的信号和槽
}

Logo::~Logo()
{
    delete ui;
}

void Logo::changeBig()
{
    emit this->back();
}

