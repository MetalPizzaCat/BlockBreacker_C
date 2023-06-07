cmake_minimum_required(VERSION 3.0.0)
project(block_breaker VERSION 0.1.0 LANGUAGES C)

add_compile_definitions(DEFAULT_WINDOW_WIDTH=800)
add_compile_definitions(DEFAULT_WINDOW_HEIGHT=600)
add_compile_definitions(BLOCK_COUNT_VERTICAL=4)
add_compile_definitions(BLOCK_COUNT_HORIZONTAL=15)
add_compile_definitions(BLOCK_COUNT_TOTAL=BLOCK_COUNT_VERTICAL*BLOCK_COUNT_HORIZONTAL)
add_compile_definitions(BLOCK_INNER_COLOR_SIZE_PERCENT=0.9f)
add_compile_definitions(BLOCK_SIZE_RATIO=1.f/5.f)

find_package(SDL2 REQUIRED)
include_directories(block_breaker ${SDL2_INCLUDE_DIRS})
add_executable(block_breaker main.c window.h window.c block.h block.c ball.h ball.c geometry.h geometry.c color.h color.c game.h game.c)
target_link_libraries(block_breaker ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
