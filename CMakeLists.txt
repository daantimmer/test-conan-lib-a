cmake_minimum_required(VERSION 3.15)

project(conan-library-a VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTING "Build tests" OFF)

find_package(nlohmann_json REQUIRED)

add_library(conan-library-a
    src/sum.cpp
)

add_library(conan-library-a::conan-library-a ALIAS conan-library-a)

target_include_directories(conan-library-a
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(conan-library-a
    PUBLIC
        nlohmann_json::nlohmann_json
)

target_compile_features(conan-library-a PUBLIC cxx_std_17)

if(BUILD_TESTING)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS conan-library-a
    EXPORT conan-library-a-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT conan-library-a-targets
    FILE conan-library-a-targets.cmake
    NAMESPACE conan-library-a::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/conan-library-a
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/conan-library-a-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/conan-library-a-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/conan-library-a
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/conan-library-a-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/conan-library-a-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/conan-library-a-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/conan-library-a
)
