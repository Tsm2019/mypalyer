#include "geci.h"
#include "ui_geci.h"
#include "widget.h"

using namespace std;
void *deal_lrc(void *arg);
extern map<int,QString> m_lrc;
extern map<int,QString> songName;
extern vector<int> v_lrc_time;
QString lrc_buf[7] = {};
int key = 0;


Geci::Geci(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Geci)
{
    ui->setupUi(this);

    //创建一个线程写歌词
    pthread_t falg_lrc1;
    pthread_create(&falg_lrc1,NULL,deal_lrc,(void *)ui);
    pthread_detach(falg_lrc1);

}

Geci::~Geci()
{
    delete ui;
}


void *deal_lrc(void *arg)
{
    Ui::Geci* my_ui = (Ui::Geci*)arg;

    while(Widget::falg_over)
    {
        usleep(100*1000);
        my_ui->pushButton->setText(Widget::file_name);
        if(!m_lrc.empty() && !v_lrc_time.empty())
        {
            for_each(m_lrc.begin(),m_lrc.end(),[=](pair<int,QString> val){
                if(Widget::nowtime == val.first)
                {
                    lrc_buf[3] =val.second;
                    key = val.first;
                }
            });
            for(vector<int>::iterator it=v_lrc_time.begin(); it != v_lrc_time.end(); it++)
            {
                vector<int>::iterator lrc1=it;
                //对迭代器取*就是容器的内容
                if(key == *it && (it-1)!= v_lrc_time.begin() && (it+1)!= v_lrc_time.end() && it!= v_lrc_time.begin())
                {
                    int i = 4;
                    for(lrc1=it+1;lrc1!=v_lrc_time.end();lrc1++,i++)
                    {
                        if(i == 7)
                        {
                            break;
                        }
                        lrc_buf[i] = m_lrc.at(*lrc1).toUtf8().data();
                    }
                    i = 2;
                    for(lrc1 = it-1;lrc1!=v_lrc_time.begin();lrc1--,i--)
                    {
                        if(i < 0)
                            break;
                        lrc_buf[i] = m_lrc.at(*lrc1).toUtf8().data();
                    }
                }
                my_ui->pushButton_0->setText(" ");
                my_ui->pushButton_1->setText(" ");
                my_ui->pushButton_2->setText(" ");
                my_ui->pushButton_3->setText(" ");
                my_ui->pushButton_4->setText(" ");
                my_ui->pushButton_5->setText(" ");
                my_ui->pushButton_6->setText(" ");
            }
            my_ui->pushButton_0->setText(lrc_buf[0]);
            my_ui->pushButton_1->setText(lrc_buf[1]);
            my_ui->pushButton_2->setText(lrc_buf[2]);
            my_ui->pushButton_3->setText(lrc_buf[3]);
            my_ui->pushButton_4->setText(lrc_buf[4]);
            my_ui->pushButton_5->setText(lrc_buf[5]);
            my_ui->pushButton_6->setText(lrc_buf[6]);
        }
    }
}
