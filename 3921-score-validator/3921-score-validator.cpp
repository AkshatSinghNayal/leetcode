class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score= 0, count = 0; 
        for(auto& it : events ){
            int size = it.size(); 
            if(size == 1 and it !="W"){
                int temp = stoi(it);
                score+=temp; 
            }
            else{
                if( it == "WD" or it == "NB"){
                    score++; 
                }
                else{
                    count++; 
                }
            }
            if( count == 10 ) break;
            
        }
        return {score ,count}; 
    }
};