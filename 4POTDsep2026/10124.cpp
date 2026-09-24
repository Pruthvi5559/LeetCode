//3550. Smallest Index With Digit Sum Equal to Index
/*
You are given an integer array nums.
Return the smallest index i such that the sum of the 
digits of nums[i] is equal to i.
If no such index exists, return -1.
*/

class Solution {
public:
    int calDigitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if( calDigitSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};