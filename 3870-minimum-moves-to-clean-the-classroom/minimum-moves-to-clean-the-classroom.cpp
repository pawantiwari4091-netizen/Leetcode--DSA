class Solution {
public:
    using VB = vector<bool>;
    using VVB = vector<VB>;
    using VVVB = vector<VVB>;
    using VVVVB = vector<VVVB>;

    int minMoves(vector<string>& classi, int energy) {
        int n = classi.size();
        int m = classi[0].size();

        vector<vector<int>> idx(n, vector<int>(m));

        int sr = 0, sc = 0;
        int k = 0;

        // Find starting position and assign index to every L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classi[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classi[i][j] == 'L') {
                    idx[i][j] = k++;
                }
            }
        }

        // No letters to collect
        if (k == 0)
            return 0;

        int totalMaxNumber = (1 << k) - 1;

        struct state {
            int r, c, energy, num;
        };

        queue<state> q;

        VVVVB seen(n, VVVB(m, VVB(energy + 1, VB(1 << k, false))));

        q.push({sr, sc, energy, 0});
        seen[sr][sc][energy][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int moves = 0;

        while (!q.empty()) {

            // Number of states in the current BFS level
            int size = q.size();

            while (size--) {

                state curr = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = curr.r + dr[d];
                    int nc = curr.c + dc[d];

                    // Out of bounds
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    // Wall
                    if (classi[nr][nc] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int ne = curr.energy - 1;

                    if (ne < 0)
                        continue;

                    int nnum = curr.num;

                    // Recharge
                    if (classi[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // Collect letter
                    if (classi[nr][nc] == 'L') {
                        nnum |= (1 << idx[nr][nc]);
                    }

                    // All letters collected
                    if (nnum == totalMaxNumber) {
                        return moves + 1;
                    }

                    // New state
                    if (!seen[nr][nc][ne][nnum]) {

                        seen[nr][nc][ne][nnum] = true;

                        q.push({nr, nc, ne, nnum});
                    }
                }
            }

            // Finished processing one BFS level
            moves++;
        }

        return -1;
    }
};