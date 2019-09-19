#ifndef FUN_H
#define FUN_H
#include "widget.h"

class Fun
{
public:
    Fun();
};

typedef struct lrc
{
    int time;
    char lrc[256];
    struct lrc *next;
}LRC;

extern int lrc_cut(char *data, char *buf[]);
extern LRC *insert_link(LRC *head, LRC tmp);
extern LRC *lrc_analysis(LRC *head1, char *lrc[], int row);
extern void write_lrc(LRC *head, Ui::Widget *ui);

#endif // FUN_H
