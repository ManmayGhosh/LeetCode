class Solution {
public:
    const long long INF = 1e18;

    unordered_map<string, int> mp;
    vector<vector<long long>> dist;
    string src, tgt;
    int n;
    vector<long long> dp;

    long long solve(int i) {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long ans = INF;
        if (src[i] == tgt[i])
            ans = min(ans, solve(i + 1));
        
        for (auto &p1 : mp) {
            const string &s1 = p1.first;
            int u = p1.second;
            int len = s1.size();

            if (i + len > n)
                continue;
            if (src.compare(i, len, s1) != 0)
                continue;

            for (auto &p2 : mp) {
                const string &s2 = p2.first;
                int v = p2.second;

                if (tgt.compare(i, len, s2) != 0) continue;
                if (dist[u][v] == INF) continue;

                ans = min(ans, dist[u][v]+solve(i + len));
            }
        }

        return dp[i] = ans;
    }

    long long minimumCost(string source,string target,vector<string>& original,vector<string>& changed,
        vector<int>& cost
    ) {
        src = source;
        tgt = target;
        n = source.size();
        int cnt = 0;
        for (int i = 0; i < original.size(); i++) {
            if (!mp.count(original[i])) mp[original[i]] = cnt++;
            if (!mp.count(changed[i]))  mp[changed[i]]  = cnt++;
        }
        dist.assign(cnt, vector<long long>(cnt, INF));

        for (int i = 0; i < cnt; i++)
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < cnt; k++)
            for (int i = 0; i < cnt; i++)
                for (int j = 0; j < cnt; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        dp.assign(n, -1);
        long long ans = solve(0);

        if(ans>=INF) return -1;

        return ans;
    }
};