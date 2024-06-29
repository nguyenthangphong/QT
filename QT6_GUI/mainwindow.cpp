#include "mainwindow.h"
#include "ui_mainwindow.h"

double calculatorFormulas[11][4] = {
    {0.0251, 0.2157, 0.7888, 1.2957},
    {0.0244, 0.2079, 0.8053, 1.3281},
    {0.0237, 0.2000, 0.8217, 1.3605},
    {0.0230, 0.1922, 0.8382, 1.3929},
    {0.0222, 0.1844, 0.8546, 1.4253},
    {0.0215, 0.1765, 0.8710, 1.4577},
    {0.0171, 0.1062, 0.6080, 1.8600},
    {0.0184, 0.1134, 0.6566, 1.9200},
    {0.0196, 0.1205, 0.7053, 1.9800},
    {0.0208, 0.1277, 0.7539, 2.0400},
    {0.0221, 0.1349, 0.8025, 2.1000}
};

enum Grades {
    __5_percent_grade = 0,
    __4_percent_grade,
    __3_percent_grade,
    __2_percent_grade,
    __1_percent_grade,
    _0_percent_grade,
    _1_percent_grade,
    _2_percent_grade,
    _3_percent_grade,
    _4_percent_grade,
    _5_percent_grade
};

int position = 0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initializer the members with values from the ui
    m_person.setWeight(ui->weightSpinBox->value());
    m_time = ui->timeSpinBox->value();
    m_speed = ui->speedSpinBox->value();
    m_slope = ui->slopeComboBox->currentText();

    // Connect ui componenets to respective slots
    connect(ui->weightSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::weight_changed);
    connect(ui->timeSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::time_changed);
    connect(ui->speedSpinBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::speed_changed);
    connect(ui->slopeComboBox, &QComboBox::currentTextChanged, this, &MainWindow::slope_changed);

    // Display the calory count
    connect(this, &MainWindow::calory_count_changed, [=](){
        ui->caloryCountNumberLabel->setText(QString::number(m_calory_count));
    });

    calculate_calories();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate_calories()
{
    if (m_slope.compare("-5% grade") == 0) {
        position = __5_percent_grade;
    } else if (m_slope.compare("-4% grade") == 0) {
        position = __4_percent_grade;
    } else if (m_slope.compare("-3% grade") == 0) {
        position = __3_percent_grade;
    } else if (m_slope.compare("-2% grade") == 0) {
        position = __2_percent_grade;
    } else if (m_slope.compare("-1% grade") == 0) {
        position = __1_percent_grade;
    } else if (m_slope.compare(" 0% grade") == 0) {
        position = _0_percent_grade;
    } else if (m_slope.compare("+1% grade") == 0) {
        position = _1_percent_grade;
    } else if (m_slope.compare("+2% grade") == 0) {
        position = _2_percent_grade;
    } else if (m_slope.compare("+3% grade") == 0) {
        position = _3_percent_grade;
    } else if (m_slope.compare("+4% grade") == 0) {
        position = _4_percent_grade;
    } else if (m_slope.compare("+4% grade") == 0) {
        position = _5_percent_grade;
    }

    // CB = [A x KPH ^ 3 - B x KPH ^ 2 + C x KPH + D] x WKG x T
    double A = calculatorFormulas[position][0];
    double B = calculatorFormulas[position][1];
    double C = calculatorFormulas[position][2];
    double D = calculatorFormulas[position][3];

    m_calory_count = ((A * (m_speed * m_speed * m_speed)) -
        (B * (m_speed * m_speed)) + (C * m_speed) + D) * m_person.getWeight() * m_time;

    emit calory_count_changed();
}

void MainWindow::weight_changed(double weight)
{
    m_person.setWeight(weight);
    calculate_calories();
}

void MainWindow::time_changed(double time)
{
    m_time = time;
    calculate_calories();
}

void MainWindow::speed_changed(double speed)
{
    m_speed = speed;
    calculate_calories();
}

void MainWindow::slope_changed(QString slope)
{
    m_slope = slope;
    calculate_calories();
}
