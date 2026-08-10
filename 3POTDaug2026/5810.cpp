//1510. Stone Game IV
class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        // No stones left -> current player loses
        if (n == 0)
            return false;

        // Return already computed result
        if (dp[n] != -1)
            return dp[n];

        // Try taking every possible perfect square
        for (int x = 1; x * x <= n; x++) {

            // If opponent loses after our move,
            // current player wins
            if (!solve(n - x * x)) {
                return dp[n] = true;
            }
        }

        // No winning move found
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);

        return solve(n);
    }
};