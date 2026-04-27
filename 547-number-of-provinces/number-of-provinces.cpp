class Solution {
public:
    unordered_map<int, vector<int>>graph;
    vector<bool> seen;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        //equal to writing vector<bool> seen(n,false)
        seen = vector(n,false);
        for(int i = 0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
                if(isConnected[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            //can also write !seen[i]
            if(seen[i] == false){
                ans++;
                seen[i] = true;
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int node){
        for(int neighbor : graph[node]){
            if(!seen[neighbor]){
                seen[neighbor] = true;
                dfs(neighbor);
            }
        }
    }
};