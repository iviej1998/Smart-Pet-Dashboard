cmake_minimum_required(VERSION 3.16)

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
    PetOwner.h PetOwner.cpp
    Device.h Device.cpp
    PetProfile.h PetProfile.cpp
    SmartFeeder.h SmartFeeder.cpp
    SmartLight.h SmartLight.cpp
    SystemAdmin.h SystemAdmin.cpp
    AuthenticationManager.h AuthenticationManager.cpp
    QAUser.h QAUser.cpp
    PPwindow.h PPwindow.cpp PPwindow.ui
    PPDog.h PPDog.cpp ppdog.ui
    PPCat.h PPCat.cpp ppcat.ui
    PPFish.h PPFish.cpp ppfish.ui
    PPReptile.h PPReptile.cpp ppreptile.ui
    Login.h Login.cpp login.ui
    resources.qrc
    CreateAccount.h CreateAccount.cpp createaccount.ui
    PetProfileManager.h PetProfileManager.cpp
    Database.h Database.cpp
    UserProfile.h UserProfile.cpp
    UserProfileManager.h UserProfileManager.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartPetIoT_UI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(SmartPetIoT_UI SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(SmartPetIoT_UI
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(SmartPetIoT_UI PRIVATE
    "C:/mysqlconnector/mysql-connector-c++-9.6.0-winx64/include"
)

# Required when linking the Connector/C++ static JDBC library
target_compile_definitions(SmartPetIoT_UI PRIVATE STATIC_CONCPP)

target_link_libraries(SmartPetIoT_UI PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets

    # Classic JDBC static connector
    "C:/mysqlconnector/mysql-connector-c++-9.6.0-winx64/lib64/vs14/mysqlcppconn-static.lib"

    # Connector dependencies present in your install
    "C:/mysqlconnector/mysql-connector-c++-9.6.0-winx64/lib64/vs14/libcrypto.lib"
    "C:/mysqlconnector/mysql-connector-c++-9.6.0-winx64/lib64/vs14/libssl.lib"

    # Windows system libs commonly needed
    ws2_32
    crypt32
)

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