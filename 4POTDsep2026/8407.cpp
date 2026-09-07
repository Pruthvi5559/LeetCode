//940. Distinct Subsequences II
/*
Given a string s, return the number of distinct non-empty subsequences of s. 
Since the answer may be very large, return it modulo 109 + 7.

A subsequence of a string is a new string that is formed from 
the original string by deleting some (can be none) of the characters without disturbing the relative
 positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
 
*/

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        // Total number of distinct non-empty subsequences.
        int total = 0;

        // end[i] = number of distinct subsequences ending with
        // the character ('a' + i).
        int end[26] = {0};

        for (char c : s) {
            int index = c - 'a';

            // Save the previous total before adding subsequences
            // formed using the current character.
            int oldTotal = total;

            // New subsequences = all previous subsequences + current
            // character itself, excluding duplicates ending with c.
            int newSubsequences =
                (oldTotal + 1 - end[index] + MOD) % MOD;

            // Add the newly formed distinct subsequences to the total.
            total = (total + newSubsequences) % MOD;

            // Update the count of subsequences ending with c.
            end[index] =
                (end[index] + newSubsequences) % MOD;
        }

        return total;
    }
};