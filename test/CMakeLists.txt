set(VC4REGMAP_INCLUDE_DIRS "${BCM_HOST_INCLUDE_DIRS}")
set(VC4REGMAP_CFLAGS_OTHER "${BCM_HOST_CFLAGS_OTHER}")
set(VC4REGMAP_LDFLAGS "${BCM_HOST_LDFLAGS}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -W -Wall -Wextra -O2 -g")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(ident ident.c)
target_include_directories(ident PRIVATE "${VC4REGMAP_INCLUDE_DIRS}")
target_compile_options(ident PRIVATE "${VC4REGMAP_CFLAGS_OTHER}")
target_link_libraries(ident vc4regmap "${VC4REGMAP_LDFLAGS}")
add_test(Ident ident)
