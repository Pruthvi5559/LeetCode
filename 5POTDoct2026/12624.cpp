//2409. Count Days Spent Together
/*
Alice and Bob are traveling to Rome for separate business meetings.
You are given 4 strings arriveAlice, leaveAlice, arriveBob, 
and leaveBob. Alice will be in the city from the dates arriveAlice 
to leaveAlice (inclusive), while Bob will be in the city from the 
dates arriveBob to leaveBob (inclusive). Each will be a 5-character 
string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.
You can assume that all dates occur in the same calendar year, which 
is not a leap year. Note that the number of days per month can be represented as: 
[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].
*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDayOfYear = [&](string s) {
            int m = (s[0] - '0') * 10 + (s[1] - '0');
            int d = (s[3] - '0') * 10 + (s[4] - '0');
            int totalDays = d;
            for (int i = 0; i < m - 1; i++) {
                totalDays += days[i];
            }
            return totalDays;
        };

        int aliceArrival = getDayOfYear(arriveAlice);
        int aliceLeave = getDayOfYear(leaveAlice);
        int bobArrival = getDayOfYear(arriveBob);
        int bobLeave = getDayOfYear(leaveBob);

        int start = max(aliceArrival, bobArrival);
        int end = min(aliceLeave, bobLeave);

        return max(0, end - start + 1);

    }
};