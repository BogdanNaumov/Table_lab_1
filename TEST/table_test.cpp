#include "..//gtest/gtest-all.cc"
#include "..\\TableManager\TableManager.h"

TEST(ProbingHashTableTest, InsertAndFind) {
    ProbingHashTable<int, std::string> table;

    table.Insert(1, "One");

    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "One");

    EXPECT_EQ(table.Find(2), nullptr);
}

TEST(ProbingHashTableTest, Update) {
    ProbingHashTable<int, std::string> table;

    table.Insert(1, "One");

    table.Insert(1, "New One");

    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "New One");
}


TEST(ProbingHashTableTest, Delete) {
    ProbingHashTable<int, std::string> table;

    table.Insert(1, "One");

    table.Delete(1);
    EXPECT_EQ(table.Find(1), nullptr);
}

TEST(SortArrayTableTest, InsertAndFind) {
    SortArrayTable<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(*table.Find(1), "one");
    EXPECT_EQ(*table.Find(2), "two");
    EXPECT_EQ(*table.Find(3), "three");
}


TEST(SortArrayTableTest, ResetAndNext) {
    SortArrayTable<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(table.Reset(), 0);

    table.GoNext();
    EXPECT_EQ(table.GetKey(), 2);

    table.GoNext();
    EXPECT_EQ(table.GetKey(), 3);

    table.GoNext();
    EXPECT_EQ(table.IsTabEnded(), 1);
}

TEST(UnorderedTable_masTest, InsertAndFind) {
    UnorderedTable_mas<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(*table.Find(1), "one");
    EXPECT_EQ(*table.Find(2), "two");
    EXPECT_EQ(*table.Find(3), "three");
}

TEST(UnorderedTable_masTest, Delete) {
    UnorderedTable_mas<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    table.Delete(2);

    EXPECT_EQ(*table.Find(1), "one");
    EXPECT_EQ(table.Find(2), nullptr);
    EXPECT_EQ(*table.Find(3), "three");
}

TEST(UnorderedTable_masTest, Count) {
    UnorderedTable_mas<int, string> table;

    EXPECT_EQ(table.GetDataCount(), 0);

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(table.GetDataCount(), 3);

    table.Delete(2);

    EXPECT_EQ(table.GetDataCount(), 2);
}

TEST(UnorderedTable_masTest, ResetAndNext) {
    UnorderedTable_mas<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(table.Reset(), 0);

    table.GoNext();
    EXPECT_EQ(table.GetKey(), 2);

    table.GoNext();
    EXPECT_EQ(table.GetKey(), 3);

    table.GoNext();
    EXPECT_EQ(table.IsTabEnded(), 1);
}

TEST(Unordered_TableTest, InsertAndFind) {
    Unordered_Table<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    EXPECT_EQ(*table.Find(1), "one");
    EXPECT_EQ(*table.Find(2), "two");
    EXPECT_EQ(*table.Find(3), "three");
}

TEST(Unordered_TableTest, Delete) {
    Unordered_Table<int, string> table;

    table.Insert(1, "one");
    table.Insert(2, "two");
    table.Insert(3, "three");

    table.Delete(2);

    EXPECT_EQ(*table.Find(1), "one");
    EXPECT_EQ(table.Find(2), nullptr);
    EXPECT_EQ(*table.Find(3), "three");
}


TEST(Unordered_TableTest, AccessEmptyTable) {
    Unordered_Table<int, string> table;

    EXPECT_THROW(table.GetKey(), std::out_of_range);
    EXPECT_THROW(table.GetValuePtr(), std::out_of_range);
}

TEST(AVL_TreeTest, InsertAndFind) {
    AVL_Tree<int, string> tree;

    tree.Insert(1, "one");
    tree.Insert(2, "two");
    tree.Insert(3, "three");

    EXPECT_EQ(*tree.Find(1), "one");
    EXPECT_EQ(*tree.Find(2), "two");
    EXPECT_EQ(*tree.Find(3), "three");
}

TEST(AVL_TreeTest, Delete) {
    AVL_Tree<int, string> tree;

    tree.Insert(1, "one");
    tree.Insert(2, "two");
    tree.Insert(3, "three");

    tree.Delete(2);

    EXPECT_EQ(*tree.Find(1), "one");
    EXPECT_EQ(tree.Find(2), nullptr);
    EXPECT_EQ(*tree.Find(3), "three");
}