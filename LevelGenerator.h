#pragma once
#include <random>
#include <iostream>
#include <thread>


#include "Quadtree.h"
#include "CircleCreator.h"
#include "RectangleCreator.h"

class LevelGenerator
{
public:
   EXPORT_API LevelGenerator(const Point &size,int numberToGenerateShapes);
   EXPORT_API ~LevelGenerator();
   EXPORT_API void generate();
private:
    void generateCircle();
    void generateRectangle();
    float generateNumber(int minimal,int maximal);
    CircleCreator circleCreator;
    RectangleCreator rectangleCreator;
    Quadtree *scene = nullptr;
    Point size;
    int numberToGenerateShapes;
};
