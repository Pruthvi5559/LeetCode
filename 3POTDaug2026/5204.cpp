//3731. Find Missing Elements
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int n = nums.size();

        // Find the smallest and largest elements
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        // Mark the elements present in the range [mini, maxi]
        vector<int> hash(maxi - mini + 1, 0);

        for (int i = 0; i < n; i++) {
            hash[nums[i] - mini]++;
        }

        vector<int> ans;

        // Collect the missing elements
        for (int i = 0; i <= maxi - mini; i++) {
            if (hash[i] == 0) {
                ans.push_back(i + mini);
            }
        }

        return ans;
    }
};