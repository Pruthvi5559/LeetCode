//3739. Count Subarrays With Majority Element II
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        int cumSum = 0;
        mp[0] = 1;

        long long validLeftPoints = 0;
        long long result = 0;

        for(int j=0; j<nums.size(); j++){
            if(nums[j] == target){
                validLeftPoints += mp[cumSum];
                cumSum +=1;
            }else{
                cumSum -=1;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum] += 1;
            result += validLeftPoints;
        }
        return result;
    }
};