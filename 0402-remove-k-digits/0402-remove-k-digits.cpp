class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size() == k) return "0";
        string result =""; 
        int n = nums.size(); 
        for(int i  = 0; i< n ;i++ ){
            while(!result.empty() and result.back() > nums[i] and k>0){
                result.pop_back(); 
                k--; 
            }
            result+=nums[i]; 
        }
       while(k>0 and !result.empty()){
            k--; 
            result.pop_back();
       }
       int i  = 0 ; n = result.size(); 
       while(i < n and result[i] == '0')i++; 
       result = result.substr(i);
       return result.size() == 0 ? "0" : result;
        
    }
};