#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->b_connect, SIGNAL(clicked()), this, SLOT(connect()));
    QObject::connect(ui->b_disconnect, SIGNAL(clicked()), this, SLOT(disconnect()));
    QObject::connect(ui->b_update, SIGNAL(clicked()), this, SLOT(update()));
    QObject::connect(ui->b_load, SIGNAL(clicked()), this, SLOT(loadConfig()));
    QObject::connect(ui->b_save, SIGNAL(clicked()), this, SLOT(saveConfig()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect()
{

    ui->b_connect->setEnabled(false);
    ui->b_disconnect->setEnabled(true);
    ui->b_set->setEnabled(true);
    ui->b_get->setEnabled(true);
    ui->b_update->setEnabled(true);
}

void MainWindow::disconnect()
{

    ui->b_connect->setEnabled(true);
    ui->b_disconnect->setEnabled(false);
    ui->b_set->setEnabled(false);
    ui->b_get->setEnabled(false);
    ui->b_update->setEnabled(false);
}

void MainWindow::update()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open firmware file"), "", tr("BIN Files (*.bin)"));

    QFile file(filename);
}

void MainWindow::loadConfig()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open config file"), "", tr("XML Files (*.xml)"));

    QFile file(filename);
}

void MainWindow::saveConfig()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save config file"), "", tr("XML Files (*.xml)"));

    QFile file(filename);
}
