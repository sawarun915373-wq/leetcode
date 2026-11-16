class Solution {
    int rows[9], cols[9], boxes[9];
    vector<pair<int,int>> empties;

    void place(int i, int j, int d) {
        int bit = 1 << d;
        rows[i] |= bit;
        cols[j] |= bit;
        boxes[(i / 3) * 3 + j / 3] |= bit;
    }

    void unplace(int i, int j, int d) {
        int bit = ~(1 << d);
        rows[i] &= bit;
        cols[j] &= bit;
        boxes[(i / 3) * 3 + j / 3] &= bit;
    }

    bool dfs(vector<vector<char>>& board, int done) {
        int n = empties.size();
        if (done == n) return true;

        int best = done, bestCount = 10, bestMask = 0;
        for (int k = done; k < n; k++) {
            int i = empties[k].first, j = empties[k].second;
            int used = rows[i] | cols[j] | boxes[(i / 3) * 3 + j / 3];
            int avail = ~used & 0x1FF;
            int cnt = __builtin_popcount(avail);
            if (cnt < bestCount) {
                bestCount = cnt;
                best = k;
                bestMask = avail;
                if (cnt <= 1) break;
            }
        }
        if (bestCount == 0) return false;

        swap(empties[done], empties[best]);
        int i = empties[done].first, j = empties[done].second;

        while (bestMask) {
            int d = __builtin_ctz(bestMask);
            bestMask &= bestMask - 1;

            place(i, j, d);
            board[i][j] = '1' + d;
            if (dfs(board, done + 1)) return true;
            unplace(i, j, d);
        }

        board[i][j] = '.';
        swap(empties[done], empties[best]);
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof rows);
        memset(cols, 0, sizeof cols);
        memset(boxes, 0, sizeof boxes);
        empties.clear();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') empties.push_back({i, j});
                else place(i, j, board[i][j] - '1');
            }
        }
        dfs(board, 0);
    }
};