//3789. Minimum Cost to Acquire Required Items
/*
You are given five integers cost1, cost2, costBoth, need1, and need2.

There are three types of items available:

An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least 
need1 and the total contribution toward type 2 is at least need2.

Return an integer representing the minimum possible total cost to achieve these requirements.
*/

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1;
        long long c2 = cost2;
        long long cBoth = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        // Cost to satisfy the overlapping requirement using either type 3 or individual type 1 + type 2
        long long common = min(n1, n2);
        long long totalCost = common * min(cBoth, c1 + c2);

        // Remaining requirement for type 1
        long long rem1 = n1 - common;
        totalCost += rem1 * min(c1, cBoth);

        // Remaining requirement for type 2
        long long rem2 = n2 - common;
        totalCost += rem2 * min(c2, cBoth);

        return totalCost;
    }
};