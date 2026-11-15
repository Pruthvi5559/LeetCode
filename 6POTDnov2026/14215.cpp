//1524. Number of Sub-arrays With Odd Sum
/*
Given an array of integers arr, 
return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int prefixSum = 0;
        int evenCount = 1; 
        int oddCount = 0;

        for(int num : arr){
            prefixSum += num;

            if(prefixSum % 2 != 0){
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }else{
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }

        return ans;
    }
};