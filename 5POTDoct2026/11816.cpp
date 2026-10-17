//3551. Minimum Swaps to Sort by Digit Sum
/*
You are given an array nums of distinct positive integers. 
You need to sort the array in increasing order based on the 
sum of the digits of each number. If two numbers have the 
same digit sum, the smaller number appears first in the sorted order.

Return the minimum number of swaps required to rearrange nums 
into this sorted order.
A swap is defined as exchanging the values at two distinct positions in the array.
*/

class Solution {
private:
    int helper(int x){
        int total = 0;
        while(x > 0){
            total += x%10;
            x /= 10;
        }
        return total;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> initial;
        for(int i = 0; i < n; ++i){
            initial[nums[i]] = i;
        }    

        auto comp = [this](int a, int b) {
            int sumA = helper(a);
            int sumB = helper(b);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a < b;
        };

        sort(nums.begin(), nums.end(), comp);

        vector<bool> visited(n, false);
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            
            int j = i;
            int steps = 0;
            while (!visited[j]) {
                visited[j] = true;
                steps++;
                j = initial[nums[j]];
            }
            res += steps - 1;
        }
        
        return res;
    }
};