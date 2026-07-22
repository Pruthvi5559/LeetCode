//1189. Maximum Number of Balloons
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() < 7) return 0;
        vector<int> hash(5,0);
        for(char ch: text){
            if(ch == 'b'){
                hash[0]+=1;
            }else if(ch == 'a'){
                hash[1]+=1;
            }else if(ch == 'l'){
                hash[2]+=1;
            }else if(ch == 'o'){
                hash[3]+=1;
            }else if(ch == 'n'){
                hash[4]+=1;
            }
        }
        hash[2]/=2;
        hash[3]/=2;
        return *min_element(hash.begin(),hash.end());
    }
};