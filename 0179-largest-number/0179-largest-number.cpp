class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto& it : nums ){
            str.push_back(to_string(it));
        }

        sort( str.begin() , str.end() , [&] (auto a , auto b ){
            return a+b > b+a ;
        }); 
        string result= "";
        for(auto& it : str ){
            result+=it;
        }
        if(result[0]  == '0'  ) return "0";
        return result;
    }
};