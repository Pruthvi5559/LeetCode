//2472. Maximum Number of Non-overlapping Palindrome Substrings
/*
You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[l][r] = whether s[l..r] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome DP.
        // Iterate l backwards so pal[l + 1][r - 1] is already known.
        for (int l = n - 1; l >= 0; --l) {
            for (int r = l; r < n; ++r) {
                if (s[l] == s[r] &&
                    (r - l <= 1 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // that can be selected from s[0 .. i-1].
        vector<int> dp(n + 1, 0);

        for (int r = 0; r < n; ++r) {
            // Don't use any palindrome ending at r.
            dp[r + 1] = dp[r];

            // Try every palindrome ending at r.
            for (int l = 0; l <= r - k + 1; ++l) {
                if (pal[l][r]) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};