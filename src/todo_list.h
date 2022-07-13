#pragma once

#include <vector>
#include <string>

class todo_list {
public:
    todo_list(std::string save_file);
    explicit todo_list(std::string save_file, std::vector<std::string> list);
    ~todo_list();



private:
    bool read_file(void);
    std::string save_file;
    std::vector<std::string> todo_items;

};

