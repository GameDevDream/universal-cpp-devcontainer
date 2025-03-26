cmake_minimum_required( VERSION 3.23.0 )

project( advanced_example_test VERSION 1.0.0 )

add_executable( test_advanced )

target_sources(
  test_advanced

  PRIVATE FILE_SET HEADERS
    BASE_DIRS
      src/   # private local headers here
    FILES
      src/array_to_string.hpp
      src/trackers.hpp

  PRIVATE
    src/main.cpp
    src/trackers.cpp
)

target_link_libraries(
  test_advanced

  PRIVATE
    advanced_lib
)
