set(VC4REGMAP_INCLUDE_DIRS "${BCM_HOST_INCLUDE_DIRS}")
set(VC4REGMAP_CFLAGS_OTHER "${BCM_HOST_CFLAGS_OTHER}")
set(VC4REGMAP_LDFLAGS "${BCM_HOST_LDFLAGS}")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -W -Wall -Wextra -O2 -g")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(dmainfo dmainfo.c)
target_include_directories(dmainfo PRIVATE "${VC4REGMAP_INCLUDE_DIRS}")
target_compile_options(dmainfo PRIVATE "${VC4REGMAP_CFLAGS_OTHER}")
target_link_libraries(dmainfo vc4regmap "${VC4REGMAP_LDFLAGS}")
