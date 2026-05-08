class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // slow approach
        unordered_map<string, vector<string>> group;
        vector<vector<string>>ans;
        for(string s : strs){
            string key = s;
            sort(key.begin(),key.end());
            group[key].push_back(s);
        }
        for(auto& entries : group){
            ans.push_back(entries.second);
        }
        return ans;
    }
};