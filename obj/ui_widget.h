/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_start;
    QPushButton *game_running;
    QPushButton *game_quit;
    QLabel *start_photo;
    QWidget *page_movePhoto;
    QLabel *show_move;
    QPushButton *dop_btn;
    QWidget *page_choise;
    QPushButton *ka_num1;
    QLabel *label_1photo;
    QPushButton *pushButton_return_start;
    QLabel *label_2photo;
    QPushButton *ka_num2;
    QPushButton *ka_num3;
    QPushButton *ka_num5;
    QLabel *label_3photo;
    QLabel *label_5photo;
    QLabel *label_6photo;
    QPushButton *ka_num6;
    QLabel *label_7photo;
    QPushButton *ka_num7;
    QPushButton *ka_num4;
    QLabel *label_4photo;
    QLabel *label_8photo;
    QPushButton *ka_num8;
    QLabel *label_choisePhoto;
    QWidget *page_num1;
    QLabel *label_text_time_2;
    QLabel *label_name;
    QPushButton *game_help;
    QLabel *label_num_text_2;
    QPushButton *game_start;
    QPushButton *gam_exit;
    QLabel *label_num;
    QPushButton *pushButton_return_choise;
    QLCDNumber *lcdTime;
    QLabel *labelPlay;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1366, 768);
        Widget->setMinimumSize(QSize(1366, 768));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1366, 768));
        stackedWidget->setMinimumSize(QSize(1366, 768));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        stackedWidget->setFont(font);
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        stackedWidget->setLineWidth(10);
        page_start = new QWidget();
        page_start->setObjectName(QString::fromUtf8("page_start"));
        page_start->setMinimumSize(QSize(1366, 768));
        game_running = new QPushButton(page_start);
        game_running->setObjectName(QString::fromUtf8("game_running"));
        game_running->setGeometry(QRect(450, 610, 161, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        game_running->setFont(font1);
        game_quit = new QPushButton(page_start);
        game_quit->setObjectName(QString::fromUtf8("game_quit"));
        game_quit->setGeometry(QRect(740, 610, 171, 51));
        game_quit->setFont(font1);
        start_photo = new QLabel(page_start);
        start_photo->setObjectName(QString::fromUtf8("start_photo"));
        start_photo->setGeometry(QRect(0, 0, 1366, 768));
        start_photo->setMinimumSize(QSize(1366, 768));
        stackedWidget->addWidget(page_start);
        start_photo->raise();
        game_running->raise();
        game_quit->raise();
        page_movePhoto = new QWidget();
        page_movePhoto->setObjectName(QString::fromUtf8("page_movePhoto"));
        show_move = new QLabel(page_movePhoto);
        show_move->setObjectName(QString::fromUtf8("show_move"));
        show_move->setGeometry(QRect(0, 0, 1366, 768));
        show_move->setMinimumSize(QSize(1366, 768));
        dop_btn = new QPushButton(page_movePhoto);
        dop_btn->setObjectName(QString::fromUtf8("dop_btn"));
        dop_btn->setGeometry(QRect(1170, 650, 75, 23));
        stackedWidget->addWidget(page_movePhoto);
        page_choise = new QWidget();
        page_choise->setObjectName(QString::fromUtf8("page_choise"));
        page_choise->setMinimumSize(QSize(1366, 768));
        ka_num1 = new QPushButton(page_choise);
        ka_num1->setObjectName(QString::fromUtf8("ka_num1"));
        ka_num1->setGeometry(QRect(140, 90, 111, 31));
        label_1photo = new QLabel(page_choise);
        label_1photo->setObjectName(QString::fromUtf8("label_1photo"));
        label_1photo->setGeometry(QRect(70, 150, 261, 141));
        label_1photo->setFrameShape(QFrame::Box);
        pushButton_return_start = new QPushButton(page_choise);
        pushButton_return_start->setObjectName(QString::fromUtf8("pushButton_return_start"));
        pushButton_return_start->setGeometry(QRect(20, 20, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(12);
        pushButton_return_start->setFont(font2);
        label_2photo = new QLabel(page_choise);
        label_2photo->setObjectName(QString::fromUtf8("label_2photo"));
        label_2photo->setGeometry(QRect(380, 150, 261, 141));
        label_2photo->setFrameShape(QFrame::Box);
        ka_num2 = new QPushButton(page_choise);
        ka_num2->setObjectName(QString::fromUtf8("ka_num2"));
        ka_num2->setGeometry(QRect(460, 90, 111, 31));
        ka_num3 = new QPushButton(page_choise);
        ka_num3->setObjectName(QString::fromUtf8("ka_num3"));
        ka_num3->setGeometry(QRect(770, 90, 111, 31));
        ka_num5 = new QPushButton(page_choise);
        ka_num5->setObjectName(QString::fromUtf8("ka_num5"));
        ka_num5->setGeometry(QRect(130, 390, 111, 31));
        label_3photo = new QLabel(page_choise);
        label_3photo->setObjectName(QString::fromUtf8("label_3photo"));
        label_3photo->setGeometry(QRect(690, 150, 261, 141));
        label_3photo->setFrameShape(QFrame::Box);
        label_5photo = new QLabel(page_choise);
        label_5photo->setObjectName(QString::fromUtf8("label_5photo"));
        label_5photo->setGeometry(QRect(70, 450, 261, 141));
        label_5photo->setFrameShape(QFrame::Box);
        label_6photo = new QLabel(page_choise);
        label_6photo->setObjectName(QString::fromUtf8("label_6photo"));
        label_6photo->setGeometry(QRect(370, 450, 261, 141));
        label_6photo->setFrameShape(QFrame::Box);
        ka_num6 = new QPushButton(page_choise);
        ka_num6->setObjectName(QString::fromUtf8("ka_num6"));
        ka_num6->setGeometry(QRect(460, 390, 111, 31));
        label_7photo = new QLabel(page_choise);
        label_7photo->setObjectName(QString::fromUtf8("label_7photo"));
        label_7photo->setGeometry(QRect(690, 450, 261, 141));
        label_7photo->setFrameShape(QFrame::Box);
        ka_num7 = new QPushButton(page_choise);
        ka_num7->setObjectName(QString::fromUtf8("ka_num7"));
        ka_num7->setGeometry(QRect(780, 390, 111, 31));
        ka_num4 = new QPushButton(page_choise);
        ka_num4->setObjectName(QString::fromUtf8("ka_num4"));
        ka_num4->setGeometry(QRect(1070, 90, 111, 31));
        label_4photo = new QLabel(page_choise);
        label_4photo->setObjectName(QString::fromUtf8("label_4photo"));
        label_4photo->setGeometry(QRect(1000, 150, 261, 141));
        label_4photo->setFrameShape(QFrame::Box);
        label_8photo = new QLabel(page_choise);
        label_8photo->setObjectName(QString::fromUtf8("label_8photo"));
        label_8photo->setGeometry(QRect(1000, 450, 261, 141));
        label_8photo->setFrameShape(QFrame::Box);
        ka_num8 = new QPushButton(page_choise);
        ka_num8->setObjectName(QString::fromUtf8("ka_num8"));
        ka_num8->setGeometry(QRect(1080, 390, 111, 31));
        label_choisePhoto = new QLabel(page_choise);
        label_choisePhoto->setObjectName(QString::fromUtf8("label_choisePhoto"));
        label_choisePhoto->setGeometry(QRect(0, 0, 1366, 768));
        label_choisePhoto->setMinimumSize(QSize(1366, 768));
        stackedWidget->addWidget(page_choise);
        label_choisePhoto->raise();
        pushButton_return_start->raise();
        label_2photo->raise();
        ka_num3->raise();
        ka_num5->raise();
        label_3photo->raise();
        label_5photo->raise();
        label_6photo->raise();
        ka_num6->raise();
        label_7photo->raise();
        ka_num7->raise();
        label_1photo->raise();
        ka_num4->raise();
        label_4photo->raise();
        label_8photo->raise();
        ka_num8->raise();
        ka_num1->raise();
        ka_num2->raise();
        page_num1 = new QWidget();
        page_num1->setObjectName(QString::fromUtf8("page_num1"));
        page_num1->setMinimumSize(QSize(1366, 768));
        label_text_time_2 = new QLabel(page_num1);
        label_text_time_2->setObjectName(QString::fromUtf8("label_text_time_2"));
        label_text_time_2->setGeometry(QRect(830, 240, 111, 31));
        label_text_time_2->setFont(font1);
        label_name = new QLabel(page_num1);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(960, 150, 121, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setWeight(50);
        label_name->setFont(font3);
        game_help = new QPushButton(page_num1);
        game_help->setObjectName(QString::fromUtf8("game_help"));
        game_help->setGeometry(QRect(970, 390, 71, 31));
        game_help->setFont(font2);
        label_num_text_2 = new QLabel(page_num1);
        label_num_text_2->setObjectName(QString::fromUtf8("label_num_text_2"));
        label_num_text_2->setGeometry(QRect(1070, 240, 131, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(18);
        label_num_text_2->setFont(font4);
        game_start = new QPushButton(page_num1);
        game_start->setObjectName(QString::fromUtf8("game_start"));
        game_start->setGeometry(QRect(830, 480, 121, 61));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(20);
        game_start->setFont(font5);
        gam_exit = new QPushButton(page_num1);
        gam_exit->setObjectName(QString::fromUtf8("gam_exit"));
        gam_exit->setGeometry(QRect(1060, 480, 131, 61));
        gam_exit->setFont(font5);
        label_num = new QLabel(page_num1);
        label_num->setObjectName(QString::fromUtf8("label_num"));
        label_num->setGeometry(QRect(1070, 300, 91, 41));
        label_num->setFont(font4);
        label_num->setFrameShape(QFrame::Box);
        pushButton_return_choise = new QPushButton(page_num1);
        pushButton_return_choise->setObjectName(QString::fromUtf8("pushButton_return_choise"));
        pushButton_return_choise->setGeometry(QRect(1234, 30, 81, 31));
        lcdTime = new QLCDNumber(page_num1);
        lcdTime->setObjectName(QString::fromUtf8("lcdTime"));
        lcdTime->setGeometry(QRect(830, 300, 91, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        lcdTime->setFont(font6);
        lcdTime->setFrameShape(QFrame::StyledPanel);
        lcdTime->setMode(QLCDNumber::Hex);
        labelPlay = new QLabel(page_num1);
        labelPlay->setObjectName(QString::fromUtf8("labelPlay"));
        labelPlay->setGeometry(QRect(0, -10, 1366, 768));
        labelPlay->setMinimumSize(QSize(1366, 768));
        stackedWidget->addWidget(page_num1);
        labelPlay->raise();
        label_text_time_2->raise();
        label_name->raise();
        game_help->raise();
        label_num_text_2->raise();
        game_start->raise();
        gam_exit->raise();
        label_num->raise();
        pushButton_return_choise->raise();
        lcdTime->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        game_running->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        game_quit->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        start_photo->setText(QString());
        show_move->setText(QString());
        dop_btn->setText(QCoreApplication::translate("Widget", "\350\267\263\350\277\207", nullptr));
        ka_num1->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\200\345\205\263", nullptr));
        label_1photo->setText(QString());
        pushButton_return_start->setText(QCoreApplication::translate("Widget", "\350\277\224\345\233\236", nullptr));
        label_2photo->setText(QString());
        ka_num2->setText(QCoreApplication::translate("Widget", "\347\254\254\344\272\214\345\205\263", nullptr));
        ka_num3->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\211\345\205\263", nullptr));
        ka_num5->setText(QCoreApplication::translate("Widget", "\347\254\254\344\272\224\345\205\263", nullptr));
        label_3photo->setText(QString());
        label_5photo->setText(QString());
        label_6photo->setText(QString());
        ka_num6->setText(QCoreApplication::translate("Widget", "\347\254\254\345\205\255\345\205\263", nullptr));
        label_7photo->setText(QString());
        ka_num7->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\203\345\205\263", nullptr));
        ka_num4->setText(QCoreApplication::translate("Widget", "\347\254\254\345\233\233\345\205\263", nullptr));
        label_4photo->setText(QString());
        label_8photo->setText(QString());
        ka_num8->setText(QCoreApplication::translate("Widget", "\347\254\254\345\205\253\345\205\263", nullptr));
        label_choisePhoto->setText(QString());
        label_text_time_2->setText(QCoreApplication::translate("Widget", "\346\270\270\346\210\217\346\227\266\351\227\264", nullptr));
        label_name->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\200\345\205\263", nullptr));
        game_help->setText(QCoreApplication::translate("Widget", "\345\270\256\345\212\251", nullptr));
        label_num_text_2->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\346\254\241\346\225\260", nullptr));
        game_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        gam_exit->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        label_num->setText(QString());
        pushButton_return_choise->setText(QCoreApplication::translate("Widget", "\350\277\224\345\233\236", nullptr));
        labelPlay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
