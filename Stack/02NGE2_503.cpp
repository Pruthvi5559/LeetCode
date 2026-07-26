//503. Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // Stores the next greater element for each index
        vector<int> nge(n);

        // Monotonic decreasing stack (stores values)
        stack<int> st;

        // Traverse the array twice from right to left
        // This simulates the circular nature of the array
        for (int i = (2 * n) - 1; i >= 0; i--) {

            // Remove all elements that are smaller than or equal
            // to the current element since they can't be the next greater
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // Only fill answers during the first traversal
            // (i from n-1 down to 0)
            if (i < n) {
                // If stack is empty, no greater element exists
                // Otherwise, the top of the stack is the next greater element
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push the current element onto the stack
            // so it can serve as the next greater for elements to its left
            st.push(nums[i % n]);
        }

        return nge;
    }
};