//115. Distinct Subsequences
/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // dp[j] = number of ways to form t[0...j-1].
        vector<double> dp(m+1, 0);

        // Empty string can always be formed in exactly one way.
        dp[0] = 1;
        

        for(int i = 1; i <= n; i++){

            // Traverse backwards so each character of s
            // is used at most once.
            for(int j = m; j >= 1; j--){
                if(s[i-1] == t[j-1]){

                    // Add ways to form t[0...j-2] using
                    // the previous characters of s.
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }

        return (int)dp[m];
    }
};