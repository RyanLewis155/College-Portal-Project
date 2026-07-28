cmake_minimum_required(VERSION 3.16)

project(College-Portal-Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

set(PROJECT_SOURCES
    main.cpp
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(College-Portal-Project
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    loginwindow.h loginwindow.cpp loginwindow.ui

    mainwindow.h mainwindow.cpp mainwindow.ui
    studentdisplay.h studentdisplay.cpp studentdisplay.ui
    resources.qrc
    classscheduleitem.h classscheduleitem.cpp classscheduleitem.ui
    course.h
    section.h section.cpp
    room.h
    schedule.h schedule.cpp
    user.h user.cpp
    studentregistrationform.h studentregistrationform.cpp studentregistrationform.ui
    viewplanform.h viewplanform.cpp viewplanform.ui
    queryparams.h
    database.h
    database.cpp
    professordisplay.h professordisplay.cpp professordisplay.ui
    administratordisplay.h administratordisplay.cpp administratordisplay.ui
    coursesection.h coursesection.cpp
    userinfo.h







)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET College-Portal-Project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
if(ANDROID)
    add_library(College-Portal-Project SHARED
        ${PROJECT_SOURCES}
    )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(College-Portal-Project
        ${PROJECT_SOURCES}
    )
endif()
endif()

# target_link_libraries(College-Portal-Project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(College-Portal-Project
PRIVATE
Qt6::Core
Qt6::Gui
Qt6::Widgets
Qt6::Network
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.College-Portal-Project)
endif()
set_target_properties(College-Portal-Project PROPERTIES
${BUNDLE_ID_OPTION}
MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
MACOSX_BUNDLE TRUE
WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS College-Portal-Project
BUNDLE DESTINATION .
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
qt_finalize_executable(College-Portal-Project)
endif()
