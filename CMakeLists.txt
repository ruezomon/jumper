cmake_minimum_required(VERSION 3.17)
project(jumper VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_CURRENT_SOURCE_DIR}/bin
)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

include_directories(include)

file(GLOB SRC "src/*.cpp")
add_executable(jumper ${SRC})

target_include_directories(jumper PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(jumper PRIVATE 
	SFML::Graphics
	SFML::Window
	SFML::System
)