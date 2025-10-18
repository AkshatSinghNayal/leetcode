class Solution {
  public:
    int findMin(int n) {
       int mini=0;
       while(n>0){
           if(n>=10){
               n-=10;
               mini++;
           }
           else if(n>=5){
               n-=5;
               mini++;
           }
           else if(n>=2){
               n-=2;
               mini++;
           }
           else{
               n-=1;
               mini++;
           }
           
           
       }
        return mini;
    }
};