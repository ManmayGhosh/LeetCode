class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int,int> last;
        set<int> dryDays;

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1;
                if (last.count(lake)) {
                    int prevDay = last[lake];
                    auto it = dryDays.lower_bound(prevDay + 1);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                last[lake] = i;
            } else {
                dryDays.insert(i);
            }
        }
        return ans;
    }
};