#ifndef PAMAINWIDGET_H
#define PAMAINWIDGET_H

#include <QMainWindow>
#include <QEvent>

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

protected:
    //void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent* event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent*) Q_DECL_OVERRIDE;
    bool eventFilter(QObject* object, QEvent* event) Q_DECL_OVERRIDE;

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
