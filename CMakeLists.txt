cmake_minimum_required(VERSION 3.15)
project(mitsoapi C)

set(CMAKE_C_STANDARD 99)

add_library(${PROJECT_NAME} SHARED src/core/http/fetch/fetch_and_parse_html.c src/mitsoapi.c src/mitsoapi_structure.c)
include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} PRIVATE curl gumbo)

add_subdirectory(example)
