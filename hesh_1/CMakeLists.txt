file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${hesh_1} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${vector}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
target_link_libraries(${hesh_1} ${Base_Table}) # Подключаем к проекту с именем ${hesh_1} библиотеку с именем ${Base_Table}
