//3886. Sum of Sortable Integers
/*
You are given an integer array nums of length n.
An integer k is called sortable if k divides n 
and you can sort nums in non-decreasing order by 
sequentially performing the following operations:

Partition nums into consecutive subarrays of length k.
Cyclically rotate each subarray independently any number of times to the left or to the right.
Return an integer denoting the sum of all possible sortable integers k.
*/

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int k = 1; k <= n; k++){
            if( n%k ) continue;
            bool ok = 1;
            int prev_max = INT_MIN;
            bool first = 1;

            for(int i = 0; i < n; i+=k){
                int d = 0, mn = 1e9, mx = -1e9;
                for(int j = 0; j < k; j++){
                    int cur = nums[i+j];
                    int nxt = nums[i+(j+1)%k];
                    if(cur > nxt) d++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }

                if(d > 1){ok = 0; break;}
                if(!first && prev_max>mn){ok = 0; break;}
                prev_max = mx;
                first = 0;
            }
            if(ok) ans+=k;
        }
        return ans;
    }
};