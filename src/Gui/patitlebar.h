#ifndef PATITLEBAR_H
#define PATITLEBAR_H

#include <QFrame>

class QToolButton;
class QLabel;
class QSlider;

class PATitleBar : public QFrame
{
    Q_OBJECT
public:
    explicit PATitleBar(QWidget *parent = nullptr);
    ~PATitleBar();

private:
    void initUi();
    void initLayout();
signals:

public slots:

private:
    QToolButton *m_btClose;
    QToolButton *m_btMinimize;
    QToolButton *m_btMaximum;
    QToolButton *m_btBack;
    QToolButton *m_btMode;
    QToolButton *m_btZoomIn;
    QToolButton *m_btZoomOut;
    QSlider *m_sliderZoom;
    QLabel *m_labelTimeStampTitle;
    QLabel *m_labelImageCountTitle;

    QToolButton *m_btFaver;
    //empty button
    QToolButton *m_btFunc1;
    QToolButton *m_btFunc2;
    QToolButton *m_btFunc3;
};

#endif // PATITLEBAR_H
