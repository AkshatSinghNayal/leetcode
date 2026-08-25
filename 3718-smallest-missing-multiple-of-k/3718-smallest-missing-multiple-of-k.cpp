class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end()); 
        int temp = k ; 
        while(true){
            if(!st.count(temp)){
                return temp;
            }
            else{
                temp+=k; 
            }
        }
        return -1;
    }
};