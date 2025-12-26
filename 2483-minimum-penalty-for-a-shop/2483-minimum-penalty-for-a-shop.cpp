class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size() ; 
        int countN = 0 , countY = 0 ;
        for( auto& it : customers ) if(it == 'Y') countY++; 
        
        int bestFit = countY ; 
        int panelty =  0 ; 

        for( int i = 0 ; i< n ; i++){
            if( customers[i] ==  'N') countN++; 
            else countY--; 

            if( bestFit > countY+countN){
                bestFit = countY+countN ; 
                panelty = i+1 ; 
            }
        }

        return panelty ; 

    }
};