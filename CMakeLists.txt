cmake_minimum_required(VERSION 3.15)

set(shenprintf_VERSION 1.0.1)

project(shenprintf
	VERSION ${shenprintf_VERSION}
	DESCRIPTION "A sample C++ library"
	HOMEPAGE_URL "https://github.com/shenyanbin1021/shenprintf"
	LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)


add_library(shenprintf src/shenprintf.cpp include/shenprintf.h)
add_library(shenprintf::shenprintf ALIAS shenprintf)

if(BUILD_SHARED_LIBS AND WIN32)
	target_compile_definitions(shenprintf
		PRIVATE "SHENPRINTF_EXPORT=__declspec(dllexport)"
		INTERFACE "SHENPRINTF_EXPORT=__declspec(dllimport)")
endif()

target_compile_features(shenprintf PUBLIC cxx_std_17)
target_include_directories(shenprintf
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)


configure_package_config_file(cmake/config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/shenprintf-config.cmake
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATADIR}/shenprintf
	NO_SET_AND_CHECK_MACRO)
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/shenprintf-config-version.cmake
	VERSION ${shenprintf_VERSION}
	COMPATIBILITY SameMajorVersion)
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/shenprintf-config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/shenprintf-config-version.cmake
	DESTINATION
		${CMAKE_INSTALL_DATADIR}/shenprintf)

install(TARGETS shenprintf EXPORT shenprintf-targets)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT shenprintf-targets
	NAMESPACE shenprintf::
	DESTINATION ${CMAKE_INSTALL_DATADIR}/shenprintf)
