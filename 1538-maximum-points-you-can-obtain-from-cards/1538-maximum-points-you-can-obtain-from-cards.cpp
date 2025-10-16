class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int sum = 0 ; int i = 0; 
        for(  i  ; i<k ; i++){
            sum+=card[i]; 
        }
        int maxi= 0 ; 
        maxi= max(maxi,sum); 
        i--;
        int j = card.size()-1; 
        while(k>0 && i>=0){
            sum=sum-card[i];
            sum+=card[j];

            maxi = max( maxi , sum ) ;
            k--;
            i--;
            j--;
        }
        return maxi ;
    }
};