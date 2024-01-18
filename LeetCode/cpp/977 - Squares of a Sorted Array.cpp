class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> rst(A.size());
        int front = 0, end = A.size() - 1;
        for (int i = end; i >= 0; --i) {
            int a = A[front] * A[front];
            int b = A[end] * A[end];
            if (a > b) {
                rst[i] = a;
                ++front;
            } else {
                rst[i] = b;
                --end;
            }
        }
        return rst;
    }
};