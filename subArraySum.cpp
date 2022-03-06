class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // s[r] - s[l-1] = k
        // O(n): 计算s[x]
        // O(n): s[r]组成新元素, k+s[l-1]在unordered_map中, +1
        int ans = 0;
        int preMax = 0;
        // O(n): 计算s[x]
        for (int i = 0; i < nums.size(); i++) {
            preMax += nums[i];
            vec.push_back(preMax);
        }
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        unordered_map<int, int> h1;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == k) {
                ans += 1;
            }
            auto it = h1.find(vec[i]-k);
            if (it != h1.end()) {
                ans += it->second;
                //cout << "step2 ans:" << ans << endl;
            }
            // 如何避免值覆盖
            // 第一次
            if (h1.find(vec[i]) == h1.end()) {
                h1[vec[i]] = 1;
            } else {
                int oldCurr = h1[vec[i]];
                h1[vec[i]] += 1;
            }
        }
        return ans;
    }
private:
    vector<int> vec;
};
