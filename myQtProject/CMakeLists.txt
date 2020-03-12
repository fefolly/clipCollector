cmake_minimum_required(VERSION 3.5)

project(myQtProject LANGUAGES CXX)

#local header filesare here
SET(TARGET_H
    Header.h
    Plugin.h
    templateimplemetation.h
    )

#Local source files here
#SET(TARGET_SRC
 #   templateimplemetation.cpp
 #   )


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(myQtProject main.cpp templateimplemetation.cpp)
