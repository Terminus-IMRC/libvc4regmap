# For CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT
cmake_minimum_required(VERSION 3.7.2)

project(libvc4regmap)
include(CTest)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_CONTACT "Sugizaki Yukimasa <ysugi@idein.jp>")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
        "A library for accessing peripherals on Raspberry Pi")

# See https://semver.org/ and https://www.pakin.org/~scott/ltver.html .
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 1)

# CMAKE_INSTALL_PREFIX and CPACK_PACKAGING_INSTALL_PREFIX must be identical
# because the install prefix is used in the pkg-config file which will be
# auto-generated.
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "/usr" CACHE PATH "Install prefix" FORCE)
endif ()
set(CPACK_PACKAGING_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")
message(STATUS "Install prefix is set to ${CMAKE_INSTALL_PREFIX}")
include(CPack)

find_package(PkgConfig)

pkg_check_modules(BCM_HOST bcm_host=1)
if (NOT BCM_HOST_FOUND)
    message(STATUS "Adding /opt/vc/lib/pkgconfig to PKG_CONFIG_PATH")
    set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/opt/vc/lib/pkgconfig")
    pkg_check_modules(BCM_HOST bcm_host=1)
    if (NOT BCM_HOST_FOUND)
        message (FATAL_ERROR "bcm_host not found even in /opt/vc/lib. "
                             "Building on non-RPi host? "
                             "Please specify PKG_CONFIG_PATH.")
    endif ()
endif ()

add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)
add_subdirectory(example)

configure_file(libvc4regmap.pc.in libvc4regmap.pc @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/libvc4regmap.pc"
        DESTINATION lib/pkgconfig)
