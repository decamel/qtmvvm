cmake_minimum_required (VERSION 3.13.0)
project(qtmvvm_iface VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Don't use GNU extensions
set(CMAKE_CXX_EXTENSIONS OFF)
message(STATUS "Setting minimum C++ standard to C++17")

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)


set(CMAKE_VERIFY_INTERFACE_HEADER_SETS ON)
add_subdirectory(include)

include(cmake/createcmakeconfig.cmake)