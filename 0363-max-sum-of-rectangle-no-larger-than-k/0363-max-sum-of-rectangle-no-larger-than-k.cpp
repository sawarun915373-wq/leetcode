class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        bool transpose = m > n;
        int R = transpose ? n : m;       // smaller dimension, paired up in the outer loops
        int C = transpose ? m : n;       // larger dimension, scanned with the ordered set
        auto at = [&](int r, int c) {
            return transpose ? matrix[c][r] : matrix[r][c];
        };

        int best = INT_MIN;
        for (int top = 0; top < R; top++) {
            vector<int> colSum(C, 0);
            for (int bot = top; bot < R; bot++) {
                for (int c = 0; c < C; c++) colSum[c] += at(bot, c);

                set<int> prefixes;
                prefixes.insert(0);
                int pre = 0;
                for (int c = 0; c < C; c++) {
                    pre += colSum[c];
                    auto it = prefixes.lower_bound(pre - k);   // smallest earlier prefix >= pre - k
                    if (it != prefixes.end()) best = max(best, pre - *it);
                    prefixes.insert(pre);
                }
                if (best == k) return k;                       // cannot beat k
            }
        }
        return best;
    }
};