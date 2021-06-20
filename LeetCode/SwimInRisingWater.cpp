// Swim in Rising Water


// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).
// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim 
// from a square to another 4-directionally adjacent square if and only if the elevation of 
// both squares individually are at most t. You can swim infinite distance in zero time. Of course, 
// you must stay within the boundaries of the grid during your swim.

// You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size(), l = grid[0][0], r = N * N - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (reachable(m, grid, N)) r = m;
            else l = m + 1;
        }
        return r;
    }

    int reachable(int T, vector<vector<int>>& grid, int N) {
        queue<pair<int, int>> bfs;
        vector<vector<int>> seen(N, vector<int>(N, 0));
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
        bfs.emplace(0, 0);
        seen[0][0] = 1;
        while (bfs.size()) {
            int x = bfs.front().first, y = bfs.front().second;
            bfs.pop();
            if (grid[x][y] <= T) {
                if (x == N - 1 && y == N - 1) return true;
                for (auto& d : dir) {
                    int i = x + d[0], j = y + d[1];
                    if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j]) {
                        seen[i][j] = 1;
                        bfs.emplace(i, j);
                    }
                }
            }
        }
        return false;
    }
};