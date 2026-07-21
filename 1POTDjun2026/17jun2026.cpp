//1358. Number of Substrings Containing All Three Characters
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>lastseen = {-1,-1,-1};
        int cnt = 0;
        for(int i = 0; i < n; i++){
            lastseen[s[i]-'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt = cnt + (1+min({lastseen[0],lastseen[1],lastseen[2]}));
            }
        }
        return cnt;
    }
};