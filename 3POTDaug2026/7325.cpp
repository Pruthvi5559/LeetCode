//3718. Smallest Missing Multiple of K
/*Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
A multiple of k is any positive integer divisible by k.

Example 1:
Input: nums = [8,2,3,4,6], k = 2
Output: 10
Explanation:
The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100*/

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        if (k <= 0) return 0; // Invalid k

        // Store all numbers for quick lookup
        unordered_set<int> present_numbers;

        for (int num : nums) {
            present_numbers.insert(num);
        }

        // Check multiples of k starting from k
        for (int i = k; i < INT_MAX; i += k) {
            // Return the first multiple not present
            if (present_numbers.find(i) == present_numbers.end()) {
                return i;
            }
        }

        return 0; // Fallback
    }
};