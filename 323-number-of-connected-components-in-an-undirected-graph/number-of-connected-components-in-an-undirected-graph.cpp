class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<bool>seen;
    int countComponents(int n, vector<vector<int>>& edges) {
        seen = vector(n,false);
        for(auto& edge: edges){
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int count = 0;
        for(int i = 0; i<n; ++i){
            count+=dfs(i);
        }
        return count;
    }

    int dfs(int node){
        if(seen[node]) return 0;
        seen[node] = true;
        for(int neighbor : graph[node]){
            if(!seen[neighbor]){
                dfs(neighbor);
            }
        }
        return 1;
    }
};