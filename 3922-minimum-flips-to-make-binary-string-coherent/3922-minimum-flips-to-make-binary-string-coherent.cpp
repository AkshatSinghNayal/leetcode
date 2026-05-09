class Solution {
public:
    int minFlips(string s) {
        int cnt0=0;int cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
        }
        if(cnt1<2)return 0;
        if(cnt0==0)return 0;
        
        if(s[0]=='1'&&s.back()=='1')return min(cnt1-2,cnt0);
        else return min(cnt1-1,cnt0);
    }
};