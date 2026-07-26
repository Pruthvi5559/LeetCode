//496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Stack to maintain a decreasing sequence
        stack<int> st;

        // Map: element -> its next greater element
        unordered_map<int, int> nge;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all elements smaller than or equal to current element
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists
            if (st.empty())
                nge[nums2[i]] = -1;
            else
                nge[nums2[i]] = st.top();

            // Push current element onto the stack
            st.push(nums2[i]);
        }

        // Build the answer for nums1 using the hash map
        vector<int> ans;

        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};