cmake_minimum_required(VERSION 3.5)

project(Geometry)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
)

set(HEADERS
  primitive/primitive.h
  line/line.h
  circle/circle.h
  rectangle/rectangle.h
  square/square.h
  triangle/triangle.h
)

set(SOURCES
  primitive/primitive.cc
  line/line.cc
  circle/circle.cc
  rectangle/rectangle.cc
  square/square.cc
  triangle/triangle.cc
)

add_executable(${PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
  main.cc
)

set_target_properties(sfml-graphics PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
set_target_properties(sfml-window PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
set_target_properties(sfml-system PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
set_target_properties(sfml-audio PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)

# Подключаем библиотеки SFML
target_link_libraries(${PROJECT_NAME}
  sfml-graphics
  sfml-window
  sfml-system
)