//3483. Unique 3-Digit Even Numbers
/**
You are given an array of digits called digits. Your task 
is to determine the number of distinct three-digit even numbers that can 
be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
*/

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Count frequencies of available digits
        vector<int> freq(10, 0);
        for (int d : digits) {
            freq[d]++;
        }
        
        int ans = 0;
        
        // Test all valid 3-digit even candidates
        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;
            
            freq[d1]--;
            freq[d2]--;
            freq[d3]--;
            
            // Increment if digits are available in input
            if (freq[d1] >= 0 && freq[d2] >= 0 && freq[d3] >= 0) {
                ans++;
            }
            
            // Restore frequencies for next iteration
            freq[d1]++;
            freq[d2]++;
            freq[d3]++;
        }
        
        return ans;
    }
};