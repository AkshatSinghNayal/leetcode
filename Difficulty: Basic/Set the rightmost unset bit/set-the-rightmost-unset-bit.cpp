class Solution {
  public:
    int setBit(int n) {
       
      n = (n|(n+1));
      return n ; 
    } 
};