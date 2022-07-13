add_library(todo_lib)

target_sources(todo_lib
        PUBLIC parse_args.cpp
               todo_list.cpp)

add_executable(todo)

target_sources(todo PRIVATE main.cpp)
target_link_libraries(todo PRIVATE todo_lib)

