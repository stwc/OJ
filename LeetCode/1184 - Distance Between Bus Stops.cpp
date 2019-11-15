class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance,
                                int start,
                                int destination)
    {
        int n = distance.size();
        if (start > destination)
            swap(start, destination);

        int total = 0, d = 0;
        for (int &i : distance)
            total += i;
        for (int i = start; i < destination; ++i)
            d += distance[i];
        return min(d, total - d);
    }
};
