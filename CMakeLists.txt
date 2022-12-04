# Instantiate Project
project(geometry-playground)

# Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Directory Setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXTERNAL_REPO_DIRECTORY ${PROJECT_SOURCE_DIR}/extern)

# Submodule Setup
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
	if(UPDATE_SUBMODULES)
		message("Submodule update")
 
		execute_process(COMMAND git submodule update --init --recursive 
			WORKING_DIRECTORY ${EXTERNAL_REPO_DIRECTORY}/glfw
			RESULT_VARIABLE GIT_SUBMODULE_RESULT)
		if(NOT GIT_SUBMODULE_RESULT EQUAL "0")
			message("Submodule update failed with code: ${GIT_SUBMODULE_RESULT}")
		endif()
	endif()
else()
	message("Must Build from within a valid Git repository to get/update submodules")
endif()

# System Configuration
message("Building on ${CMAKE_SYSTEM_NAME} system")
if(UNIX)
	add_definitions(-DLINUX_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linux)
elseif(WIN32)
	add_definitions(-DWINDOWS_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/win)
endif()

# Make Executables
add_executable(cmake_hello src/main.cpp)
