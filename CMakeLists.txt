set(PROJECT_NAME MED-project)

cmake_minimum_required(VERSION 3.0.0)
project(${PROJECT_NAME} VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(CMAKE_CXX_STANDARD 20)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SOURCES "main.cpp" "src/*.cpp" "src/dataset/*.cpp" "src/exceptions/*.cpp" "src/grouping/*.cpp" "src/metrics/*.cpp" "src/rating/*.cpp" "src/output/*.cpp")

include_directories("./include" "./include/dataset" "./include/exceptions" "./include/grouping")

add_subdirectory(tests)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE)
target_link_libraries(
    ${PROJECT_NAME} 
    GTest::gtest_main
)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
include(GoogleTest)