cmake_minimum_required(VERSION 3.16)

project(weatherApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавьте Network в список компонентов
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp

        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(weatherApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resource.qrc
        mainwindow.cpp
        countrylistmanager.h countrylistmanager.cpp
        weatherapiclient.h weatherapiclient.cpp
        weatherdataparser.h weatherdataparser.cpp
        weathericonmanager.h weathericonmanager.cpp
        instructionsdialog.h instructionsdialog.cpp instructionsdialog.ui



    )
else()
    if(ANDROID)
        add_library(weatherApp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(weatherApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Добавьте Qt Network в целевые библиотеки
target_link_libraries(weatherApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.weatherApp)
endif()
set_target_properties(weatherApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS weatherApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(weatherApp)
endif()
