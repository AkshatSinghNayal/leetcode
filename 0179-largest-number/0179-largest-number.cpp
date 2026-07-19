class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str; 
        for(auto& it : nums){
            string temp = to_string(it);
            str.push_back(temp); 
        }
        sort(str.begin(),str.end(), [&](auto a , auto b ){
            return a+b>b+a;
        }); 

        string result = ""; 
        for(auto& it : str ){
            result+=it;
        }
        int i  = 0 , n  =  result.size() , count = 0 ; 
        
        return result[0] == '0' ? "0" : result;
    }
};