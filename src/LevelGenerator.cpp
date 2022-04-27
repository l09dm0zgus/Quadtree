#include "include/LevelGenerator.h"

LevelGenerator::LevelGenerator(const Point &size, int numberToGenerateShapes):size(size),numberToGenerateShapes(numberToGenerateShapes)
{
    scene = new Quadtree(0,Rectangle(0,0,this->size.getX(),this->size.getY()));
}

LevelGenerator::~LevelGenerator()
{
    delete scene;
    scene = nullptr;
}

void LevelGenerator::generate()
{
    for(int i = 0;i<numberToGenerateShapes;i++)
    {
        if(generateNumber(0,1) > 0.5f)
        {
            generateRectangle();
        }
        else
        {
            generateCircle();
        }
    }
    std::cout<<"Generation done on thread: "<<std::this_thread::get_id()<<std::endl;
}

void LevelGenerator::generateCircle()
{
    Circle *circle = static_cast<Circle*>(circleCreator.create());
    circle->setRadius(generateNumber(0,size.getY()));
    circle->setY(generateNumber(0,size.getY()));
    circle->setX(generateNumber(0,size.getX()));
    scene->insertCircle(circle);
}

void LevelGenerator::generateRectangle()
{
    Rectangle *rectangle = static_cast<Rectangle*>(rectangleCreator.create());
    rectangle->setHeight(generateNumber(0,size.getY()));
    rectangle->setWidth(generateNumber(0,size.getX()));
    rectangle->setY(generateNumber(0,size.getY()));
    rectangle->setX(generateNumber(0,size.getX()));
    scene->insertRectangle(rectangle);
}

float LevelGenerator::generateNumber(int minimal, int maximal)
{
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_real_distribution<float> distribution(minimal,maximal);
    return distribution(randomEngine);
}
