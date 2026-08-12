//2958. Length of Longest Subarray With at Most K Frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l=0, r=0;
        int len = 0, maxlen = 0;

        //stores freq of elem in the current window
        unordered_map<int, int> freq;
        
        for( r = 0; r < n; r++){
            
            //add current element to the window
            freq[nums[r]]++;

            //shrink window until every freq is <= k
            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }

            //update maximum valid window lenght
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
        
    }
};