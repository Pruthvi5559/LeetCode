// 1563. Stone Game V

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sums for O(1) range-sum queries
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score Alice can get
        // from the subarray [l...r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Process smaller intervals before larger intervals
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                // Try every possible split
                for (int mid = l; mid < r; mid++) {

                    int leftSum =
                        prefix[mid + 1] - prefix[l];

                    int rightSum =
                        prefix[r + 1] - prefix[mid + 1];

                    if (leftSum < rightSum) {

                        // Bob removes the right part.
                        // Alice keeps the left part.
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][mid]
                        );

                    } else if (leftSum > rightSum) {

                        // Bob removes the left part.
                        // Alice keeps the right part.
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[mid + 1][r]
                        );

                    } else {

                        // Equal sums: Alice can choose either part.
                        dp[l][r] = max({
                            dp[l][r],
                            leftSum + dp[l][mid],
                            rightSum + dp[mid + 1][r]
                        });
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};