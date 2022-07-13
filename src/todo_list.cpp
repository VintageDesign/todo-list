//
// Created by riley on 7/12/22.
//

#include "todo_list.h"

using namespace std;

todo_list::todo_list() = default;

todo_list::~todo_list() = default;

todo_list::todo_list(vector<string> list):
todo_items(std::move(list))
{

}



