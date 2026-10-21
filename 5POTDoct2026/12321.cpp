//3863. Minimum Operations to Sort a String
/*
You are given a string s consisting of lowercase English letters.
In one operation, you can select any substring of s that is not 
the entire string and sort it in non-descending alphabetical order.

Return the minimum number of operations required to make s sorted 
in non-descending order. If it is not possible, return -1.
*/

class Solution {
public:
    int minOperations(string s) {
        char mx = 'a', mn = 'z';
        int n = s.length();

        for(char x : s){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        if(ranges::is_sorted(s)) return 0;
        if(s.size() == 2) return -1;

        if(s[0] == mn || s[n-1] == mx){
            return 1;
        }

        for(int i = 1; i < n-1; i++){
            if(s[i] == mn || s[i] == mx){
                return 2;
            }
        }

        return 3;
    }
};