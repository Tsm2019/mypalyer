#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QPushButton>
#include <QIcon>
#include <dirent.h>
#include <QString>
#include <QFileDialog>
#include <QIODevice>
#include <QByteArray>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>
#include <map>
#include <algorithm>
#include <time.h>

using namespace std;


char all_time[16] = "";
extern struct MyFd
{
    int fifo_fd;
    int fd[2];
}My_fd;

int Widget::percent=0;//进度
int Widget::alltime=0;//总时间
int Widget::nowtime=0;//当前时间
int Widget::volume_num=50;//初始音量
int Widget::falg_volume=1;//初始非静音
bool Widget::falg_geci = true;
bool Widget::falg_pause = false;
char Widget::file_name[128]="";
bool Widget::falg_over = true;

bool falg_new_table = false;
bool falg_hor = true;
bool falg_cut_song = true;

QString  lrc_buf_now = "";
QString  lrc_buf_next = "";
int pattern = 2;
int song_num = 0;
int lrc_num_falg = 0;
int next_song_num = 0;


map<int,QString> m_lrc;
map<int,QString> songName;
vector<int> v_lrc_time;

void *deal_fun(void *arg);
void *deal_fun2(void *arg);
void *deal_write_lrc(void *arg);

extern map<int, QString> lrc_analysis(map<int,QString> m_lrc, char *lrc[], int row);


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //歌词窗口隐藏
    ui->widget->hide();
    //歌曲列表初始化
    Widget::on_pushButton_update_clicked();

    //创建一个接受mplayer回应的线程
    pthread_t mplayer_ack;
    //创建一个线程 给mplayer发送指令
    pthread_t send_mplayer;
    pthread_create(&mplayer_ack,NULL,deal_fun, (void *)ui);
    pthread_create(&send_mplayer,NULL,deal_fun2, (void *)this);
    pthread_detach(mplayer_ack);
    pthread_detach(send_mplayer);
    //创建一个线程写歌词
    pthread_t falg_lrc;
    pthread_create(&falg_lrc,NULL,deal_write_lrc,(void *)ui);
    pthread_detach(falg_lrc);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
#if 0
    //定义一个画家
    //QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/image/beijing2.jpg");
    //修改图片大小
    pix = pix.scaled(600,180);
    //画图
    //painter->drawPixmap(0,0,pix.width(),pix.height(),pix);
    //ui->pushButton_geci->setPixmap(pix1);
    //printf("-----------1---------------\n");
#endif
    int falg_i = 1;
    if(falg_new_table && falg_i)
    {
        Widget::on_tableWidget_cellClicked(next_song_num, 0);
        falg_i = 0;
        usleep(200*1000);
    }
}


void *deal_fun(void *arg)
{
    Ui::Widget* ui = (Ui::Widget*)arg;
    while(1)
    {
        char buf[128]="";
        read(My_fd.fd[0],buf,sizeof(buf));
        char cmd[128]="";

        sscanf(buf,"%[^=]",cmd);
        if(strcmp(cmd,"ANS_PERCENT_POSITION") == 0)//百分比
        {
            float num = 0.0f;
            sscanf(buf,"%*[^=]=%f",&num);
            Widget::percent=(int)(num+0.5);
            printf("\r当前的百分比为:%%%d \t", Widget::percent);
            char hor_buf[16] = "";
            sprintf(hor_buf,"%d%%",Widget::percent);
            if(falg_hor)
            {
                ui->label_h->setText(hor_buf);
                ui->horizontalSlider->setValue(Widget::percent);
            }

        }
        else if(strcmp(cmd,"ANS_TIME_POSITION") == 0)//当前时间
        {
            float num = 0.0f;
            sscanf(buf,"%*[^=]=%f",&num);
            Widget::nowtime = (int)(num+0.5);
            int m = (int)(Widget::nowtime)/60;
            int s = (int)(Widget::nowtime)%60;
            char now_time[16] = "";
            sprintf(now_time,"%02d:%02d",m,s);
            ui->label_nowtime->setText(now_time);
            printf("当前的时间为:%s",now_time);
        }
        else if(strcmp(cmd,"ANS_LENGTH") == 0)//总时间
        {
            float num = 0.0f;
            sscanf(buf,"%*[^=]=%f",&num);
            Widget::alltime = (int)(num+0.5);
            int m = (int)(Widget::alltime)/60;
            int s = (int)(Widget::alltime)%60;
            char alltime[16] = "";
            sprintf(alltime,"%02d:%02d",m,s);
            ui->label_time->setText(alltime);

        }
        else if(strcmp(cmd,"ANS_FILENAME") == 0)//歌名
        {
            char file_buf[128] ="";
            sscanf(buf,"%*[^=]=%s",file_buf);
            file_buf[0] = ' ';
            int len = strlen(file_buf);
            char song_name[32] = "";
            strncpy(song_name,file_buf,len-5);
            strcmp(Widget::file_name,song_name);
            ui->label_file_name->setText(song_name);
        }
        fflush(stdout);
    }
}

