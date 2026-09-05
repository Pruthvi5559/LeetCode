//455. Assign Cookies
/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie
j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize
the number of your content children and output the maximum number.
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int i = 0, j = 0;

        // Sort children's greed and cookie sizes.
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        // Try to satisfy each child using the smallest suitable cookie.
        while (i < g.size() && j < s.size()) {

            // Current cookie can satisfy the current child.
            if (s[j] >= g[i]) {
                cnt++;
                i++;
                j++;
            }
            else {
                // Cookie is too small, so try the next larger cookie.
                j++;
            }
        }

        return cnt;
    }
};