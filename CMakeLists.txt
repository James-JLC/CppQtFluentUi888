cmake_minimum_required(VERSION 3.20)

project(FluWinGallery VERSION 0.1.5 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

add_subdirectory("3rdparty")
add_subdirectory("FluControls")
add_subdirectory("FluExamples")
add_subdirectory("FluIconTool")
add_subdirectory("FluUtils")
add_subdirectory("FluWinGallery")
# add_subdirectory("res")
# add_subdirectory("StyleSheet")

install(DIRECTORY res
    DESTINATION .
)

install(DIRECTORY StyleSheet
    DESTINATION .
)

set(CPACK_SYSTEM_NAME ${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR})
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    string(APPEND CPACK_SYSTEM_NAME "-debug")
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "ZIP")
include(CPack)