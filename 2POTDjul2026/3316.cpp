//3867. Sum of GCD of Formed Pairs
class Solution {
public:
    int gcd(int m,int n){
        int r;
        while(n != 0){
            r = m%n;
            m = n;
            n = r;
        }
        return m;
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = nums[0];
        for(int i : nums){
            mx = max(mx,i);
            prefixGcd.push_back(gcd(i,mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int n = prefixGcd.size();
        int small = 0, large = n-1;
        long long sum = 0;
        while(small < large){
            sum = sum + gcd(prefixGcd[small], prefixGcd[large]);
            small++;
            large--;
        }
        return sum;
    }
};