cmake_minimum_required(VERSION 3.10)

project(karatsuba)
set(CMAKE_CXX_STANDARD 20)

add_executable(karatsuba main.cpp)

set(xgerm "-fsanitize=address,undefined") #sanitizer 
target_compile_options(karatsuba PRIVATE -Wall -Wextra -Werror ${xgerm})
target_link_options(karatsuba PRIVATE ${xgerm})


