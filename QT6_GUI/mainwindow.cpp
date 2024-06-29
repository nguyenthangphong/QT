#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
        String Notation
        connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
        connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(respond(int)));
    */

    /*
        Functor Notation
        connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
        connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::respond);
    */

    /*
        Functor Notation : Lambas
    */

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](){
        ui->progressBar->setValue(ui->horizontalSlider->value());
        respond(ui->horizontalSlider->value());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::respond(int value)
{
    qDebug() << "value : " << value;
}
