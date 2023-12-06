cmake_minimum_required (VERSION 3.8)

project (cvk LANGUAGES C)

add_executable (cvk "src/cvk.c")

target_link_libraries(cvk -static)
# target_compile_options(cvk PRIVATE /MT)
target_include_directories(cvk PRIVATE "include")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cvk PROPERTY C_STANDARD 23)
endif()