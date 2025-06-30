class Solution {
private:
    vector<vector<bool>>* v;
    vector<vector<char>>* g;
    int m;
    int n;
public:
    void print_grid() {
        vector<vector<bool>> x = *v;
        for(const auto& i : x) {
            for(const auto& j : i) {
                cout << j << ' ';
            }
            cout << endl;
        }
        cout << "##################\n";
    }

    void navigate(int i, int j) {
        if(i < 0 || j < 0) {return;}
        if(i >= m || j >= n) {return;} // out of bounds
        if((*v)[i][j]) {return;}
        (*v)[i][j] = true;
        if((*g)[i][j] == '0'){return;}
        navigate(i, j + 1);
        navigate(i + 1, j);
        navigate(i - 1, j);
        navigate(i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {return 0;}
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        v = &visited;
        g = &grid;
        int islands{};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(visited[i][j]) {continue;}
                visited[i][j] = true;
                if(grid[i][j] == '0'){continue;}
                navigate(i, j + 1);
                navigate(i + 1, j);
                navigate(i - 1, j);
                navigate(i, j - 1);
                ++islands;
            }
        }

        return islands;
    }
};
