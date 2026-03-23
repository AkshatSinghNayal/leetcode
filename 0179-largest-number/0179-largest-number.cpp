class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto& it : nums ){
            str.push_back(to_string(it)); 
        }
        string result ="";
        sort(str.begin() , str.end() ,[&] (auto a , auto b ){
            return a+b > b+a;
        }); 
        for(auto& it : str ){
            result+=it;
        }
        return (result[0] ==  '0') ? "0" : result;
    }
};