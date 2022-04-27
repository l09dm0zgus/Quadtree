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
   EXPORT_API Quadtree(int level , const Rectangle &bounds);
   EXPORT_API ~Quadtree();
   EXPORT_API void clear();
   EXPORT_API void insertRectangle(Rectangle* rectangle);
   EXPORT_API void insertCircle(Circle* circle);
   EXPORT_API Rectangle getBounds();
   EXPORT_API std::vector<Shape*> getShapes();
   EXPORT_API Quadtree *getNorthWestChild();
   EXPORT_API Quadtree *getNorthEastChild();
   EXPORT_API Quadtree *getSouthWestChild();
   EXPORT_API Quadtree *getSouthEastChild();
private:
    void split();
    FittedSide getFittedSideOfQuadtreeForRectangle(Rectangle *rectangle);
    FittedSide getFittedSideOfQuadtreeForCircle(Circle *circle);
    FittedSide getFittedSideOfQuadtreeForShape(Shape *shape,float shapeWidth,float shapeHeight);
    Quadtree* getChildByFittedSide(FittedSide side);
    const int MAX_OBJECTS = 4;
    const int MAX_LEVELS = 100;
    int level;
    std::vector<Shape*> shapes;
    Quadtree *northWest = nullptr;
    Quadtree *northEast = nullptr;
    Quadtree *southWest = nullptr;
    Quadtree *southEast = nullptr;
    Rectangle bounds;
};
void iterate(Quadtree *child,std::function<void(Quadtree *child)> callback);

