class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& h, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (auto &d : dirs) {
            int x=i+d[0], y=j+d[1];
            if (x>=0 && y>=0 && x<m && y<n && !vis[x][y] && h[x][y] >= h[i][j]) {
                dfs(h,x,y,vis);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(); n=heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false)), atl(m,vector<bool>(n,false));
        
        for (int i=0;i<m;i++) {
            dfs(heights,i,0,pac);
            dfs(heights,i,n-1,atl);
        }
        for (int j=0;j<n;j++) {
            dfs(heights,0,j,pac);
            dfs(heights,m-1,j,atl);
        }
        
        vector<vector<int>> res;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};