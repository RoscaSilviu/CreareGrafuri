#include "arch.h"

Arch::Arch()
{
}

Arch::Arch(Node* firstNode, Node* secondNode) : firstNode(firstNode), secondNode(secondNode)
{
}

Node* Arch::getFirstNode()
{
    return firstNode;
}

Node* Arch::getSecondNode()
{
    return secondNode;
}


void Arch::setFirstNode(Node* node){

    firstNode=node;

}

void Arch::setSecondNode(Node* node){

    secondNode=node;

}
