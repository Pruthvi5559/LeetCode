//2410. Maximum Matching of Players With Trainers
/*
You are given a 0-indexed integer array players, where players[i] 
represents the ability of the ith player. You are also given a 0-indexed integer array trainers, 
where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less 
than or equal to the trainer's training capacity. Additionally, the ith player 
can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.
*/

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        int cnt = 0;
        int i = 0, j = 0;

        // Sort players and trainers by ability.
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        // Try to match each player with the smallest suitable trainer.
        while (i < n && j < m) {

            // Current trainer can train the current player.
            if (players[i] <= trainers[j]) {
                cnt++;
                i++;
                j++;
            }
            else {
                // Trainer is too weak, so skip this trainer.
                j++;
            }
        }

        return cnt;
    }
};