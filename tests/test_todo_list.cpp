#include <gtest/gtest.h>
#include <cstdio>
#include <fstream>
#include "todo_list.h"

TEST(test_todo_list, can_create)
{
    std::string save = ".can_create.txt";
    {
        todo_list todo(save);
    }

    std::ifstream read_list;
    read_list.open(save);

    ASSERT_TRUE(read_list.is_open());
    int value = 0;
    if(read_list.is_open())
    {
        read_list.close();
        value = remove(save.c_str());
    }

}


TEST(test_todo_list, can_add)
{
    std::string save = ".can_add.txt";
    {
        todo_list todo(save);
        todo.add_item("Test_1");
        todo.add_item("Test_2");
        todo.add_item("Test_3");
    }

    std::ifstream read_list;
    read_list.open(save);

    std::string line_1;
    std::string line_2;
    std::string line_3;
    std::string line_4;

    if (read_list.is_open())
    {
        EXPECT_TRUE(getline(read_list, line_1));
        EXPECT_TRUE(getline(read_list, line_2));
        EXPECT_TRUE(getline(read_list, line_3));
        EXPECT_FALSE(getline(read_list, line_4));

        EXPECT_EQ(line_1, "Test_1");
        EXPECT_EQ(line_2, "Test_2");
        EXPECT_EQ(line_3, "Test_3");

        read_list.close();
        remove(save.c_str());
    }
}

TEST(test_todo_list, can_read)
{
    std::string save = ".can_read.txt";

    std::ofstream print_list;
    print_list.open(save);
    print_list << "Test_1\n";
    print_list << "Test_2\n";
    print_list << "Test_3\n";
    print_list.close();


    {
        todo_list todo(save);
        remove(save.c_str());
    }

    std::ifstream read_list;
    read_list.open(save);

    std::string line_1;
    std::string line_2;
    std::string line_3;
    std::string line_4;

    if (read_list.is_open())
    {
        EXPECT_TRUE(getline(read_list, line_1));
        EXPECT_TRUE(getline(read_list, line_2));
        EXPECT_TRUE(getline(read_list, line_3));
        EXPECT_FALSE(getline(read_list, line_4));

        EXPECT_EQ(line_1, "Test_1");
        EXPECT_EQ(line_2, "Test_2");
        EXPECT_EQ(line_3, "Test_3");

        read_list.close();
        remove(save.c_str());
    }
}

