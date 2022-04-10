cmake_minimum_required(VERSION 3.20)
project(MorzeGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(MorzeGame main.cpp Label.cpp Buttons.cpp Windows.cpp Factories.cpp )
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(SFML/include)
target_link_libraries(MorzeGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
