/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Sep 23 11:13:05 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include <mainwindow.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QFrame *frame;
    QFrame *frame_3;
    QPushButton *pushButton_9;
    QPushButton *btnSmallLogo;
    QPushButton *btnClose;
    QPushButton *btnSet;
    QPushButton *pushButton_12;
    QPushButton *btnStyle;
    QPushButton *pushButton_14;
    QLabel *label_3;
    QLineEdit *editSing;
    QPushButton *btnSearch;
    QPushButton *btnSmall;
    QFrame *frame_2;
    QFrame *frame_4;
    QPushButton *btnLast;
    QPushButton *btnPause;
    QPushButton *btnNext;
    QLabel *nowTime;
    QPushButton *btnListSing;
    QPushButton *btnSound;
    QPushButton *btnPlayMode;
    QLabel *singSum;
    QSlider *progressBar;
    QFrame *frame_5;
    QFrame *frame_6;
    QLabel *label_4;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QFrame *frame_7;
    QLabel *label_5;
    QToolButton *btnLocalMusic;
    QFrame *frame_8;
    QLabel *label_6;
    QToolButton *btnLove;
    QToolButton *btnLoad;
    QStackedWidget *stackedWidget;
    mainWindow *page_2;
    QSlider *voiceSlider;
    QListWidget *listSing;
    QListWidget *singContentList;
    QFrame *styleFrame;
    QToolButton *style1;
    QToolButton *style2;
    QToolButton *style3;
    QListWidget *listLove;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1024, 600);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 65, 1277, 3));
        label_2->setStyleSheet(QString::fromUtf8("background-color: #c62f2f;"));
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1277, 65));
        frame->setStyleSheet(QString::fromUtf8("background-color: #212124;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 10, 1061, 45));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_9 = new QPushButton(frame_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(950, 15, 20, 20));
        pushButton_9->setStyleSheet(QString::fromUtf8("border-image: url(:/big.png);"));
        btnSmallLogo = new QPushButton(frame_3);
        btnSmallLogo->setObjectName(QString::fromUtf8("btnSmallLogo"));
        btnSmallLogo->setGeometry(QRect(910, 15, 24, 24));
        btnSmallLogo->setStyleSheet(QString::fromUtf8("border-image: url(:/small.png);"));
        btnClose = new QPushButton(frame_3);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(990, 15, 18, 18));
        btnClose->setStyleSheet(QString::fromUtf8("border-image: url(:/close.png);"));
        btnSet = new QPushButton(frame_3);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));
        btnSet->setGeometry(QRect(760, 12, 25, 25));
        btnSet->setStyleSheet(QString::fromUtf8("border-image: url(:/set.png);"));
        pushButton_12 = new QPushButton(frame_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(690, 12, 25, 25));
        pushButton_12->setStyleSheet(QString::fromUtf8("border-image: url(:/mail.png);"));
        btnStyle = new QPushButton(frame_3);
        btnStyle->setObjectName(QString::fromUtf8("btnStyle"));
        btnStyle->setGeometry(QRect(620, 12, 25, 25));
        btnStyle->setStyleSheet(QString::fromUtf8("border-image: url(:/clothes.png);"));
        pushButton_14 = new QPushButton(frame_3);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(10, 5, 40, 40));
        pushButton_14->setStyleSheet(QString::fromUtf8("border-image: url(:/logo.png);"));
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(51, 5, 181, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font.setPointSize(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        editSing = new QLineEdit(frame_3);
        editSing->setObjectName(QString::fromUtf8("editSing"));
        editSing->setGeometry(QRect(260, 10, 241, 31));
        QFont font1;
        font1.setPointSize(6);
        editSing->setFont(font1);
        editSing->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: outset; \n"
"border-width: 2px; \n"
"border-color: rgb(255, 255, 255);"));
        btnSearch = new QPushButton(frame_3);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(510, 10, 25, 25));
        btnSearch->setStyleSheet(QString::fromUtf8("border-image: url(:/search.png);"));
        btnSmall = new QPushButton(frame_3);
        btnSmall->setObjectName(QString::fromUtf8("btnSmall"));
        btnSmall->setGeometry(QRect(870, 15, 20, 20));
        btnSmall->setStyleSheet(QString::fromUtf8("border-image: url(:/narrow.png);"));
        frame_2 = new QFrame(Widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 535, 1024, 65));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #212124;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 10, 230, 45));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        btnLast = new QPushButton(frame_4);
        btnLast->setObjectName(QString::fromUtf8("btnLast"));
        btnLast->setGeometry(QRect(20, 2, 40, 40));
        btnLast->setStyleSheet(QString::fromUtf8("border-image: url(:/last.png);"));
        btnPause = new QPushButton(frame_4);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setGeometry(QRect(100, 2, 40, 40));
        btnPause->setStyleSheet(QString::fromUtf8("border-image: url(:/suspend.png);"));
        btnNext = new QPushButton(frame_4);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(180, 2, 40, 40));
        btnNext->setStyleSheet(QString::fromUtf8("border-image: url(:/next.png);"));
        nowTime = new QLabel(frame_2);
        nowTime->setObjectName(QString::fromUtf8("nowTime"));
        nowTime->setGeometry(QRect(240, 20, 141, 25));
        QFont font2;
        font2.setPointSize(7);
        nowTime->setFont(font2);
        nowTime->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        btnListSing = new QPushButton(frame_2);
        btnListSing->setObjectName(QString::fromUtf8("btnListSing"));
        btnListSing->setGeometry(QRect(940, 14, 35, 35));
        btnListSing->setStyleSheet(QString::fromUtf8("border-image: url(:/list.png);"));
        btnSound = new QPushButton(frame_2);
        btnSound->setObjectName(QString::fromUtf8("btnSound"));
        btnSound->setGeometry(QRect(880, 14, 35, 35));
        btnSound->setStyleSheet(QString::fromUtf8("border-image: url(:/sound.png);"));
        btnPlayMode = new QPushButton(frame_2);
        btnPlayMode->setObjectName(QString::fromUtf8("btnPlayMode"));
        btnPlayMode->setGeometry(QRect(820, 14, 35, 35));
        btnPlayMode->setStyleSheet(QString::fromUtf8("border-image: url(:/play1.png);"));
        singSum = new QLabel(frame_2);
        singSum->setObjectName(QString::fromUtf8("singSum"));
        singSum->setGeometry(QRect(990, 20, 30, 25));
        singSum->setFont(font2);
        singSum->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255)"));
        progressBar = new QSlider(frame_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(390, 25, 411, 20));
        progressBar->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal \n"
