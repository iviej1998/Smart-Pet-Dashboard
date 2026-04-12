cmake_minimum_required(VERSION 3.16)

project(SmartPetIoT_UI VERSION 0.1 LANGUAGES CXX)

project(SmartPetIoT_UI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Headers/PetProfileManager.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartPetIoT_UI
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}


            User.cpp

            globals.h
            User.h
            globals.cpp
            PetOwner.h PetOwner.cpp
            Device.h Device.cpp
            PetProfile.h PetProfile.cpp
            SmartFeeder.h SmartFeeder.cpp
            SmartLight.h SmartLight.cpp
            SystemAdmin.h SystemAdmin.cpp
            AuthenticationManager.h
            AuthenticationManager.cpp
            QAUser.h QAUser.cpp




    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET SmartPetIoT_UI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SmartPetIoT_UI SHARED
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartPetIoT_UI
                ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(SmartPetIoT_UI PRIVATE
        /usr/local/Cellar/mysql-connector-c++/9.6.0/include
)

target_link_libraries(SmartPetIoT_UI PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        /usr/local/Cellar/mysql-connector-c++/9.6.0/lib/libmysqlcppconnx.dylib
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SmartPetIoT_UI)
endif()
set_target_properties(SmartPetIoT_UI PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SmartPetIoT_UI
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartPetIoT_UI)
endif()
