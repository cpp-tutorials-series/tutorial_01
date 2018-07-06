cmake_minimum_required(VERSION 3.0.0)

#=====================================================================
# Tutorial 01
#=====================================================================
project(Tutorial01)

include_directories(${PROJECT_SOURCE_DIR}/../framework/header)

add_executable(Tutorial01 main.cpp)

target_link_libraries(Tutorial01 TutorialFramework)

install(TARGETS Tutorial01 DESTINATION bin)