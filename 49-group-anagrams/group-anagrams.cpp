class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groups;
        for(string s : strs){
            string k = s;
            sort(k.begin(), k.end());
            groups[k].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto entries : groups){
            ans.push_back(entries.second);
        }
        return ans;
    }
};