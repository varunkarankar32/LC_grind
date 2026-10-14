class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string out="";
        if(num*9<sum){
            return out;
        }
        int m=sum;
        for(int i=0;i<num;i++){
            if(m>9){
                out.push_back('9');
                m-=9;
            }
            else {
                out.push_back('0'+m);
                m=0;
            }
            
        }
        return out;
        
        
    }
};