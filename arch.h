#ifndef ARCH_H
#define ARCH_H

#include "node.h"

class Arch
{
private:

    Node *firstNode;
    Node *secondNode;


public:
    Arch();
    Arch(Node *firstNode, Node *secondNode);

    Node* getFirstNode();
    Node* getSecondNode();
    void setFirstNode(Node* node);
    void setSecondNode(Node* node);
};

#endif // ARCH_H
