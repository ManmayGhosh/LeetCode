class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        for (int i = 1; i < n; i++)
            if (nums[i] > nums[i-1]) pre[i] = pre[i-1] + 1;

        int low = 1, high = n/2, ans = 1;
        while (low <= high) {
            int mid = (low + high)/2;
            bool found = false;
            for (int i = mid; i < n; i++)
                if (pre[i] >= mid && pre[i-mid] >= mid) { found = true; break; }
            if (found) { ans = mid; low = mid + 1; }
            else high = mid - 1;
        }
        return ans;
    }
};