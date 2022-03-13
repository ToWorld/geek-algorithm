class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        total = nums.size();
        visit = vector<bool>(total, false);
        permute(nums, 0);
        return result;
    }
    // 占第一个坑位,直到没有坑位返回
    void permute(vector<int>& candidates, int pos) {
        if (pos == total) {
            string s = getStr(a);
            if (h.find(s) == h.end()) {
                result.push_back(a);
                h[s] = true;
            }
            
            return;
        }
        // 第pos个位置，随机选1个
        for (int i = 0; i < total; i++) {
            if (!visit[i]) {
                a.push_back(candidates[i]);
                visit[i] = true;
                permute(candidates, pos+1);
                visit[i] = false;
                a.pop_back();
            }
        }
        return;
    }
    string getStr(vector<int>& s) {
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            s1 += to_string(s[i]);
        }
        return s1;
    }
private:
    int total;
    vector<vector<int>> result;
    vector<bool> visit;
    vector<int> a;
    unordered_map<string, bool> h;
};