"{\n"
"border: 0px solid #bbb;\n"
"}\n"
"QSlider::sub-page:horizontal \n"
"{\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));\n"
"border-radius: 0px;\n"
"margin-top:5px;\n"
"margin-bottom:5px; \n"
"}\n"
"QSlider::add-page:horizontal \n"
"{ \n"
"background: rgb(255,255, 255);\n"
"border: 0px solid #777;\n"
"border-radius: 2px;\n"
"margin-top:5px;\n"
"margin-bottom:5px;\n"
"} \n"
"QSlider::handle:horizontal \n"
"{\n"
"background: rgb(0, 170, 255);\n"
"border: 0px solid rgb(0, 170, 255);\n"
"width: 8px;\n"
"height:8px;\n"
"border-radius: 4px;\n"
"margin-top:1px;\n"
"margin-bottom:1px;\n"
"}\n"
"QSlider::handle:horizontal:hover \n"
"{\n"
"background: rgb(255,128,6);\n"
"border: 0px solid rgba(102,102,102,102);\n"
"border-radius: 7px;\n"
"}\n"
"QSlider::sub-page:horizontal:disabled \n"
"{\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"QSlider::add-page:horizontal:disabled\n"
"{\n"
"background: #eee"
                        ";\n"
"border-color: #999;\n"
"}\n"
"QSlider::handle:horizontal:disabled \n"
"{\n"
"background: #eee;\n"
"border: 0px solid #aaa;\n"
"border-radius: 4px;\n"
"}\n"
""));
        progressBar->setMaximum(100);
        progressBar->setSingleStep(1);
        progressBar->setOrientation(Qt::Horizontal);
        frame_5 = new QFrame(Widget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(0, 68, 230, 471));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: #212124;"));
        frame_5->setFrameShape(QFrame::WinPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(0, 0, 231, 30));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 211, 16));
        QFont font3;
        font3.setPointSize(5);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        toolButton = new QToolButton(frame_5);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(0, 40, 230, 30));
        QFont font4;
        font4.setPointSize(8);
        toolButton->setFont(font4);
        toolButton->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/music.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(frame_5);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 75, 230, 30));
        toolButton_2->setFont(font4);
        toolButton_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/privateFM.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);
        toolButton_3 = new QToolButton(frame_5);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(0, 110, 230, 30));
        toolButton_3->setFont(font4);
        toolButton_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/radio.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_3->setAutoRaise(true);
        toolButton_4 = new QToolButton(frame_5);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(0, 145, 230, 30));
        toolButton_4->setFont(font4);
        toolButton_4->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/friend.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_4->setAutoRaise(true);
        frame_7 = new QFrame(frame_5);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(0, 180, 231, 30));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 211, 16));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        btnLocalMusic = new QToolButton(frame_5);
        btnLocalMusic->setObjectName(QString::fromUtf8("btnLocalMusic"));
        btnLocalMusic->setGeometry(QRect(0, 215, 230, 30));
        btnLocalMusic->setFont(font4);
        btnLocalMusic->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/localM.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLocalMusic->setIcon(icon4);
        btnLocalMusic->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnLocalMusic->setAutoRaise(true);
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(0, 285, 231, 30));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 211, 16));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        btnLove = new QToolButton(frame_5);
        btnLove->setObjectName(QString::fromUtf8("btnLove"));
        btnLove->setGeometry(QRect(0, 320, 230, 30));
        btnLove->setFont(font4);
        btnLove->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/favorite.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLove->setIcon(icon5);
        btnLove->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnLove->setAutoRaise(true);
        btnLoad = new QToolButton(frame_5);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setGeometry(QRect(0, 250, 230, 30));
        btnLoad->setFont(font4);
        btnLoad->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/load.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLoad->setIcon(icon6);
        btnLoad->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btnLoad->setAutoRaise(true);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(230, 68, 794, 471));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #212124;"));
        page_2 = new mainWindow();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        voiceSlider = new QSlider(page_2);
        voiceSlider->setObjectName(QString::fromUtf8("voiceSlider"));
        voiceSlider->setGeometry(QRect(655, 310, 22, 160));
        voiceSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:vertical\n"
