set(VC4REGMAP_INCLUDE_DIRS ${BCM_HOST_INCLUDE_DIRS})
set(VC4REGMAP_CFLAGS_OTHER ${BCM_HOST_CFLAGS_OTHER})
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -W -Wall -Wextra -pipe -O2 -g")
include_directories(${CMAKE_SOURCE_DIR}/include ${VC4REGMAP_INCLUDE_DIRS})

set(vc4regmap_SOURCES vc4regmap.c)

add_library(vc4regmap        SHARED ${vc4regmap_SOURCES})
target_compile_options(vc4regmap PRIVATE "${VC4REGMAP_CFLAGS_OTHER}")

add_library(vc4regmap-static STATIC ${vc4regmap_SOURCES})
target_compile_options(vc4regmap PRIVATE "${VC4REGMAP_CFLAGS_OTHER}")
set_target_properties(vc4regmap-static PROPERTIES OUTPUT_NAME "vc4regmap")

install(TARGETS vc4regmap        LIBRARY DESTINATION lib)
install(TARGETS vc4regmap-static ARCHIVE DESTINATION lib)
