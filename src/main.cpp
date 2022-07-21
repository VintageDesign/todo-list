#include <iostream>
#include "parse_args.h"
#include "todo_list.h"

static std::string SAVE_FILE = std::string(getenv("HOME" )) + "/.todo_list";

int main(int argc, char** argv)
{
    todo_list todo(SAVE_FILE);
    std::cout<<SAVE_FILE<<std::endl;
    parsed_args args = parse_args(argc, argv);

    if(!args.read_todo.empty())
    {
        std::cout << "Adding todo item: " << args.read_todo << std::endl;
        todo.add_item(args.read_todo);
    }
    else if(args.list_todo)
    {
        std::cout << "Listing Items" << std::endl;
        std::cout << todo.list_items();
    }


}