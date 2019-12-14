#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QTime>
#include <QMediaPlayer>
#include <QMessageBox>  //程序退出提示窗口
#include <time.h> //随机数的产生
#include <QImage>

static XY arr[Numbers] = {{150,150},{300,150}, {450,150}, {150,300}, {300,300},
               {450, 300},{150, 450},{300,450},{450,450} };


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
        ui->setupUi(this);
        mythread = new myThread(this);  //线程 申请空间


        connect(mythread,SIGNAL(threadDone()),this,SLOT(waitThreadSlot())); //线程结束时


       //设置窗口标题
       setWindowTitle("王者大拼图");
       this->setWindowIcon(QIcon(":/photo/pr2/head.png"));  //窗口的图标

       //设置窗口大小
       this->setMinimumSize(1366,750);
       this->setMaximumSize(1366,750);
       move(0,0);

       //游戏开始按键贴图

       //游戏退出 按键贴图

       //初始化进入页面
       ui->stackedWidget->setCurrentWidget(ui->page_start);



       /*=====================图片美化==================*/

       //打开程序的游戏背景图片 gift
       movie1.setFileName(":/photo/pr2/start.jpg");
       ui->start_photo->setScaledContents(true); //让图片自己适应显示框大小
       ui->start_photo->setMovie(&movie1);
       //动图播放
       movie1.start();


        //进入游戏 介绍 添加动画
        movie2.setFileName(":/photo/pr2/beijing2.jpg");
        ui->show_move->setScaledContents(true); //让图片自己适应显示框大小
        ui->show_move->setMovie(&movie2);


       //初始化 选择关卡 背景
       pix.load(":/photo/pr2/beijinn1.jpg");
       ui->label_choisePhoto->setScaledContents(true); //让图片自己适应显示框大小
       ui->label_choisePhoto->setPixmap(pix);

       //玩游戏壁纸显示
        setAutoFillBackground(true);
        QPalette pal = this->palette();
        pal.setBrush(backgroundRole(), QPixmap(":/photo/pr2/play1.jpg"));
        setPalette(pal);


        //游戏关卡图片
        pix.load(":/photo/pr3/1.jpg");
        ui->label_1photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_1photo->setPixmap(pix);

        pix.load(":/photo/pr3/10.jpg");
        ui->label_2photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_2photo->setPixmap(pix);

        pix.load(":/photo/pr3/11.jpg");
        ui->label_3photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_3photo->setPixmap(pix);

        pix.load(":/photo/pr3/12.jpg");
        ui->label_4photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_4photo->setPixmap(pix);

        pix.load(":/photo/pr3/2.jpg");
        ui->label_5photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_5photo->setPixmap(pix);

        pix.load(":/photo/pr3/5.jpg");
        ui->label_6photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_6photo->setPixmap(pix);

        pix.load(":/photo/pr3/6.jpg");
        ui->label_7photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_7photo->setPixmap(pix);

        pix.load(":/photo/pr3/7.jpg");
        ui->label_8photo->setScaledContents(true); //让图片自己适应显示框大小
        ui->label_8photo->setPixmap(pix);



        /*=================开始游戏 计时器 鼠标点击=============*/

       // 初始化  click鼠标的点击次数
       clickNum = 0;

       //开始游戏 计时
       connect(&timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));

       //对ledNumber 初始化
       //设置lcdNumber 能够显示8个字符
       ui->lcdTime->setDigitCount(8);
       //默认显示的是“00：00：00”时间格式
       QTime time(0 , 0, 0);
       ui->lcdTime->display(time.toString("hh:mm:ss"));
       ui->lcdTime->setSegmentStyle(QLCDNumber::Flat);  //时间颜色
       Ntime = 0;


       /*================游戏音效========================*/

       //进入游戏 背景音乐播放
       player  = new QMediaPlayer(this);
       player->setMedia(QUrl::fromLocalFile ("../music/1.mp3"));
       player->setVolume(50); //音量
       player->play();



        //进入关卡1 声音
        gamePlayer1  = new QMediaPlayer(this);
        gamePlayer1->setMedia(QUrl::fromLocalFile ("../music/ka1.mp3"));
        gamePlayer1->setVolume(100); //音量

        //进入 关卡2 音乐
        gamePlayer2  = new QMediaPlayer(this);
        gamePlayer2->setMedia(QUrl::fromLocalFile ("../music/level.mp3"));
        gamePlayer2->setVolume(100); //音量

        //游戏成功的声音
        successPlayer  = new QMediaPlayer(this);
        successPlayer->setMedia(QUrl::fromLocalFile ("../music/gameSuccess.mp3"));
        successPlayer->setVolume(100); //音量

         //移动滑块的声音
        movePlayer  = new QMediaPlayer(this);
        movePlayer->setMedia(QUrl::fromLocalFile ("../music/movePlay.mp3"));
        movePlayer->setVolume(80); //音量

        //开始游戏的声音
        startPlayer  = new QMediaPlayer(this);
        startPlayer->setMedia(QUrl::fromLocalFile ("../music/movePlay.mp3"));
        startPlayer->setVolume(80); //音量



       /*===================游戏图片顺序的初始化==============*/

        // 初始化 set_num
       int j = 0;
       for (j = 0; j < 9; j++)
       {
           set_num[j] = j;
       }

       //初始化 不显示整张图
        flag = false;
        top = false;


}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *)
{
    //创建一个画家
    QPainter p(this);
    //创建画笔
    QPen pen;
    pen.setWidth(1);  //笔粗
    pen.setColor(Qt::green); //笔的颜色
    p.setPen(pen); //将画笔交给画家

    //建立9 宫格
    int x1 = 150;
    int y1 = 150;
    int x2 = 150;
    int y2 = 600;
    for (int i =0; i <4; i++)
    {
        //画竖线
        p.drawLine(x1,y1,x2,y2);
        //画横线
        p.drawLine(y1,x1,y2,x2);

        x1 += 150;
        x2 = x1;

    }

    //初始化图片
    QPixmap image1(":/photo/pr1/1.jpg");
    QPixmap image2(":/photo/pr1/2.jpg");
    QPixmap image3(":/photo/pr1/3.jpg");
    QPixmap image4(":/photo/pr1/4.jpg");
    QPixmap image5(":/photo/pr1/5.jpg");
    QPixmap image6(":/photo/pr1/6.jpg");
    QPixmap image7(":/photo/pr1/7.jpg");
    QPixmap image8(":/photo/pr1/8.jpg");
    QPixmap image9(":/photo/pr1/9.jpg");
    QPixmap image10(":/photo/pr1/1-9.jpg"); //完整照片

    //显示图片

    p.drawPixmap(QPoint(arr[set_num[0]].x,arr[set_num[0]].  y),image1);
    p.drawPixmap(QPoint(arr[set_num[1]].x,arr[set_num[1]].  y),image2);
    p.drawPixmap(QPoint(arr[set_num[2]].x,arr[set_num[2]].  y),image3);
    p.drawPixmap(QPoint(arr[set_num[3]].x,arr[set_num[3]].  y),image4);
    p.drawPixmap(QPoint(arr[set_num[4]].x,arr[set_num[4]].  y),image5);
    p.drawPixmap(QPoint(arr[set_num[5]].x,arr[set_num[5]].  y),image6);
    p.drawPixmap(QPoint(arr[set_num[6]].x,arr[set_num[6]].  y),image7);
    p.drawPixmap(QPoint(arr[set_num[7]].x,arr[set_num[7]].  y),image8);
    p.drawPixmap(QPoint(arr[set_num[8]].x,arr[set_num[8]].  y),image9);

    //帮助 显示整张图
    if ( flag == true)
    {
        p.drawPixmap(QPoint(arr[0].x,arr[0].  y),image10);

    }
}

