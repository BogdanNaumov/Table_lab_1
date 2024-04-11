cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

set(PROJECT_NAME Table_lab_1) # Создаем обычную локальную переменную с именем проекта.
project(${PROJECT_NAME}) # Название проекта.

# Определяем переменные с именами приложений и библиотек.
set(polinom polinom)
set(polinomlib polinomlib)
set(listlib listlib)
set(Base_Table Base_Table)
set(TEST TEST)
set(UnorderedTable_list UnorderedTable_list)
set(Three_avl Three_avl)
set(hesh_1 hesh_1)
set(hesh_2 hesh_2)
set(Table_arr Table_arr)
set(UnorderedTable_arr UnorderedTable_arr)
set(TableManager TableManager)
set(postfix postfix)
set(postfixlib postfixlib)
set(stack stack)
set(stacklib stacklib)
set(experiment experiment)

# Создаем переменную для типов сборки и устанавливаем значения Debug и Release.
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

# Если не указан тип сборки, устанавливаем Release по умолчанию.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Включаем папку с заголовочными файлами gtest.
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
# Добавляем субдиректорию для сборки gtest.
add_subdirectory(gtest)

# Включаем папки с заголовочными файлами и библиотеками для остальных проектов.
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/listlib
    ${CMAKE_CURRENT_SOURCE_DIR}/polinomlib
    ${CMAKE_CURRENT_SOURCE_DIR}/postfixlib
    ${CMAKE_CURRENT_SOURCE_DIR}/stacklib
    ${CMAKE_CURRENT_SOURCE_DIR}/hesh_1
    ${CMAKE_CURRENT_SOURCE_DIR}/hesh_2
    ${CMAKE_CURRENT_SOURCE_DIR}/Three_avl
    ${CMAKE_CURRENT_SOURCE_DIR}/Base_Table
    ${CMAKE_CURRENT_SOURCE_DIR}/TableManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Table_arr
    ${CMAKE_CURRENT_SOURCE_DIR}/UnorderedTable_arr
    ${CMAKE_CURRENT_SOURCE_DIR}/UnorderedTable_list
    ${CMAKE_CURRENT_SOURCE_DIR}/TEST
    ${CMAKE_CURRENT_SOURCE_DIR}/experiment
)

# Добавляем субдиректории для сборки остальных проектов.
add_subdirectory(listlib)
add_subdirectory(polinom)
add_subdirectory(polinomlib)
add_subdirectory(postfix)
add_subdirectory(postfixlib)
add_subdirectory(stack)
add_subdirectory(stacklib)
add_subdirectory(hesh_1)
add_subdirectory(hesh_2)
add_subdirectory(Three_avl)
add_subdirectory(Base_Table)
add_subdirectory(TableManager)
add_subdirectory(Table_arr)
add_subdirectory(UnorderedTable_arr)
add_subdirectory(UnorderedTable_list)
add_subdirectory(TEST)
add_subdirectory(experiment)
