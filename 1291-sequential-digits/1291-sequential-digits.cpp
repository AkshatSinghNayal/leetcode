class Solution {
public:
    bool check(int num) {

        while (num >= 10) {

            int last_digit = num % 10;

            int prev_digit = (num / 10) % 10;

            if (last_digit != prev_digit + 1) {

                return false;
            }

            num /= 10;
        }

        return true;
    }
long long ok = 0 ; unordered_set<int> st;
    void solve( vector<int>& ans , int high , long long initial , long long temp , long long ok ){
        //base
        if( initial > high) return ; 
        if( check(initial) == true and temp%10 == 9 and !st.count(initial)){
            st.insert(initial);
            ans.push_back(initial); 
            solve(ans , high , 1LL*temp*10+temp%10+1 , 1LL*temp*10+temp%10+1 , ok*1LL*10+1 ); 
            return ; 
        }
        if( check(initial) == true and !st.count(initial)){
            st.insert(initial);
            ans.push_back(initial); 
        }
        
        if( check(initial) == true ) solve(ans , high , initial+ok , temp , ok);
        solve(ans , high , 1LL*temp*10+temp%10+1 , 1LL*temp*10+temp%10+1 , ok*1LL*10+1 ); 

    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int digits = (int)log10(low) + 1; 
        long long initial = 0 , temp = 0 ;

        for(int i = 1 ; i<= digits ; i++ ){
            ok = ok*10 + 1; 
            initial = initial*10 + i ; 
        }
        temp = initial;
        while(initial<low){
            initial+=ok;
        }

        if(initial > high ) return ans; 

        solve( ans , high , initial , temp , ok) ; 

        return ans; 
 
    }  
};