#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QThread>
#include <QMediaPlayer> //音乐

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QWidget *parent = nullptr);

signals:
    void threadDone();
protected:
    void run();

public slots:

private:
      QMediaPlayer *choisePlayer;  //选择关卡背景音乐
};

#endif // MYTHREAD_H
