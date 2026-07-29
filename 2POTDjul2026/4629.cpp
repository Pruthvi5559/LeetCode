//3518. Smallest Palindromic Rearrangement II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using int64 = long long;

    // Computes nCr, stopping early if the value exceeds limit
    int64 comb(int n, int r, int64 limit) {
        if (r > n) return 0;
        r = min(r, n - r);

        __int128 ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > limit) return limit;
        }
        return (int64)ans;
    }

    // Number of distinct permutations for the remaining multiset
    int64 countPermutations(vector<int>& freq, int remaining, int64 limit) {
        __int128 ans = 1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            ans *= comb(remaining, freq[i], limit);
            if (ans > limit) return limit;
            remaining -= freq[i];
        }

        return (int64)ans;
    }

    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;
        char mid = 0;

        // Store only half frequencies
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid = char('a' + i);
            freq[i] /= 2;
        }

        int half = s.size() / 2;
        string left;

        for (int pos = 0; pos < half; pos++) {
            bool found = false;
            
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0)
                    continue;
                freq[c]--;

                long long ways =
                    countPermutations(freq, half - pos - 1, k);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    found = true;
                    break;
                }

                k -= ways;
                freq[c]++;
            }

            if (!found)
                return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + mid + right;

        return left + right;
    }
};