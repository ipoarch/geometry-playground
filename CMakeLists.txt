project(geometry-playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message("Building on ${CMAKE_SYSTEM_NAME} system")
if(UNIX)
	add_definitions(-DLINUX_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linux)
elseif(WIN32)
	add_definitions(-DWINDOWS_BUILD)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/win)
endif()

add_executable(cmake_hello src/main.cpp)


