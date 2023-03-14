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

# заполняем список библиотечных файлов: все файлы с расширениями h и hpp
file(GLOB LIB_HEADERS_LIST "${SOURCES_DIR}/lib/include/*.h" "${SOURCES_DIR}/lib/include/*.hpp")

# заполняем список библиотечных файлов: все файлы с расширениями c и cpp
file(GLOB LIB_SOURCES_LIST "${SOURCES_DIR}/lib/src/*.c" "${SOURCES_DIR}/lib/src/*.cpp")

# расположение заголовочных файлов библиотеки
include_directories(${SOURCES_DIR}/lib/include)

add_executable(test_task ${HEADERS_LIST} ${SOURCES_LIST})

# включение экспорта всех символов для создания динамической библиотеки
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

# добавление библиотеки
add_library(cur3d SHARED ${LIB_HEADERS_LIST} ${LIB_SOURCES_LIST})

# линковка программы с библиотекой
target_link_libraries(test_task cur3d)
