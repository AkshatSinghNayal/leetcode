class Solution {
public:

    string result ="";

    bool solve(string& s , string& target , int n , vector<int>&freq , int i, bool found  ){
        //base
        if( i == n ){
            if( result > target ){
                found = true;
                return true;
            }
            return false;
        }

        for(char ch = 'a' ; ch<='z' ; ch++ ){
            if( freq[ch-'a'] == 0 ) continue;
            if( !found and ch < target[i] ) continue;

            result+=ch; 
            freq[ch-'a']--;  
            bool isFound = false;
            if( found or ch > target[i]) isFound = true;
            if(solve(s , target , n , freq, i+1 , isFound )) return true;
            result.pop_back(); 
            freq[ch-'a']++; 
        }
        return false;
    }


    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26);
        for(auto& it: s ){
            int ele = it-'a'; 
            freq[ele]++; 
        }

        solve( s , target , target.length(), freq , 0 , false ); 
        return result;

    }
};