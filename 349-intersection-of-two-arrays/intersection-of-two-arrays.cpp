class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());
        vector<int> numbers;
        if(set1.size()>set2.size()){
            for(int i : set1){
                if(set2.contains(i)){
                    numbers.push_back(i);
                }
            }
        } else if(set1.size()<=set2.size()){
            for(int i : set2){
                if(set1.contains(i)){
                    numbers.push_back(i);
                }
            }
        }
        return numbers;
        
    }
};