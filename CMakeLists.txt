cmake_minimum_required(VERSION 3.26)
project(l5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Code/C++/qt6/qt6-static/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(src)

add_executable(l5 main.cpp
        src/widget/widget.cpp
        src/web/web.cpp)

target_link_libraries(l5
        Qt::Core
        Qt::Gui
        Qt::Widgets
)