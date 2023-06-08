cmake_minimum_required(VERSION 3.0.0)
project(block_breaker VERSION 0.1.0 LANGUAGES C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(GAME_FAIL_SOUND audio/fail1.wav)
set(GAME_HIT_SOUND audio/hit_soft1.wav)
set(GAME_DESTRUCTION_SOUND audio/hit1.wav)
set(GAME_WIN_SOUND audio/hit1.wav)

option(USE_MAP_LOADING "Enable map loading(using a 64 bit integer to load map layout)" OFF)

if(USE_MAP_LOADING)
    add_compile_definitions(ENABLE_MAP_LOADING)
endif()

add_compile_definitions(DEFAULT_WINDOW_WIDTH=800)
add_compile_definitions(DEFAULT_WINDOW_HEIGHT=600)
add_compile_definitions(BLOCK_COUNT_VERTICAL=4)
add_compile_definitions(BLOCK_COUNT_HORIZONTAL=15)
add_compile_definitions(BLOCK_COUNT_TOTAL=BLOCK_COUNT_VERTICAL*BLOCK_COUNT_HORIZONTAL)
add_compile_definitions(BLOCK_INNER_COLOR_SIZE_PERCENT=0.9f)
add_compile_definitions(BLOCK_SIZE_RATIO=1.f/5.f)

add_compile_definitions(GAME_FAIL_SOUND_PATH="${GAME_FAIL_SOUND}")
add_compile_definitions(GAME_HIT_SOUND_PATH="${GAME_HIT_SOUND}")
add_compile_definitions(GAME_DESTRUCTION_SOUND_PATH="${GAME_DESTRUCTION_SOUND}")
add_compile_definitions(GAME_WIN_SOUND_PATH="${GAME_DESTRUCTION_SOUND}")


find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
include_directories(block_breaker ${SDL2_INCLUDE_DIRS})
add_executable(block_breaker 
                main.c
                window.h window.c 
                block.h block.c 
                ball.h ball.c 
                geometry.h geometry.c 
                color.h color.c 
                game.h game.c 
                keyhandler.h keyhandler.c
                audio.h audio.c
                )
target_link_libraries(block_breaker ${SDL2_LIBRARIES} SDL2::Mixer)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# copy audio files into final build
configure_file(${GAME_FAIL_SOUND} ${GAME_FAIL_SOUND} COPYONLY)
configure_file(${GAME_HIT_SOUND} ${GAME_HIT_SOUND} COPYONLY)
configure_file(${GAME_DESTRUCTION_SOUND} ${GAME_DESTRUCTION_SOUND} COPYONLY)
configure_file(${GAME_WIN_SOUND} ${GAME_WIN_SOUND} COPYONLY)