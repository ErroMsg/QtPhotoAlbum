#ifndef PAMAINWIDGET_H
#define PAMAINWIDGET_H

#include <QMainWindow>
#include <QEvent>

//无边MainWindow

namespace Ui {
class PAMainWidget;
}
class PATitleBar;
class PAPictureViewWidget;
class PAAlbumListWidget;
class PAMainWidget : public QMainWindow
{
    Q_OBJECT
public:

    enum class StretchSide
    {
        None = 0,
        Left,
        Right,
        Top,
        Bottom,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
     };

public:
    explicit PAMainWidget(QWidget *parent = 0);
    ~PAMainWidget();

private:
    void initUi();
    void initFrameShaodowEffect();

protected:
    virtual void resizeEvent(QResizeEvent* event) override;
    virtual void closeEvent(QCloseEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
    virtual void leaveEvent(QEvent*) override;
    virtual bool eventFilter(QObject* object, QEvent* event) override;


private:
    StretchSide m_stretchSide;
    bool m_canMoveWindow;
    bool m_canStretchWindow;
    QPoint m_mousePos;

    PATitleBar *m_pTitleBar;
    PAAlbumListWidget *m_pAlbumList;
    PAPictureViewWidget *m_pPictureView;
};

#endif // PAMAINWIDGET_H
