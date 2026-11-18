class Solution {
public:
    int minChanges(string s) {
        int n  = s.size();
        int count = 0 ; 
        for(int i  = 0;i<n-1;i+=2){
            int a = s[i]; 
            int b = s[i+1]; 

            if(a!=b) count++;
        }
        
        return count; ;
    }
};