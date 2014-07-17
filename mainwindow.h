#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <flowchart.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    flowchart* current_flowchart;

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
