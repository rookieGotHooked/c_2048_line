cmake_minimum_required(VERSION 3.31)
project(C_2048 C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

function(include_dependency libname gitURL gitTag)

    FetchContent_Declare(${libname}
            GIT_REPOSITORY  ${gitURL}
            GIT_TAG         ${gitTag}
            GIT_SHALLOW     TRUE
            GIT_PROGRESS    TRUE
    )

    FetchContent_MakeAvailable(${libname})
endfunction()

find_package(SDL3 QUIET)
if (NOT SDL3_FOUND)
    include_dependency(SDL3 https://github.com/libsdl-org/SDL.git release-3.2.20)
endif()

add_executable(C_2048 main.c
        SDL_drawing_utilities.h
        SDL_drawing_utilities.c
        board_handling.c
        board_handling.h
        ikoniq_utilities.c
        ikoniq_utilities.h
)

target_include_directories(C_2048 PUBLIC ${SDL3_INCLUDE_DIRS})

target_compile_definitions(C_2048 PRIVATE SDL_MAIN_USE_CALLBACKS)

target_link_libraries(C_2048 PRIVATE SDL3::SDL3)

if (WIN32)
    add_custom_command(
            TARGET C_2048 POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL3::SDL3>" "$<TARGET_FILE_DIR:C_2048>"
            VERBATIM
    )
endif ()