cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.


set(PROJECT_NAME Table_lab_1) #Создаем обычную локальную переменную с и менем проекта
project(${PROJECT_NAME}) # Название проекта

set(polinom polinom) #Переменная с именем приложения
set(polinomlib polinomlib) #Переменная с именем библиотеки
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

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/listlib)
add_subdirectory(listlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/polinomlib) 
add_subdirectory(polinom) 
add_subdirectory(polinomlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/postfixlib) 
add_subdirectory(postfix)
add_subdirectory(postfixlib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklib) 
add_subdirectory(stack) 
add_subdirectory(stacklib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hesh_1)
add_subdirectory(hesh_1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hesh_2)
add_subdirectory(hesh_2)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Three_avl)
add_subdirectory(Three_avl)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Base_Table)
add_subdirectory(Base_Table)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TableManager)
add_subdirectory(TableManager)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Table_arr)
add_subdirectory(Table_arr)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/UnorderedTable_arr)
add_subdirectory(UnorderedTable_arr)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/UnorderedTable_list)
add_subdirectory(UnorderedTable_list)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/TEST)
add_subdirectory(TEST)

