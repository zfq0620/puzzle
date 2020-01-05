#include "mythread.h"

myThread::myThread(QWidget *parent) : QThread (parent)
{

}

void myThread:: run()
{

        //进入选择关卡的背景音乐
        choisePlayer  = new QMediaPlayer(this);
        choisePlayer->setMedia(QUrl::fromLocalFile ("../music/m_choise.mp3"));
        choisePlayer->setVolume(60); //音量
        choisePlayer->play();


    //发信号告诉主线程子线程结束了
     emit threadDone();
}
