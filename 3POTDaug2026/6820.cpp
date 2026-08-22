// 3069. Distribute Elements Into Two Arrays I

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1, arr2;

        // First two elements go to separate arrays
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Distribute remaining elements based on last elements
        for (int i = 2; i < nums.size(); i++) {

            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr1 and arr2
        vector<int> result = arr1;

        result.insert(result.end(), arr2.begin(), arr2.end());

        return result;
    }
};