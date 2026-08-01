//486. Predict the Winner
class Solution {
public:
    int t[23][23];

    // Returns the maximum score the current player can obtain
    // from the subarray nums[i...j].
    int solve(int i, int j, vector<int>& nums) {

        // No elements left.
        if (i > j)
            return 0;

        // Only one element left.
        if (i == j)
            return nums[i];

        // Return the already computed answer.
        if (t[i][j] != -1)
            return t[i][j];

        // If current player picks the left element,
        // opponent plays optimally and leaves us the
        // minimum possible future score.
        int take_i = nums[i] +
                     min(solve(i + 2, j, nums),
                         solve(i + 1, j - 1, nums));

        // If current player picks the right element,
        // opponent again minimizes our future score.
        int take_j = nums[j] +
                     min(solve(i, j - 2, nums),
                         solve(i + 1, j - 1, nums));

        // Store and return the best possible score.
        return t[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {

        // Initialize DP table.
        memset(t, -1, sizeof(t));

        int n = nums.size();

        // Total sum of all elements.
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Maximum score Player 1 can achieve.
        int p1 = solve(0, n - 1, nums);

        // Remaining score belongs to Player 2.
        int p2 = sum - p1;

        // Player 1 wins even if the scores are equal.
        return p1 >= p2;
    }
};