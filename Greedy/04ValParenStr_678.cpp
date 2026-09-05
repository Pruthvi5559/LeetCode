//678. Valid Parenthesis String
/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/

class Solution {
public:
    bool checkValidString(string s) {
        // low  = minimum possible number of unmatched '('
        // high = maximum possible number of unmatched '('
        int low = 0, high = 0;

        for (char ch : s) {

            if (ch == '(') {
                // '(' increases the number of unmatched opening brackets.
                low++;
                high++;
            } else if (ch == ')') {
                // ')' must close an opening bracket.
                low--;
                high--;
            } else {
                // '*' can be '(', ')' or an empty string.
                low--;  // Treat '*' as ')'
                high++; // Treat '*' as '('
            }

            // We cannot have fewer than 0 unmatched '('.
            low = max(low, 0);

            // Even the maximum possible opening count is negative.
            // So there is no valid interpretation.
            if (high < 0) {
                return false;
            }
        }

        // If minimum possible unmatched '(' is 0,
        // we can form a valid parenthesis string.
        return low == 0;
    }
};