"{\n"
"border: 0px solid #bbb;\n"
"border-radius: 5px\n"
"}\n"
"QSlider::sub-page:vertical\n"
"{\n"
"background: rgb(255,255, 255);\n"
"border-radius: 5px;\n"
"}\n"
"QSlider::add-page:vertical\n"
"{ \n"
"background: rgb(0, 170, 255);\n"
"border: 0px solid #777;\n"
"border-radius: 0px;\n"
"} \n"
"QSlider::handle:vertical\n"
"{\n"
"background: rgb(0, 170, 255);\n"
"border: 0px solid rgb(0, 170, 255);\n"
"width: 4px;\n"
"height:4px;\n"
"border-radius: 2px;\n"
"margin-top:1px;\n"
"margin-bottom:1px;\n"
"}\n"
"QSlider::handle:vertical:hover \n"
"{\n"
"background: rgb(255,128,6);\n"
"border: 0px solid rgba(102,102,102,102);\n"
"border-radius: 5px;\n"
"}\n"
"QSlider::sub-page:vertical:disabled \n"
"{\n"
"background: #bbb;\n"
"border-color: #999;\n"
"border-radius: 5px\n"
"}\n"
"QSlider::add-page:vertical:disabled\n"
"{\n"
"background: #eee;\n"
"border-color: #999;\n"
"border-radius: 5px\n"
"}\n"
"QSlider::handle:vertical:disabled \n"
"{\n"
"background: #eee;\n"
"border: 0px solid #aaa;\n"
""
                        "border-radius: 5px;\n"
"}"));
        voiceSlider->setMaximum(100);
        voiceSlider->setValue(50);
        voiceSlider->setOrientation(Qt::Vertical);
        listSing = new QListWidget(page_2);
        QFont font5;
        font5.setPointSize(10);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listSing);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font5);
        listSing->setObjectName(QString::fromUtf8("listSing"));
        listSing->setGeometry(QRect(525, -1, 271, 481));
        listSing->setFont(font2);
        listSing->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: outset; \n"
