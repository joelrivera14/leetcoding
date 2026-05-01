class Solution {
    unordered_map<int, vector<int>> graph;
    vector<bool> seen;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        seen = vector(n,false);
        for(auto& edge : edges){
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        return dfs(source, destination);
    }

    bool dfs(int currNode, int dest){
        if(currNode == dest) return true;
        seen[currNode] = true;
        for(int nextNode : graph[currNode]){
            if(!seen[nextNode]){
                if(dfs(nextNode, dest)) return true;
            }
        }
        return false;
    }
};