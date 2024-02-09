cmake_minimum_required(VERSION 3.27)
project(sfml_4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compile commands generation option
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Set the output directory for built binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(sfml_game ./src/main.cpp)
target_include_directories(sfml_game PUBLIC /home/botondhergyo/sfml/SFML-2.6.1/include)

# Detect and add SFML
set(SFML_DIR "/home/botondhergyo/sfml/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(sfml_game PUBLIC sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
