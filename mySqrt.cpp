class Solution {
public:
    // <=x(最后一个)(upper_bound)
    int mySqrt(int x) {
        int left = 1, right = x; 
        while (left < right) {
            int mid = left + (right-left+1)/2;
            // mid之后都满足，说明保持right，放弃left
            if (mid <= int(x/mid)) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        return right;
    }
};
