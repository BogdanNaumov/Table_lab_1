file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${postfix} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${postfix}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${postfix} ${postfixlib}) #Подключаем к проекту с именем ${postfix} библиотеку с именем ${postfixlib}

#add_library(${MyLib1} STATIC ${srcs} ${hdrs}) #Создаем статическую библиотеку с именем из переменной ${MyLib1}, объявленной в родительском CMake файле (локальные переменные переносятся в наследников), в неё добавляются файлы из переменных ${srcs} и ${hdrs}
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
