//3723. Maximize Sum of Squares of Digits
/*
You are given two positive integers num and sum.
A positive integer n is good if it satisfies both of the following:

The number of digits in n is exactly num.
The sum of digits in n is exactly sum.
The score of a good integer n is the sum of the squares of digits in n.

Return a string denoting the good integer n that achieves the maximum score. 
If there are multiple possible integers, return the maximum ​​​​​​​one. 
If no such integer exists, return an empty string.
*/

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        
        if(sum > 9*num) return "";

        while(sum >= 9 && ans.size() < num){
            ans.push_back('9');
            sum -= 9;
        }

        if(sum > 0 && ans.size()<num){
            ans.push_back(sum+'0');
            sum = 0;
        }

        while(ans.size() < num){
            ans.push_back('0');
        }
        
        return ans;
    }
};