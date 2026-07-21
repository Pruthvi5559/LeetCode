//3699. Number of ZigZag Arrays I
class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<int> up(m), down(m);

        // length = 2
        for (int v = 0; v < m; v++) {
            up[v] = v;
            down[v] = m - 1 - v;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> prefUp(m + 1, 0);
            vector<int> prefDown(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] =
                    (prefUp[i] + up[i]) % MOD;

                prefDown[i + 1] =
                    (prefDown[i] + down[i]) % MOD;
            }

            vector<int> newUp(m);
            vector<int> newDown(m);

            for (int v = 0; v < m; v++) {

                // previous value < current value
                newUp[v] = prefDown[v];

                // previous value > current value
                newDown[v] =
                    (prefUp[m] - prefUp[v + 1] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        if (n == 2) {
            for (int v = 0; v < m; v++) {
                ans += up[v];
                ans += down[v];
            }
            return ans % MOD;
        }

        for (int v = 0; v < m; v++) {
            ans += up[v];
            ans += down[v];
            ans %= MOD;
        }

        return (int)ans;
    }
};
