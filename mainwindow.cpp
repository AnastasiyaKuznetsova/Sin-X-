#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double A = (ui->lineEdit->text()).toDouble();
    double B = (ui->lineEdit_2->text()).toDouble();
    double C = (ui->lineEdit_3->text()).toDouble();
    double a = -10;
    double b =  10;
    double h = 0.1;
    int N = (b - a)/h + 2;
    QVector<double> x(N), y(N);
    int i=0;
    for (double X = a; X<=b; X+=h)
    {
        x[i] = X;
        y[i] = A*sin(B*X + C);
        i++;
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(a, b);
    double minY = y[0], maxY = y[0];
    for (int i = 1; i < N; i++)
    {
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);
    ui->widget->replot();
}
