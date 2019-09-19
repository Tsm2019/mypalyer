/********************************************************************************
** Form generated from reading UI file 'geci.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GECI_H
#define UI_GECI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Geci
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;

    void setupUi(QFrame *Geci)
    {
        if (Geci->objectName().isEmpty())
            Geci->setObjectName(QStringLiteral("Geci"));
        Geci->resize(600, 400);
        pushButton = new QPushButton(Geci);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 20, 200, 30));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton->setFlat(true);
        pushButton_0 = new QPushButton(Geci);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(200, 80, 200, 25));
        QPalette palette;
        QBrush brush(QColor(211, 215, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(190, 190, 190, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_0->setPalette(palette);
        QFont font1;
        font1.setPointSize(10);
        pushButton_0->setFont(font1);
        pushButton_0->setFlat(true);
        pushButton_1 = new QPushButton(Geci);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(180, 120, 240, 28));
        QPalette palette1;
        QBrush brush2(QColor(186, 189, 182, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_1->setPalette(palette1);
        QFont font2;
        font2.setPointSize(12);
        pushButton_1->setFont(font2);
        pushButton_1->setFlat(true);
        pushButton_2 = new QPushButton(Geci);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 160, 280, 31));
        QPalette palette2;
        QBrush brush3(QColor(136, 138, 133, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_2->setPalette(palette2);
        QFont font3;
        font3.setPointSize(14);
        pushButton_2->setFont(font3);
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(Geci);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 200, 320, 34));
        QPalette palette3;
        QBrush brush4(QColor(239, 41, 41, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_3->setPalette(palette3);
        QFont font4;
        font4.setPointSize(16);
        pushButton_3->setFont(font4);
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(Geci);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(160, 245, 280, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_4->setPalette(palette4);
        pushButton_4->setFont(font3);
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(Geci);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(180, 285, 240, 28));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_5->setPalette(palette5);
        pushButton_5->setFont(font2);
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(Geci);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(200, 325, 200, 25));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        pushButton_6->setPalette(palette6);
        pushButton_6->setFont(font1);
        pushButton_6->setFlat(true);
        label = new QLabel(Geci);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 400));
        label->raise();
        pushButton->raise();
        pushButton_0->raise();
        pushButton_1->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();

        retranslateUi(Geci);

        QMetaObject::connectSlotsByName(Geci);
    } // setupUi

    void retranslateUi(QFrame *Geci)
    {
        Geci->setWindowTitle(QApplication::translate("Geci", "Frame", nullptr));
        pushButton->setText(QString());
        pushButton_0->setText(QString());
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Geci: public Ui_Geci {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GECI_H
