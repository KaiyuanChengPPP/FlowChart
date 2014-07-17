#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPushButton button("Test", qApp->wi);
//    button.setFont(QFont("Comic Sans MS", 14));
//    button.setCursor(Qt::PointingHandCursor);
//    button.setIcon(QIcon("if.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    const QPixmap * mypix = new QPixmap(":/iso/if.png");
    ui->label->setPixmap(*mypix);
}

void MainWindow::on_buttonquit_clicked()
{
    qApp->quit();
}
