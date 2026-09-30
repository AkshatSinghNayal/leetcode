class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans ;
        int open = 0 ; 
        open = ( seq[0] == '(') ? 1 : 0 ; 
        if(open%2 == 0  ) ans.push_back(0); 
        else ans.push_back(1); 
        int n  = seq.size(); 
        for( int i =1 ; i<n ;i++ ){
            char ch = seq[i]; 
            if( ch == ')'){
                if( open%2 != 0 ) ans.push_back(1); 
                else ans.push_back(0);   
                open--; 
                continue;
            }else{
                open++;
                if(open%2 == 0 ) ans.push_back(0); 
                else ans.push_back(1); 
            }
        }
        return ans; 
    }
};