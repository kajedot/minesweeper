cmake_minimum_required(VERSION 3.14)

set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

project(minesweeper)

find_package(SFML  REQUIRED graphics window system)

set(CMAKE_CXX_STANDARD 11)

add_executable(minesweeper main.cpp minesBoard.cpp minesBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h MSSFMLView.cpp MSSFMLView.h MSSFMLMenu.cpp MSSFMLMenu.h)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(minesweeper ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(minesweeper sfml-system sfml-window sfml-graphics sfml-audio)
endif()