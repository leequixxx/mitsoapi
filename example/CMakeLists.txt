cmake_minimum_required(VERSION 3.15)

project(mitsoapi_example C)

set(CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} src/main.c src/fetch_and_parse_html.c)
target_link_libraries(${PROJECT_NAME} PRIVATE mitsoapi gumbo)
