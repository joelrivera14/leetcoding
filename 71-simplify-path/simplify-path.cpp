class Solution {
public:
    string simplifyPath(string path) {
        vector<string> newPath;
        stringstream stream(path);
        string temp;
        while(getline(stream, temp, '/')){
            if(temp == ".."){
                if(!newPath.empty()) newPath.pop_back();
            }
            else if(temp != "." && !temp.empty())newPath.push_back(temp);
        }
        string result = "";
        for(string s : newPath){
            result +="/" + s;
        }
        if(result == "") return "/";
        return result;
    }
};