void *deal_fun2(void *arg)
{
    Widget* my_this = (Widget*)arg;
    //不停的给fifo_cmd发送获取当前时间以及进度
    while(1)
    {

        usleep(100*1000);//0.1秒
        if(Widget::falg_pause)
        {
            usleep(100*1000);//0.1秒发指令
            write(My_fd.fifo_fd,"get_percent_pos\n", strlen("get_percent_pos\n"));
            usleep(100*1000);//0.1秒发指令
            write(My_fd.fifo_fd,"get_time_pos\n", strlen("get_time_pos\n"));
            usleep(100*1000);//0.1秒发指令
            write(My_fd.fifo_fd,"get_time_length\n", strlen("get_time_length\n"));
            usleep(100*1000);//0.1秒发指令
            write(My_fd.fifo_fd,"get_file_name\n", strlen("get_file_name\n"));
            falg_new_table=false;
            if(Widget::nowtime == Widget::alltime-1)//循环
            {
                if(songName.empty())
                {
                    continue;
                }
                falg_cut_song = true;
                my_this->cut_song();
                usleep(100*1000);//0.1秒发指令
                write(My_fd.fifo_fd,"get_time_pos\n", strlen("get_time_pos\n"));
                usleep(100*1000);//0.1秒发指令
                write(My_fd.fifo_fd,"get_time_length\n", strlen("get_time_length\n"));

                falg_new_table=true;
            }
        }
        else
        {
            usleep(100*1000);//0.1秒
        }
    }
}

void *deal_write_lrc(void *arg)
{
    Ui::Widget* my_ui = (Ui::Widget*)arg;
    if(m_lrc.empty())
    {
        sleep(3);
    }
    sort(v_lrc_time.begin(),v_lrc_time.end());
    while(Widget::falg_over)
    {
        usleep(500*1000);
        //lrc_num_falg++;
        for_each(m_lrc.begin(),m_lrc.end(),[=](pair<int,QString> val){
            if(Widget::nowtime == val.first)
            {
                lrc_buf_now =val.second;

            }
        });
        my_ui->pushButton->setText(lrc_buf_now);
    }
}

void Widget::on_pushButton_suspend_clicked()//播放暂停
{
    if(Widget::falg_pause)
    {
        Widget::falg_pause = false;
        usleep(500*1000);//0.3秒发指令
        write(My_fd.fifo_fd,"pause\n",strlen("pause\n"));
        ui->pushButton_suspend->setIcon(QIcon(":/image/begin_song.png"));

    }
    else if(!Widget::falg_pause)
    {
        Widget::falg_pause = true;
        usleep(500*1000);//0.3秒发指令
        write(My_fd.fifo_fd,"pause\n",strlen("pause\n"));
        ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    }
    return;
}


void Widget::on_horizontalSlider_sliderPressed()//进度条
{
    falg_hor = false;
}
void Widget::on_horizontalSlider_sliderReleased()//进度条
{
    if(ui->horizontalSlider->value() != Widget::percent)
    {
        usleep(100*1000);
        int seek_time = ((ui->horizontalSlider->value()-Widget::percent)*(Widget::alltime)/100);
        char buf[128] = "";
        sprintf(buf,"%s %d\n","seek",seek_time);
        printf("%s",buf);

        write(My_fd.fifo_fd,buf,strlen(buf));
        if(!falg_pause)
        {
            falg_pause = true;
            ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
        }
        ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));

        falg_hor = true;
    }
}

