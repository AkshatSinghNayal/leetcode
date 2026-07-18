class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string result =  "";  int count = 0; 
        for(auto& it : s ){
            if( it != x ) result+=it;
            else{
                count++; 
            }
        }
        result = result + string(count , x);
        return result;
    }
};