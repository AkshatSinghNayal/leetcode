class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>>temp;
        int done = 0;  
        for(auto& it : courses){
            temp.push_back({it[1] , it[0]}); 
        }
        sort(temp.begin() , temp.end() , [&](auto a , auto b ){
            auto [ first  , second ] = a; 
            auto [ firstB , secondB] = b; 

            if( first == firstB ){
                return second < secondB ; 
            }   
            return first < firstB ; 
        }); 

        priority_queue<int>pq;
        long long total =0;

        for(auto& it : temp ){
            auto [second , first ] = it;
            pq.push(first);
            done++; 
            total+=first; 
            while(total>second){
                total-=pq.top(); pq.pop(); 
                done--; 
            }

        }

        return done;

    }
};