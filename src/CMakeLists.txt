# CMakeLists.txt
# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(decaf_src_files
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/MyDecafVisitor.cpp"
    PARENT_SCOPE
)

message("in other ${decaf_src_files}")