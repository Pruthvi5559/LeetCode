//2029. Stone Game IX

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0};

        // Count stones based on their remainder modulo 3
        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If the number of remainder-0 stones is even,
        // Alice wins as long as both remainder-1 and
        // remainder-2 stones are available.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If remainder-0 stones are odd, one type must have
        // at least 3 more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};