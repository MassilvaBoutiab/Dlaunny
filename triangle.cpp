#include "triangle.h"

void Triangle::computeCircle()
{
    Vector2D AC = *ptr[2] - *ptr[0];
    Vector2D AB = *ptr[1] - *ptr[0];
    AC.orthoNormed();
    double k = (AB * AB - AC * AB) / (2 * AC.orthoNormed() * AB);
    circumCenter = 0.5 * AC + k * AC.orthoNormed() + *ptr[0];
    circumRadius = (circumCenter - *ptr[0]).length();
}

void Triangle::draw(QPainter &painter)
{
    QPen pen(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.setBrush(isHighlited ? Qt::red
                                 : (isDelaunay ? Qt::gray : (isflipable ? Qt::cyan : Qt::yellow)));
    QPointF points[3];
    for (int i = 0; i < 3; i++) {
        points[i].setX(ptr[i]->x);
        points[i].setY(ptr[i]->y);
    }
    painter.drawPolygon(points, 3);
}

void Triangle::drawCircle(QPainter &painter)
{
    painter.setPen(QPen(Qt::black, 5, Qt::DashLine));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(circumCenter.x - circumRadius,
                        circumCenter.y - circumRadius,
                        2.0 * circumRadius,
                        2.0 * circumRadius);
}
