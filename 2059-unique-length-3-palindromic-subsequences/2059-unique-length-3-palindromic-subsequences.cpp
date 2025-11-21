class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int ans = 0;
        for (auto &it : mp) {
            const vector<int> &ind = it.second;
            int start = ind[0];
            int end = ind[ind.size() - 1];

            if (end - start <= 1) continue;

            unordered_set<char> mid;
            for (int i = start + 1; i < end; i++) {
                mid.insert(s[i]);
            }

            ans += mid.size();
        }
        return ans;
    }
};