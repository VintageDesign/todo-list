#include <gtest/gtest.h>
#include "test_parse_args.h"
#include "parse_args.h"


TEST(test_parse_args, can_create)
{
    char* argv[1] = {"todo"};
    parsed_args test = parse_args(1, argv);

    ASSERT_FALSE(test.clear_list);
    ASSERT_FALSE(test.list_todo);
    ASSERT_FALSE(test.remove_item);
    ASSERT_EQ(0, test.item_index);
    ASSERT_EQ("", test.read_todo);

}

TEST(test_parse_args, can_read)
{
    char* argv[3] = {"todo", "read", "me"};
    parsed_args test = parse_args(3, argv);

    ASSERT_FALSE(test.clear_list);
    ASSERT_FALSE(test.list_todo);
    ASSERT_FALSE(test.remove_item);
    ASSERT_EQ(0, test.item_index);
    ASSERT_EQ("read me", test.read_todo);

}

TEST(test_parse_args, can_remove)
{
    char* argv[3] = {"todo", "-r", "10"};
    parsed_args test = parse_args(3, argv);

    ASSERT_FALSE(test.clear_list);
    ASSERT_FALSE(test.list_todo);
    ASSERT_TRUE(test.remove_item);
    ASSERT_EQ(10, test.item_index);
    ASSERT_EQ("", test.read_todo);
}

TEST(test_parse_args, can_clear)
{
    char* argv[2] = {"todo", "-c"};
    parsed_args test = parse_args(2, argv);

    ASSERT_TRUE(test.clear_list);
    ASSERT_FALSE(test.list_todo);
    ASSERT_FALSE(test.remove_item);
    ASSERT_EQ(0, test.item_index);
    ASSERT_EQ("", test.read_todo);
}

TEST(test_parse_args, can_list)
{
    char* argv[2] = {"todo", "-l"};
    parsed_args test = parse_args(2, argv);

    ASSERT_FALSE(test.clear_list);
    ASSERT_TRUE(test.list_todo);
    ASSERT_FALSE(test.remove_item);
    ASSERT_EQ(0, test.item_index);
    ASSERT_EQ("", test.read_todo);
}

