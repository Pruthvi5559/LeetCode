//1406. Stone Game III
class Solution {
public:
    int n;

    // Memoization table
    vector<int> t;

    // Returns the maximum score difference the current player
    // can achieve starting from index i
    int solve(int i, vector<int>& stoneValue) {

        // No stones left
        if (i >= n) return 0;

        // Return memoized result
        if (t[i] != -1) return t[i];

        int result = INT_MIN;

        // Take one stone
        result = max(result,
                     stoneValue[i] - solve(i + 1, stoneValue));

        // Take two stones
        if (i + 1 < n) {
            result = max(result,
                         stoneValue[i] + stoneValue[i + 1] -
                         solve(i + 2, stoneValue));
        }

        // Take three stones
        if (i + 2 < n) {
            result = max(result,
                         stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                         solve(i + 3, stoneValue));
        }

        // Store and return the best score difference
        return t[i] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();

        t.resize(n + 1, -1);

        // Maximum score difference Alice can achieve
        int diff = solve(0, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";

        return "Tie";
    }
};