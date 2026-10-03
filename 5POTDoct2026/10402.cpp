//22. Generate Parentheses
/*
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.
*/

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open, int close, int max_pairs) {
        // Base case: formed a sequence of length 2 * n
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add opening parenthesis if we haven't reached n
        if (open < max_pairs) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max_pairs);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Add closing parenthesis if it wouldn't exceed opening count
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max_pairs);
            current.pop_back(); // Backtrack
        }
    }
};