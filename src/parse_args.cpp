#include <cstdlib>
#include "parse_args.h"
#include "cstring"


parsed_args parse_args(int argc, char **argv) {
    parsed_args retval;
    char * argv_end;
    if(1 < argc)
    {
        if(0 == std::strcmp(argv[1], "-l"))
        {
            retval.list_todo = true;
        }
        else if (0 == std::strcmp(argv[1], "-c"))
        {
            retval.clear_list = true;
        }
        else if(0 == std::strcmp(argv[1], "-r")
                && 0 < std::strtol(argv[2], nullptr,  10))
        {
            retval.remove_item = true;
            retval.item_index = std::strtol(argv[2], nullptr,  10);
        }
    }
    else
    {
        retval.read_stdin= true;
    }

    return retval;
}
