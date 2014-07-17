#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <symbol.h>
using namespace std;

//enum my_symbol { If, For, Bloc};

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
    delete current_flowchart;
}

void MainWindow::init()
{
    current_flowchart = new flowchart();
}

void MainWindow::on_buttonquit_clicked()
{
    qApp->quit();
}

void MainWindow::on_buttonif_clicked()
{
    current_flowchart->addSymbol(Symbol::If);
    setLabelWithCurrentSymbol();
}

void MainWindow::on_buttonfor_clicked()
{
    current_flowchart->addSymbol(Symbol::For);
    setLabelWithCurrentSymbol();
}

void MainWindow::on_buttonbloc_clicked()
{
    current_flowchart->addSymbol(Symbol::Bloc);
    setLabelWithCurrentSymbol();
}

void MainWindow::setLabelWithCurrentSymbol()
{
    QString str = NULL;
    for (int i=0; i < current_flowchart->nb_symbol; i++)
    {
        str.append(" ");
        str.append(current_flowchart->symbol_array[i].getSymbolText());
        //label = label+ current_flowchart->symbol_array[i].getSymbolText();
        //ui->label->setText(ui->label->text()+current_flowchart->symbol_array[i].getSymbolText());
    }
    ui->label->setText(str);
}
