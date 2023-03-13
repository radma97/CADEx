cmake_minimum_required(VERSION 3.15)
project(test_task_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# путь к папке с исходным кодом
set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)

# заполняем список файлов: все файлы с расширениями h и hpp
file(GLOB HEADERS_LIST "${SOURCES_DIR}/*.h" "${SOURCES_DIR}/*.hpp")

# заполняем список файлов: все файлы с расширениями c и cpp
file(GLOB SOURCES_LIST "${SOURCES_DIR}/*.c" "${SOURCES_DIR}/*.cpp")

add_executable(test_task ${HEADERS_LIST} ${SOURCES_LIST})
