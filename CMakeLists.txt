# CMakeLists.txt

# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
SET(CMAKE_CXX_STANDARD 17)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE $ENV{ANTLR_JAR})

find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(decaf_lexer ${CMAKE_CURRENT_SOURCE_DIR}/grammar/DecafLexer.g4 LEXER
    PACKAGE decaf
    OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/antlr_generated)

antlr_target(decaf_parser ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Decaf.g4 PARSER
    PACKAGE decaf
    DEPENDS_ANTLR decaf_lexer
    COMPILE_FLAGS -lib ${ANTLR_decaf_lexer_OUTPUT_DIR}
    VISITOR
    OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/antlr_generated
)

include_directories(${ANTLR_decaf_lexer_OUTPUT_DIR})
include_directories(${ANTLR_decaf_parser_OUTPUT_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(output ${decaf_src_files} ${ANTLR_decaf_lexer_CXX_OUTPUTS} ${ANTLR_decaf_parser_CXX_OUTPUTS})

target_link_libraries(output antlr4_static)
target_include_directories(output
    PUBLIC
    ${ANTLR_decaf_lexer_CXX_OUTPUTS}
    ${ANTLR_decaf_parser_CXX_OUTPUTS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include)