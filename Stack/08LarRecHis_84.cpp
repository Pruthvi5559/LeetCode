//84. Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Stores the maximum rectangle area
        int maxi = INT_MIN;

        int nse, pse, elem;

        // Monotonic increasing stack (stores indices)
        stack<int> st;

        for (int i = 0; i < n; i++) {

            // Current bar is the Next Smaller Element (NSE)
            // for all taller bars in the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {

                elem = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                // Width = NSE - PSE - 1
                maxi = max(maxi, heights[elem] * (nse - pse - 1));
            }

            st.push(i);
        }

        // Process remaining bars (NSE = n)
        while (!st.empty()) {

            elem = st.top();
            st.pop();

            nse = n;
            pse = st.empty() ? -1 : st.top();

            // Width = NSE - PSE - 1
            maxi = max(maxi, heights[elem] * (nse - pse - 1));
        }

        return maxi;
    }
};