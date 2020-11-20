/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Sep 22 14:46:04 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QLabel *label;

    void setupUi(QWidget *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->setEnabled(true);
        mainWindow->resize(791, 461);
        mainWindow->setStyleSheet(QString::fromUtf8("background-color: #212124;"));
        label = new QLabel(mainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 100, 250, 250));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/sing.png);\n"
"background-color: transparent;"));
        label->setFrameShape(QFrame::WinPanel);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QWidget *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
