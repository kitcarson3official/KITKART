cmake_minimum_required(VERSION 3.10)

project(KITKART LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(LIBKK_SOURCES
    lin_alg.cpp     lin_alg.h
    car.cpp         car.h
    track.cpp       track.h)

list(TRANSFORM LIBKK_SOURCES PREPEND "libkk/")
add_library(libkk ${LIBKK_SOURCES})

add_executable(test     test/main.cpp)
target_include_directories(test PRIVATE "libkk" ${INCLUDE_DIR})
target_link_directories(test PRIVATE ${LIBS_DIR})
target_link_libraries(test PRIVATE libkk sfml-graphics sfml-window sfml-system)

add_executable(game
    SRC/kart.cpp SRC/kart.h
    SRC/main.cpp)
target_include_directories(game PUBLIC "libkk" PUBLIC PUBLIC ${INCLUDE_DIR})
target_link_directories(game PUBLIC PUBLIC ${LIBS_DIR})
target_link_libraries(game PUBLIC libkk sfml-graphics sfml-window sfml-system)