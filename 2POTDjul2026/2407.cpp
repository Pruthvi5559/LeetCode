//3754. Concatenate Non-Zero Digits and Multiply by Sum I
class Solution {
public:
    long long sumAndMultiply(int n) {
        string numStr = to_string(abs(n)); 

        numStr.erase(remove(numStr.begin(), numStr.end(), '0'), numStr.end());
        
        long long finalNumber = 0;
        if (!numStr.empty()) {
            finalNumber = stoll(numStr); 
        }
        
        long long digitSum = 0;
        for (char c : numStr) {
            if (c >= '0' && c <= '9') {
                digitSum += (c - '0');
            }
        }
        
        return finalNumber * digitSum;
    }
};