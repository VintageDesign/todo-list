#include <gtest/gtest.h>
#include <stdio.h>
#include <fstream>
#include "todo_list.h"

TEST(test_todo_list, can_create)
{
    const char *save = "test.txt";
    todo_list todo(save);

    std::ifstream read_list;
    read_list.open(save);

    ASSERT_TRUE(read_list.is_open());
    if(read_list.is_open())
    {
        read_list.close();
        remove(save);
    }

}


