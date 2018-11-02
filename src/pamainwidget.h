#ifndef PAMAINWIDGET_H
#define PAMAINWIDGET_H

#include <QWidget>

namespace Ui {
class PAMainWidget;
}

class PAMainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PAMainWidget(QWidget *parent = 0);
    ~PAMainWidget();

private:
    Ui::PAMainWidget *ui;
};

#endif // PAMAINWIDGET_H
