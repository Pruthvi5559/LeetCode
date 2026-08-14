//3090. Maximum Length Substring With Two Occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l=0;
        int len = 0, maxlen = 0;

        //stores freq of elem in the current window
        unordered_map<char, int> freq;
        
        for(int r = 0; r < n; r++){
            
            //add current element to the window
            freq[s[r]]++;

            //shrink window until every freq is <= 2
            while(freq[s[r]] > 2){
                freq[s[l]]--;
                l++;
            }

            //update maximum valid window lenght
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};