void Widget::on_pushButton_over_clicked()
{
    usleep(100*1000);
    falg_over = false;
    write(My_fd.fifo_fd,"quit\n",strlen("quit\n"));
    sleep(1);
    m_lrc.clear();
    songName.clear();
    usleep(100*1000);
    this->close();
}

void Widget::on_pushButton_next_song_clicked()//下一曲
{
    usleep(200*1000);
    if(songName.empty())
    {
        ui->pushButton->setText("请刷新列表");
        usleep(100*1000);
        return;
    }
    falg_cut_song = true;
    Widget::cut_song();
}
void Widget::on_pushButton_last_song_clicked()//上一曲
{
    usleep(200*1000);
    //printf("\n------------\n");
    if(songName.empty())
    {
        ui->pushButton->setText("请刷新列表");
        usleep(100*1000);
        return;
    }
    falg_cut_song = false;
    Widget::cut_song();
}

void Widget::on_pushButton_kauitui_clicked()//快退
{
    usleep(100*1000);
    if(nowtime-10 < 0)
    {
        return;
    }
    write(My_fd.fifo_fd,"seek -10\n",strlen("seek -10\n"));
    if(!falg_pause)
    {
        falg_pause = true;
        ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    }
}
void Widget::on_pushButton_kauijin_clicked()//快进
{
    usleep(100*1000);
    if(nowtime+10 > alltime)
    {
        return;
    }
    write(My_fd.fifo_fd,"seek 10\n",strlen("seek 10\n"));
    if(!falg_pause)
    {
        falg_pause = true;
        ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    }
}
void Widget::on_pushButton_pattern_clicked()//模式
{
    //Widget::on_pushButton_update_clicked();
    if(pattern == 0)
    {
        pattern = 1;//单曲循环
        ui->pushButton_pattern->setIcon(QIcon(":/image/danqu.png"));
    }
    else if(pattern == 1)
    {
        pattern = 2;//列表循环
        ui->pushButton_pattern->setIcon(QIcon(":/image/shunxu.png"));
    }
    else if(pattern == 2)
    {
        pattern = 0;//随机播放
        ui->pushButton_pattern->setIcon(QIcon(":/image/suiji.png"));
    }
}

void Widget::on_pushButton_yinjian_clicked()//音量减
{
    if(volume_num<0)
    {
        return;
    }
    volume_num -= 10;
    Widget::falg_volume= 1;
    ui->pushButton_volume->setIcon(QIcon(":/image/yinliang.png"));
    char volume_2[32] = "";
    sprintf(volume_2,"%s %d 1\n","volume",volume_num);
    write(My_fd.fifo_fd,volume_2,strlen(volume_2));
}
void Widget::on_pushButton_yinjia_clicked()//音量加
{
    if(volume_num>100)
    {
        return;
    }
    volume_num +=10;
    Widget::falg_volume= 1;
    ui->pushButton_volume->setIcon(QIcon(":/image/yinliang.png"));
    char volume_1[32] = "";
    sprintf(volume_1,"%s %d 1\n","volume",volume_num);
    write(My_fd.fifo_fd,volume_1,strlen(volume_1));
}
void Widget::on_pushButton_volume_clicked()//静音
{
    char buf[64] = "";
    sprintf(buf,"%s %d\n","mute",Widget::falg_volume);
    write(My_fd.fifo_fd,buf,strlen(buf));
    if(Widget::falg_volume == 1)
    {
        Widget::falg_volume = 0;
        ui->pushButton_volume->setIcon(QIcon(":/image/jingyin.png"));
    }
    else
    {
        Widget::falg_volume = 1;
        ui->pushButton_volume->setIcon(QIcon(":/image/yinliang.png"));
    }
}

