class Solution {
public:
    int n;
    vector<int> dir = {0,1,0,-1,0};

    bool canReach(vector<vector<int>>& grid, int t) {
        if (grid[0][0] > t) return false;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            if (r == n-1 && c == n-1) return true;
            for (int k=0;k<4;k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                if (nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc] && grid[nr][nc] <= t) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = grid[0][0], high = n*n-1, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canReach(grid, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};