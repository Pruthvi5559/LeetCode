//3734. Lexicographically Smallest Palindromic Permutation Greater Than Target

/*You are given two strings s and target, each of length n, consisting of lowercase English letters.
Return the lexicographically smallest string that is both a palindromic permutation of s and strictly greater than target. If no such 
permutation exists, return an empty string.*/

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        // Count characters
        for (char c : s)
            cnt[c - 'a']++;

        // Find the middle character
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != 0)
                    return "";   // More than one odd count
                mid = 'a' + i;
                cnt[i]--;
            }
        }

        int half = n / 2;

        // Remove the characters needed for target's left half
        for (int i = 0; i < half; i++)
            cnt[target[i] - 'a'] -= 2;

        auto valid = [&]() {
            for (int x : cnt)
                if (x < 0)
                    return false;
            return true;
        };

        // Case 1: target's left half itself can be used
        if (valid()) {
            string left = target.substr(0, half);
            string right;

            if (mid)
                right += mid;

            right += string(left.rbegin(), left.rend());

            // Left halves are equal, so compare the remaining part
            if (right > target.substr(half))
                return left + right;
        }

        // Case 2: Make the left half just slightly larger
        for (int i = half - 1; i >= 0; i--) {
            int x = target[i] - 'a';

            // Restore target[i] so we can try a larger character here
            cnt[x] += 2;

            if (!valid())
                continue;

            // Choose the smallest available character > target[i]
            int bigger = -1;

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] >= 2) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            cnt[bigger] -= 2;

            // Keep target's prefix, increase position i,
            // then fill the rest as small as possible
            string left = target.substr(0, i);
            left += char('a' + bigger);

            for (int c = 0; c < 26; c++) {
                left += string(cnt[c] / 2, char('a' + c));
            }

            string ans = left;

            if (mid)
                ans += mid;

            ans += string(left.rbegin(), left.rend());

            return ans;
        }

        return "";
    }
};