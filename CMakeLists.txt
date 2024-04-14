cmake_minimum_required(VERSION 3.10)
project(lvgl-demo C)

# Select underlying LCGL display driver (SDL2 || X11)
set(LV_DRIVER X11)
#set(LV_DRIVER SDL2)

set(PROJECT_NAME lvgl-demo)
set(WORKING_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${WORKING_DIR}/obj)
set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(UI_DIR ui)


# Compiler settings
set(CMAKE_C_COMPILER gcc)

# Compiler flags
add_compile_options(
    -O0
    -g
    -Wall
    -Wextra
    -Wshadow
    -Wundef
    -Wmaybe-uninitialized
    -Wmissing-prototypes
    -Wno-discarded-qualifiers
    -Wno-unused-function
    -Wno-error=strict-prototypes
    -Wpointer-arith
    -fno-strict-aliasing
    -Wno-error=cpp
    -Wuninitialized
    -Wno-unused-parameter
    -Wno-missing-field-initializers
    -Wno-format-nonliteral
    -Wno-cast-qual
    -Wunreachable-code
    -Wno-switch-default
    -Wreturn-type
    -Wmultichar
    -Wformat-security
    -Wno-ignored-qualifiers
    -Wno-error=pedantic
    -Wno-sign-compare
    -Wno-error=missing-prototypes
    -Wdouble-promotion
    -Wclobbered
    -Wdeprecated
    -Wempty-body
    -Wshift-negative-value
    -Wstack-usage=2048
    -Wtype-limits
    -Wsizeof-pointer-memaccess
    -Wpointer-arith
)

# Simulator library define
if (LV_DRIVER STREQUAL "SDL2")
    set(LV_DRIVER_USE USE_SDL)
else()
    set(LV_DRIVER_USE "USE_${LV_DRIVER}")
endif()

# Add simulator defines to allow modification of source
add_definitions(-DSIMULATOR=1 -DLV_BUILD_TEST=0 -D${LV_DRIVER_USE})

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/simulator/inc/
    ${CMAKE_CURRENT_SOURCE_DIR}/
    ${CMAKE_CURRENT_SOURCE_DIR}/main/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lvgl/
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Link libraries
link_libraries(
    -lX11
    -lm
    -lfreetype
    -lavformat
    -lavcodec
    -lavutil
    -lswscale
    -lm
    -lz
    -lpthread
)

# Automatically include all source files
file(GLOB_RECURSE SRCS "${SRC_DIR}/*.c")
list(FILTER SRCS EXCLUDE REGEX "${SRC_DIR}/build/.*")
#message("Source files:")
#foreach(SRC ${SRCS})
#    message(${SRC})
#endforeach()

# Executable
set(EXECUTABLE_OUTPUT_PATH ${BIN_DIR})
add_executable(${PROJECT_NAME} ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)

# Install target
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/lib/${PROJECT_NAME}/bin/)
