//219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        // Stores elements in the current window
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            // Remove element that goes out of the window
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }

            // Duplicate found within window
            if (window.count(nums[i])) {
                return true;
            }

            // Add current element to the window
            window.insert(nums[i]);
        }

        return false;
    }
};