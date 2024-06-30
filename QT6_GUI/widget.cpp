#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent) : QWidget{parent}, ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->imageTextLabel->move(100, 30);

    QPixmap my_image(":/images/Kobie_Mainoo.png");

    ui->imageLabel->move(0, 70);
    ui->imageLabel->setPixmap(my_image.scaled(400, 400));
}

Widget::~Widget()
{

}
