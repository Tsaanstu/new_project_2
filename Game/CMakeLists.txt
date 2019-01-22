cmake_minimum_required(VERSION 3.10)
project(new_strategy_1)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -DCMAKE_OSX_ARCHITECTURES")

set(PROJECT_SOURCE_FILES project/src/allomant.cpp project/src/allomantic_power.cpp project/src/being.cpp
        project/src/cell.cpp project/src/field.cpp project/src/game.cpp project/src/graphics.cpp
        project/src/item.cpp project/src/main.cpp project/src/menu.cpp project/src/metal.cpp
        project/src/mistborn.cpp project/src/misting.cpp project/src/object.cpp project/src/page.cpp
        project/src/player.cpp project/src/soldier.cpp project/src/store.cpp project/src/tab.cpp project/src/ui.cpp
        project/src/button.cpp
        )

set(GRAPHIC_WRAP_SOURCE_FILES graphic_wrap/src/color.cpp graphic_wrap/src/contextsettings.cpp graphic_wrap/src/event.cpp
        graphic_wrap/src/image.cpp graphic_wrap/src/rect.cpp graphic_wrap/src/string.cpp
        graphic_wrap/src/system.cpp graphic_wrap/src/vector2.cpp graphic_wrap/src/videomode.cpp
        graphic_wrap/src/window.cpp)

include_directories(project/include graphic_wrap/include)

add_executable(new_strategy_1 ${PROJECT_SOURCE_FILES} ${GRAPHIC_WRAP_SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(new_strategy_1 ${SFML_LIBRARIES})
endif()

set(BOOST_ROOT "/usr/local/Cellar/boost@1.60/1.60.0")

find_package(Boost 1.60.0 COMPONENTS system filesystem REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

include_directories(${Boost_INCLUDE_DIRS})

message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

# FOR BOOST TO WORK IN CLION ON MAC DO:
# 1. $ brew install boost@1.60
# 2. check whether you have CMake version 3.10 or newer (but newer is not allowed in CLion)
# 3. C++ 17 required