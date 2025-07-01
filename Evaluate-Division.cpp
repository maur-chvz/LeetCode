class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& m, string src, string des) {
        if(m[src].empty() || m[des].empty()) {return -1;}
        deque<pair<string, double>> d{{src, 1.0}}; // stack
        unordered_map<string, bool> visited{};
    
        while(!d.empty()) {
            pair<string, double> t = d.back();
            d.pop_back();
            if(t.first == des) {return t.second;}
            visited[t.first] = true;
            for(const auto& [v, e] : m[t.first]) {
                if(visited[v]) {continue;}
                d.push_back({v, t.second * e});
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> m;
        for(int i = 0; i < equations.size(); ++i) {
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1 / values[i]}); 
        }

        vector<double> out;
        for(auto const& q : queries) {
            out.push_back(dfs(m, q[0], q[1]));
        }
        return out;
    }
};
