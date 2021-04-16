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
#include "src/valid_parentheses/Solution.h"
#include "src/min_stack/MinStack.h"
#include "src/implement_queue_using_stacks/MyQueue.h"
#include "src/flipping_an_image/Solution.h"
#include "src/number_of_recent_calls/RecentCounter.h"
#include "src/binary_tree_right_side_view/Solution.h"
#include "src/basic_calculator_ii/Solution.h"
#include "src/pattern132/Solution.h"
#include "src/task_scheduler/Solution.h"
#include "src/shortest_path_in_binary_matrix/Solution.h"
#include "src/trapping_rain_water/Solution.h"
#include "src/word_ladder/Solution.h"
#include "src/insert_delete_getrandom_o1_duplicates_allowed/RandomizedCollection.h"
#include "src/merge_two_sorted_lists/Solution.h"
#include "src/linked_list_cycle/Solution.h"
#include "src/remove_linked_list_elements/Solution.h"
#include "src/reverse_linked_list/Solution.h"
#include "src/delete_node_in_a_linked_list/Solution.h"
#include "src/missing_number/Solution.h"
#include "src/remove_nth_node_from_end_of_list/Solution.h"
#include "src/rotate_list/Solution.h"
#include "src/reverse_linked_list_ii/Solution.h"
#include "src/copy_list_with_random_pointer/Solution.h"
#include "src/linked_list_cycle_ii/Solution.h"
#include "src/top_k_frequent_elements/Solution.h"
#include "src/smallest_range_covering_elements_from_k_lists/Solution.h"

int main() {
    two_sum::Solution().test(); // # 1
    add_two_numbers::Solution().test(); // # 2
    longest_substring_without_repeating_characters::Solution().test(); // # 3
    median_of_two_sorted_arrays::Solution().test(); // # 4
    longest_palindromic_substring::Solution().test(); // # 5
    zigzag_conversion::Solution().test(); // # 6

    sum3::Solution().test(); // # 15
    valid_parentheses::Solution().test(); // # 20
    merge_k_sorted_lists::Solution().test(); // # 23
    remove_duplicates_from_sorted_array::Solution().test(); // # 26
    search_insert_position::Solution().test(); // # 35
    trapping_rain_water::Solution().test(); // # 42
    merge_intervals::Solution().test(); // # 56
    minimum_window_substring::Solution().test(); // # 76
    valid_palindrome::Solution().test(); // # 123
    word_ladder::Solution().test(); // # 127
    longest_consecutive_sequence::Solution().test(); // # 128
    min_stack::MinStack::test(); // # 155
    two_sum_ii_input_array_is_sorted::Solution().test(); // # 167
    binary_tree_right_side_view::Solution().test(); // # 199
    isomorphic_strings::Solution().test(); // # 205
    minimum_size_subarray_sum::Solution().test(); // # 209
    contains_duplicate::Solution().test(); // # 217
    basic_calculator_ii::Solution().test(); // # 227
    implement_queue_using_stacks::MyQueue::test(); // # 232
    product_of_array_except_self::Solution().test(); // # 238
    game_of_life::Solution().test(); // # 289
    super_ugly_number::Solution().test(); // # 313
    reverse_string::Solution().test(); // # 344
    reverse_vowels_of_a_string::Solution().test(); // # 345
    insert_delete_getrandom_o1::RandomizedSet::test(); // # 380
    insert_delete_getrandom_o1_duplicates_allowed::RandomizedCollection::test(); // # 381
    third_maximum_number::Solution().test(); // # 414
    find_all_numbers_disappeared_in_an_array::Solution().test(); // # 448
    pattern132::Solution().test(); // # 456
    complex_number_multiplication::Solution().test(); // # 537
    permutation_in_string::Solution().test(); // # 567
    task_scheduler::Solution().test(); // # 621
    longest_continuous_increasing_subsequence::Solution().test(); // # 674
    to_lower_case::Solution().test(); // # 709
    random_pick_with_blacklist::Solution::test(); // # 710
    flipping_an_image::Solution().test(); // # 832
    score_of_parentheses::Solution().test(); // # 856
    number_of_recent_calls::RecentCounter::test(); // # 933
    pairs_of_songs_with_total_durations_divisible_by_60::Solution().test(); // # 1010
    shortest_path_in_binary_matrix::Solution().test(); // # 1091
    distribute_candies_to_people::Solution().test(); // # 1103
    can_make_palindrome_from_substring::Solution().test(); // # 1177
    count_number_of_nice_subarrays::Solution().test(); // # 1248

    merge_two_sorted_lists::Solution().test(); // # 21
    linked_list_cycle::Solution().test(); // # 141
    remove_linked_list_elements::Solution().test(); // # 141
    reverse_linked_list::Solution().test(); // # 206
    delete_node_in_a_linked_list::Solution().test(); // # 237
    missing_number::Solution().test(); // # 268
    remove_nth_node_from_end_of_list::Solution().test(); // # 19
    rotate_list::Solution().test(); // # 61
    reverse_linked_list_ii::Solution().test(); // # 92
    copy_list_with_random_pointer::Solution().test(); // # 138
    linked_list_cycle_ii::Solution().test(); // # 142
    top_k_frequent_elements::Solution().test(); // # 347
    smallest_range_covering_elements_from_k_lists::Solution().test(); // # 632

    return 0;
}
