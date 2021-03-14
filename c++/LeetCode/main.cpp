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

int main() {
    two_sum::Solution().test(); // #1
    add_two_numbers::Solution().test(); // #2
    longest_substring_without_repeating_characters::Solution().test(); // #3
    median_of_two_sorted_arrays::Solution().test(); // #4
    longest_palindromic_substring::Solution().test(); // #5

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
    score_of_parentheses::Solution().test(); // # 856
    pairs_of_songs_with_total_durations_divisible_by_60::Solution().test(); // # 1010
    distribute_candies_to_people::Solution().test(); // # 1103
    can_make_palindrome_from_substring::Solution().test(); // # 1177

    return 0;
}
