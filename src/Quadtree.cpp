#include "include/Quadtree.h"

Quadtree::Quadtree(int level, const Rectangle &bounds):level(level),bounds(bounds)
{

}

Quadtree::~Quadtree()
{

    clear();
}

void Quadtree::clear()
{
    if(northWest != nullptr)
    {
        northWest->clear();
        northEast->clear();
        southWest->clear();
        southEast->clear();

        delete northWest;
        delete northEast;
        delete southWest;
        delete southEast;

        northWest = nullptr;
        northEast = nullptr;
        southWest = nullptr;
        southEast = nullptr;
    }

}

void Quadtree::insertRectangle(Rectangle *rectangle)
{
    if(northWest != nullptr)
    {
       Quadtree* side =  getChildByFittedSide(getFittedSideOfQuadtreeForRectangle(rectangle));
       if(side != nullptr)
       {
           side->insertRectangle(rectangle);
           return;
       }
    }
    shapes.push_back(rectangle);
    if(shapes.size() > MAX_OBJECTS && level < MAX_LEVELS)
    {
        if(northWest != nullptr)
        {
            split();
        }
        std::vector<Shape*>::iterator i = shapes.begin();
        while(i !=shapes.end())
        {
            Quadtree* side =  getChildByFittedSide(getFittedSideOfQuadtreeForRectangle(rectangle));
            if(side != nullptr)
            {
              side->insertRectangle(static_cast<Rectangle*>(*i));
              shapes.erase(i);
            }
            else
            {
                i++;
            }
        }
    }
}

void Quadtree::insertCircle(Circle *circle)
{
    if(northWest != nullptr)
    {
       Quadtree* side =  getChildByFittedSide(getFittedSideOfQuadtreeForCircle(circle));
       if(side != nullptr)
       {
           side->insertCircle(circle);
           return;
       }
    }
    shapes.push_back(circle);
    if(shapes.size() > MAX_OBJECTS && level < MAX_LEVELS)
    {
        if(northWest != nullptr)
        {
            split();
        }
        std::vector<Shape*>::iterator i = shapes.begin();
        while(i !=shapes.end())
        {
            Quadtree* side =  getChildByFittedSide(getFittedSideOfQuadtreeForCircle(circle));
            if(side != nullptr)
            {
              side->insertCircle(static_cast<Circle*>(*i));
              shapes.erase(i);
            }
            else
            {
                i++;
            }
        }
    }
}

Rectangle Quadtree::getBounds()
{
    return bounds;
}

std::vector<Shape *> Quadtree::getShapes()
{
    return shapes;
}

Quadtree* Quadtree::getNorthWestChild()
{
    return northWest;
}

Quadtree *Quadtree::getNorthEastChild()
{
    return northEast;
}

Quadtree *Quadtree::getSouthWestChild()
{
    return southWest;
}

Quadtree *Quadtree::getSouthEastChild()
{
    return southEast;
}

void Quadtree::split()
{
    int halfOfWidth = (int)(bounds.getWidth()/2);
    int halfOfHeight = (int)(bounds.getHeight()/2);

    int x = (int)bounds.getX();
    int y = (int)bounds.getY();

    northWest = new Quadtree(level+1,Rectangle(x+halfOfWidth,y,halfOfWidth,halfOfHeight));
    northEast = new Quadtree(level+1,Rectangle(x,y,halfOfWidth,halfOfHeight));
    southWest = new Quadtree(level+1,Rectangle(x,y+halfOfHeight,halfOfWidth,halfOfHeight));
    southEast = new Quadtree(level+1,Rectangle(x+halfOfWidth,y,halfOfWidth,halfOfHeight));
}

FittedSide Quadtree::getFittedSideOfQuadtreeForRectangle(Rectangle *rectangle)
{
    return getFittedSideOfQuadtreeForShape(rectangle,rectangle->getWidth(),rectangle->getHeight());
}

FittedSide Quadtree::getFittedSideOfQuadtreeForCircle(Circle *circle)
{
    return getFittedSideOfQuadtreeForShape(circle,circle->getRadius(),circle->getRadius());
}

FittedSide Quadtree::getFittedSideOfQuadtreeForShape(Shape *shape, float shapeWidth, float shapeHeight)
{
    FittedSide fittedSide = NOT_FITTED;
    double verticalMidpoint = bounds.getX() + (bounds.getWidth() / 2);
    double horizontalMidpoint = bounds.getY() + (bounds.getHeight() / 2);
    bool topQuadrant =(shape->getY() < horizontalMidpoint && shape->getY()+shapeHeight < horizontalMidpoint);
    bool bottomQuadrant = (shape->getY() > horizontalMidpoint);
    if((shape->getX() < verticalMidpoint) && (shape->getX()+shapeWidth < verticalMidpoint))
    {
        if(topQuadrant)
        {
            fittedSide = NORTH_EAST;
        }
        else if(bottomQuadrant)
        {
            fittedSide = SOUTH_WEST;
        }
    }
    else if(shape->getX() > verticalMidpoint)
    {
        if(topQuadrant)
        {
            fittedSide = NORTH_WEST;
        }
        else if(bottomQuadrant)
        {
            fittedSide = SOUTH_EAST;
        }
    }
    return fittedSide;
}

Quadtree *Quadtree::getChildByFittedSide(FittedSide side)
{
    switch(side)
    {
        case NOT_FITTED:
        return nullptr;
        break;
        case NORTH_WEST:
        return northWest;
        break;
        case NORTH_EAST:
        return northEast;
        break;
        case SOUTH_WEST:
        return southEast;
        break;
        case SOUTH_EAST:
        return southEast;
        break;
    }
}



void iterate(Quadtree *child, std::function<void (Quadtree *child)> callback)
{
    if(child != nullptr)
    {
        if(child->getNorthWestChild() != nullptr)
        {
            callback(child);
            iterate(child->getNorthWestChild(),callback);
            iterate(child->getNorthEastChild(),callback);
            iterate(child->getSouthWestChild(),callback);
            iterate(child->getSouthEastChild(),callback);
        }
    }
}