void Widget::on_toolButton_tuijian_1_clicked()//月光
{
    Widget::falg_pause=true;
    usleep(200*1000);
    write(My_fd.fifo_fd, "loadfile ./music/月光.mp3\n", strlen("loadfile ./music/月光.mp3\n"));
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    read_lrc("./music/月光.lrc");
}
void Widget::on_toolButton_tuijian_2_clicked()//大泫-静悄悄
{
    Widget::falg_pause=true;
    usleep(200*1000);
    write(My_fd.fifo_fd, "loadfile ./music/静悄悄.mp3\n", strlen("loadfile ./music/静悄悄.mp3\n"));
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    read_lrc("./music/静悄悄.lrc");
}
void Widget::on_toolButton_tuijian_3_clicked()//可不可以
{
    Widget::falg_pause=true;
    usleep(200*1000);
    write(My_fd.fifo_fd, "loadfile ./music/可不可以.mp3\n", strlen("loadfile ./music/可不可以.mp3\n"));
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    read_lrc("./music/可不可以.lrc");
}
void Widget::on_toolButton_tuijian_4_clicked()//李玉刚-刚好遇见你
{
    Widget::falg_pause=true;
    usleep(200*1000);
    write(My_fd.fifo_fd, "loadfile ./music/刚好遇见你.mp3\n", strlen("loadfile ./music/刚好遇见你.mp3\n"));
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    read_lrc("./music/刚好遇见你.lrc");
}
void Widget::on_toolButton_huafeng_clicked()//MV 后弦-画风
{
    usleep(100*1000);
    Widget::falg_pause=false;
    usleep(100*1000);
    write(My_fd.fifo_fd, "loadfile 00.mp3\n", strlen("loadfile 00.mp3\n"));
    usleep(500*1000);//0.5秒发指令
    write(My_fd.fifo_fd, "loadfile ./MV/后弦-画风.mkv\n", strlen("loadfile ./MV/后弦-画风.mkv\n"));
    ui->pushButton_suspend->setIcon(QIcon(":/image/begin_song.png"));
}

void Widget::on_pushButton_update_2_clicked()//!!!!!!!!!err---
{
    ui->lineEdit->show();
    QString path = QFileDialog::getOpenFileName(this,"open","E:\\Share");
    ui->lineEdit->setText(path);
}

void Widget::on_pushButton_update_clicked()//更新歌曲信息
{
    DIR *dir;
    dir = opendir("./songfile");
    song_num = 0;
    while (1)
    {
        struct dirent *ent=NULL;
        ent = readdir(dir);
        if(ent == NULL)
        {
            ui->tableWidget->setColumnCount(1);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"歌曲");
            ui->tableWidget->setRowCount(song_num);
            int i = 0;
            for(i=0;i<song_num;i++)
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(songName[i].toUtf8().data()));
            }
            break;
        }
        if (ent->d_type == DT_REG)
        {
            char filename[128] = "";
            strcpy(filename,ent->d_name);
            int name_long = strlen(filename);
            if(strcmp(filename+name_long-3,"mp3") == 0)
            {
                songName.insert(make_pair(song_num,filename));
                song_num++;
            }
        }

    }
    closedir(dir);
}

void Widget::on_tableWidget_itemClicked(QTableWidgetItem *item)//单击表格内容切割
{
    next_song_num = item->row();
    if(!Widget::falg_pause)
    {
        Widget::falg_pause=true;
    }
    usleep(100*1000);
    char buf[64] = "";
    sprintf(buf,"%s ./songfile/%s\n","loadfile",item->text().toUtf8().data());
    write(My_fd.fifo_fd, buf, strlen(buf));
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    char buf1[64] = "";
    char buf2[64] = "";
    int song_len = strlen(item->text().toUtf8().data());
    strncpy(buf2,item->text().toUtf8().data(),song_len-3);
    sprintf(buf1,"%s%slrc","./lyricsfile/",buf2);
    read_lrc(buf1);
}

void Widget::on_tableWidget_cellClicked(int row, int column)
{
    //printf("%d %d \n",row,column);
    int i = 0;
    for(i = 0;i<song_num;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(songName.at(i).toUtf8().data() ));
    }
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QIcon(":/image/music.png"),songName.at(row).toUtf8().data()));
}

void Widget::read_lrc(char *lrc_name)//读歌词
{

    //读歌词文件
    FILE *fpr = fopen(lrc_name, "r");
    if (fpr == NULL)
    {
        perror("fopen");
        return;
    }
    fseek(fpr, 0, 2);
    long len = ftell(fpr);
    char *file = (char *)calloc(1, len + 1);
    rewind(fpr);
    fread(file, len, 1, fpr);
    fclose(fpr);
    char *lrc_file = file;

    //歌词文件按行切割
    char *buf[128] = {NULL};
    int row = 0;
    row = lrc_cut(lrc_file, buf);

    //逐行解析歌词
    m_lrc.clear();
    v_lrc_time.clear();
    m_lrc = lrc_analysis(m_lrc, buf, row);

}