//鼠标点击玩游戏
void Widget::mousePressEvent(QMouseEvent *event)
{

     getx = event->x() ;
     gety = event->y();

     //点击鼠标左键
     int i = 0;
     //记录下没有图片位置的下标
     int nullity = 0;


     //求出空白图片的 位置
     for ( i = 0; i < 9; i++)
     {
            if (set_num[i] == 8)
            {
                nullity = i;
            }
             qDebug()<<set_num[i];
      }
     qDebug()<<"空白图片 ";
     qDebug()<<nullity;


      if(Qt::LeftButton == event->button())
      {
           //点击选框
          for ( int tmp = 0; tmp < 9; tmp++)
          {

              if ( (getx-(getx % 150)) ==arr[tmp].x && (gety-(gety % 150)) == arr[tmp].y )
              {
                       //交换空白位置的照片和所点击的位置

                       //图片交换
                       qDebug()<<"tmp = ";
                       qDebug()<<tmp;

                         qDebug()<<"set_num[tmp] = ";
                         qDebug()<<set_num[tmp];
                         set_num[nullity] =  set_num[tmp] ;
                         set_num[tmp] = 8;
                        qDebug()<<set_num[tmp];
                         update();


                       //鼠标点击次数显示
                       clickNum++;
                       char str[4] = {0};
                       sprintf(str,"%d",clickNum);
                       ui->label_num->setText(QString(str));

                       //点击音效
                       movePlayer->play();

                       //游戏成功的判断
                       int su = 0;
                       for (su = 0; su < 9; su++)
                       {
                           //失败退出继续点击
                           if (set_num[su] != su)
                           {
                               return;
                           }
                       }
                       //成功 播放成功音乐
                       successPlayer->play();
                       //显示完整照片
                       flag = true;
                       //计时停止
                       timer.stop();


                 }
              }
         }

}


//游戏时间的显示
//开始计时
void Widget:: timeoutSlot()
{
    //更新ledNumber 上的值
    Ntime++;
    QTime time(0, 0, 0);
    QTime tmp = time.addSecs(Ntime);
    ui->lcdTime->display(tmp.toString("hh:mm:ss"));

}



