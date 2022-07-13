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
        for(std::string input; file_handle.getline(reinterpret_cast<char *>(&input), 80, '\n');)
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



