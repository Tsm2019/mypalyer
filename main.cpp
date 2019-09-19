#include "widget.h"
#include <QApplication>

struct MyFd
{
    int fifo_fd;
    int fd[2];
}My_fd;
int main(int argc, char *argv[])
{

    //创建一个无名管道 获取mplayer回应
    pipe(My_fd.fd);

    pid_t pid = fork();

    if(pid == 0)//子进程
    {
        //创建一个管道
        mkfifo("fifo_cmd",0666);
        //将1设备重定向到fd[1]
        dup2(My_fd.fd[1],1);

        //使用execlp启动mplayer
        execlp("mplayer","mplayer","-idle","-slave","-quiet","-input","file=./fifo_cmd", "02.mp3",NULL);

    }
    else//父进程
    {
        //创建一个管道
        mkfifo("fifo_cmd",0666);
        My_fd.fifo_fd = open("fifo_cmd",O_WRONLY);
        write(My_fd.fifo_fd, "volume 50 1\n", strlen("volume 50 1\n"));
        usleep(100*1000);
        write(My_fd.fifo_fd, "pause\n", strlen("pause\n"));

        QApplication a(argc, argv);
        Widget w;
        w.show();

        return a.exec();
    }
    return 0;
}
