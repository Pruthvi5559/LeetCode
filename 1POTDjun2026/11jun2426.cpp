//3700. Number of ZigZag Arrays II
class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef vector<vector<long long>> Matrix;

    int SZ, L, R;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                for (int j = 0; j < n; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }

    Matrix matpow(Matrix M, long long p) {
        int n = M.size();
        Matrix result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) result[i][i] = 1;
        while (p > 0) {
            if (p & 1) result = multiply(result, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return result;
    }

    int idx(int v, int d) { return (v - L) * 2 + d; }

    int zigZagArrays(int n, int l, int r) {
        L = l; R = r;
        SZ = (r - l + 1) * 2;

        Matrix M(SZ, vector<long long>(SZ, 0));
        for (int v = l; v <= r; v++) {
            
            int from = idx(v, 0);
            for (int u = l; u < v; u++)
                M[from][idx(u, 1)] = 1;
            
            from = idx(v, 1);
            for (int u = v + 1; u <= r; u++)
                M[from][idx(u, 0)] = 1;
        }

        
        vector<long long> cur(SZ, 0);
        for (int a = l; a <= r; a++)
            for (int b = l; b <= r; b++) {
                if (a < b) cur[idx(b, 0)]++;   
                if (a > b) cur[idx(b, 1)]++;   
            }

        
        Matrix Mp = matpow(M, n - 2);

        vector<long long> res(SZ, 0);
        for (int i = 0; i < SZ; i++) {
            if (!cur[i]) continue;
            for (int j = 0; j < SZ; j++)
                res[j] = (res[j] + cur[i] * Mp[i][j]) % MOD;
        }

        long long ans = 0;
        for (auto x : res) ans = (ans + x) % MOD;
        return ans;
    }
};