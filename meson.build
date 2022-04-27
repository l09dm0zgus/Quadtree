project('Quadtree','cpp')
projectFiles = files([
'include/Defines.h',
'include/Circle.h',
'include/CircleCreator.h',
'include/IShapeCreator.h',
'include/LevelGenerator.h',
'include/Point.h',
'include/Quadtree.h',
'include/Rectangle.h',
'include/RectangleCreator.h',
'include/Shape.h',
'src/Circle.cpp',
'src/CircleCreator.cpp',
'src/LevelGenerator.cpp',
'src/Point.cpp',
'src/Quadtree.cpp',
'src/Rectangle.cpp',
'src/RectangleCreator.cpp',
'src/Shape.cpp'
])
lib = shared_library('quadtreelib',projectFiles)

incdir = include_directories('include')

executable('main', 'main.cpp', include_directories : incdir ,link_with : lib)
