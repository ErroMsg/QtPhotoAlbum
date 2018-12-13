#include "pamainwidget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Gui/patitlebar.h"
#include "Gui/paalbumlistwidget.h"
#include "Gui/papictureviewwidget.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#define LAYOUTMARGIN 10

PAMainWidget::PAMainWidget(QWidget *parent) :
    QMainWindow(parent),
    m_canMoveWindow(false),
    m_canStretchWindow(false),
    m_stretchSide(StretchSide::None),
    m_pTitleBar(nullptr),
    m_pAlbumList(nullptr),
    m_pPictureView(nullptr)
{

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    resize(800,600);
    this->setMouseTracking(true);
    initUi();
    initFrameShaodowEffect();


}

PAMainWidget::~PAMainWidget()
{
}

void PAMainWidget::initUi()
{
    QWidget *w = new QWidget();

    m_pTitleBar = new PATitleBar();
    m_pTitleBar->setMouseTracking(true);
    m_pPictureView = new PAPictureViewWidget();
    m_pPictureView->setMouseTracking(true);
    m_pAlbumList = new PAAlbumListWidget();
    m_pAlbumList->setMouseTracking(true);

    QHBoxLayout *hly = new QHBoxLayout;
    hly->setSpacing(0);
    hly->setMargin(0);

    hly->addWidget(m_pAlbumList);
    hly->addWidget(m_pPictureView);

    QVBoxLayout *vly = new QVBoxLayout;
    vly->setSpacing(0);
    vly->setMargin(5);
    vly->addWidget(m_pTitleBar);
    vly->addLayout(hly);

    w->setLayout(vly);
    w->setMouseTracking(true);
    setCentralWidget(w);

}

void PAMainWidget::initFrameShaodowEffect()
{
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(Qt::black);
    shadowEffect->setBlurRadius(10);
    this->setGraphicsEffect(shadowEffect);
}

void PAMainWidget::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

void PAMainWidget::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
}

void PAMainWidget::mousePressEvent(QMouseEvent *event)
{
    m_mousePos = event->pos();
    if(event->buttons() == Qt::LeftButton)
    {
        //Judge the widget drag area(int titlebar);
        if(m_mousePos.x() < this->width()-LAYOUTMARGIN &&
                m_mousePos.x() >LAYOUTMARGIN &&
                m_mousePos.y() < m_pTitleBar->height() &&
                m_mousePos.y() > LAYOUTMARGIN)
        {
            m_canMoveWindow = true;
            QApplication::setOverrideCursor(QCursor(Qt::ClosedHandCursor));
        }
        else
        {
            //Judge the mouse's stretch side
            m_canStretchWindow = true;
            if((m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN) &&
                    (m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0))
            {
                m_stretchSide = StretchSide::TopRight;
            }
            else if((m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN) &&
                    (m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN))
            {
                m_stretchSide = StretchSide::BottomRight;
            }
            else if((m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0) &&
                    (m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0))
            {
                m_stretchSide = StretchSide::TopLeft;
            }
            else if((m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0) &&
                    (m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN))
            {
                m_stretchSide = StretchSide::BottomLeft;
            }
            else if(m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN)
            {
                m_stretchSide = StretchSide::Right;
            }
            else if(m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0)
            {
                m_stretchSide = StretchSide::Left;
            }
            else if(m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN)
            {
                m_stretchSide = StretchSide::Bottom;
            }
            else if(m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0)
            {
                m_stretchSide = StretchSide::Top;
            }
            else
            {
                m_stretchSide = StretchSide::None;
            }
        }
        event->accept();
    }
    else
    {
        QMainWindow::mousePressEvent(event);
    }
}

void PAMainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(!m_canStretchWindow && !m_canMoveWindow)
    {

        m_mousePos = event->pos();
        if((m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN)
                && (m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0))
        {
            m_stretchSide = StretchSide::TopRight;
        }
        else if((m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN)
                && (m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN))
        {
            m_stretchSide = StretchSide::BottomRight;
        }
        else if((m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0)
                && (m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0))
        {
            m_stretchSide = StretchSide::TopLeft;
        }
        else if((m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0)
                && (m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN))
        {
            m_stretchSide = StretchSide::BottomLeft;
        }
        else if(m_mousePos.x() < this->width() && m_mousePos.x() > this->width() - LAYOUTMARGIN)
        {
            m_stretchSide = StretchSide::Right;
        }
        else if(m_mousePos.x() < LAYOUTMARGIN && m_mousePos.x() > 0)
        {
            m_stretchSide = StretchSide::Left;
        }
        else if(m_mousePos.y() < this->height() && m_mousePos.y() > this->height() - LAYOUTMARGIN)
        {
            m_stretchSide = StretchSide::Bottom;
        }
        else if(m_mousePos.y() < LAYOUTMARGIN && m_mousePos.y() > 0)
        {
            m_stretchSide = StretchSide::Top;
        }else
        {
            m_stretchSide = StretchSide::None;
        }
    }

    if(!m_canMoveWindow)
    {
        switch (m_stretchSide)
        {
        case StretchSide::Right:
        case StretchSide::Left:
            this->centralWidget()->setCursor(Qt::SizeHorCursor);
            break;
        case StretchSide::Top:
        case StretchSide::Bottom:
            this->centralWidget()->setCursor(Qt::SizeVerCursor);
            break;
        case StretchSide::TopRight:
        case StretchSide::BottomLeft:
            this->centralWidget()->setCursor(Qt::SizeBDiagCursor);
            break;
        case StretchSide::TopLeft:
        case StretchSide::BottomRight:
            this->centralWidget()->setCursor(Qt::SizeFDiagCursor);
            break;
        default:
            if(!m_canStretchWindow)
                this->centralWidget()->setCursor(Qt::ArrowCursor);
            break;
        }
    }

    if(m_canMoveWindow)
    {
        int dx = event->globalX() - m_mousePos.x();
        int dy = event->globalY() - m_mousePos.y();
        move (dx, dy);

    }
    else if(m_canStretchWindow && !isMaximized() && !isFullScreen())
    {
        int newX = x();
        int newY = y();
        int newWidth = width();
        int newHeight = height();

        int minY =  QApplication::desktop()->availableGeometry().y();

        switch (m_stretchSide)
        {
        case StretchSide::Right:
            newWidth = abs(event->globalX()-this->x()+1);
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;
            break;
        case StretchSide::Left:
            newX = event->globalX() - m_mousePos.x();
            newX = newX > 0 ? newX : 0;
            newX = newX > geometry().bottomRight().x() - minimumWidth() ? geometry().bottomRight().x() - minimumWidth() : newX;
            newWidth = geometry().topRight().x() - newX + 1;
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;
            break;
        case StretchSide::Top:
            newY = event->globalY() - m_mousePos.y();
            newY = newY < minY ? minY : newY;
            newY = newY > geometry().bottomRight().y() - minimumHeight() ? geometry().bottomRight().y() - minimumHeight() : newY;
            newHeight = geometry().bottomLeft().y() - newY + 1;
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight ;

            break;
        case StretchSide::Bottom:
            newHeight = abs(event->globalY()-y()+1);
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight;

            break;
        case StretchSide::TopLeft:
            newX = event->globalX() - m_mousePos.x();
            newX = newX < 0 ? 0: newX;
            newX = newX > geometry().bottomRight().x() - minimumWidth() ? geometry().bottomRight().x()-minimumWidth() : newX;

            newY = event->globalY() - m_mousePos.y();
            newY = newY < minY ? minY : newY;
            newY = newY > geometry().bottomRight().y() - minimumHeight() ? geometry().bottomRight().y() - minimumHeight() : newY;

            newWidth = geometry().bottomRight().x() - newX + 1;
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;

            newHeight = geometry().bottomRight().y() - newY + 1;
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight;

            break;
        case StretchSide::BottomLeft:
            newX = event->globalX() - m_mousePos.x();
            newX = newX < 0 ? 0: newX;
            newX = newX > geometry().bottomRight().x() - minimumWidth() ? geometry().bottomRight().x()-minimumWidth() : newX;

            newWidth = geometry().bottomRight().x() - newX + 1;
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;

            newHeight = event->globalY() - y() + 1;
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight;

            break;
        case StretchSide::TopRight:
            newY = event->globalY() - m_mousePos.y();
            newY = newY > geometry().bottomRight().y() - minimumHeight() ? geometry().bottomRight().y() - minimumHeight() : newY;
            newY = newY < minY ? minY : newY;

            newWidth = event->globalX() - x() + 1;
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;

            newHeight = geometry().bottomRight().y() - newY + 1;
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight;

            break;
        case StretchSide::BottomRight:
            newWidth = event->globalX() - x() + 1;
            newWidth = newWidth < minimumWidth() ? minimumWidth() : newWidth;

            newHeight = event->globalY() - y() + 1;
            newHeight = newHeight < minimumHeight() ? minimumHeight() : newHeight;

            break;
        default:
            break;
        }

        setGeometry(newX, newY, newWidth, newHeight);
    }
    event->accept();
}

void PAMainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_canMoveWindow = false;
    m_canStretchWindow = false;
    QApplication::restoreOverrideCursor();
    event->accept();
}

void PAMainWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QMainWindow::mouseMoveEvent(event);
}

void PAMainWidget::leaveEvent(QEvent *)
{
    this->unsetCursor();
}

bool PAMainWidget::eventFilter(QObject *object, QEvent *event)
{
    return QObject::eventFilter(object, event);
}
