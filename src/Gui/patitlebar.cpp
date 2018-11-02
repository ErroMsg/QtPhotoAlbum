#include "patitlebar.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QToolButton>
#include <QLabel>
#include <QSlider>
#include <QToolButton>
#include <QPalette>
#include <QColor>

PATitleBar::PATitleBar(QWidget *parent) : QFrame(parent)
{
    setObjectName("PATitleBar");
    initUi();
    initLayout();
    setFixedHeight(60);

    this->setStyleSheet("QWidget#PATitleBar{background-color:rgb(80,80,80);border-top-left-radius:8px;border-top-right-radius:8px;}");
}

PATitleBar::~PATitleBar()
{

}

void PATitleBar::initUi()
{
    m_btClose = new QToolButton(this);
    m_btMinimize = new QToolButton(this);
    m_btMaximum = new QToolButton(this);
    m_btBack = new QToolButton(this);
    m_btMode = new QToolButton(this);
    m_btZoomIn = new QToolButton(this);
    m_btZoomOut = new QToolButton(this);

    m_sliderZoom = new QSlider(Qt::Horizontal,this);
    m_sliderZoom->setRange(0,10);
    m_sliderZoom->setFixedWidth(60);

    m_labelTimeStampTitle = new QLabel("m_labelTimeStampTitle",this);
    m_labelTimeStampTitle->setAlignment(Qt::AlignCenter);
    m_labelImageCountTitle = new QLabel("m_labelImageCountTitle",this);
    m_labelImageCountTitle->setAlignment(Qt::AlignCenter);

    m_btFaver = new QToolButton(this);
    m_btFunc1 = new QToolButton(this);
    m_btFunc2 = new QToolButton(this);
    m_btFunc3 = new QToolButton(this);
}

void PATitleBar::initLayout()
{
    QHBoxLayout *playoutBtCtrl = new QHBoxLayout;
    playoutBtCtrl->addWidget(m_btClose);
    playoutBtCtrl->addWidget(m_btMinimize);
    playoutBtCtrl->addWidget(m_btMaximum);
    QSpacerItem *pSpacerCtrl = new QSpacerItem(5,1,QSizePolicy::Fixed,QSizePolicy::Fixed);
    playoutBtCtrl->addItem(pSpacerCtrl);

    QHBoxLayout *playoutImageCtr = new QHBoxLayout;
    playoutImageCtr->addWidget(m_btBack);
    playoutImageCtr->addWidget(m_btMode);
    playoutImageCtr->addWidget(m_btZoomIn);
    playoutImageCtr->addWidget(m_sliderZoom);
    playoutImageCtr->addWidget(m_btZoomOut);
    QSpacerItem *pSpacer2= new QSpacerItem(5,1,QSizePolicy::Fixed,QSizePolicy::Fixed);
    playoutImageCtr->addItem(pSpacer2);

    QVBoxLayout *pTitleLaout = new QVBoxLayout;
    pTitleLaout->addWidget(m_labelTimeStampTitle);
    pTitleLaout->addWidget(m_labelImageCountTitle);

    playoutImageCtr->addLayout(pTitleLaout);
    playoutImageCtr->addWidget(m_btFaver);
    playoutImageCtr->addWidget(m_btFunc1);
    playoutImageCtr->addWidget(m_btFunc2);
    playoutImageCtr->addWidget(m_btFunc3);

    QHBoxLayout *pMainlayou = new QHBoxLayout;
    pMainlayou->addLayout(playoutBtCtrl);
    pMainlayou->addLayout(playoutImageCtr);
    setLayout(pMainlayou);
}
