//2091. Removing Minimum and Maximum From Array
/*
You are given a 0-indexed array of distinct integers nums.
There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. 
Your goal is to remove both these elements from the array.
A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Keep indices in increasing order
        int i = min(minIndex, maxIndex);
        int j = max(minIndex, maxIndex);

        // 1. Remove both from the front
        int front = j + 1;

        // 2. Remove both from the back
        int back = n - i;

        // 3. Remove one from each side
        int both = (i + 1) + (n - j);

        return min({front, back, both});
    }
};