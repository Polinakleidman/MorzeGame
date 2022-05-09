cmake_minimum_required(VERSION 3.20)
project(MorzeGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(MorzeGame main.cpp Label.cpp Buttons.cpp Windows/Windows.cpp Factories/MenuFactory.h Factories/MorzeFactory.h Factories/LevelListFactory.h Factories/GameProcessFactory.h Factories/GameCheckedFactory.h Factories/MenuFactory.cpp Factories/MorzeFactory.cpp Factories/LevelListFactory.cpp Factories/GameProcessFactory.cpp Factories/GameCheckedFactory.cpp Windows/MenuWindow.h Windows/AlphabetWindow.h Windows/AllLevelsWindow.h Windows/MenuWindow.cpp Windows/AlphabetWindow.cpp Windows/AllLevelsWindow.cpp Windows/GameWindows.cpp Windows/GameWindows.h)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(SFML/include)
target_link_libraries(MorzeGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
