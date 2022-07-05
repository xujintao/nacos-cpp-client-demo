cmake_minimum_required(VERSION 3.0.0)
project(nacos-cpp-client-demo VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(/usr/local/include/nacos)

aux_source_directory(. SRCS_DIRS)

add_executable(${PROJECT_NAME} ${SRCS_DIRS})

target_link_libraries(${PROJECT_NAME} nacos-cli)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
