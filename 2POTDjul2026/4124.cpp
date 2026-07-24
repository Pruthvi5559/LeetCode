//3514. Number of Unique XOR Triplets II
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> present(MAXX, false);
        for (int x : nums)
            present[x] = true;

        vector<bool> pairXor(MAXX, false);

        // All possible XORs of two values present in the array
        for (int a = 0; a < MAXX; a++) {
            if (!present[a])
                continue;
            for (int b = a; b < MAXX; b++) {
                if (!present[b])
                    continue;
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> tripletXor(MAXX, false);

        // XOR every pair XOR with every value present
        for (int x = 0; x < MAXX; x++) {
            if (!pairXor[x])
                continue;
            for (int v = 0; v < MAXX; v++) {
                if (present[v])
                    tripletXor[x ^ v] = true;
            }
        }

        return count(tripletXor.begin(), tripletXor.end(), true);
    }
};