class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            words.push_back(temp);
        }
        string reversed = "";
        for(int i = words.size()-1; i>=0; --i){
            reversed += words[i];
            if(i != 0) reversed +=" ";
        }
        return reversed;
    }
};