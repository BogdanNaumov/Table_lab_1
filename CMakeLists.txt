cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME All_lab) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

SET(CMAKE_C_COMPILER "gcc.exe")
SET(CMAKE_CXX_COMPILER "gcc.exe")

set(stack stack) #Переменная с именем приложения
set(stacklib stacklib) #Переменная с именем 
set(stacktest stacktest)

set(queue queue) 
set(queuelib queuelib)  
set(queuetest queuetest)

set(postfix postfix)
set(postfixlib postfixlib)
set(postfixtest postfixtest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stacklib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/stacklib" в дополняемые каталоги включаемых файлов
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queuelib)
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории
add_subdirectory(stack) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(stacklib)
add_subdirectory(stacktest)

add_subdirectory(queue) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(queuelib)
add_subdirectory(queuetest)

add_subdirectory(postfix)
add_subdirectory(postfixlib)
add_subdirectory(postfixtest)


