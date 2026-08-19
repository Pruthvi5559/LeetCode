// 1386. Cinema Seat Allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Store reserved seats for only the affected rows
        unordered_map<int, int> reserved;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            // Use bits 2...9 to represent reserved seats
            reserved[row] |= (1 << col);
        }

        int ans = 2 * n;

        // Rows with reservations may have fewer than 2 groups
        for (auto &[row, mask] : reserved) {

            int groups = 0;

            // Seats 2,3,4,5 are all free
            bool left =
                !(mask & (1 << 2)) &&
                !(mask & (1 << 3)) &&
                !(mask & (1 << 4)) &&
                !(mask & (1 << 5));

            // Seats 6,7,8,9 are all free
            bool right =
                !(mask & (1 << 6)) &&
                !(mask & (1 << 7)) &&
                !(mask & (1 << 8)) &&
                !(mask & (1 << 9));

            // If both sides are available, we can seat 2 groups
            if (left && right) {
                groups = 2;
            }
            else {

                // Check the middle block: 4,5,6,7
                bool middle =
                    !(mask & (1 << 4)) &&
                    !(mask & (1 << 5)) &&
                    !(mask & (1 << 6)) &&
                    !(mask & (1 << 7));

                if (left || right || middle) {
                    groups = 1;
                }
            }

            // An initially empty row was counted as 2,
            // so replace that with its actual number.
            ans -= 2 - groups;
        }

        return ans;
    }
};