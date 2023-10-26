#include "node.h"
#include "qpoint.h"

Node::Node()
{
    coordinate=QPoint(0,0);
    value = -1;
}

Node::Node(const Node* other) {
    if (other!=nullptr) {
        coordinate=other->coordinate;
        value = other->value;
    } else {
        value = -1;
    }
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
{
    return value;
}

void Node::setCoordinate(const QPoint& position)
{
    this->coordinate = position;
}

int Node::getX()
{
    return coordinate.x();
}
int Node::getY()
{
    return coordinate.y();
}
QPoint Node::getCoordinate()
{
    return coordinate;
}
Node& Node::operator=(const Node *other) {
    if (other) {
        this->coordinate=other->coordinate;
        this->value=other->value;
    }
    else{
        coordinate=QPoint(0,0);
        value = -1;
    }
    return *this;
}
