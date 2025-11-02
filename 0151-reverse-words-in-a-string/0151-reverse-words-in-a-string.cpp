class Solution {
public:
    string reverseWords(string s) {
        
        int i  = 0 ;int j = s.size()-1; 
        vector<string> ans;
        while( s[i]==' ')i++;

        while( s[j]==' ')j--;

        while(i<=j){
            string result=""; 
            while(s[i]!=' ' && i<=j){
                result+=s[i]; 
                i++; 
            }
            ans.push_back(result);
            while( s[i]==' ')i++;
        }
        reverse(ans.begin(),ans.end());

            string res; 
        for( int i = 0; i<ans.size() ; i++){
            res+=ans[i]; 
            if(i<ans.size()-1){
                res+=' '; 
            }
        }
        return res ;
    }
};