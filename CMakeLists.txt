cmake_minimum_required(VERSION 3.10)
project(game VERSION 0.1.0 LANGUAGES CXX)

find_package(Qt5Widgets REQUIRED)

add_executable(game main.cc game.cc game.h)
target_compile_features(game PRIVATE cxx_std_11)
target_link_libraries(game PRIVATE Qt5::Widgets)
set_target_properties(game PROPERTIES AUTOMOC TRUE)
