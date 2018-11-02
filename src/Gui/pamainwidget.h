#ifndef PAMAINWIDGET_H
#define PAMAINWIDGET_H

#include <QMainWindow>
#include <QEvent>

namespace Ui {
class PAMainWidget;
}

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

protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
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
    int m_mousePressX;
    int m_mousePressY;
};

#endif // PAMAINWIDGET_H
