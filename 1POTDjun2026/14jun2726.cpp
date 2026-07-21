//3020. Find the Maximum Number of Elements in Subset
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &[start, cnt] : freq) {

            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (true) {

                if (!freq.count(x))
                    break;

                if (freq[x] == 1) {
                    len++;
                    break;
                }

                len += 2;

                if (x > 1000000000LL / x)
                    break;

                x *= x;
            }

            if (len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};