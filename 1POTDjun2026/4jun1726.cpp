//3614. Process String with Special Operations II
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        long long curr = 0;

        for(int i=0; i<n; i++){
            char c = s[i];
            if(c >='a' && c <='z'){
                curr++;
            }else if(c == '*'){
                if(curr>0) curr--;
            }else if( c == '#'){
                curr = min(curr *2, (long long)4e18);
            }
            len[i]=curr;
        }

        if(k<0 || k>=curr){
            return '.';
        }

        for(int i = n-1; i>=0; i--){
            long long prevLen = (i==0) ? 0 : len[i-1];
            char c = s[i];
            if(c>='a' && c<='z'){
                if(k == prevLen){
                    return c;
                }
            }else if(c == '#'){
                if(k>=prevLen){
                    k-=prevLen;
                }
            }else if(c == '%'){
                k = prevLen -1 -k;
            }
        }
        return '.';
    }
};