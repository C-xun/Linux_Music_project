/********************************************************************************
** Form generated from reading UI file 'smallwindow.ui'
**
** Created: Tue Sep 22 12:42:40 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMALLWINDOW_H
#define UI_SMALLWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmallWindow
{
public:
    QFrame *frame;
    QLabel *label;
    QToolButton *btnBig;
    QToolButton *btnSound;
    QToolButton *toolButton_3;
    QLabel *label_2;
    QFrame *frame_2;
    QLabel *sing;

    void setupUi(QWidget *SmallWindow)
    {
        if (SmallWindow->objectName().isEmpty())
            SmallWindow->setObjectName(QString::fromUtf8("SmallWindow"));
        SmallWindow->resize(400, 387);
        SmallWindow->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        frame = new QFrame(SmallWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 410, 60));
        frame->setStyleSheet(QString::fromUtf8("background-color: #26282c;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(5, 5, 50, 50));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/logo.png);"));
        btnBig = new QToolButton(frame);
        btnBig->setObjectName(QString::fromUtf8("btnBig"));
        btnBig->setGeometry(QRect(360, 17, 25, 25));
        btnBig->setStyleSheet(QString::fromUtf8("border-image: url(:/big.png);"));
        btnSound = new QToolButton(frame);
        btnSound->setObjectName(QString::fromUtf8("btnSound"));
        btnSound->setGeometry(QRect(310, 18, 25, 25));
        btnSound->setStyleSheet(QString::fromUtf8("border-image: url(:/sound.png);"));
        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(260, 17, 25, 25));
        toolButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/list.png);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 10, 171, 41));
        QFont font;
        font.setPointSize(7);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);"));
        frame_2 = new QFrame(SmallWindow);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 60, 410, 81));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: #26282c;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        sing = new QLabel(frame_2);
        sing->setObjectName(QString::fromUtf8("sing"));
        sing->setGeometry(QRect(0, 19, 401, 41));
        QFont font1;
        font1.setPointSize(6);
        sing->setFont(font1);
        sing->setStyleSheet(QString::fromUtf8("color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(231,80,229, 255), stop:1 rgba(7,208,255, 255));"));
        sing->setAlignment(Qt::AlignCenter);
        frame->raise();
        btnBig->raise();
        frame_2->raise();

        retranslateUi(SmallWindow);

        QMetaObject::connectSlotsByName(SmallWindow);
    } // setupUi

    void retranslateUi(QWidget *SmallWindow)
    {
        SmallWindow->setWindowTitle(QApplication::translate("SmallWindow", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        btnBig->setText(QString());
        btnSound->setText(QString());
        toolButton_3->setText(QString());
        label_2->setText(QApplication::translate("SmallWindow", "\345\260\217\346\233\271\343\201\256Music", 0, QApplication::UnicodeUTF8));
        sing->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SmallWindow: public Ui_SmallWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMALLWINDOW_H
