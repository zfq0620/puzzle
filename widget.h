#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include "mythread.h"

#include <QMouseEvent>
#include <QPixmap>
#include <QMovie>
#include <QTimer>
#include <QMediaPlayer> //音乐
#include <QHBoxLayout>  //水平布局类

typedef struct xy
{
    int x;
    int y;
}XY;

#define Numbers 9

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//延时 动画显示 多线程
void Delay_MSec(int msec);

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private slots:
    void on_game_start_clicked(); //点击开始 打乱顺序
    //菜单切换
    void on_game_help_clicked();
    void on_game_running_clicked();
    void on_pushButton_return_start_clicked();
    void on_ka_num1_clicked();  //进入关卡1
    void on_ka_num2_clicked();
    void on_pushButton_return_choise_clicked();
    void timeoutSlot(); //游戏时间计算
    void on_dop_btn_clicked();

    void waitThreadSlot(); //线程退出执行函数
    void on_game_quit_clicked(); //程序退出
    void on_gam_exit_clicked();


private:
    Ui::Widget *ui;
    myThread *mythread;  //线程

    int getx;  //鼠标得到的坐标
    int gety;
    int set_num[Numbers]; //保存要显示图片的数组
    bool flag;  //拼图完整图片的显示
    bool top;  //延时后的选择

    QPixmap pix; //静图
    QMovie movie1; //动图登录游戏
    QMovie movie2; //进入游戏

    QTimer timer;  //计时器
    int  Ntime;
    int clickNum; //鼠标的点击次数

    QMediaPlayer *player;  //背景音乐


    QMediaPlayer *gamePlayer1; //进入关卡1音乐
    QMediaPlayer *gamePlayer2; //进入 关卡2 音乐

    QMediaPlayer *successPlayer;  //游戏成功的声音
    QMediaPlayer *movePlayer;  //移动滑块的声音
    QMediaPlayer *startPlayer;  //开始游戏声音

};

#endif // WIDGET_H
