file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${experiment} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${postfix}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${experiment} ${Base_Table}) #Подключаем к проекту с именем ${postfix} библиотеку с именем ${postfixlib}
