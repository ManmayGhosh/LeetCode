class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[((i + nums[i]) % n + n) % n];
            // To ensure we always get a valid positive index, we use the standard formula:
            // ((target % n) + n) % n.
            // This formula handles both positive shifts (wrapping from end to start) and
            // negative shifts (wrapping from start to end) correctly.
        }
        return ans;
    }
};