cmake_minimum_required(VERSION 3.5)

# Project settings
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ".")
set(PROJECT_UNIT_TESTS_NAME ${PROJECT_NAME}_unit_tests)

# Dependencies
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Gather the header and source files
file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/tests/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp ${PROJECT_SOURCE_DIR}/tests/dataset/*.cpp ${PROJECT_SOURCE_DIR}/tests/grouping/*.cpp ${PROJECT_SOURCE_DIR}/tests/metrics/*.cpp ${PROJECT_SOURCE_DIR}/tests/rating/*.cpp ${PROJECT_SOURCE_DIR}/tests/output/*.cpp)

# Include paths
set(UNIT_TESTS_INCLUDES ${PROJECT_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/dataset)

file(GLOB SOURCES "../src/*.cpp" "../src/dataset/*.cpp" "../src/exceptions/*.cpp" "../src/grouping/*.cpp" "../src/metrics/*.cpp" "../src/rating/*.cpp" "../src/output/*.cpp")

# Assign the include directories
include_directories(${UNIT_TESTS_INCLUDES})


#add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} $<TARGET_OBJECTS:demo_objects> )
add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES} ${SRC_FILES} ${SOURCES})
target_link_libraries(
        ${PROJECT_UNIT_TESTS_NAME}
        GTest::gtest_main
)
include(GoogleTest)

enable_testing()
add_test(DemoTest ${PROJECT_UNIT_TESTS_NAME})

gtest_discover_tests(${PROJECT_UNIT_TESTS_NAME})





