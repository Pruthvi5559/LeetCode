//2104. Sum of Subarray Ranges
class Solution {
private:
    // Find Next Smaller Element indices
    vector<int> findNSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--){

            int currElem = nums[i];

            // Remove elements greater than or equal to current
            while(!st.empty() && nums[st.top()] >= currElem){
                st.pop();
            }

            // Index of next smaller element
            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    // Find Next Greater Element indices
    vector<int> findNGE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--){

            int currElem = nums[i];

            // Remove elements smaller than or equal to current
            while(!st.empty() && nums[st.top()] <= currElem){
                st.pop();
            }

            // Index of next greater element
            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    // Find Previous Smaller or Equal Element indices
    vector<int> findPSEE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from left to right
        for(int i = 0; i < n; i++){

            int currElem = nums[i];

            // Remove strictly greater elements
            while(!st.empty() && nums[st.top()] > currElem){
                st.pop();
            }

            // Index of previous smaller or equal element
            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

    // Find Previous Greater or Equal Element indices
    vector<int> findPGEE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from left to right
        for(int i = 0; i < n; i++){

            int currElem = nums[i];

            // Remove strictly smaller elements
            while(!st.empty() && nums[st.top()] < currElem){
                st.pop();
            }

            // Index of previous greater or equal element
            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

    // Calculate total contribution of each element as the minimum
    long long minSubarraySum(vector<int>& nums){
        int n = nums.size();
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++){

            // Number of choices on left and right
            int left = i - psee[i];
            int right = nse[i] - i;

            // Number of subarrays where nums[i] is the minimum
            long long freq = 1LL * left * right;

            // Contribution of nums[i]
            sum += freq * nums[i];
        }

        return sum;
    }

    // Calculate total contribution of each element as the maximum
    long long maxSubarraySum(vector<int>& nums){
        int n = nums.size();
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long sum = 0;

        for(int i = 0; i < n; i++){

            // Number of choices on left and right
            int left = i - pgee[i];
            int right = nge[i] - i;

            // Number of subarrays where nums[i] is the maximum
            long long freq = 1LL * left * right;

            // Contribution of nums[i]
            sum += freq * nums[i];
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {

        // Sum of subarray ranges = Sum of maximums - Sum of minimums
        return maxSubarraySum(nums) - minSubarraySum(nums);
    }
};