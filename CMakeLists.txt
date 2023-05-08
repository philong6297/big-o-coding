cmake_minimum_required(VERSION 3.26)

project(BigO LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(main_dirs topological_sort/topological_sorting topological_sort/hierarchy
              topological_sort/fox_and_names topological_sort/kings_path
              topological_sort/beverages
)
foreach(dir IN LISTS main_dirs)
  string(REPLACE "/" "_" target_name ${dir})
  add_executable(${target_name} src/${dir}/main.cc)
endforeach()
