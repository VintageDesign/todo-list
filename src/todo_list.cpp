//
// Created by riley on 7/12/22.
//

#include "todo_list.h"
#include <fstream>
#include <utility>

using namespace std;

todo_list::todo_list(std::string save_file):
save_file(std::move(save_file))
{
    this->read_file();
}

todo_list::~todo_list() = default;

todo_list::todo_list(std::string save_file, vector<string> list):
save_file(std::move(save_file)),
todo_items(std::move(list))
{
    this->read_file();
}

bool todo_list::read_file(void) {
    bool retval = false;
    ifstream file_handle;
    file_handle.open(this->save_file);

    if(file_handle.is_open())
    {
        std::string input;
        for(; file_handle.getline(reinterpret_cast<char *>(&input), 80, '\n');)
        {
            this->todo_items.push_back(input);
        }
        file_handle.close();
        retval = true;
    }
    else
    {
       ofstream{this->save_file};
    }
    return retval;
}

void todo_list::add_item(std::string item)
{
    this->todo_items.push_back(item);
}

std::string todo_list::list_items(void)
{
    std::string output;
    uint8_t count = 0;
    for(string item: this->todo_items)
    {
        count++;
        output += std::string(reinterpret_cast<const char *>(count)) + ". " + item + "\n";
    }

    return output;
}








