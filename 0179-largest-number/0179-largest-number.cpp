class Solution {
public:

    class comp{
        public : 
        bool operator()(const string& a , const string& b){
            return a+b > b+a ; 
        }
    };

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto& it : nums ){
            str.push_back(to_string(it)); 
        }
        string result ="";
        sort(str.begin() , str.end() ,comp());
        for(auto& it : str ){
            result+=it;
        }
        return (result[0] ==  '0') ? "0" : result;
    }
};