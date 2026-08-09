//1140. Stone Game II
class Solution {
public:
    int n;

    // dp[player][i][M]
    // player = 1 -> Alice's turn
    // player = 0 -> Bob's turn
    vector<vector<vector<int>>> dp;

    // Returns the number of stones Alice can finally get
    int dfs(bool alice, int i, int M, vector<int>& piles) {

        // All piles have been taken
        if (i == n)
            return 0;

        // Return memoized result
        if (dp[alice][i][M] != -1)
            return dp[alice][i][M];

        int result = alice ? 0 : INT_MAX;
        int total = 0;

        // Current player can take X piles, where 1 <= X <= 2*M
        for (int X = 1; X <= 2 * M; X++) {

            if (i + X > n)
                break;

            // Add the newly taken pile
            total += piles[i + X - 1];

            // Alice wants to maximize her stones
            if (alice) {
                result =
                    max(result, total + dfs(false, i + X, max(M, X), piles));
            }
            // Bob wants to minimize Alice's final stones
            else {
                result = min(result, dfs(true, i + X, max(M, X), piles));
            }
        }

        return dp[alice][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        // Maximum possible M is n
        dp.assign(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));

        // Alice starts from index 0 with M = 1
        return dfs(true, 0, 1, piles);
    }
};