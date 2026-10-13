//3727. Maximum Alternating Sum of Squares
/*
You are given an integer array nums. 
You may rearrange the elements in any order.
The alternating score of an array arr is defined as:

score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible 
alternating score of nums after rearranging its elements.
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = nums[i]*nums[i];
        }

        //sort in ascending order 
        sort(nums.begin(), nums.end());

        long long res = 0;
        int half = n/2;

        //substract smaller elements
        for(int i = 0; i < half; i++){
            res -= nums[i];
        }

        //add larger elements
        for(int i = half; i < n; i++){
            res += nums[i];
        }

        return res;
    }
};