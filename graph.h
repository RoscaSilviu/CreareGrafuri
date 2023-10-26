#ifndef GRAPH_H
#define GRAPH_H

#include "arch.h"

class Graph
{
    std::vector<Node*> nodes;
    std::vector<Arch> arches;
    std::vector<std::vector<int>> adjacencyMatrix;
    bool isOriented;
    Node* selectedNode;

public:
    ~Graph();
    Graph();
    std::vector<Node*>& getNodes();
    std::vector<Arch> &getArches();
    void addNode(Node* n);
    void addNode(const QPoint& position);
    void addArch(Arch arc);
    void addArch(Node* firstNode, Node* secondNode);
    void saveAdjacencyMatrixToFile(const std::string &filename);
    void setOriented();
    void setNotOriented();
    bool getOrientation();
    void setSelectedNode(Node* node);
    Node* getSelectedNode();
};

#endif // GRAPH_H
