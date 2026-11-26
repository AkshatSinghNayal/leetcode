class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)return false;
        bool flag = true;
        int last = 10;
        while(n>0){

            if(n-last < 0 ){
                if(flag) return false;
                else return true;
            }
            n-=last;
            // cout<< n << " ";
            last--; 
            flag = (flag) ? false : true;
        }
        return !flag;
    }
};