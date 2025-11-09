class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans; 
        int i = 0; 
        while(i<words.size()){
            
            auto s = words[i]; 
            if( s.find(x) != string::npos ){
                ans.push_back( i); 
            }


            i++;
        }
        return ans; 
    }
};