class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        while (left < right) {
            int lmid = (left+right)/2;
            int rmid = lmid+1;
            // 递增，则放弃left
            if (nums[lmid] <= nums[rmid]) {
                left = lmid+1;
            } else {
                // 递减，则放弃right，直接从rmid-1开始
                right = rmid-1;
            }
        }
        return right;
    }
};
