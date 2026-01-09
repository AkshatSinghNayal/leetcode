class Solution {
public:
    int minimumFlips(int n) {
        string s=""; 
        int msb=31-__builtin_clz(n);
        
        for(int i = 0 ; i<=msb ; i++){
            int mask =1<<i;
            if(mask&n){
                s+='1';
            }
            else{
                s+='0';
            }
            
        }
        int count = 0; 
        string temp = s ;
        cout<<temp;
        reverse(s.begin(),s.end()); 
        for(int i= 0; i<s.size() ; i++){
            if(temp[i]!=s[i])count++; 
        }
        return count ; 
    }
};