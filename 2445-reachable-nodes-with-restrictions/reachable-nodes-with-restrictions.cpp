class Solution {
public:
    unordered_map<int,vector<int>>graph;
    vector<bool> seen;
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        seen = vector(n,false);
        for(auto& edge : edges){
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int res : restricted){
            seen[res] = true;
        }
        int ans = 0;
        dfs(0,ans);
        return ans;
    }

    void dfs(int currNode,  int& ans){
        ans++;
        seen[currNode] = true;
        for(int neighbors : graph[currNode]){
            if(!seen[neighbors]) dfs(neighbors, ans);
        }
    }
};