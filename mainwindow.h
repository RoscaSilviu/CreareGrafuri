#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void mousePressEvent(QMouseEvent*  mouseEvent);
    virtual void paintEvent(QPaintEvent* mouseEvent);
    virtual void mouseMoveEvent(QMouseEvent* mouseEvent);
    virtual void mouseReleaseEvent(QMouseEvent*  mouseEvent);


private slots:
    void on_Oriented_toggled(bool checked);
    void on_NotOriented_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Node* afirstNode=nullptr;
    Graph graph;

};
#endif // MAINWINDOW_H
