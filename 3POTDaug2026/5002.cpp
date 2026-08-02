//877. Stone Game
class Solution {
public:
    // Memoization table
    int t[501][501];

    // Returns the maximum score difference the current player
    // can achieve over the opponent from piles[i...j]
    int solve(int i, int j, vector<int>& piles) {

        // No piles left
        if (i > j) return 0;

        // Only one pile left
        if (i == j) return piles[i];

        // Return memoized result
        if (t[i][j] != -1) return t[i][j];

        // Pick the left pile
        int take_i = piles[i] - solve(i + 1, j, piles);

        // Pick the right pile
        int take_j = piles[j] - solve(i, j - 1, piles);

        // Choose the better move
        return t[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        memset(t, -1, sizeof(t));

        // Alice wins if her score difference is non-negative
        return solve(0, n - 1, piles) >= 0;
    }
};