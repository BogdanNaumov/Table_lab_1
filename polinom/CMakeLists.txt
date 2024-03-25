file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${polinom} ${srcs} ${hdrs}) 
target_link_libraries(${polinom} ${polinomlib} ${listlib}) 

#add_library(${MyLib1} STATIC ${srcs} ${hdrs}) 

