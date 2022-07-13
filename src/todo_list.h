#pragma once

#include <vector>
#include <string>

class todo_list {
public:
    todo_list();
    explicit todo_list(std::vector<std::string> list);
    ~todo_list();

private:
    std::vector<std::string> todo_items;

};

