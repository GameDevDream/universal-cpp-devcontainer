cmake_minimum_required( VERSION 3.23.0 )

project( advanced_example_lib VERSION 1.0.0 )

add_library( advanced_lib INTERFACE )

target_include_directories(
  advanced_lib

  INTERFACE
    include/
)
