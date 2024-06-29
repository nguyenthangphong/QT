#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculate_calories();
    void weight_changed(double weight);
    void time_changed(double time);
    void speed_changed(double speed);
    void slope_changed(QString slope);

signals:
    void calory_count_changed();

private:
    Ui::MainWindow *ui;
    Person m_person;
    double m_time;
    double m_speed;
    QString m_slope;
    double m_calory_count;
};
#endif // MAINWINDOW_H
