class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int left=0,right=m-1,top=0,bottom=n-1;
        vector<int>out;
        while(left<=right&&top<=bottom){
            for(int i=left;i<=right;i++){
                out.push_back(matrix[top][i]);
            }
            top++;
            if(top>bottom){
                break;
            }
            for(int i=top;i<=bottom;i++){
                out.push_back(matrix[i][right]);
            }
            right--;
            if(left>right){
                break;
            }
            for(int i=right;i>=left;i--){
                out.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(top>bottom){
                break;
            }
            for(int i=bottom;i>=top;i--){
                out.push_back(matrix[i][left]);
            }
            left++;
        }
        return out;
    }
};