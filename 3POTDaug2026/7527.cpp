// 3720. Lexicographically Smallest Permutation Greater Than Target
/*You are given two strings s and target, both having length n, consisting of lowercase English letters.
Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b*/

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Count frequency of each character
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            // Use the same character as target[i]
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
                continue;
            }

            // Cannot match target[i].
            // Try a character greater than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, i);

                    // Place the smallest greater character
                    ans += char('a' + c);
                    freq[c]--;

                    // Place remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        ans += string(freq[j], char('a' + j));
                    }

                    return ans;
                }
            }

            // Backtrack to find an earlier position to increase
            for (int j = i - 1; j >= 0; j--) {

                // Restore the character used at target[j]
                freq[target[j] - 'a']++;

                // Try a greater character
                for (int c = target[j] - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string ans = target.substr(0, j);

                        ans += char('a' + c);
                        freq[c]--;

                        // Remaining characters in sorted order
                        for (int x = 0; x < 26; x++) {
                            ans += string(freq[x], char('a' + x));
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // target and s are equal.
        // Find the next greater permutation.
        for (int i = n - 1; i >= 0; i--) {
            freq[target[i] - 'a']++;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string ans = target.substr(0, i);

                    ans += char('a' + c);
                    freq[c]--;

                    // Put remaining characters in sorted order
                    for (int x = 0; x < 26; x++) {
                        ans += string(freq[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};