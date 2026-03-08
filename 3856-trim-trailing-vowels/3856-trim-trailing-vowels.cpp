class Solution {
public:
    string trimTrailingVowels(string s) {
        unordered_set<char>st ={ 'a' , 'e' , 'i' ,'o','u' }; 
        int n  = s.size()-1; 
        while(n>=0){
            if(st.count(s[n])){
                s.pop_back(); n--; 
            }
            else{
                break;
            }
        }
        return s;
    }
};