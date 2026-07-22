//907. Sum of Subarray Minimums
class Solution {
private:
    // Find Next Smaller Element (strictly smaller) indices
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--){

            // Remove elements greater than or equal to current
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            // Index of next smaller element
            ans[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }

        return ans;
    }

    // Find Previous Smaller or Equal Element indices
    vector<int> findPSEE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        // Traverse from left to right
        for(int i = 0; i < n; i++){

            // Remove strictly greater elements
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            // Index of previous smaller or equal element
            ans[i] = !st.empty() ? st.top() : -1;

            st.push(i);
        }

        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        // Nearest smaller element indices
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();
        int total = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){

            // Number of choices on left and right
            int left = i - psee[i];
            int right = nse[i] - i;

            // Number of subarrays where arr[i] is the minimum
            long long freq = 1LL * left * right;

            // Contribution of arr[i]
            int val = (1LL * freq * arr[i]) % mod;

            total = (total + val) % mod;
        }

        return total;
    }
};