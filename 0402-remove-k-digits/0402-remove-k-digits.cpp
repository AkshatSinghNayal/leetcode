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
        int i = 0 ;
        while(i<n and result[i] == '0') i++; 
        n= result.size(); 
        if( k>0) n=n-k-i;
        if(n<0) return "0"; 
        result = result.substr(i , n); 
        return result.size() == 0 ? "0" : result; 
        
    }
};