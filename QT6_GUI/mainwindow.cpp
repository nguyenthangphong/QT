#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
        String Notation
        connect(ui->myButton, SIGNAL(clicked()), this, SLOT(change_text()));
    */

    /*
        Functor Notation : Regular Slots
        connect(ui->myButton, &QPushButton::clicked, this, &MainWindow::change_text);
    */

    /*
        Functor Notation : Lambdas
    */

    connect(ui->myButton, &QPushButton::clicked, [=](){
        ui->myLabel->setText("Some other text from lambda");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_text()
{
    ui->myLabel->setText("Some other text");
}
