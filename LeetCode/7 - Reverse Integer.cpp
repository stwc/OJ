class Solution {
public:
    int reverse(int x) {
        long long  sol = 0;
        char str[15];
        sprintf(str, "%d", abs(x));
        
        int len = strlen(str);
        for (int i = len - 1; i >= 0; --i)
            sol = sol * 10 + str[i] - '0';
        sol = (x > -1)? sol : -sol;
        
        if ((x < 0 && sol < INT_MIN) || (sol > INT_MAX))
            return 0;
        else
            return (int)sol;
    }
};