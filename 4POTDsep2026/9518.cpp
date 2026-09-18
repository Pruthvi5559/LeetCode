//1520. Maximum Number of Non-Overlapping Substrings
/*Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of 
substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in any order.
 */

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> firstOccurrence(26, n);
        vector<int> lastOccurrence(26, -1);

        // Find the first and last occurrence of every character.
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';

            firstOccurrence[ch] = min(firstOccurrence[ch], i);
            lastOccurrence[ch] = i;
        }

        vector<pair<int, int>> validIntervals;

        // Build the smallest valid interval starting at each character's
        // first occurrence.
        for (int ch = 0; ch < 26; ch++) {
            if (lastOccurrence[ch] == -1)
                continue;

            int start = firstOccurrence[ch];
            int end = lastOccurrence[ch];

            bool isValid = true;

            for (int i = start; i <= end; i++) {
                int currentChar = s[i] - 'a';

                // This character occurs before our current start,
                // so the substring cannot contain all its occurrences.
                if (firstOccurrence[currentChar] < start) {
                    isValid = false;
                    break;
                }

                // We must include every occurrence of this character.
                end = max(end, lastOccurrence[currentChar]);
            }

            if (isValid) {
                validIntervals.push_back({start, end});
            }
        }

        // Earliest ending interval first -> maximum number of
        // non-overlapping intervals.
        sort(validIntervals.begin(), validIntervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int previousEnd = -1;

        for (auto &[start, end] : validIntervals) {
            if (start > previousEnd) {
                result.push_back(s.substr(start, end - start + 1));
                previousEnd = end;
            }
        }

        return result;
    }
};