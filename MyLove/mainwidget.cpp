#include "mainwidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        m_MainWidgetImage.load(":/image/mainPic.png");
         connect(ui->ExitBtn, SIGNAL(clicked()), this, SLOT(OnExitBtn()));

        //托盘功能
        m_systray.setToolTip(QStringLiteral("七夕节快乐"));
        m_systray.setIcon(QIcon(":/image/LoveToolTip.png"));

        //设置托盘菜单
        QMenu *menu_systray = new QMenu();
        menu_systray->addAction(ui->actionShow);
        menu_systray->addSeparator();
        menu_systray->addAction(ui->actionExit);

        //设立为托盘菜单
        m_systray.setContextMenu(menu_systray);

        connect(&m_systray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(OnSystemTrayClicked(QSystemTrayIcon::ActivationReason)));
        m_systray.show();
        connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(OnExitWindows()));
        connect(ui->actionShow, SIGNAL(triggered()), this, SLOT(OnShowActive()));

        //gif动态标签（七夕快乐）
        QMovie *QiXiHappyMovie = new QMovie(":/image/QiXiHappy.gif");
        ui->QiXiHappylabel->setMovie(QiXiHappyMovie);
        QiXiHappyMovie->start();

        //播放音乐
        SoundShow("Music/Music_QiXi.wav",true);

        //gif头像文件
        QMovie *HeadMovie=new QMovie(":/image/main_head.gif");
        ui->HeadLabel->setMovie(HeadMovie);
        HeadMovie->start();

        connect(ui->clickBtn,SIGNAL(clicked(bool)),this,SLOT(OnClickHere()));

        //


}

//“点这里”函数实现
void mainWidget::OnClickHere()
{
    rose=new Rose();
    rose->show();
    this->hide();


}


//退出程序
int mainWidget::OnExitWindows()
{
    QApplication::exit();
    return 0;
}

void mainWidget::closeEvent(QCloseEvent *event)
{
   this->hide();
    event->ignore();
}

void mainWidget::SoundShow(const string filepath,bool loop)
{
    QSound *music=new QSound(filepath.c_str(),this);
    music->play();
    if(loop)
        music->setLoops(400);
}

mainWidget::~mainWidget()
{
    delete ui;
}
void mainWidget::OnExitBtn()
{
    this->hide();

}
void mainWidget::OnShowActive()
{
    this->show();
}

int mainWidget::OnSystemTrayClicked(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::DoubleClick)
        this->showNormal();
    return 0;
}

void mainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect fameRect = rect();
    painter.drawPixmap(fameRect, m_MainWidgetImage);
}

void mainWidget::mousePressEvent(QMouseEvent *event)
{
    //响应左键
    if (event->button() == Qt::LeftButton)
    {
        m_dragging = true;
        m_startPosition = event->globalPos();
        m_framePosition = frameGeometry().topLeft();
    }
    QWidget::mousePressEvent(event);
}
void mainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons()&Qt::LeftButton)
    {
        if (m_dragging)
        {
            //delta 相对偏移量
            QPoint delta = event->globalPos() - m_startPosition;
            //新位置：窗体原始位置+偏移量
            move(m_framePosition + delta);
        }
    }
    QWidget::mouseMoveEvent(event);
}

void mainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_dragging = false;
    QWidget::mouseReleaseEvent(event);
}

