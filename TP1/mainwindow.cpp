#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSignalMapper>
#include "mymesh.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSignalMapper* signalMapper = new QSignalMapper (this);
    ui->radioPoint->setChecked(true);
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(onButton()));
    connect(ui->minus, SIGNAL(released()), this, SLOT(onMinus()));
    connect(ui->plus, SIGNAL(released()), this, SLOT(onPlus()));

    connect(ui->radioPoint, SIGNAL(released()), signalMapper, SLOT(map()));
    connect(ui->radioLine, SIGNAL(released()), signalMapper, SLOT(map()));
    connect(ui->radioTriangle, SIGNAL(released()), signalMapper, SLOT(map()));

    signalMapper -> setMapping(ui->radioPoint, 0);
    signalMapper -> setMapping(ui->radioLine, 1);
    signalMapper -> setMapping(ui->radioTriangle, 2);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(modeSwitch(int)));

}

void MainWindow::onButton(){
    ui->widget->changeColor();
}

void MainWindow::onMinus(){
    ui->widget->zoomOut();
}

void MainWindow::onPlus(){
    ui->widget->zoomIn();
}

void MainWindow::modeSwitch(int m){
    ui->widget->modeDraw(m);
}


MainWindow::~MainWindow()
{
    delete ui;
}
