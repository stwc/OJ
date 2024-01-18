class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int maxRow[51], maxCol[51];
        memset(maxRow, 0, sizeof(maxRow));
        memset(maxCol, 0, sizeof(maxCol));
        int len = grid.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[i] = max(maxCol[i], grid[j][i]);
            }
        }
        int rst = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j)
                rst += (min(maxRow[i], maxCol[j]) - grid[i][j]);
        }
        return rst;
    }
};