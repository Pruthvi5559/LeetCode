//3498. Reverse Degree of a String
/*
Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:
For each character, multiply its position in the reversed alphabet 
('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.
*/

class Solution {
public:
    int reverseDegree(string s) {
        int totalSum = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reversedAlphabetPos = 'z' - s[i] + 1; // 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            int stringPos = i + 1;                    // 1-indexed string position
            totalSum += reversedAlphabetPos * stringPos;
        }
        return totalSum;
    }
};
