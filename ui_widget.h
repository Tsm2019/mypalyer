/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <geci.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    Geci *widget;
    QToolButton *toolButton_MV;
    QLabel *label;
    QToolButton *toolButton_tuijian;
    QToolButton *toolButton_lib;
    QToolButton *toolButton_zhibo;
    QLabel *label_nowtime;
    QSlider *horizontalSlider;
    QLabel *label_time;
    QPushButton *pushButton_suspend;
    QLabel *label_file_name;
    QToolButton *toolButton_tuijian_1;
    QToolButton *toolButton_tuijian_2;
    QToolButton *toolButton_tuijian_3;
    QLabel *label_beijing;
    QPushButton *pushButton_over;
    QPushButton *pushButton_next_song;
    QPushButton *pushButton_last_song;
    QPushButton *pushButton_kauitui;
    QPushButton *pushButton_kauijin;
    QPushButton *pushButton_pattern;
    QPushButton *pushButton_yinjian;
    QPushButton *pushButton_yinjia;
    QPushButton *pushButton_volume;
    QToolButton *toolButton_huafeng;
    QPushButton *pushButton_update;
    QPushButton *pushButton_update_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label_h;
    QToolButton *toolButton_tuijian_4;
    QPushButton *pushButton_cut_p;
    QPushButton *pushButton_geci;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1024, 600);
        widget = new Geci(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 10, 600, 400));
        toolButton_MV = new QToolButton(Widget);
        toolButton_MV->setObjectName(QStringLiteral("toolButton_MV"));
        toolButton_MV->setGeometry(QRect(590, 50, 120, 30));
        toolButton_MV->setAutoRaise(true);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 10, 600, 400));
        toolButton_tuijian = new QToolButton(Widget);
        toolButton_tuijian->setObjectName(QStringLiteral("toolButton_tuijian"));
        toolButton_tuijian->setGeometry(QRect(310, 50, 120, 30));
        toolButton_tuijian->setAutoRaise(true);
        toolButton_lib = new QToolButton(Widget);
        toolButton_lib->setObjectName(QStringLiteral("toolButton_lib"));
        toolButton_lib->setGeometry(QRect(450, 50, 120, 30));
        toolButton_lib->setAutoRaise(true);
        toolButton_zhibo = new QToolButton(Widget);
        toolButton_zhibo->setObjectName(QStringLiteral("toolButton_zhibo"));
        toolButton_zhibo->setGeometry(QRect(730, 50, 120, 30));
        toolButton_zhibo->setAutoRaise(true);
        label_nowtime = new QLabel(Widget);
        label_nowtime->setObjectName(QStringLiteral("label_nowtime"));
        label_nowtime->setGeometry(QRect(287, 460, 50, 20));
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(327, 462, 500, 20));
        QPalette palette;
        QBrush brush(QColor(114, 159, 207, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        horizontalSlider->setPalette(palette);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_time = new QLabel(Widget);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(830, 460, 50, 20));
        pushButton_suspend = new QPushButton(Widget);
        pushButton_suspend->setObjectName(QStringLiteral("pushButton_suspend"));
        pushButton_suspend->setGeometry(QRect(500, 530, 50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/begin_song.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_suspend->setIcon(icon);
        pushButton_suspend->setIconSize(QSize(50, 50));
        pushButton_suspend->setFlat(true);
        label_file_name = new QLabel(Widget);
        label_file_name->setObjectName(QStringLiteral("label_file_name"));
        label_file_name->setGeometry(QRect(290, 420, 151, 40));
        QFont font;
        font.setFamily(QStringLiteral("AR PL UKai TW MBE"));
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_file_name->setFont(font);
        toolButton_tuijian_1 = new QToolButton(Widget);
        toolButton_tuijian_1->setObjectName(QStringLiteral("toolButton_tuijian_1"));
        toolButton_tuijian_1->setGeometry(QRect(310, 120, 120, 30));
        toolButton_tuijian_1->setAutoRaise(true);
        toolButton_tuijian_2 = new QToolButton(Widget);
        toolButton_tuijian_2->setObjectName(QStringLiteral("toolButton_tuijian_2"));
        toolButton_tuijian_2->setGeometry(QRect(310, 180, 120, 30));
        toolButton_tuijian_2->setAutoRaise(true);
        toolButton_tuijian_3 = new QToolButton(Widget);
        toolButton_tuijian_3->setObjectName(QStringLiteral("toolButton_tuijian_3"));
        toolButton_tuijian_3->setGeometry(QRect(310, 240, 120, 30));
        toolButton_tuijian_3->setAutoRaise(true);
        label_beijing = new QLabel(Widget);
        label_beijing->setObjectName(QStringLiteral("label_beijing"));
        label_beijing->setGeometry(QRect(0, 0, 1024, 600));
        label_beijing->setPixmap(QPixmap(QString::fromUtf8(":/image/beijing1.jpg")));
        pushButton_over = new QPushButton(Widget);
        pushButton_over->setObjectName(QStringLiteral("pushButton_over"));
        pushButton_over->setGeometry(QRect(984, 0, 40, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/over1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_over->setIcon(icon1);
        pushButton_over->setIconSize(QSize(40, 40));
        pushButton_over->setFlat(true);
        pushButton_next_song = new QPushButton(Widget);
        pushButton_next_song->setObjectName(QStringLiteral("pushButton_next_song"));
        pushButton_next_song->setGeometry(QRect(550, 530, 50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/nextsong.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next_song->setIcon(icon2);
        pushButton_next_song->setIconSize(QSize(50, 50));
        pushButton_next_song->setFlat(true);
        pushButton_last_song = new QPushButton(Widget);
        pushButton_last_song->setObjectName(QStringLiteral("pushButton_last_song"));
        pushButton_last_song->setGeometry(QRect(450, 530, 50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/last_song.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_last_song->setIcon(icon3);
        pushButton_last_song->setIconSize(QSize(50, 50));
        pushButton_last_song->setFlat(true);
        pushButton_kauitui = new QPushButton(Widget);
        pushButton_kauitui->setObjectName(QStringLiteral("pushButton_kauitui"));
        pushButton_kauitui->setGeometry(QRect(400, 530, 50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/kuaitui_song.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_kauitui->setIcon(icon4);
        pushButton_kauitui->setIconSize(QSize(50, 50));
        pushButton_kauitui->setFlat(true);
        pushButton_kauijin = new QPushButton(Widget);
        pushButton_kauijin->setObjectName(QStringLiteral("pushButton_kauijin"));
        pushButton_kauijin->setGeometry(QRect(600, 530, 50, 50));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/kuaijin_song.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_kauijin->setIcon(icon5);
        pushButton_kauijin->setIconSize(QSize(50, 50));
        pushButton_kauijin->setFlat(true);
        pushButton_pattern = new QPushButton(Widget);
        pushButton_pattern->setObjectName(QStringLiteral("pushButton_pattern"));
        pushButton_pattern->setGeometry(QRect(310, 530, 50, 50));
        QPalette palette1;
        QBrush brush1(QColor(238, 238, 236, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        pushButton_pattern->setPalette(palette1);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/shunxu.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pattern->setIcon(icon6);
        pushButton_pattern->setIconSize(QSize(50, 50));
        pushButton_pattern->setFlat(true);
        pushButton_yinjian = new QPushButton(Widget);
        pushButton_yinjian->setObjectName(QStringLiteral("pushButton_yinjian"));
        pushButton_yinjian->setGeometry(QRect(730, 535, 40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/yin_jian.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_yinjian->setIcon(icon7);
        pushButton_yinjian->setIconSize(QSize(40, 40));
        pushButton_yinjian->setFlat(true);
        pushButton_yinjia = new QPushButton(Widget);
        pushButton_yinjia->setObjectName(QStringLiteral("pushButton_yinjia"));
        pushButton_yinjia->setGeometry(QRect(830, 535, 40, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/yin_jia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_yinjia->setIcon(icon8);
        pushButton_yinjia->setIconSize(QSize(40, 40));
        pushButton_yinjia->setFlat(true);
        pushButton_volume = new QPushButton(Widget);
        pushButton_volume->setObjectName(QStringLiteral("pushButton_volume"));
        pushButton_volume->setGeometry(QRect(780, 535, 40, 40));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/yinliang.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_volume->setIcon(icon9);
        pushButton_volume->setIconSize(QSize(40, 40));
        pushButton_volume->setFlat(true);
        toolButton_huafeng = new QToolButton(Widget);
        toolButton_huafeng->setObjectName(QStringLiteral("toolButton_huafeng"));
        toolButton_huafeng->setGeometry(QRect(590, 120, 120, 30));
        toolButton_huafeng->setAutoRaise(true);
        pushButton_update = new QPushButton(Widget);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));
        pushButton_update->setGeometry(QRect(210, 530, 50, 50));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/shuaxin.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update->setIcon(icon10);
        pushButton_update->setIconSize(QSize(50, 50));
        pushButton_update->setFlat(true);
        pushButton_update_2 = new QPushButton(Widget);
        pushButton_update_2->setObjectName(QStringLiteral("pushButton_update_2"));
        pushButton_update_2->setGeometry(QRect(175, 120, 25, 25));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/image/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_update_2->setIcon(icon11);
        pushButton_update_2->setIconSize(QSize(25, 25));
        pushButton_update_2->setFlat(true);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(5, 120, 145, 25));
        lineEdit->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        lineEdit->setFrame(false);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 490, 350, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("TakaoPGothic"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setFlat(true);
        tableWidget = new QTableWidget(Widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(5, 150, 210, 261));
        QPalette palette2;
        QRadialGradient gradient(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(0, 0, 0, 0));
        gradient.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush2(gradient);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        QRadialGradient gradient1(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(0, 0, 0, 0));
        gradient1.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient1.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient1.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient1.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient1.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient1.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient1.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush5(gradient1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(191, 64, 64, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush6);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        QRadialGradient gradient2(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(0, 0, 0, 0));
        gradient2.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient2.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient2.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient2.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient2.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient2.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient2.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush7(gradient2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        QRadialGradient gradient3(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(0, 0, 0, 0));
        gradient3.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient3.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient3.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient3.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient3.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient3.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient3.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush9(gradient3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        QRadialGradient gradient4(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(0, 0, 0, 0));
        gradient4.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient4.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient4.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient4.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient4.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient4.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient4.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush10(gradient4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        QRadialGradient gradient5(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(0, 0, 0, 0));
        gradient5.setColorAt(0.52, QColor(0, 0, 0, 0));
        gradient5.setColorAt(0.565, QColor(82, 121, 76, 33));
        gradient5.setColorAt(0.65, QColor(159, 235, 148, 64));
        gradient5.setColorAt(0.721925, QColor(255, 238, 150, 129));
        gradient5.setColorAt(0.77, QColor(255, 128, 128, 204));
        gradient5.setColorAt(0.89, QColor(191, 128, 255, 64));
        gradient5.setColorAt(1, QColor(0, 0, 0, 0));
        QBrush brush12(gradient5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        QBrush brush13(QColor(145, 145, 145, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        tableWidget->setPalette(palette2);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QStringLiteral("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Sunken);
        tableWidget->setLineWidth(0);
        tableWidget->setAutoScroll(true);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->horizontalHeader()->setDefaultSectionSize(180);
        label_h = new QLabel(Widget);
        label_h->setObjectName(QStringLiteral("label_h"));
        label_h->setGeometry(QRect(780, 440, 40, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("TakaoPGothic"));
        font2.setPointSize(12);
        label_h->setFont(font2);
        toolButton_tuijian_4 = new QToolButton(Widget);
        toolButton_tuijian_4->setObjectName(QStringLiteral("toolButton_tuijian_4"));
        toolButton_tuijian_4->setGeometry(QRect(310, 300, 120, 30));
        toolButton_tuijian_4->setAutoRaise(true);
        pushButton_cut_p = new QPushButton(Widget);
        pushButton_cut_p->setObjectName(QStringLiteral("pushButton_cut_p"));
        pushButton_cut_p->setGeometry(QRect(900, 530, 50, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("TakaoPGothic"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_cut_p->setFont(font3);
        pushButton_cut_p->setFlat(true);
        pushButton_geci = new QPushButton(Widget);
        pushButton_geci->setObjectName(QStringLiteral("pushButton_geci"));
        pushButton_geci->setGeometry(QRect(670, 530, 50, 50));
        QFont font4;
        font4.setFamily(QStringLiteral("TakaoPGothic"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_geci->setFont(font4);
        pushButton_geci->setIconSize(QSize(50, 50));
        pushButton_geci->setFlat(true);
        label_beijing->raise();
        label->raise();
        horizontalSlider->raise();
        label_time->raise();
        label_nowtime->raise();
        pushButton_suspend->raise();
        label_file_name->raise();
        toolButton_tuijian_1->raise();
        toolButton_tuijian_2->raise();
        toolButton_tuijian_3->raise();
        pushButton_next_song->raise();
        pushButton_last_song->raise();
        pushButton_kauitui->raise();
        pushButton_kauijin->raise();
        pushButton_pattern->raise();
        pushButton_yinjian->raise();
        pushButton_yinjia->raise();
        pushButton_volume->raise();
        toolButton_huafeng->raise();
        pushButton_over->raise();
        pushButton_update->raise();
        pushButton_update_2->raise();
        lineEdit->raise();
        pushButton->raise();
        tableWidget->raise();
        toolButton_tuijian->raise();
        toolButton_zhibo->raise();
        toolButton_lib->raise();
        toolButton_MV->raise();
        label_h->raise();
        toolButton_tuijian_4->raise();
        widget->raise();
        pushButton_cut_p->raise();
        pushButton_geci->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        toolButton_MV->setText(QApplication::translate("Widget", "MV", nullptr));
        label->setText(QString());
        toolButton_tuijian->setText(QApplication::translate("Widget", "\346\216\250\350\215\220", nullptr));
        toolButton_lib->setText(QApplication::translate("Widget", "\344\271\220\345\272\223", nullptr));
        toolButton_zhibo->setText(QApplication::translate("Widget", "\347\233\264\346\222\255", nullptr));
        label_nowtime->setText(QString());
        label_time->setText(QString());
        pushButton_suspend->setText(QString());
        label_file_name->setText(QString());
        toolButton_tuijian_1->setText(QApplication::translate("Widget", " \346\234\210\345\205\211", nullptr));
        toolButton_tuijian_2->setText(QApplication::translate("Widget", "\351\235\231\346\202\204\346\202\204", nullptr));
        toolButton_tuijian_3->setText(QApplication::translate("Widget", "\345\217\257\344\270\215\345\217\257\344\273\245", nullptr));
        label_beijing->setText(QString());
        pushButton_over->setText(QString());
        pushButton_next_song->setText(QString());
        pushButton_last_song->setText(QString());
        pushButton_kauitui->setText(QString());
        pushButton_kauijin->setText(QString());
        pushButton_pattern->setText(QString());
        pushButton_yinjian->setText(QString());
        pushButton_yinjia->setText(QString());
        pushButton_volume->setText(QString());
        toolButton_huafeng->setText(QApplication::translate("Widget", "\345\220\216\345\274\246-\347\224\273\351\243\216", nullptr));
        pushButton_update->setText(QString());
        pushButton_update_2->setText(QString());
        pushButton->setText(QString());
        label_h->setText(QString());
        toolButton_tuijian_4->setText(QApplication::translate("Widget", "\345\210\232\345\245\275\351\201\207\350\247\201\344\275\240", nullptr));
        pushButton_cut_p->setText(QApplication::translate("Widget", "cut", nullptr));
        pushButton_geci->setText(QApplication::translate("Widget", "\350\257\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
