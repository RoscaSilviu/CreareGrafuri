#include "graph.h"
#include <QFile>
#include <iostream>
#include <fstream>

Graph::Graph()
{

}

std::vector<Node*> &Graph::getNodes()
{
    return nodes;
}

std::vector<Arch> &Graph::getArches()
{
    return arches;
}

bool Graph::getOrientation(){
    return isOriented;
}

void Graph::addNode(const QPoint& position)
{
    Node* newNode = new Node();
    newNode->setValue(nodes.size());
    newNode->setCoordinate(position);
    nodes.push_back(newNode);
    adjacencyMatrix.push_back(std::vector<int>(nodes.size()-1, 0));
    for (int i = 0; i < adjacencyMatrix.size(); i++)
        adjacencyMatrix[i].push_back(0);
}

void Graph::setOriented(){
    isOriented=true;
}

void Graph::setNotOriented(){
    isOriented=false;
}

void Graph::setSelectedNode(Node* node){
    selectedNode = node;
}


Node* Graph::getSelectedNode(){
    return selectedNode;
}


void Graph::addArch(Arch arc)
{
    arches.push_back(arc);
    if(isOriented==false){
        adjacencyMatrix[arc.getFirstNode()->getValue()][arc.getSecondNode()->getValue()]=1;
    adjacencyMatrix[arc.getSecondNode()->getValue()][arc.getFirstNode()->getValue()]=1;
    }
    else
    adjacencyMatrix[arc.getFirstNode()->getValue()][arc.getSecondNode()->getValue()]=1;

}

void Graph::saveAdjacencyMatrixToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
    file << getNodes().size() << "\n";

    for (int i = 0; i < getNodes().size(); i++)
    {
        for (int j = 0; j < getNodes().size(); j++)
        {
            file << adjacencyMatrix[i][j] << " ";
        }
        file << "\n";
    }

    file.close();
    }
    else
    {
    std::cerr << "Eroare: Fișierul nu a putut fi creat sau deschis." << std::endl;
    }
}
Graph::~Graph() {
    for (Node* node : nodes) {
    delete node;
    }
    nodes.clear();
}
