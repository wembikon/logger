cmake_minimum_required(VERSION 3.1)

project(basic_test)
set(TARGET a.out)
set(CMAKE_CXX_STANDARD 17)

set(PROJECTS_ROOT_DIR ${PROJECT_SOURCE_DIR}/../..)

include_directories(
  ${PROJECTS_ROOT_DIR}/detail)

set(SRCS
    ${PROJECTS_ROOT_DIR}/detail/jamo/console_logger.cpp
    ${PROJECTS_ROOT_DIR}/detail/jamo/file_logger.cpp
    ${PROJECTS_ROOT_DIR}/detail/jamo/network_logger.cpp
    main.cpp)

add_executable(${TARGET} ${SRCS})
target_compile_options(${TARGET} PUBLIC -fno-rtti -g -Wall)
target_link_libraries(${TARGET} pthread)