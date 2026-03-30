class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        if(s1 == s2 ) return true;

        string temp = s1;
        swap(temp[0],temp[2]);
        if(temp == s2 ){
            return true;
        }else{
            swap(temp[1],temp[3]);
            if( temp == s2){
                return true;
            }
            else{
                swap(temp[0],temp[2]);
                if( temp == s2 ){
                    return true;
                }
            }
        }

        return false;

    }
};