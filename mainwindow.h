#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <flowchart.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    flowchart* current_flowchart;

    QGraphicsView *view;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    void setLabelWithCurrentSymbol();

private slots:
    void on_buttonquit_clicked();
    void on_buttonif_clicked();
    void on_buttonfor_clicked();
    void on_buttonbloc_clicked();
    //void properties();
    void updateActions();
    void on_buttonlink_clicked();
    void on_buttondelete_clicked();
    void on_buttongenerate_clicked();
};

#endif // MAINWINDOW_H
