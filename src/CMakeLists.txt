add_executable(todo)

#target_include_directories(todo PRIVATE)

target_sources(todo PRIVATE main.cpp
        parse_args.cpp)

