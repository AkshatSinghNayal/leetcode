class Solution {
public:
    long long ok = 0 ; unordered_set<int> st;
    void solve( vector<int>& ans , int low, int high , long long initial , long long temp , long long ok ){
        if( initial > high) return ; 
        if (initial % 10 == 9) {
            if(initial >= low && !st.count(initial)){
                st.insert(initial);
                ans.push_back(initial); 
            }
            solve(ans , low, high , 1LL*temp*10+temp%10+1 , 1LL*temp*10+temp%10+1 , ok*1LL*10+1 ); 
            return;
        }

        if(initial >= low && !st.count(initial)){
            st.insert(initial);
            ans.push_back(initial); 
        }
        
        solve(ans , low, high , initial+ok , temp , ok);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int digits = (int)log10(low) + 1; 
        if (digits < 2) digits = 2; 
        long long initial = 0 , temp = 0 ;

        for(int i = 1 ; i<= digits ; i++ ){
            ok = ok*10 + 1; 
            initial = initial*10 + i ; 
        }
        temp = initial;


        solve( ans , low, high , initial , temp , ok) ; 

        return ans; 
    }
};