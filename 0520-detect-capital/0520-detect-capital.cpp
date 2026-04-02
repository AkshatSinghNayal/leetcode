class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0 , n = word.size();
        for(auto& it : word ){
            if( it >= 'A' and it<='Z') count++; 
        }
        bool flag = false;
        if(word[0]>= 'A' and word[0]<='Z') flag = true;
        return( count == n or count == 0  ) ? true : ( count ==1 and flag ) ? true : false;
    }
};