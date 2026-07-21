//3312. Sorted GCD Pair Queries
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> arr(mx + 1, 0);

        for (int num : nums)
            arr[num]++;

        for (int i = 1; i <= mx; i++) {
            for (int j = i * 2; j <= mx; j += i) {
                arr[i] += arr[j];
            }
        }

        for (int i = 1; i <= mx; i++) {
            arr[i] = arr[i] * (arr[i] - 1) / 2;
        }

        for (int i = mx; i >= 1; i--) {
            for (int j = i * 2; j <= mx; j += i) {
                arr[i] -= arr[j];
            }
        }

        for (int i = 1; i <= mx; i++) {
            arr[i] += arr[i - 1];
        }

        vector<int> res;

        for (long long q : queries) {
            int idx = lower_bound(arr.begin(), arr.end(), q + 1) - arr.begin();
            res.push_back(idx);
        }

        return res;
    }
};