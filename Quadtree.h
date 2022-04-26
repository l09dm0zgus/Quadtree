#pragma once
#include <vector>
#include <functional>
#include "Circle.h"
#include "Rectangle.h"
enum FittedSide
{
    NOT_FITTED = -1,
    NORTH_WEST,
    NORTH_EAST,
    SOUTH_WEST,
    SOUTH_EAST
};

class Quadtree
{
public:
    Quadtree(int level , const Rectangle &bounds);
    ~Quadtree();
    void clear();
    void insertRectangle(Rectangle* rectangle);
    void insertCircle(Circle* circle);
    Rectangle getBounds();
    std::vector<Shape*> getShapes();
    Quadtree *getNorthWestChild();
    Quadtree *getNorthEastChild();
    Quadtree *getSouthWestChild();
    Quadtree *getSouthEastChild();
private:
    void split();
    FittedSide getFittedSideOfQuadtreeForRectangle(Rectangle *rectangle);
    FittedSide getFittedSideOfQuadtreeForCircle(Circle *circle);
    FittedSide getFittedSideOfQuadtreeForShape(Shape *shape,float shapeWidth,float shapeHeight);
    Quadtree* getChildByFittedSide(FittedSide side);
    const int MAX_OBJECTS = 4;
    const int MAX_LEVELS = 15;
    int level;
    std::vector<Shape*> shapes;
    Quadtree *northWest = nullptr;
    Quadtree *northEast = nullptr;
    Quadtree *southWest = nullptr;
    Quadtree *southEast = nullptr;
    Rectangle bounds;
};
void iterate(Quadtree *child,std::function<void(Quadtree *child)> callback);

