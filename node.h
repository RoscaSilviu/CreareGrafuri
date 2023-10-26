#ifndef NODE_H
#define NODE_H
#include <QPainter>
class Node
{
private:

    int value;
    QPoint coordinate;

public:
    Node();
    Node(const Node* node);
    void setValue(int value);
    void setCoordinate(const QPoint& position);
    void setX(int x);
    void setY(int y);
    int getValue();
    QPoint getCoordinate();
    int getX();
    int getY();
    Node& operator=(const Node *other);
};


#endif // NODE_H
