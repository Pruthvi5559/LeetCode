//1621. Number of Sets of K Non-Overlapping Line Segments
/*
Given n points on a 1-D plane, where the ith point (from 0 to n-1) 
is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment 
covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments 
do not have to cover all n points, and they are allowed to share endpoints.

Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.
*/
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int dp[1001][1001];
    int prefDp[1001][1001];

    int add(int a, int b) {
        return (a + b) % MOD;
    }

    // Sum of solve(i, k) for i = 1 ... n.
    int prefOk(int n, int k) {
        if (n <= 0)
            return 0;

        if (prefDp[n][k] != -1)
            return prefDp[n][k];

        return prefDp[n][k] =
            add(prefOk(n - 1, k), solve(n, k));
    }

    int solve(int n, int k) {
        // No segments -> exactly one way.
        if (k == 0)
            return 1;

        // k segments need at least k + 1 points.
        if (n < k + 1)
            return 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        // Case 1: point n - 1 is not used.
        int ans = solve(n - 1, k);

        // Case 2: the last segment ends at point n - 1.
        // Its starting point can be anywhere before it.
        ans = add(ans, prefOk(n - 1, k - 1));

        return dp[n][k] = ans;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(prefDp, -1, sizeof(prefDp));

        return solve(n, k);
    }
};