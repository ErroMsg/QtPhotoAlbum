#include "papictureviewwidget.h"
#include <QPalette>
#include <QColor>

PAPictureViewWidget::PAPictureViewWidget(QWidget *parent) : QFrame(parent)
{
    //temp color setting
    setObjectName("PAPictureViewWidget");
    this->setStyleSheet("QWidget{background-color:white;border-bottom-right-radius :8px;}");
}
