cmake_minimum_required(VERSION 3.27)
project(sfml_4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(sfml_game ./src/main.cpp)
target_include_directories(sfml_game PUBLIC /home/botondhergyo/sfml/SFML-2.6.1/include)

# Detect and add SFML
set(SFML_DIR "/home/botondhergyo/sfml/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(sfml_game PUBLIC sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
