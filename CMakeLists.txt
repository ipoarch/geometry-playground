# CMake Req
cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0003 NEW)
cmake_policy(SET CMP0048 NEW)

# Instantiate Project
project(geometry-playground)

# Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Directory Setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXTERNAL_REPO_DIRECTORY ${PROJECT_SOURCE_DIR}/extern)

# Submodule Setup
set(UPDATE_SUBMODULES 1)
if(UPDATE_SUBMODULES)
	message("Submodule update")

	find_package(Git REQUIRED)
	if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
		execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive 
			WORKING_DIRECTORY ${EXTERNAL_REPO_DIRECTORY}/glfw
			RESULT_VARIABLE GIT_SUBMODULE_RESULT)
		if(NOT GIT_SUBMODULE_RESULT EQUAL "0")
			message("Submodule update failed with code: ${GIT_SUBMODULE_RESULT}")
		endif()
	else()
		message("Must Build from within a valid Git repository to get/update submodules")
	endif()
endif()

# Library Setup
message("Library setup")

# Vulkan
if(MSVC OR WIN32)
	set(VULKAN_INSTALL_DIR "C:/VulkanSDK/1.3.231.1")
	set(ENV{VULKAN_SDK} "${VULKAN_INSTALL_DIR}")
	include_directories("${VULKAN_INSTALL_DIR}/Include")
endif()
find_package(Vulkan REQUIRED)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
add_subdirectory(${EXTERNAL_REPO_DIRECTORY}/glfw)
include_directories(${EXTERNAL_REPO_DIRECTORY}/glfw/include)

# System Configuration
message("Building on ${CMAKE_SYSTEM_NAME} system")
if(UNIX)
	add_definitions(-DLINUX_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linux)
elseif(MSVC OR WIN32)
	add_definitions(-DWINDOWS_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/win)
endif()

# Make Executables
add_executable(cmake_hello src/main.cpp)

target_link_libraries(cmake_hello glfw ${Vulkan_LIBRARIES})
