#include "fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>



Fun::Fun()
{

}
#if 0
int free_link(LRC **head)//链表的释放
{
    LRC *move = *head;
    while(move)
    {
        *head = move->next;
        free(move);
        move = *head;
    }
    *head = NULL;
    return 0;
}
#endif


int lrc_cut(char *data, char *buf[])
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

LRC *insert_link(LRC *head, LRC tmp)
{
    LRC *pi = (LRC *)calloc(1, sizeof(LRC));
    *pi = tmp;
    pi->next = NULL;
    if (head == NULL)
    {
        head = pi;
        return head;
    }
    else
    {
        LRC *pf = head, *pb = head;
        while ((pb->time < pi->time) && (pb->next != NULL))
        {
            pf = pb;
            pb = pb->next;
        }
        if (pb->time >= pi->time) //前 中部 插入
        {
            if (pb == head)
            {
                pi->next = head;
                head = pi;
            }
            else
            {
                pf->next = pi;
                pi->next = pb;
            }
        }
        else if (pb->next == NULL) //尾部插入
        {
            pb->next = pi;
        }
    }
    return head;
}

LRC *lrc_analysis(LRC *head1, char *lrc[], int row)
{
    int i = 0;
    for (i = 3; i >= 0; i--)
    {
        char *p = lrc[i];
        LRC tm;
        tm.time = 0;
        strcpy(tm.lrc, p);
        head1 = insert_link(head1, tm);
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
            LRC tmp;
            tmp.time = m * 60 + s;
            strcpy(tmp.lrc, p_lrc);
            head1 = insert_link(head1, tmp);
            ps += 10;
        }
    }
    return head1;
}

void write_lrc(LRC *head, Ui::Widget* ui)
{
    LRC *pb = head;
    int i = 0;
    if(pb->lrc == NULL)
    {
        ui->label_4->setText("no lrc");
        return;
    }
    for (i = 0; i <4; i++)
    {
        printf("%s\n", pb->lrc);
        pb = pb->next;
    }
    while (1)
    {
        if (nowtime == pb->time)
        {
            //当前歌词
            printf("  %s\n", pb->lrc);
            pb = pb->next;
            if (pb == NULL)
            {
                printf("\n");
                break;
            }
            //下一行歌词预读
            printf("  %s\n", pb->lrc);
            fflush(stdout);
        }
    }
 }
