class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int lenR = matrix.size();
        int lenC = matrix[0].size();

        // Mark zero
        int flag = -1;
        if (matrix[0][0] != 0) {
            for (int j = 1; j < lenC; ++j) {
                if (matrix[0][j] == 0) {
                    flag = 1;
                    break;
                }
            }
            for (int i = 1; i < lenR; ++i) {
                if (matrix[i][0] == 0 && flag == 1) {
                    flag = 0;
                    break;
                }
                if (matrix[i][0] == 0 && flag == -1) {
                    flag = 2;
                    break;
                }
            }
        } else
            flag = 0;
        for (int i = 1; i < lenR; ++i) {
            for (int j = 1; j < lenC; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set to zero
        for (int i = 1; i < lenR; ++i) {
            if (matrix[i][0] == 0)
                fill(matrix[i].begin() + 1, matrix[i].end(), 0);
        }
        for (int j = 1; j < lenC; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < lenR; ++i)
                    matrix[i][j] = 0;
            }
        }
        if (flag == 0) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
            for (int i = 0; i < lenR; ++i)
                matrix[i][0] = 0;
        } else if (flag == 1) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        } else if (flag == 2) {
            for (int i = 0; i < lenR; ++i)
                matrix[i][0] = 0;
        }
    }
};