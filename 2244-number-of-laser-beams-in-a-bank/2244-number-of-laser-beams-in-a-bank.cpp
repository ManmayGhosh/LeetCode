class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, result = 0;
        for (auto &row : bank) {
            int cur = count(row.begin(), row.end(), '1');
            if (cur > 0) {
                result += prev * cur;
                prev = cur;
            }
        }
        return result;
    }
};