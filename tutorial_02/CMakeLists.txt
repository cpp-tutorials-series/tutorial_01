cmake_minimum_required(VERSION 3.0.0)

#=====================================================================
# Tutorial 02
#=====================================================================
project(Tutorial02)

include_directories(${PROJECT_SOURCE_DIR}/../framework/header)
include_directories(${PROJECT_SOURCE_DIR}/header)

#=====================================================================
# Add all header/source files within subdirectories
#=====================================================================
file(GLOB_RECURSE SOURCES
    header/*.h
    source/*.cpp 
)  

add_executable(Tutorial02 ${SOURCES})

target_link_libraries(Tutorial02 TutorialFramework)

install(TARGETS Tutorial02 DESTINATION bin)