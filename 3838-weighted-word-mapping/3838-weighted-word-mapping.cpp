class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string temp = " abcdefghijklmnopqrstuvwxyz";
        cout<< temp[1];
        string result = ""; 
        for(auto& it : words){
            int size = it.size(); 
            int digit = 0; 
            for( int i = 0 ; i< size  ; i++ ){
                digit+=weights[it[i]-'a'];
            }
            digit=digit%26;
            digit = 26-digit;
            result+=temp[digit];
        }
        return result;
    }
};