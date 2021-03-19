#include "src/two_sum/Solution.h"
#include "src/add_two_numbers/Solution.h"
#include "src/longest_substring_without_repeating_characters/Solution.h"
#include "src/median_of_two_sorted_arrays/Solution.h"
#include "src/longest_palindromic_substring/Solution.h"
#include "src/isomorphic_strings/Solution.h"
#include "src/contains_duplicate/Solution.h"
#include "src/reverse_string/Solution.h"
#include "src/reverse_vowels_of_a_string/Solution.h"
#include "src/find_all_numbers_disappeared_in_an_array/Solution.h"
#include "src/to_lower_case/Solution.h"
#include "src/distribute_candies_to_people/Solution.h"
#include "src/3sum/Solution.h"
#include "src/game_of_life/Solution.h"
#include "src/super_ugly_number/Solution.h"
#include "src/complex_number_multiplication/Solution.h"
#include "src/score_of_parentheses/Solution.h"
#include "src/pairs_of_songs_with_total_durations_divisible_by_60/Solution.h"
#include "src/can_make_palindrome_from_substring/Solution.h"
#include "src/random_pick_with_blacklist/Solution.h"
#include "src/zigzag_conversion/Solution.h"
#include "src/remove_duplicates_from_sorted_array/Solution.h"
#include "src/search_insert_position/Solution.h"
#include "src/valid_palindrome/Solution.h"
#include "src/two_sum_ii_input_array_is_sorted/Solution.h"
#include "src/third_maximum_number/Solution.h"
#include "src/longest_continuous_increasing_subsequence/Solution.h"
#include "src/merge_intervals/Solution.h"
#include "src/minimum_size_subarray_sum/Solution.h"
#include "src/product_of_array_except_self/Solution.h"
#include "src/insert_delete_getrandom_o1/RandomizedSet.h"
#include "src/permutation_in_string/Solution.h"
#include "src/count_number_of_nice_subarrays/Solution.h"
#include "src/merge_k_sorted_lists/Solution.h"
#include "src/minimum_window_substring/Solution.h"
#include "src/longest_consecutive_sequence/Solution.h"

int main() {
    two_sum::Solution().test(); // # 1
    add_two_numbers::Solution().test(); // # 2
    longest_substring_without_repeating_characters::Solution().test(); // # 3
    median_of_two_sorted_arrays::Solution().test(); // # 4
    longest_palindromic_substring::Solution().test(); // # 5
    zigzag_conversion::Solution().test(); // # 6

    sum3::Solution().test(); // # 15
    isomorphic_strings::Solution().test(); // # 205
    contains_duplicate::Solution().test(); // # 217
    game_of_life::Solution().test(); // # 289
    super_ugly_number::Solution().test(); // # 313
    reverse_string::Solution().test(); // # 344
    reverse_vowels_of_a_string::Solution().test(); // # 345
    find_all_numbers_disappeared_in_an_array::Solution().test(); // # 448
    complex_number_multiplication::Solution().test(); // # 537
    to_lower_case::Solution().test(); // # 709
    random_pick_with_blacklist::Solution::test(); // # 710
    score_of_parentheses::Solution().test(); // # 856 #fix it
    pairs_of_songs_with_total_durations_divisible_by_60::Solution().test(); // # 1010
    distribute_candies_to_people::Solution().test(); // # 1103
    can_make_palindrome_from_substring::Solution().test(); // # 1177

    merge_k_sorted_lists::Solution().test(); // # 23
    remove_duplicates_from_sorted_array::Solution().test(); // # 26
    search_insert_position::Solution().test(); // # 35
    merge_intervals::Solution().test(); // # 56
    minimum_window_substring::Solution().test(); // # 76
    valid_palindrome::Solution().test(); // # 123
    longest_consecutive_sequence::Solution().test(); // # 128
    two_sum_ii_input_array_is_sorted::Solution().test(); // # 167
    minimum_size_subarray_sum::Solution().test(); // # 209
    product_of_array_except_self::Solution().test(); // # 238
    insert_delete_getrandom_o1::RandomizedSet::test(); // # 380
    third_maximum_number::Solution().test(); // # 414
    permutation_in_string::Solution().test(); // # 567
    longest_continuous_increasing_subsequence::Solution().test(); // # 674
    count_number_of_nice_subarrays::Solution().test(); // # 1248

    return 0;
}
