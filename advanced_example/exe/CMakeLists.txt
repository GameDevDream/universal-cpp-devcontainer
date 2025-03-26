cmake_minimum_required( VERSION 3.23.0 )

project( advanced_example VERSION 1.0.0 )

add_executable( advanced )

target_sources(
  advanced

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
  advanced

  PRIVATE
    advanced_lib
)
