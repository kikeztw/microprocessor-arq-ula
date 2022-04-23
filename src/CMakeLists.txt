# check cmake version required
cmake_minimum_required(VERSION 3.5)

project(microprocessor CXX)

include(CTest)
set(CMAKE_PREFIX_PATH /usr/local/systemc-2.3.3)
find_library(systemc systemc ${CMAKE_PREFIX_PATH}/lib-linux64)
link_directories(${CMAKE_PREFIX_PATH}/lib-linux64)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(cv)
  set(CMAKE_CXX_STANDARD 17)
  # set(CMAKE_PREFIX_PATH $ENV{SYSTEMC_HOME})
  # find_package(SystemCLanguage CONFIG REQUIRED)

endif()

include_directories(
  /
  modules/
  phases/
  utils/
)

# set(HEADER_GATES ${CMAKE_SOURCE_DIR}/gates/includes)
# set(HEADER_TEST_BENCH ${CMAKE_SOURCE_DIR}/test_bench/includes)

add_subdirectory(modules)
add_subdirectory(phases)
add_subdirectory(utils)
add_subdirectory(tests)

add_executable(
  ${PROJECT_NAME}.run
  main.cpp datapath.cpp
)

target_link_libraries(
  ${PROJECT_NAME}.run
  PUBLIC systemc
  PUBLIC A_UTILITY_FILES
  PUBLIC A_MODULES_PHASE_ONE
  PUBLIC A_PHASES
  # PRIVATE SystemCLanguage
)

# set_property(
#   TARGET ${PROJECT_NAME}.run
#   PROPERTY CXX_STANDARD ${SystemC_CXX_STANDARD}
# )

add_test(
  NAME ${PROJECT_NAME}
  COMMAND ./${PROJECT_NAME}.run
  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
