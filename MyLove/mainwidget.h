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

#endif // MAINWIDGET_H
