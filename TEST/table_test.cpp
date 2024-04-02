#include <gtest.h>
#include "..\\TableManager\TableManager.h"

TEST(ProbingHashTableTest, InsertAndFind) {
    ProbingHashTable<int, std::string> table;

    // Вставляем элемент
    table.Insert(1, "One");

    // Проверяем, что элемент найден
    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "One");

    // Проверяем, что элемент, которого нет, не найден
    EXPECT_EQ(table.Find(2), nullptr);
}

// Тест проверки обновления элемента
TEST(ProbingHashTableTest, Update) {
    ProbingHashTable<int, std::string> table;

    // Вставляем элемент
    table.Insert(1, "One");

    // Обновляем значение элемента
    table.Insert(1, "New One");

    // Проверяем, что значение обновлено
    EXPECT_NE(table.Find(1), nullptr);
    EXPECT_EQ(*table.Find(1), "New One");
}

// Тест проверки удаления элемента
TEST(ProbingHashTableTest, Delete) {
    ProbingHashTable<int, std::string> table;

    // Вставляем элемент
    table.Insert(1, "One");

    // Удаляем элемент
    table.Delete(1);

    // Проверяем, что элемент больше не найден
    EXPECT_EQ(table.Find(1), nullptr);
}
