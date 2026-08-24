// 1872. Stone Game VIII

/* Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:

Choose an integer x > 1, and remove the leftmost x stones from the row.
Add the sum of the removed stones' values to the player's score.
Place a new stone, whose value is equal to that sum, on the left side of the row.
The game stops when only one stone is left in the row.

The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference.

Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and Bob if they both play optimally. */

class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // dp represents the best score difference
        // from the current position.
        long long dp = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};