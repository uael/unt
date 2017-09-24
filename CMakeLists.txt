cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

if (NOT EXISTS ${CMAKE_CACHEFILE_DIR}/cmake)
  execute_process(
    COMMAND git clone https://github.com/uael/cmake-modules.git cmake
    RESULT_VARIABLE result OUTPUT_QUIET
    WORKING_DIRECTORY ${CMAKE_CACHEFILE_DIR}
  )
endif ()

set(CMAKE_MODULE_PATH "${CMAKE_CACHEFILE_DIR}/cmake")
include(ProjectDependency)

project(unt C)
project_dependency(uty GIT_REPOSITORY https://github.com/uael/uty.git)

set(unt_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(unt_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(unt_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

file(GLOB_RECURSE unt_SRCS ${unt_SRCS} ${unt_SRC_DIR}/*.c)
file(GLOB_RECURSE unt_HDRS ${unt_HDRS} ${unt_INC_DIR}/unt/*.h)
set(unt_HDR ${unt_INC_DIR}/unt.h)

add_library(unt ${unt_SRCS} ${unt_HDRS} ${unt_HDR})
target_include_directories(unt PUBLIC ${unt_INC_DIR})
target_link_libraries(unt PUBLIC uty)

get_directory_property(unt_PARENT PARENT_DIRECTORY)
if (NOT ${unt_PARENT})
  set(unt_DEVEL TRUE)
elseif (NOT ${unt_DEVEL})
  set(unt_DEVEL FALSE)
endif ()
if (${unt_DEVEL} AND EXISTS ${unt_TEST_DIR})
  project_dependency(cute GIT_REPOSITORY https://github.com/uael/cute.git)
  if (NOT unt_PARENT)
    enable_testing()
  endif ()

  file(GLOB unt_TEST_SRCS ${unt_TEST_SRCS} ${unt_TEST_DIR}/*.c)
  foreach (unt_TEST_SRC ${unt_TEST_SRCS})
    get_filename_component(unt_TEST_NAME ${unt_TEST_SRC} NAME_WE)
    add_executable(test_${unt_TEST_NAME} ${unt_TEST_SRC})
    add_dependencies(test_${unt_TEST_NAME} unt cute)
    target_link_libraries(test_${unt_TEST_NAME} unt cute)
    add_test(${unt_TEST_NAME} test_${unt_TEST_NAME})
  endforeach ()
endif ()

install(FILES ${unt_HDRS}
  DESTINATION include/unt)
install(FILES ${unt_HDR}
  DESTINATION include)