#pragma once

#include <vector>
#include <string>

class todo_list {
public:
    explicit todo_list(std::string save_file);
    explicit todo_list(std::string save_file, std::vector<std::string> list);
    ~todo_list();

    void add_item(std::string item);
    std::string list_items(void);




private:
    bool read_file(void);
    std::string save_file;
    std::vector<std::string> todo_items;

};

