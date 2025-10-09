class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        
        // Base time: all wizards on last potion
        long long totalTime = 0;
        for (int s : skill) totalTime += (long long)s * mana[m-1];
        
        // Compute prefix sums
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + skill[i];
        }
        
        // Process consecutive potion pairs
        for (int j = 0; j < m - 1; j++) {
            long long maxDelay = 0;
            for (int i = 1; i <= n; i++) {
                long long delay = prefixSum[i] * mana[j] 
                                - prefixSum[i-1] * mana[j+1];
                maxDelay = max(maxDelay, delay);
            }
            totalTime += maxDelay;
        }
        
        return totalTime;
    }
};