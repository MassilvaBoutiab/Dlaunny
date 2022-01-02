#ifndef CANVAS_H
#define CANVAS_H
#include "mainwindow.h"
#include <triangle.h>
#include <QFile>
#include <QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

    void loadMesh(const QString &title);

    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void addPoints(const QVector<Vector2D> &tab);
    void addTriangle(int id0, int id1, int id2);
    void addTriangle(int id0, int id1, int id2, const QColor &color, int i);
    void replaceTriangle(int index, Triangle tr) { this->triangles.replace(index, tr); }
    void clear();
    void reScale();
    inline int getSizeofV() { return vertices.size(); }
    inline int getSizeofT() { return triangles.size(); }
    bool checkDelaunay();
    Vector2D *findNeighbhoor(Vector2D first, Vector2D second, Vector2D third);
    Triangle *findTriangle(Vector2D first, Vector2D second, Vector2D third);

signals:

private:
    QPair<Vector2D, Vector2D> getBox();
    QVector<Triangle> triangles;
    QVector<Vector2D> vertices;
    float scale = 0.5;
    QPoint origin = QPoint(10, 10);

public:
    bool showTriangles = true, showCenters = false, showCircles = false;
};

#endif // CANVAS_H
