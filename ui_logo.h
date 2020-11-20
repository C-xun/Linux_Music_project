/********************************************************************************
** Form generated from reading UI file 'logo.ui'
**
** Created: Tue Sep 22 11:38:50 2020
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGO_H
#define UI_LOGO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logo
{
public:
    QToolButton *btnBig;

    void setupUi(QWidget *Logo)
    {
        if (Logo->objectName().isEmpty())
            Logo->setObjectName(QString::fromUtf8("Logo"));
        Logo->resize(60, 60);
        Logo->setStyleSheet(QString::fromUtf8("background-color: #26282c;"));
        btnBig = new QToolButton(Logo);
        btnBig->setObjectName(QString::fromUtf8("btnBig"));
        btnBig->setGeometry(QRect(5, 5, 50, 50));
        btnBig->setStyleSheet(QString::fromUtf8("border-image: url(:/logo.png);"));

        retranslateUi(Logo);

        QMetaObject::connectSlotsByName(Logo);
    } // setupUi

    void retranslateUi(QWidget *Logo)
    {
        Logo->setWindowTitle(QApplication::translate("Logo", "Form", 0, QApplication::UnicodeUTF8));
        btnBig->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Logo: public Ui_Logo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGO_H
