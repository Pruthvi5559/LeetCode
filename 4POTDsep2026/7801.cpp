//3568. Minimum Moves to Clean the Classroom
/*
You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:

'S': Starting position of the student
'L': Litter that must be collected (once collected, the cell becomes empty)
'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
'X': Obstacle the student cannot pass through
'.': Empty space
You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.

Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.

*/

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;

        // Give every litter cell a bit number.
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }

                if (classroom[r][c] == 'L') {
                    id[r][c] = litterCount++;
                }
            }
        }

        // No litter to collect.
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        // visited[r][c][mask][e]
        // Encode the 4D state into one integer.
        int statesPerCell = totalMasks * (energy + 1);

        vector<char> visited(m * n * statesPerCell, false);

        auto encode = [&](int r, int c, int mask, int e) {
            return ((r * n + c) * totalMasks + mask) * (energy + 1) + e;
        };

        auto decode = [&](int state, int& r, int& c, int& mask, int& e) {
            e = state % (energy + 1);
            state /= (energy + 1);

            mask = state % totalMasks;
            state /= totalMasks;

            r = state / n;
            c = state % n;
        };

        queue<int> q;

        int startMask = 0;
        int startState = encode(sr, sc, startMask, energy);

        visited[startState] = true;
        q.push(startState);

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int fullMask = totalMasks - 1;
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            // Process one BFS level = one number of moves.
            while (sz--) {
                int state = q.front();
                q.pop();

                int r, c, mask, e;
                decode(state, r, c, mask, e);

                // All litter collected.
                if (mask == fullMask)
                    return moves;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Cannot walk through obstacles.
                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Cannot move when energy is 0.
                    if (e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }

                    // Reset energy after reaching R.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int nextState = encode(nr, nc, nmask, ne);

                    if (!visited[nextState]) {
                        visited[nextState] = true;
                        q.push(nextState);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};