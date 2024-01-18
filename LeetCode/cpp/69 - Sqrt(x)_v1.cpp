// Intuitive but slow, need to be improved.
class Solution
{
public:
    int mySqrt(int x)
    {
        double root;
        for (root = 1.0; root * root <= (double) x; ++root)
            ;
        return (int) (root - 1.0);
    }
};