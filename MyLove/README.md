# ValentineDay Qt实现全屏下玫瑰花(含详细注释)
功能：

1. 识别屏幕分辨率

2. 托盘程序

3.随机下玫瑰花


程序源码及素材下载：
https://github.com/wenht817/MyLove.git

 

IDE Qt Creator

先上图：
![start](https://github.com/wenht817/MyLove/raw/master/Screenshots/start.png)
![underway](https://github.com/wenht817/MyLove/raw/master/Screenshots/underway.png)

部分代码展示：

# GBK.h
<span style="font-family:SimSun;font-size:18px;">
#ifndef _QT_GBK_H
#define _QT_GBK_H


#include <QString>
#include <QTextCodec>
#include <string>
using std::string;

class GBK
{
public:
	// QString(Unicode) -> std::string (GBK)
	static string FromUnicode(const QString& qstr)
	{
		QTextCodec* pCodec = QTextCodec::codecForName("gb2312");
		if(!pCodec) return "";	

		QByteArray arr = pCodec->fromUnicode(qstr);
		string cstr = arr.data();
		return cstr;
	}

	// std::string (GBK) -> QString(Unicode)
	static QString ToUnicode(const string& cstr)
	{
		QTextCodec* pCodec = QTextCodec::codecForName("gb2312");
		if(!pCodec) return "";

		QString qstr = pCodec->toUnicode(cstr.c_str(), cstr.length());
		return qstr;
	}

};


#endif
</span>

# mainwidget.h

<span style="font-family:SimSun;font-size:18px;">
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QSystemTrayIcon>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include <QMenu>
#include <QIcon>
#include <QMovie>
#include <QSound>

#include "GBK.h"
#include "rose.h"


namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void OnExitBtn();	//隐藏程序，调用托盘
    void OnShowActive();	//托盘显示程序
    void SoundShow(const string filepath,bool loop);
    int OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason);
    int OnExitWindows();
    void OnClickHere(); // “点这里”相关处理



private:
    Ui::mainWidget *ui;

    void closeEvent(QCloseEvent *event);    //重写close按钮
    virtual void paintEvent(QPaintEvent *event);

    QPixmap m_MainWidgetImage;
    bool m_dragging;	//是否正在拖动
    QPoint m_startPosition; //拖动开始前的鼠标位置
    QPoint m_framePosition;	//窗体的原始位置

    QSystemTrayIcon m_systray;	//托盘图标

    Rose *rose;


};

#endif // MAINWIDGET_H<
/span>

# rose.h
<span style="font-family:SimSun;font-size:18px;">
#ifndef ROSE_H
#define ROSE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QApplication>
#include <QDesktopWidget>
#include <QTimerEvent>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <QCloseEvent>


class Rose : public QWidget
{
    Q_OBJECT
public:
    explicit Rose(QWidget *parent = 0);
    void GetScreenInfo();   //获得屏幕分辨率
    void closeEvent(QCloseEvent *event);

    int Screen_x;   //屏幕x轴
    int Screen_y;   //屏幕y轴

signals:

public slots:

protected:
    void timerEvent(QTimerEvent *event);

private:
    virtual void paintEvent(QPaintEvent *event);

    QLabel *rose_1[20];
    QLabel *rose_2[5];
    QLabel *rose_3[5];
    QLabel *rose_4[5];
    QLabel *rose_5[5];

    int rand_x_rose_1[20][2];    //rose1 20个的玫瑰花坐标  第二个为玫瑰的速度
    int rand_x_rose_2[5][2];    //rose2 5个的玫瑰花坐标  第二个为玫瑰的速度
    int rand_x_rose_3[5][2];     //rose3 5个的玫瑰花坐标  第二个为玫瑰的速度
    int rand_x_rose_4[5][2];    //rose4 5个的玫瑰花坐标  第二个为玫瑰的速度
    int rand_x_rose_5[5][2];    //rose4 5个的玫瑰花坐标  第二个为玫瑰的速度


    int crood_y_rose_1[20];       //rose_1 的y坐标
    int crood_y_rose_2[5];      //rose_2 的y坐标
    int crood_y_rose_3[5];      //rose_3 的y坐标
    int crood_y_rose_4[5];      //rose_4 的y坐标
    int crood_y_rose_5[5];      //rose_5 的y坐标


    int RoseSpeed_Kind[10];      //玫瑰的10种不同的速度


};

#endif // ROSE_H
</span>
