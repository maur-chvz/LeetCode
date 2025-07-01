class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int out{};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        auto bfs = [&](int i, int j) 
        { 
            deque<pair<int, int>> q{};
            q.push_back({i, j}); // {i, j}
            while(!q.empty()) {
                int i = q.back().first;
                int j = q.back().second;
                q.pop_back();
                if(i < 0 || j < 0){continue;}
                if(i >= m || j >= n){continue;}
                if(visited[i][j]) {continue;}
                visited[i][j] = true;
                if(grid[i][j] == '0') {continue;}
                q.push_back({i, j + 1});
                q.push_back({i + 1, j});
                q.push_back({i, j - 1});
                q.push_back({i - 1, j});
            }
        };
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j] || grid[i][j] == '0') {continue;}
                bfs(i, j);
                ++out;
            }
        }
        
        return out;
    }
};
