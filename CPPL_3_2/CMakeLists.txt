cmake_minimum_required (VERSION 3.8)

project ("CPPL_3_2")

add_executable (CPPL_3_2 "CPPL_3_2.cpp"  "Exception.cpp" "Exception.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPPL_3_2 PROPERTY CXX_STANDARD 20)
endif()

