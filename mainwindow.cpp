#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <symbol.h>
#include <flowchart.h>
using namespace std;

//enum my_symbol { If, For, Bloc};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //scene = new QGraphicsScene(0, 0, 650, 530);

    //view = new QGraphicsView;

    //setCentralWidget(view);

    //createActions();
    //createMenus();
    //createToolBars();


    //view->show();
    setWindowTitle(tr("Diagram"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete current_flowchart;
}

void MainWindow::init()
{
    current_flowchart = new flowchart();
    view = ui->graphicsView;
    view->setScene(current_flowchart->scene);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    view->setContextMenuPolicy(Qt::ActionsContextMenu);

    connect(current_flowchart->scene, SIGNAL(selectionChanged()), this, SLOT(updateActions()));
    updateActions();
}

void MainWindow::on_buttonquit_clicked()
{
    qApp->quit();
}

void MainWindow::on_buttonif_clicked()
{
    Symbol * my_if = current_flowchart->addSymbol(If);
    Symbol * my_then = current_flowchart->addSymbol(Then);
    Symbol * my_else = current_flowchart->addSymbol(Else);
    current_flowchart->addLink(my_if, my_then, Then);
    current_flowchart->addLink(my_if, my_else, Else);
    setLabelWithCurrentSymbol();
}

void MainWindow::on_buttonfor_clicked()
{
    Symbol * my_for = current_flowchart->addSymbol(For);
    Symbol * my_for_instructions = current_flowchart->addSymbol(ForBloc);
    current_flowchart->addLink(my_for, my_for_instructions,For);
    //current_flowchart->addLink(my_for_instructions, my_for,For);

    setLabelWithCurrentSymbol();
}

void MainWindow::on_buttonbloc_clicked()
{
    current_flowchart->addSymbol(Bloc);
    setLabelWithCurrentSymbol();
}

void MainWindow::setLabelWithCurrentSymbol()
{
//    QString str = NULL;
//    for (int i=0; i < current_flowchart->nb_symbol; i++)
//    {
//        str.append(" ");
//        str.append(current_flowchart->symbol_array[i].getSymbolText());
//        //label = label+ current_flowchart->symbol_array[i].getSymbolText();
//        //ui->label->setText(ui->label->text()+current_flowchart->symbol_array[i].getSymbolText());
//    }
//    ui->label->setText(str);
}



void MainWindow::on_buttonlink_clicked()
{
    current_flowchart->addLink();
}




void MainWindow::on_buttondelete_clicked()
{
    current_flowchart->del();
}


void MainWindow::updateActions()
{
    bool hasSelection = !current_flowchart->scene->selectedItems().isEmpty();
    bool isNode = (current_flowchart->selectedNode() != 0);
    bool isNodePair = (current_flowchart->selectedNodePair() != flowchart::NodePair());

    ui->buttonlink->setEnabled(isNodePair);
    ui->buttondelete->setEnabled(hasSelection);

    if (hasSelection){
        QList<QGraphicsItem *> items = current_flowchart->scene->selectedItems();
        QListIterator<QGraphicsItem *> javaIter( items );
        while( javaIter.hasNext() ){
            Symbol * symbol = dynamic_cast<Symbol *>(javaIter.next());
            if (symbol){
                my_symbol ms = symbol->getSymbolMeaning();
                if (ms == Then || ms == Else || ms == ForBloc)
                    ui->buttondelete->setEnabled(false);
            }
        }
    }
}

void MainWindow::on_buttongenerate_clicked()
{
    ui->label->setText(current_flowchart->generatecpp());
}
