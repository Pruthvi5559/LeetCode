//2948. Make Lexicographically Smallest Array by Swapping Elements
/*You are given a 0-indexed array of positive integers nums and a positive integer limit.
In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an 
element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
*/

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort by value
        sort(v.begin(), v.end());

        int start = 0;

        while (start < n) {
            int end = start;

            // Find all values connected by valid swaps
            while (end + 1 < n &&
                   v[end + 1].first - v[end].first <= limit) {
                end++;
            }

            // Get original indices of this group
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(v[i].second);
            }

            // Smallest values should go to smallest indices
            sort(indices.begin(), indices.end());

            for (int i = start; i <= end; i++) {
                nums[indices[i - start]] = v[i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};