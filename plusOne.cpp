class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int incr = 1;
        vector<int> result;
        stack<int> tmp;
        for (int i = digits.size()-1; i>=0; i--) {
            if (digits[i]+incr < 10) {
                tmp.push(digits[i]+incr);
                incr = 0;
            } else {
                tmp.push((digits[i]+incr)%10);
                incr = (digits[i]+incr)/10;
            }
        }
        if (incr != 0) {
            tmp.push(incr);
        }
        while(!tmp.empty()) {
            result.push_back(tmp.top());
            tmp.pop();
        }
        return result;
    }
};
