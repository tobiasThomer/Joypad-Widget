#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "joypad.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget, &JoyPad::distanceChanged, this, [this](float r){
        qDebug() << "r: " << r << " angle: " << ui->widget->angle();
    });


    connect(ui->widget, &JoyPad::angleChanged, this, [this](float a){
        qDebug() << "r: " << ui->widget->distance() << " angle: " << a;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
