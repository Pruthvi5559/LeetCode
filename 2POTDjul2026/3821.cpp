//3499. Maximize Active Section with Trade I
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        // Augment with '1' at both ends
        s = '1' + s + '1';

        int ans = ones;

        int prevZero = 0;
        int oneRun = 0;
        bool havePrevZero = false;

        int i = 1;
        while (i < s.size() - 1) {
            char ch = s[i];
            int len = 0;

            while (i < s.size() - 1 && s[i] == ch) {
                len++;
                i++;
            }

            if (ch == '0') {
                if (havePrevZero) {
                    // Pattern: prevZero - oneRun - len
                    ans = max(ans, ones + prevZero + len);
                }
                prevZero = len;
                havePrevZero = true;
            } else {
                oneRun = len;
            }
        }

        return ans;
    }
};