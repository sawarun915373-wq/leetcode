class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRowZero = true;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstColZero = true;

        // use first row and first column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // apply markers to the inner block
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // first row and column last, using the saved flags
        if (firstRowZero)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        if (firstColZero)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};