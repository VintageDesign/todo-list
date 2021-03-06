#ifndef TODO_PARSE_ARGS_H
#define TODO_PARSE_ARGS_H

#include <cstdint>
#include <string>

struct parsed_args
{
    bool list_todo = false;
    bool clear_list = false;
    bool remove_item = false;
    std::uint8_t item_index = 0;

    std::string read_todo;
};

parsed_args parse_args(int argc, char ** argv);

#endif //TODO_PARSE_ARGS_H
