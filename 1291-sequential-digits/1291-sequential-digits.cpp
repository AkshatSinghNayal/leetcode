class Solution {
public:
    unordered_set<int> st;

    bool check(long long num){
        while(num>=10){
            int last=num%10;
            int prev=(num/10)%10;
            if(last!=prev+1) return false;
            num/=10;
        }
        return true;
    }

    void solve(vector<int>& ans,int high,long long initial,long long temp,long long ok){
        if(initial>high) return;
        bool valid=check(initial);

        if(valid && temp%10==9 && !st.count(initial)){
            st.insert(initial);
            ans.push_back(initial);
            solve(ans,high,1LL*temp*10+temp%10+1,1LL*temp*10+temp%10+1,ok*10+1);
            return;
        }

        if(valid && !st.count(initial)){ st.insert(initial); ans.push_back(initial); }

        if(valid) solve(ans,high,initial+ok,temp,ok);

        solve(ans,high,1LL*temp*10+temp%10+1,1LL*temp*10+temp%10+1,ok*10+1);
    }

    vector<int> sequentialDigits(int low,int high){
        vector<int> ans;
        int digits=(int)log10(low)+1;
        long long initial=0,temp=0,ok=0;

        for(int i=1;i<=digits;i++){ ok=ok*10+1; initial=initial*10+i; }

        temp=initial;

        while(initial<low) initial+=ok;

        if(initial>high) return ans;

        solve(ans,high,initial,temp,ok);

        sort(ans.begin(),ans.end());

        return ans;
    }
};