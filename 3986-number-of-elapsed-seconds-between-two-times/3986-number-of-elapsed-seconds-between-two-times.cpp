class Solution {
public:
    int secondsBetweenTimes(string s, string E) {
        
        long long Shour = stoi(s.substr(0,2 ))*3600;
        long long Smin  = stoi(s.substr(3 , 2))*60 + Shour;
        long long Ssec = stoi(s.substr(6 ,2)) + Smin; 

        long long Ehour = stoi(E.substr(0,2 ))*3600;
        long long Emin  = stoi(E.substr(3 , 2))*60 + Ehour;
        long long Esec = stoi(E.substr(6 ,2)) + Emin; 

        return (Esec - Ssec);

       
    }
};