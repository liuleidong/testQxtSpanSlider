#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QxtSpanSlider.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("10");
    ui->lineEdit_2->setText("200");
    ui->horizontalSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);
    ui->horizontalSlider->setMaximum(200);
    ui->horizontalSlider->setLowerValue(10);
    ui->horizontalSlider->setUpperValue(200);
    connect(ui->horizontalSlider,SIGNAL(lowerValueChanged(int)),this,SLOT(lowerValueChangedSlot(int)));
    connect(ui->horizontalSlider,SIGNAL(upperValueChanged(int)),this,SLOT(upperValueChangedSlot(int)));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(lowerTextChangedSlot(QString)));
    connect(ui->lineEdit_2,SIGNAL(textChanged(QString)),this,SLOT(upperTextChangedSlot(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lowerValueChangedSlot(int value)
{
    ui->lineEdit->setText(QString("%1").arg(value));
}

void MainWindow::upperValueChangedSlot(int value)
{
    ui->lineEdit_2->setText(QString("%1").arg(value));
}

void MainWindow::lowerTextChangedSlot(const QString &text)
{
    int value = text.toInt();
    ui->horizontalSlider->setLowerValue(value);
}

void MainWindow::upperTextChangedSlot(const QString &text)
{
    int value = text.toInt();
    ui->horizontalSlider->setUpperValue(value);
}
