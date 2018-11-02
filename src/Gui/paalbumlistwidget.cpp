#include "paalbumlistwidget.h"
#include <QPalette>
#include <QColor>

PAAlbumListWidget::PAAlbumListWidget(QWidget *parent) : QFrame(parent)
{
    //temp color setting
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::red);
    this->setPalette(palette);
    setFixedWidth(200);
}
