//3414. Maximum Score of Non-overlapping Intervals
/*
You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. 
Interval i starts at position li and ends at ri, and has a weight of weighti. 
You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from intervals with 
maximum score, representing your choice of non-overlapping intervals.

Two intervals are said to be non-overlapping if they do not share any points. 
In particular, intervals sharing a left or right boundary are considered overlapping.
*/


class Solution {
public:
    int n;
    vector<int> nextIdx;

    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    vector<vector<Node>> t;

    // Find the first interval starting after r.
    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0, hi = n - 1;
        int result = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        // Store the original index of each interval.
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        // Sort by start time.
        sort(intervals.begin(), intervals.end());

        // Find the next non-overlapping interval for each interval.
        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        }

        const int K = 4;

        // t[i][k] = best result using intervals from i onward,
        // selecting at most k intervals.
        t.assign(n + 1, vector<Node>(K + 1));

        for (int i = n - 1; i >= 0; i--) {
            int weight = intervals[i][2];
            int idx = intervals[i][3];
            int j = nextIdx[i];

            for (int k = 1; k <= K; k++) {

                // Option 1: Skip the current interval.
                Node skip = t[i + 1][k];

                // Option 2: Take it and move to the next
                // non-overlapping interval.
                Node temp = t[j][k - 1];

                Node take;
                take.score = temp.score + weight;
                take.idxs = temp.idxs;
                take.idxs.push_back(idx);

                // Keep indices sorted for lexicographical comparison.
                sort(begin(take.idxs), end(take.idxs));

                // Choose the higher score.
                // If scores tie, choose lexicographically smaller indices.
                Node result;

                if (skip.score > take.score) {
                    result = skip;
                } else if (skip.score < take.score) {
                    result = take;
                } else {
                    result = (skip.idxs < take.idxs) ? skip : take;
                }

                t[i][k] = result;
            }
        }

        return t[0][K].idxs;
    }
};