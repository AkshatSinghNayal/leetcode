class Solution {
public:

    class comp{
        public:
        bool operator()(pair<int,int>&a , pair<int,int>&b ){
            return a.first < b.first ; 
        }

    }; 

    int maxDigitRange(vector<int>& nums) {
        int maxiDiff = 0 ; 
        priority_queue<pair<int,int>, vector<pair<int,int>> , comp>pq; 

        for(auto& it : nums ){
            int small = INT_MAX, maxi = INT_MIN;
            int temp = it ; 

            while(temp){
                small = min(small , temp%10); 
                maxi = max(maxi ,  temp%10 ); 
                temp/=10; 
            }
            maxiDiff = max(maxiDiff , maxi - small ); 
            pq.push({maxi-small , it }); 
        }

        int total = 0 ; 
        while(!pq.empty()){
            auto [ diff , no ] = pq.top(); pq.pop(); 
            if( diff == maxiDiff) total+=no;
            else break;
        }
        return total; 
    }
};