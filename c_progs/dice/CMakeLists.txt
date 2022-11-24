cmake_minimum_required(VERSION 3.1)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(MyProject VERSION 1.0
	DESCRIPTION "Robust positive random integer generator: The RPRIG"
                  LANGUAGES C)

include_directories(
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(Dice
	input_parser.h
	input_parser.c
	dice.h
	dice.c
	main.c)


