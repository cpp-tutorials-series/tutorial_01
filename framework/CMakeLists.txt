cmake_minimum_required(VERSION 3.0.0)

#=====================================================================
# Define name and version of the project
#=====================================================================
    project(TutorialFramework VERSION 0.1.0)

#=====================================================================
# GTK3 import
#=====================================================================
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTKMM gtkmm-3.0)

    include_directories(header ${GTK3_INCLUDE_DIRS})
    link_directories(
        ${GTKMM_LIBRARY_DIRS}  )
    include_directories(
        ${GTKMM_INCLUDE_DIRS}  )

    add_definitions(${GTK3_CFLAGS_OTHER})

#=====================================================================
# QT5 import
#=====================================================================
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)

    find_package(Qt5Core REQUIRED)
    find_package(Qt5Widgets REQUIRED)

    include_directories(${Qt5Widgets_INCLUDES})
    add_definitions(${Qt5Widgets_DEFINITIONS})

    set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#=====================================================================
# Enable testing
#=====================================================================
    include(CTest)
    enable_testing()


#=====================================================================
# Add all header/source files within subdirectories
#=====================================================================
file(GLOB_RECURSE SOURCES
    header/*.h
    source/*.cpp 
)  

#=====================================================================
# Compile framework to a library
#=====================================================================
    add_library(TutorialFramework SHARED ${SOURCES})

#=====================================================================
# CPack for installer generation
#=====================================================================
    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)


target_link_libraries(TutorialFramework ${GTKMM_LIBRARIES} ${Qt5Widgets_LIBRARIES})
