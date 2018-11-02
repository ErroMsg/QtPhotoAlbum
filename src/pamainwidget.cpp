#include "pamainwidget.h"
#include "ui_pamainwidget.h"

PAMainWidget::PAMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PAMainWidget)
{
    ui->setupUi(this);
}

PAMainWidget::~PAMainWidget()
{
    delete ui;
}
