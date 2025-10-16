class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[((num % value) + value) % value]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int remainder = i % value;
            if (counts[remainder] == 0) return i;
            counts[remainder]--;
            if (counts[remainder] == 0) {
                counts.erase(remainder);
            }
        }

        return nums.size();
    }
};