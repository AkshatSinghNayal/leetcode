class Solution {
public:
    int countRotations(string s, int k) {
        string result =  s; int n = s.size(); 
        int i  = 0  ; int count = 0;
        while( i < n ){
            int score = 0; 
            char temp = result[i]; 
            for(int idx  = i; idx< result.size()-1 ; idx++ ){
                
                if( result[idx] == result[idx+1 ]) score++;
            }    
            cout<<result<<" "; 
            if( score == k ) count++; 
            result.push_back(temp);
            i++;

        }
        return count;
    }
};