"border-width: 1px; \n"
"border-color: rgb(0, 170, 255);"));
        singContentList = new QListWidget(page_2);
        singContentList->setObjectName(QString::fromUtf8("singContentList"));
        singContentList->setGeometry(QRect(350, 40, 401, 381));
        singContentList->setFont(font1);
        singContentList->setLayoutDirection(Qt::LeftToRight);
        singContentList->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color:rgb(255, 255, 255);\n"
"border-style: outset; \n"
"border-width: 0px; \n"
"border-color: transparent;"));
        styleFrame = new QFrame(page_2);
        styleFrame->setObjectName(QString::fromUtf8("styleFrame"));
        styleFrame->setGeometry(QRect(240, 0, 320, 111));
        styleFrame->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        styleFrame->setFrameShape(QFrame::StyledPanel);
        styleFrame->setFrameShadow(QFrame::Raised);
        style1 = new QToolButton(styleFrame);
        style1->setObjectName(QString::fromUtf8("style1"));
        style1->setGeometry(QRect(20, 10, 80, 80));
        style1->setStyleSheet(QString::fromUtf8("border-image: url(:/style1.jpg);\n"
"background-color: transparent;"));
        style2 = new QToolButton(styleFrame);
        style2->setObjectName(QString::fromUtf8("style2"));
        style2->setGeometry(QRect(120, 10, 80, 80));
        style2->setStyleSheet(QString::fromUtf8("border-image: url(:/style2.jpg);\n"
"background-color: transparent;"));
        style3 = new QToolButton(styleFrame);
        style3->setObjectName(QString::fromUtf8("style3"));
        style3->setGeometry(QRect(220, 10, 80, 80));
        style3->setStyleSheet(QString::fromUtf8("border-image: url(:/style3.jpg);\n"
"background-color: transparent;"));
        listLove = new QListWidget(page_2);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listLove);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font5);
        listLove->setObjectName(QString::fromUtf8("listLove"));
        listLove->setGeometry(QRect(525, -1, 271, 481));
        listLove->setFont(font2);
        listLove->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"border-style: outset; \n"
"border-width: 1px; \n"
"border-color: rgb(0, 170, 255);"));
        stackedWidget->addWidget(page_2);
        singContentList->raise();
        voiceSlider->raise();
        styleFrame->raise();
        listSing->raise();
        listLove->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        pushButton_9->setText(QString());
        btnSmallLogo->setText(QString());
        btnClose->setText(QString());
        btnSet->setText(QString());
        pushButton_12->setText(QString());
        btnStyle->setText(QString());
        pushButton_14->setText(QString());
        label_3->setText(QApplication::translate("Widget", "\345\260\217\346\233\271\343\201\256Music", 0, QApplication::UnicodeUTF8));
        btnSearch->setText(QString());
        btnSmall->setText(QString());
        btnLast->setText(QString());
        btnPause->setText(QString());
        btnNext->setText(QString());
        nowTime->setText(QString());
        btnListSing->setText(QString());
        btnSound->setText(QString());
        btnPlayMode->setText(QString());
        singSum->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\346\216\250\350\215\220", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Widget", "\345\217\221\347\216\260\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("Widget", "\347\247\201\344\272\272FM", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("Widget", "\350\247\206\351\242\221", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("Widget", "\346\234\213\345\217\213", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        btnLocalMusic->setText(QApplication::translate("Widget", "\346\234\254\345\234\260\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\345\210\233\345\273\272\347\232\204\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        btnLove->setText(QApplication::translate("Widget", "\346\210\221\345\226\234\346\254\242\347\232\204\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
        btnLoad->setText(QApplication::translate("Widget", "\344\270\213\350\275\275\347\256\241\347\220\206", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listSing->isSortingEnabled();
        listSing->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listSing->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Widget", "\346\255\214\346\233\262\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        listSing->setSortingEnabled(__sortingEnabled);

        style1->setText(QString());
        style2->setText(QString());
        style3->setText(QString());

        const bool __sortingEnabled1 = listLove->isSortingEnabled();
        listLove->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listLove->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("Widget", "\346\255\214\346\233\262\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        listLove->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
