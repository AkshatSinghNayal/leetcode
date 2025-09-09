class Solution {
public:
    int minBitFlips(int start, int goal) {
        int last = start^goal ; 
        int count = 0 ; 
        while(last!=0){
            count++;
            last = last&(last-1);
        }
        return count ;
    }
};