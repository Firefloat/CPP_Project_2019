cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src main.cpp lagerung/Container.cpp lagerung/Container.h lagerung/Shelf.cpp lagerung/Shelf.h lagerung/Robo.cpp lagerung/Robo.h lagerung/Size.h setup/Loaderton.cpp setup/Loaderton.h lagerung/ArticleType.h lagerung/Coordinates.h lagerung/Article.h lagerung/Board.cpp lagerung/Board.h lagerung/FreeSpace.h lagerung/Queue.cpp lagerung/Queue.h lagerung/StorageManager.cpp lagerung/StorageManager.h lagerung/TestEnvironment.cpp lagerung/TestEnvironment.h)