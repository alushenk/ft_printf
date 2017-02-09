cmake_minimum_required(VERSION 3.6)
project(ft_printf)

# set(HUY /home/warto/huy)
# message("HUY points to " ${HUY})
# file(GLOB SOURCES_LIB ${LIBFT_DIR}/*.c)   # to locate all .c files in the "LIBFT_DIR" directory to SOURCES_LIB variable

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c ft_printf.c ft_printf.h functions.c output_functions.c)
add_executable(ft_printf ${SOURCE_FILES} functions.c output_functions.c)

file(GLOB SOURCES_LIB libft/*.c)
add_library(ft STATIC ${SOURCES_LIB})       # Создание статической библиотеки с именем libft

target_link_libraries(ft_printf ft)	        # Линковка программы с библиотекой