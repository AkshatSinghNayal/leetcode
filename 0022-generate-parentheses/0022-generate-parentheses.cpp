class Solution {
public:

    void solve ( vector<string> &ans , int open , int close , string storage , int n  ) {
        if ( open>= n && close>= n ){
        ans.push_back(storage);
        return ; }

        if(open < n ){
            storage.push_back('(');
            solve ( ans , open +1 , close , storage, n);
            storage.pop_back() ; 
        }
        if(close < open ){
            storage.push_back(')');
            solve ( ans , open , close +1  , storage , n);
            storage.pop_back() ; 
        }



    }

    vector<string> generateParenthesis(int n) {
        int open = 0 ;
        string storage = "" ; 
        vector<string> ans ; 
        int close = 0 ; 
        solve ( ans , open , close , storage ,n ) ; 
        return ans ; 
    }
};