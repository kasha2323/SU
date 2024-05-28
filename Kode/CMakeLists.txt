cmake_minimum_required(VERSION 3.5)

project(Kode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 REQUIRED COMPONENTS Quick Sql)
if(NOT Qt5_FOUND)
    message(FATAL_ERROR "Qt5 not found! Please install Qt5.")
endif()

add_executable(Kode main.cpp
    hero.h hero.cpp
    enemy.h enemy.cpp
    diverse.h diverse.cpp
    cave.h cave.cpp)

target_link_libraries(Kode Qt5::Sql Qt5::Quick)


include(GNUInstallDirs)
install(TARGETS Kode
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
