cmake_minimum_required(VERSION 3.20)
project(MorzeGame)

include(FetchContent)
set(CMAKE_CXX_STANDARD 14)
set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(MorzeGame main.cpp Label.cpp Buttons.cpp Windows/Windows.cpp Factories/MenuFactory.cpp Factories/MorzeFactory.cpp Factories/LevelListFactory.cpp Factories/GameProcessFactory.cpp Factories/GameCheckedFactory.cpp Windows/MenuWindow.cpp Windows/AlphabetWindow.cpp Windows/AllLevelsWindow.cpp Windows/GameWindows.cpp )


#include_directories(SFML/include)
target_link_libraries(MorzeGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
