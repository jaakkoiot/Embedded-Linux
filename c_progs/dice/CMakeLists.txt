cmake_minimum_required(VERSION 3.22)

#if(${CMAKE_VERSION} VERSION_LESS 3.12)
#    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
#endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	#GCC OPTIONS HERE
	set(CMAKE_VERBOSE_MAKEFILE 1)
	set(C_STANDARD 17)
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS "Bits64_;UNIX;_BOOL;LINUX;FUNCPROTO;_GNU_SOURCE;LINUX_64;REQUIRE_IOSTREAM")
	set(GCC_COMPILE_OPTIONS "-m64;-fPIC;-fno-strict-aliasing;-Wall;-Wextra;-Wno-multichar;-Wno-comment;-Wno-sign-compare;-funsigned-char;-pthread;-Wno-deprecated;-Wno-reorder;-ftemplate-depth-64;-fno-gnu-keywords;-std=c17;-Winline")
	set(GCC_COMPILE_DEBUG_OPTIONS "${GCC_COMPILE_OPTIONS};-ggdb;-17")
	target_compile_options(${PROJECT_NAME} PUBLIC "$<$CONFIG:Debug>:${GCC_COMPILE_DEBUG_OPTIONS}>")
	target_compile_options(${PROJECT_NAME} PUBLIC "$<$CONFIG:Release>:${GCC_COMPILE_RELEASE_OPTIONS}>")
endif()

project(MyProject VERSION 1.0
	DESCRIPTION "Robust positive random integer generator: The RPRIG"
                  LANGUAGES C)

include_directories(
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(Dice
	inc/input_parser.h
	src/input_parser.c
	inc/dice.h
	src/dice.c
	src/main.c)


