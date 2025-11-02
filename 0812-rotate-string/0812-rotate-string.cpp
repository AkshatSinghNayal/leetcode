class Solution {
public:
    bool rotateString(string s, string goal) {
        int n  = s.size() ; 
        int m = goal.size() ;
        if( n!= m ) return false ;
        string ans = s+s ; 
        
        if(ans.find(goal) != string::npos){
            return true; 
        }
        else{
            return false;
        }
        return false;
    }
};