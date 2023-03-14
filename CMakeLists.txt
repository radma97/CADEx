cmake_minimum_required(VERSION 3.15)
project(test_task_project LANGUAGES CXX)

# подключаем OpenMP
include(FindOpenMP)
if(OPENMP_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif(OPENMP_FOUND)

set(CMAKE_CXX_STANDARD 17)

# путь к папке с исходным кодом
set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)

# заполняем список файлов: все файлы с расширениями h и hpp
file(GLOB HEADERS_LIST "${SOURCES_DIR}/*.h" "${SOURCES_DIR}/*.hpp")

# заполняем список файлов: все файлы с расширениями c и cpp
file(GLOB SOURCES_LIST "${SOURCES_DIR}/*.c" "${SOURCES_DIR}/*.cpp")

add_executable(test_task ${HEADERS_LIST} ${SOURCES_LIST})
