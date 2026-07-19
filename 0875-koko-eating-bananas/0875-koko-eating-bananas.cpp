class Solution {
public:

    bool check(int mid , int h , vector<int>&piles ){
        long long hour = 0; 

        for(auto& it : piles ){
            
            hour+=( it+mid -1 )/mid;
            
        }

        return hour<=h; 

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(); 
        int start = 1;
        int end = *max_element(piles.begin() , piles.end()); 
        int mid; 

        while(start <= end ){
            mid = start+(end-start)/2; 
            if(check(mid,h,piles)){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};