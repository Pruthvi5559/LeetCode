// 3116. Kth Smallest Amount With Single Denomination Combination

class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Enumerate all subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    long long g = gcd(L, (long long)coins[i]);

                    // Prevent LCM from exceeding x
                    long long temp = L / g;

                    if (temp > x / coins[i]) {
                        overflow = true;
                        break;
                    }

                    L = temp * coins[i];
                }
            }

            if (overflow || L > x)
                continue;

            long long current = x / L;

            // Odd number of elements -> add
            // Even number -> subtract
            if (bits % 2 == 1)
                count += current;
            else
                count -= current;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        // The kth amount cannot be greater than k * smallest coin
        long long minCoin = *min_element(coins.begin(), coins.end());

        long long high = minCoin * 1LL * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};