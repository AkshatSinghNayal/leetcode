class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>arr(26,0); 
        for(auto& it : s){
            arr[it-'a']++; 
        }
        int i  = 0; 
        for(auto& it: s){
            if( arr[it-'a'] ==  1 ) return i; 
            i++; 
        }
        // for(auto& it : arr ) cout<< it << " " << endl;
        return -1;
    }
};