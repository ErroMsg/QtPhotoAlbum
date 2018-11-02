#include "paalbumlistwidget.h"
#include <QPalette>
#include <QColor>

PAAlbumListWidget::PAAlbumListWidget(QWidget *parent) : QFrame(parent)
{
    setObjectName("PAAlbumListWidget");
    setFixedWidth(200);
    this->setStyleSheet("QWidget{background-color:rgb(200,200,200);border-bottom-left-radius :8px;}");
}
