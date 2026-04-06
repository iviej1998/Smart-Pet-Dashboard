cmake_minimum_required(VERSION 3.16)

project(Smart-Pet-Dashboard)

set(CMAKE_CXX_STANDARD 17)

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable automatic UI handling
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Add your source files
add_executable(Smart-Pet-Dashboard
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    User.cpp
    User.h
    PetOwner.cpp
    PetOwner.h
    SystemEntity.h
    SystemEntity.cpp

)

# Link Qt
target_link_libraries(Smart-Pet-Dashboard Qt6::Widgets)