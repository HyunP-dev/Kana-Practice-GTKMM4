cmake_minimum_required(VERSION 3.23)
project(Kana_Practice)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK4MM REQUIRED gtkmm-4.0)
include_directories(${GTK4MM_INCLUDE_DIRS})
link_directories(${GTK4MM_LIBRARY_DIRS})
add_definitions(${GTK4MM_CFLAGS_OTHER})

add_executable(Kana_Practice main.cpp MyWindow.cpp MyWindow.h Kana.cpp Kana.h)
target_link_libraries(Kana_Practice ${GTK4MM_LIBRARIES})