class Solution {
public:
    int countRotations(string s, int k) {
        int n  = s.size();
        string temp = s+s.substr(0,n-1);
        int maxi = 0;

        for( int i = 0 ;i<n; i++ ){
            int score = 0;
            for(int j = 0 ;j < n-1 ; j++ ){
                int index = j+i; 
                if( temp[index] == temp[index+1]) score++;
            }

            if( score ==  k ) maxi++;
        }
        return maxi;
    }
};