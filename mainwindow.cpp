#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include "node.h"
#include "arch.h"
#include "graph.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent* mouseEvent) {
    if (graph.getSelectedNode()!= nullptr) {
        graph.getSelectedNode()->setCoordinate(mouseEvent->pos());
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* mouseEvent) {
    if (graph.getSelectedNode() != nullptr) {
        graph.setSelectedNode(nullptr);
    }
}


void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::RightButton)
    {
        std::vector<Node*>& nodes = graph.getNodes();
        bool overlap = false;

        for (Node *node : nodes)
        {
            if (abs(mouseEvent->pos().x() - node->getX()) < 20 &&
                abs(mouseEvent->pos().y() - node->getY()) < 20)
            {
                overlap = true;
                graph.setSelectedNode(node);
                break;
            }
        }

        if (!overlap)
        {
            graph.addNode(mouseEvent->pos());
            update();
        }

    }
    else if (mouseEvent->button() == Qt::LeftButton)
    {
        std::vector<Node*>& nodes = graph.getNodes();
        for(Node *node: nodes)
        {
            if (abs(mouseEvent->pos().x() - node->getX())< 10 &&
                abs(mouseEvent->pos().y() - node->getY()) < 10 )
            {

                if (afirstNode == nullptr)
                    afirstNode = node;
                else
                {
                    graph.addArch(Arch(afirstNode, node));
                    graph.saveAdjacencyMatrixToFile("adjacencyMatrix.txt");
                    afirstNode=nullptr;
                }
                update();
                break;
            }
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    std::vector<Node*> nodes = graph.getNodes();

    for (Node* node: nodes)
    {
        QRect rectangle(node->getX() - 10, node->getY() - 10, 20, 20);
        paint.drawEllipse(rectangle);
        QString string;
        string.setNum(node->getValue());
        paint.drawText(rectangle, Qt::AlignCenter, string);
    }


    std::vector<Arch> arches = graph.getArches();
    for (Arch& arch : arches)
    {
        if (graph.getOrientation()==true && arch.getFirstNode()->getValue() >= 0)
        {

            QPoint firstPoint(arch.getFirstNode()->getX(), arch.getFirstNode()->getY());
            QPoint secondPoint(arch.getSecondNode()->getX(), arch.getSecondNode()->getY());

            double arrowLength = 8;
            double angle = atan2(secondPoint.y() - firstPoint.y(), secondPoint.x() - firstPoint.x());
            QPoint arrowPoint(
                secondPoint.x() - arrowLength * cos(angle),
                secondPoint.y() - arrowLength * sin(angle)
                );

            paint.drawLine(firstPoint, arrowPoint);

            int arrowSize = 10;
            QPoint arrowP1(arrowPoint.x() - arrowSize * cos(angle - M_PI / 6), arrowPoint.y() - arrowSize * sin(angle - M_PI / 6));
            QPoint arrowP2(arrowPoint.x() - arrowSize * cos(angle + M_PI / 6), arrowPoint.y() - arrowSize * sin(angle + M_PI / 6));
            paint.drawLine(arrowPoint, arrowP1);
            paint.drawLine(arrowPoint, arrowP2);
        }
        else
        {
            paint.drawLine(arch.getFirstNode()->getX(), arch.getFirstNode()->getY(),
                           arch.getSecondNode()->getX(), arch.getSecondNode()->getY());
        }
    }
}


void MainWindow::on_Oriented_toggled(bool checked)
{
    graph.setOriented();
}


void MainWindow::on_NotOriented_toggled(bool checked)
{
    graph.setNotOriented();
}

