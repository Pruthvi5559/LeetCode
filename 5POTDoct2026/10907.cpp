//301. Remove Invalid Parentheses
/*
Given a string s that contains parentheses and letters, 
remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid 
with the minimum number of removals. You may return the answer in any order.
*/

class Solution {
private:
    unordered_set<string> res;
    unordered_set<string> memo;

    void dp(const string& s, int i, const string& curr, int d) {
        // If balance d < 0, more closing brackets than opening brackets -> invalid prefix
        if (d < 0) return;

        string state = to_string(i) + "#" + to_string(d) + "#" + curr;
        if (memo.count(state)) return;
        memo.insert(state);

        // Base case: reached end of string
        if (i == s.length()) {
            if (d == 0) {
                res.insert(curr);
            }
            return;
        }

        // If current character is not a parenthesis, include it
        if (s[i] != '(' && s[i] != ')') {
            dp(s, i + 1, curr + s[i], d);
        } else {
            // Option 1: Keep s[i]
            dp(s, i + 1, curr + s[i], d + (s[i] == '(' ? 1 : -1));
            // Option 2: Skip s[i] (remove it)
            dp(s, i + 1, curr, d);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        memo.clear();

        dp(s, 0, "", 0);

        // Find the maximum length among valid strings
        int m1 = 0;
        for (const string& str : res) {
            m1 = max(m1, static_cast<int>(str.length()));
        }

        // Filter and return only the valid strings of maximum length
        vector<string> out;
        for (const string& str : res) {
            if (str.length() == m1) {
                out.push_back(str);
            }
        }

        return out;
    }
};