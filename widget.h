#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <QString>
#include <QListWidgetItem>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QTableWidgetItem>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *);

public:
    static bool falg_geci;
    static bool falg_pause;
    static int percent;
    static int alltime;
    static int nowtime;
    static int volume_num;
    static int falg_volume;
    static char file_name[128];
    static bool falg_over;



private slots:

    void on_pushButton_suspend_clicked();

    void on_horizontalSlider_sliderPressed();//进度条

    void on_horizontalSlider_sliderReleased();//进度条

    void on_pushButton_over_clicked();

    void on_pushButton_next_song_clicked();//下一曲
    void on_pushButton_last_song_clicked();//上一曲

    void on_pushButton_kauitui_clicked();//快退
    void on_pushButton_kauijin_clicked();//快进

    void on_pushButton_pattern_clicked();//模式

    void on_pushButton_yinjian_clicked();//音量减
    void on_pushButton_yinjia_clicked();//音量加
    void on_pushButton_volume_clicked();//静音

    void on_toolButton_tuijian_1_clicked();//月光
    void on_toolButton_tuijian_2_clicked();//静悄悄
    void on_toolButton_tuijian_3_clicked();//可不可以
    void on_toolButton_tuijian_4_clicked();//刚好遇见你
    void on_toolButton_huafeng_clicked();//后弦-画风

    void on_pushButton_update_2_clicked();

    void on_pushButton_update_clicked();//更新歌曲信息

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_pushButton_cut_p_clicked();

    void on_pushButton_geci_clicked();

public slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    //Ui::Widget *ui;
public:
    Ui::Widget *ui;



public:
    void read_lrc(char *lrc_name);
    int lrc_cut(char *data, char *buf[]);
    void cut_song(void);
};



#endif // WIDGET_H
