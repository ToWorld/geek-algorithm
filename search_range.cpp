class Solution {
public:
    // left = >= target(第一个)
    // right = <= target(最后一个)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if (nums.size() == 0) {
            return {-1,-1};
        }
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid]>=target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        if (nums[right] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(right);
        }
        
        right = nums.size()-1;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (nums[mid]<=target) {
                left = mid;
            } else {
                right = mid-1;
            }
        }
        if (nums[right] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(right);
        }
        
        return ans;
    }
};