int Widget::lrc_cut(char *data, char *buf[])//剪切成行
{
    int i = 0;
    buf[i] = strtok(data, "\r\n");
    while (buf[i] != NULL)
    {
        i++;
        buf[i] = strtok(NULL, "\r\n");
    }
    return i;
}

map<int ,QString> lrc_analysis(map<int ,QString> m_lrc, char *lrc[], int row)//歌词存入map容器
{
    int i = 0;
    for (i = 3; i >= 0; i--)
    {
        char *p = lrc[i];
        //m_lrc.insert(make_pair(i,p));
        //v_lrc_time.push_back(i);
    }

    for (i = 4; i < row; i++)
    {
        char *p_lrc = lrc[i];
        while (*p_lrc == '[') //[02:04.94][00:36.09]我想大声宣布 对你依依不舍
        {
            p_lrc += 10;
        }
        char *ps = lrc[i];
        while (*ps == '[')
        {
            int m = 0, s = 0;
            sscanf(ps, "[%d:%d", &m, &s);
            int falg_time  = m*60+s;
            v_lrc_time.push_back(falg_time);
            m_lrc.insert(make_pair(falg_time,p_lrc));
            ps += 10;
        }
    }
    return m_lrc;
}


void Widget::cut_song()//切歌
{
    if(!songName.empty() && pattern == 2 && falg_cut_song)//下一曲列表循环
    {
        next_song_num++;
        if(next_song_num == song_num)
        {
            next_song_num = 0;
        }
    }
    if(!songName.empty() && pattern == 2 && !falg_cut_song)//上一曲列表循环
    {
        next_song_num--;
        if(next_song_num < 0)
        {
            next_song_num = song_num-1;
        }
    }
    if(!songName.empty() && pattern == 1)//单曲循环
    {

    }
    if(!songName.empty() && pattern == 0)//随机播放
    {
        usleep(200*1000);
        srand(time(NULL));
        next_song_num = rand()%song_num;
    }
    Widget::falg_pause=true;
    ui->pushButton_suspend->setIcon(QIcon(":/image/pause_song.png"));
    char buf[64] = "";
    sprintf(buf,"%s ./songfile/%s\n","loadfile",songName.at(next_song_num).toUtf8().data());
    printf("%s\n",buf);
    usleep(200*1000);
    write(My_fd.fifo_fd, buf, strlen(buf));
    char buf1[64] = "";
    char buf2[64] = "";
    int song_len = strlen(songName.at(next_song_num).toUtf8().data());
    strncpy(buf2,songName.at(next_song_num).toUtf8().data(),song_len-3);
    sprintf(buf1,"%s%slrc","./lyricsfile/",buf2);
    read_lrc(buf1);
    if(falg_new_table)
    {

    }
    Widget::on_tableWidget_cellClicked(next_song_num,0);//
}



void Widget::on_pushButton_cut_p_clicked()
{
    static int beijing_falg = 120;
    char buf[64] = "";
    sprintf(buf,":/image/%d.jpg",beijing_falg >= 120 ? (beijing_falg = 110):++beijing_falg);

    QPixmap pix;
    pix.load(buf);
    pix = pix.scaled(1024,600);
    ui->label_beijing->setPixmap(pix);
}

void Widget::on_pushButton_geci_clicked()
{
    printf("---\n");
    if(falg_geci)
    {
        ui->widget->show();
        ui->toolButton_tuijian->hide();
        ui->toolButton_tuijian_1->hide();
        ui->toolButton_tuijian_2->hide();
        ui->toolButton_tuijian_3->hide();
        ui->toolButton_tuijian_4->hide();
        ui->toolButton_lib->hide();
        ui->toolButton_MV->hide();
        ui->toolButton_zhibo->hide();
        ui->toolButton_huafeng->hide();

        falg_geci=false;
        return;
    }
    else if(!falg_geci)
    {
        ui->widget->hide();
        ui->toolButton_tuijian->show();
        ui->toolButton_tuijian_1->show();
        ui->toolButton_tuijian_2->show();
        ui->toolButton_tuijian_3->show();
        ui->toolButton_tuijian_4->show();
        ui->toolButton_lib->show();
        ui->toolButton_MV->show();
        ui->toolButton_zhibo->show();
        ui->toolButton_huafeng->show();
        falg_geci=true;
        return;
    }
}
