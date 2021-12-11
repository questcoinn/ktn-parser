cmake_minimum_required(VERSION 3.19)

# [project settings]
project(
    parser
    VERSION 0.1
    DESCRIPTION "파서"
    LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
# set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

# [directories]
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# [executable - parser]
set(MAIN_EXE parser)

add_executable(${MAIN_EXE})

set_target_properties(${MAIN_EXE} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY    ${BIN_DIR}
    RUNTIME_OUTPUT_NAME         ${MAIN_EXE})
target_include_directories(${MAIN_EXE} PUBLIC ${INCLUDE_DIR})
target_sources(${MAIN_EXE} PUBLIC
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/parser.cpp
    ${SRC_DIR}/tokenizer.cpp)

target_compile_features(${MAIN_EXE} PUBLIC cxx_std_20)
# target_compile_options(${MAIN_EXE} PUBLIC -Wall -Werror)

# [executable - test tokenizer]
set(TEST_TOKENIZER_EXE test_tokenizer)

add_executable(${TEST_TOKENIZER_EXE})

set_target_properties(${TEST_TOKENIZER_EXE} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY    ${BIN_DIR}
    RUNTIME_OUTPUT_NAME         ${TEST_TOKENIZER_EXE})
target_include_directories(${TEST_TOKENIZER_EXE} PUBLIC ${INCLUDE_DIR})
target_sources(${TEST_TOKENIZER_EXE} PUBLIC
    ${TEST_DIR}/test_tokenizer.cpp
    ${SRC_DIR}/tokenizer.cpp)

target_compile_features(${TEST_TOKENIZER_EXE} PUBLIC cxx_std_20)
# target_compile_options(${TEST_TOKENIZER_EXE} PUBLIC -Wall -Werror)
