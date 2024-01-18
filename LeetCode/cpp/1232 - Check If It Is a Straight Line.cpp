class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() == 2)
            return true;

        int delX = coordinates[0][0] - coordinates[1][0];
        int delY = coordinates[0][1] - coordinates[1][1];
        for (int i = 2; i < coordinates.size(); ++i) {
            int x = coordinates[i - 1][0] - coordinates[i][0];
            int y = coordinates[i - 1][1] - coordinates[i][1];
            if (x * delY != y * delX)
                return false;
        }
        return true;
    }
};
