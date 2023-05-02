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
  # ${CMAKE_CURRENT_SOURCE_DIR}/car
)

set(HEADERS
)

set(SOURCES
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