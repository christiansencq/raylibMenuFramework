cmake_minimum_required(VERSION 3.16)
project(state_stack VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

#Build Type Options.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "DEBUG")
    message(STATUS "[CMAKE] Build Type Not specified, building debug as default.")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE EQUAL "RELEASE")
    message("Building in Release Mode.")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/release)
endif (CMAKE_BUILD_TYPE EQUAL "RELEASE")

#FetchContent helps find external libraries
include(FetchContent)
#Dont build supplied examples & example games
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

# Disable the creation of compiler and interpreter targets for Lua
set(LUA_BUILD_COMPILER OFF CACHE INTERNAL "")
set(LUA_BUILD_INTERPRETER OFF CACHE INTERNAL "")

#Fetch Libraries! 

FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_Declare(lua GIT_REPOSITORY "https://github.com/marovira/lua" GIT_TAG master )
FetchContent_Declare(sol2 GIT_REPOSITORY "https://github.com/ThePhD/sol2.git" GIT_TAG develop)
FetchContent_Declare(plog GIT_REPOSITORY "https://github.com/SergiusTheBest/plog" GIT_TAG master)

#MakeAvailable ensures that the named dependencies have been populated, 
#Might be populated by an earlier call or by this command itself.
FetchContent_MakeAvailable(raylib lua sol2 plog)

#Adding source files.

# Define PROJECT_SOURCES variable as the list of all source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/**.cpp")
#Define PROJECT_INCLUDE to be the path to our project's include directory
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/") 

#Declare Executable

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
#Use the PROJECT_SOURCES to build the PROJECT_NAME executable
#target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib 
                                              lua 
                                              sol2
                                              plog)

target_compile_options(${PROJECT_NAME} PRIVATE "-ggdb" 
                                               "-Wall" 
                                               "-Wpedantic" 
                                               "-Wextra" 
                                               "-Wno-unused-parameter" )
#Setting the ASSETS_PATH

#Set the asset path macro to the absolute path on the dev machine
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

