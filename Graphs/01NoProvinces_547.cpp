//547. Number of Provinces
/*
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected 
directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and 
no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 
if the ith city and the jth city are directly connected, 
and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;

        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};