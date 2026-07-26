//402. Remove K Digits
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        // Monotonic increasing stack
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char digit = num[i];

            // Remove larger previous digits to minimize the number
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }

            st.push(digit);
        }

        // Remove remaining digits from the end if needed
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // If all digits are removed
        if (st.empty()) return "0";

        string ans = "";

        // Build the number in reverse order
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Remove leading zeros (currently at the end due to reversal)
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }

        // Restore original order
        reverse(ans.begin(), ans.end());

        // If only zeros were present
        if (ans.empty()) return "0";

        return ans;
    }
};