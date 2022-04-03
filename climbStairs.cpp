class Solution {
public:
    int climbStairs(int n) {
        return step(n);
    }
private:
    int step(int n) {
        /*
        if (n <= 2) {
            return n;
        }
        return step(n-1) + step(n-2);
        */
        result[1] = 1;
        result[2] = 2;
        for (int i = 3; i <= n; i++) {
            result[i] = result[i-1] + result[i-2];
        }
        return result[n];
    }
    unordered_map<int, int> result;
};
