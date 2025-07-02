class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> m;
public:
    double dfs(const string& src, const string& des) {
        if(m[src].empty() || m[des].empty()) {return -1;}
        stack<pair<string, double>> s;
        s.push({src, 1.0});
        unordered_map<string, bool> visited;
        while(!s.empty()) {
            pair<string, double> temp = s.top();
            s.pop();
            visited[temp.first] = true;
            if(temp.first == des) {return temp.second;}
            for(auto const& v : m[temp.first]) {
                if(visited[v.first]) {continue;}
                s.push({v.first, temp.second * v.second});
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> out;
        for(auto const& q : queries) {
            out.push_back(dfs(q[0], q[1]));
        }
        return out;
    }
};
