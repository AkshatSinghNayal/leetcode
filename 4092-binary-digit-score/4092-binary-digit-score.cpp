class Solution {
public:

    int setbits( int temp , int count ){
        while(temp){
            count+=(temp&1) ? 1 : 0; 
            temp = temp>>1; 
        }
        return count;
    }

    int calculateScore(int a, int b) {
        int scorea = setbits(a,0); 
        int scoreb = setbits(b,0); 

        // cout<< scorea << " " << scoreb ; 
        return ( scorea >= scoreb ) ? scorea*scoreb : (int)scoreb/scorea;
    }
};