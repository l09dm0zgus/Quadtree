#include <iostream>
#include "LevelGenerator.h"

using namespace std;
LevelGenerator *genereteLevel()
{
    float numberOfObjects,width,height;
    std::cout<<"Enter number of objects for level: ";
    std::cin>>numberOfObjects;
    std::cout<<"Enter width for level: ";
    std::cin>>width;
    std::cout<<"Enter height for level: ";
    std::cin>>height;
    return new LevelGenerator(Point(width,height),numberOfObjects);
}

int main()
{

    LevelGenerator *largeLevel = genereteLevel();
    LevelGenerator *middleLevel = genereteLevel();
    LevelGenerator *smallLevel = genereteLevel();
    thread middleLevelThread([middleLevel](){middleLevel->generate();});
    thread smallLevelThread([smallLevel](){smallLevel->generate();});
    largeLevel->generate();
    middleLevelThread.detach();
    smallLevelThread.detach();

    delete largeLevel;
    delete middleLevel;
    delete smallLevel;

    return 0;
}
