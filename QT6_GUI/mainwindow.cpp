#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent}
{
    // Add Central Widget
    QPushButton *button = new QPushButton("Hello", this);
    setCentralWidget(button);

    // Declare Quit Action
    quitAction = new QAction("Quit");

    // This memory is not managed by the window, you have to release it yourself
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    // Add Menus
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Helps");

    // Add Status Bar Message
    statusBar()->showMessage("Uploading file...");
    statusBar()->clearMessage();
}


QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}
