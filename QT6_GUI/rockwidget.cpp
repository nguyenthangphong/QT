#include "rockwidget.h"
#include <QMessageBox>
#include <QLabel>
#include <QPalette>
#include <QPushButton>

RockWidget::RockWidget(QWidget *parent) : QWidget{parent}
{
    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->move(50, 50);

    // Add a style widget and move it a round
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window, Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::blue);

    QFont label1Font("Times", 20, QFont::Bold);

    QLabel *label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("My colored label");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(50, 50);

    // Add another label
    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window, Qt::green);
    label2Palette.setColor(QPalette::WindowText, Qt::black);

    QLabel *mLabel2 = new QLabel(this);
    mLabel2->setAutoFillBackground(true);
    mLabel2->setText("This is my label2");
    mLabel2->setPalette(label2Palette);
    mLabel2->move(70, 170);
    QFont serifFont("Times", 20, QFont::Bold);
    mLabel2->setFont(serifFont);

    // Add a button and connect to slot
    QFont buttonFont("Times", 30, QFont::Bold);
    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->setFont(buttonFont);
    button->move(100, 250);

    connect(button, SIGNAL(clicked()), this, SLOT(button_clicked())); // String Notation
}

void RockWidget::button_clicked()
{
    QMessageBox::information(this, "Message", "You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(1500, 500);
}
