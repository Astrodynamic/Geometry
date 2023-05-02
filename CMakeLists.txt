cmake_minimum_required(VERSION 3.5)

project(Geometry)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Указываем версию SFML, которую хотим использовать
set(SFML_VERSION 2.5.1)

# Загружаем исходный код SFML из репозитория на GitHub
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG ${SFML_VERSION}
)

# Компилируем SFML
FetchContent_MakeAvailable(SFML)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/primitive
  ${CMAKE_CURRENT_SOURCE_DIR}/line
  ${CMAKE_CURRENT_SOURCE_DIR}/circle
  ${CMAKE_CURRENT_SOURCE_DIR}/rectangle
  ${CMAKE_CURRENT_SOURCE_DIR}/square
  ${CMAKE_CURRENT_SOURCE_DIR}/triangle
  ${CMAKE_CURRENT_SOURCE_DIR}/rhombus
)

set(HEADERS
  primitive/primitive.h
  line/line.h
  circle/circle.h
  rectangle/rectangle.h
  square/square.h
  triangle/triangle.h
  rhombus/rhombus.h
)

set(SOURCES
  primitive/primitive.cc
  line/line.cc
  circle/circle.cc
  rectangle/rectangle.cc
  square/square.cc
  triangle/triangle.cc
  rhombus/rhombus.cc
)

add_executable(${PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
  main.cc
)

# Подключаем библиотеки SFML
target_link_libraries(${PROJECT_NAME}
  sfml-graphics
  sfml-window
  sfml-system
)