//点击开始 打乱图片的顺序
void Widget::on_game_start_clicked()
{

    //产生随机数 打乱图片排序
    srand( (unsigned int)  time( NULL));
    int len = 8;
    //随机下标
    int post = 0;
    int  num[8] ={0};
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        num[i] = i;

    }

    for (int j = 0; j < 9; j++)
    {
        //单独处理 白块
        if ( j == 8)
        {
            set_num[j] = 8;
            break;
        }
        post = rand() % len;
        set_num[j] = num[post];
        //不重复 将数组后面的元素向前移动
        for (int k = post; k < len; k++)
        {
            num[k] = num[k +1];
        }
        len--;
    }

    //完整图片不显示
    flag = false;


    if("开始" == ui->game_start->text())
    {
        //设置 帮助 为不可点击
        ui->game_help->setEnabled(true);
        ui->game_start->setText("重新开始");
    }
    else
    {
        //不可点击
        ui->game_help->setEnabled(false);
        //先给记录鼠标点击次数的 清零
        clickNum = 0;
        char str[4] = {0};
        sprintf(str,"%d",clickNum);
        ui->label_num->setText(QString(str));

        //时间清零
        Ntime = 0;
        QTime time(0, 0, 0);
        ui->lcdTime->display(time.toString("hh:mm:ss"));

        ui->game_start->setText("开始");
    }

    //开始计时
    timer.start(1000);  //单位毫秒
    //更新
    update();
}


//帮助 显示完整图片
void Widget::on_game_help_clicked()
{
    if("帮助" == ui->game_help->text())
   {
       flag = true;
       timer.stop();
       ui->game_help->setText("继续游戏");
   }
   else
   {
      flag = false;
       timer.start(1000);  //单位毫秒
       ui->game_help->setText("帮助");
   }
    //更新
    update();
}




/*===============游戏菜单切换=======================*/

//点击开始游戏 进入到 游戏介绍  然后进入选择关卡
void Delay_MSec(int msec)
{

    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot( msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

//点击进入后的一段介绍
void Widget::on_game_running_clicked()
{
     //关闭 音乐 player
     player->stop();

     //启动线程
     mythread->start();

     ui->stackedWidget->setCurrentWidget(ui->page_movePhoto);
     //动图播放
     movie2.start();

     //延时
    Delay_MSec(10000); //毫秒

    //时间到了 进入到 选择关卡
    if ( top == false)
    {
         //动图停止
         movie2.stop();
         ui->stackedWidget->setCurrentWidget(ui->page_choise);
    }
}


//跳过动图显示
void Widget::on_dop_btn_clicked()
{
     //动图停止
     movie2.stop();
     ui->stackedWidget->setCurrentWidget(ui->page_choise);
     top = true;
}


//从选择关卡 返回主菜单
void Widget::on_pushButton_return_start_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_start);
}


// 进入 第一关
void Widget::on_ka_num1_clicked()
{
    //点击音乐
    gamePlayer1->play();

    //先给记录鼠标点击次数的 清零
    clickNum = 0;
    char str[4] = {0};
    sprintf(str,"%d",clickNum);
    ui->label_num->setText(QString(str));

    //时间清零
    Ntime = 0;
    QTime time(0, 0, 0);
    ui->lcdTime->display(time.toString("hh:mm:ss"));

    //拼图 图片完整显示
    flag = true;

    //帮助 不可点击
    ui->game_help->setEnabled(false);

    //切换页面
     ui->stackedWidget->setCurrentWidget(ui->page_num1);
}

//退出游戏
void Widget::on_gam_exit_clicked()
{
    on_game_quit_clicked();
}

//返回选择关卡
void Widget::on_pushButton_return_choise_clicked()
{
     //计时器时间停止
     timer.stop();
     //初始化 set_num
       int j = 0;

       for (j = 0; j < 9; j++)
       {
           set_num[j] = j;
       }
       //不显示成功后的图
       flag = false;

       ui->stackedWidget->setCurrentWidget(ui->page_choise);
}


//退出 程序
void Widget::on_game_quit_clicked()
{
    if ( !(QMessageBox::information(this,tr("退出游戏"),tr("你确定要退出游戏吗?"),tr("是"),tr("否"))))
    {

        waitThreadSlot();
        QApplication* app = nullptr ;
        app->exit(0);
    }
}

//线程退出执行函数
void Widget::waitThreadSlot()
{
    //子线程退出
    mythread->exit();
     //回收子线程
     mythread->wait();

}

//进入关卡2
void Widget::on_ka_num2_clicked()
{
    //点击音乐
    gamePlayer2->play();

    //先给记录鼠标点击次数的 清零
    clickNum = 0;
    char str[4] = {0};
    sprintf(str,"%d",clickNum);
    ui->label_num->setText(QString(str));

    //时间清零
    Ntime = 0;
    QTime time(0, 0, 0);
    ui->lcdTime->display(time.toString("hh:mm:ss"));
}
