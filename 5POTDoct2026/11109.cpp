//1541. Minimum Insertions to Balance a Parentheses String
/*
Given a parentheses string s containing only the characters '(' and ')'. 
A parentheses string is balanced if:

Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.

For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
You can insert the characters '(' and ')' at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make s balanced.
*/

class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int res = 0;
        int i = 0;
        int n = s.size();

        while(i < n){
            if(s[i] == '('){
                cnt++;
                i++;
            }else{
                if(cnt > 0){
                    cnt--;
                }else{
                    res++;
                }

                if(i+1<n && s[i+1] == ')'){
                    i += 2;
                }else{
                    res++;
                    i++;
                }
            }
        }
        return res + cnt*2;
    }
};