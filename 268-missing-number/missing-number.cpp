class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int>numbers(nums.begin(),nums.end());
        for(int i = 0; i<=numbers.size(); ++i){
            if(numbers.find(i)==numbers.end()) return i;
        }
        return 0;
    }
};