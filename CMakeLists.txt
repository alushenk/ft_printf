cmake_minimum_required(VERSION 3.6)
project(ft_printf)

# set(HUY /home/warto/huy)
# message("HUY points to " ${HUY})

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES src/*.c)
add_executable(ft_printf ${SOURCE_FILES} main.c)
file(GLOB SOURCES_LIB libft/*.c)
add_library(ft STATIC ${SOURCES_LIB})       # Создание статической библиотеки с именем libft

target_link_libraries(ft_printf ft)	        # Линковка программы с библиотекой