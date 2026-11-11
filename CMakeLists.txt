cmake_minimum_required(VERSION 3.10)


project(homework_2)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)


add_executable(homework_2 
    src/main.cpp 
    src/Detector.cpp
)

target_link_libraries(homework_2 ${OpenCV_LIBS})