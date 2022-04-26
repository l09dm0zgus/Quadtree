TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Circle.cpp \
        CircleCreator.cpp \
        Point.cpp \
        Quadtree.cpp \
        Rectangle.cpp \
        RectangleCreator.cpp \
        Shape.cpp \
        main.cpp

HEADERS += \
    Circle.h \
    CircleCreator.h \
    IShapeCreator.h \
    Point.h \
    Quadtree.h \
    Rectangle.h \
    RectangleCreator.h \
    Shape.h
