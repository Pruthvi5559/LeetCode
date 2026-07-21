//1967. Number of Strings That Appear as Substrings in Word
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &pat : patterns) {

            int m = pat.size();
            int n = word.size();

            bool found = false;

            for (int i = 0; i <= n - m; i++) {

                int j = 0;

                while (j < m && word[i + j] == pat[j]) {
                    j++;
                }

                if (j == m) {
                    found = true;
                    break;
                }
            }

            if (found)
                ans++;
        }

        return ans;
    }
};