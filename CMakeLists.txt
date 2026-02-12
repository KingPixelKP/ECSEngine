cmake_minimum_required(VERSION 4.1.2)

#set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CONFIGURATION_TYPES Debug)

project(ecs)

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)


FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(raylib)


file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/ecs/*.cpp")
file(GLOB DEFAULT_COMP "${CMAKE_SOURCE_DIR}/default_components/*.cpp")
file(GLOB DEFAULT_SYS "${CMAKE_SOURCE_DIR}/default_systems/*.cpp")


add_executable(${PROJECT_NAME} user.cpp ${SRC_FILES} ${DEFAULT_COMP} ${DEFAULT_SYS})
target_link_libraries(${PROJECT_NAME} raylib)




