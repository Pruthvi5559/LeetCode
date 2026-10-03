//32. Longest Valid Parentheses
/*
Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, max_len = 0;

        // Left-to-Right pass
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right-to-Left pass
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') left++;
            else right++;

            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return max_len;
    }
};