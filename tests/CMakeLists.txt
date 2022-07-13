add_executable(todo_tests)
target_link_libraries(todo_tests PUBLIC todo_lib gtest gtest_main)

target_sources(todo_tests PUBLIC test_parse_args.cpp test_todo_list.cpp)
target_include_directories(todo_tests PUBLIC ../src)