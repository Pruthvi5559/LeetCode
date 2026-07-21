//3756. Concatenate Non-Zero Digits and Multiply by Sum II
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        std::vector<long long> pref_sum(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            pref_sum[i + 1] = pref_sum[i] + (s[i] - '0');
        }

        std::string s_prime = "";
        std::vector<int> next_nonzero(m, -1);
        std::vector<int> prev_nonzero(m, -1);
        
        int current_nz_idx = 0;
        for (int i = 0; i < m; ++i) {
            if (s[i] != '0') {
                s_prime += s[i];
                current_nz_idx++;
            }
            prev_nonzero[i] = current_nz_idx - 1; 
        }

        int n_prime = s_prime.length();
        
        current_nz_idx = n_prime - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] != '0') {
                current_nz_idx--;
            }
            next_nonzero[i] = current_nz_idx + 1;
        }

        std::vector<long long> power10(n_prime + 1, 1);
        for (int i = 1; i <= n_prime; ++i) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        std::vector<long long> pref_val(n_prime + 1, 0);
        for (int i = 0; i < n_prime; ++i) {
            pref_val[i + 1] = (pref_val[i] * 10 + (s_prime[i] - '0')) % MOD;
        }

        std::vector<int> answer;
        answer.reserve(queries.size());


        for (const auto& q : queries) {
            int li = q[0];
            int ri = q[1];

            int l_prime = next_nonzero[li];
            int r_prime = prev_nonzero[ri];

    
            if (l_prime > r_prime || l_prime >= n_prime || r_prime < 0) {
                answer.push_back(0);
                continue;
            }

           
            int len = r_prime - l_prime + 1;
            long long x_mod = (pref_val[r_prime + 1] - (pref_val[l_prime] * power10[len]) % MOD + MOD) % MOD;

            long long current_sum = pref_sum[ri + 1] - pref_sum[li];

            long long q_ans = (x_mod * current_sum) % MOD;
            answer.push_back(static_cast<int>(q_ans));
        }

        return answer;
    }
};


