#include "papictureviewwidget.h"
#include <QPalette>
#include <QColor>

PAPictureViewWidget::PAPictureViewWidget(QWidget *parent) : QFrame(parent)
{
    //temp color setting
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::red);
    this->setPalette(palette);
}
