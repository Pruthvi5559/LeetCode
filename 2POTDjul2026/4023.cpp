//3513. Number of Unique XOR Triplets I
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // For n <= 2, all possible XOR values are unique
        if (n <= 2)
            return n;

        // Find the smallest power of 2 greater than n
        int ans = 1;
        while (ans <= n) {
            ans <<= 1;
        }

        return ans;
    }
};