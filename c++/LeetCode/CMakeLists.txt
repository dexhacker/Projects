cmake_minimum_required(VERSION 3.17)
project(LeetCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(LeetCode main.cpp src/two_sum/Solution.cpp src/two_sum/Solution.h src/add_two_numbers/Solution.cpp src/add_two_numbers/Solution.h src/longest_substring_without_repeating_characters/Solution.cpp src/longest_substring_without_repeating_characters/Solution.h src/median_of_two_sorted_arrays/Solution.cpp src/median_of_two_sorted_arrays/Solution.h src/longest_palindromic_substring/Solution.cpp src/longest_palindromic_substring/Solution.h)