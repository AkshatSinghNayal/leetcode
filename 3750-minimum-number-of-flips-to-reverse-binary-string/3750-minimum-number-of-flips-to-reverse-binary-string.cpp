class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        int msb=31-__builtin_clz(n);
        for(int i=msb;i>=0;i--){
            if((1LL<<i)&n){
                s+='1';
            }
            else s+='0';
        }
        string temp=s;
        reverse(temp.begin(),temp.end());
        int cnt=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=s[i])cnt++;
        }
        return cnt;
    }
};