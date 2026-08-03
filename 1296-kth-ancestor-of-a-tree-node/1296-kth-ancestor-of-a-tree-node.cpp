class TreeAncestor {
public:
    vector<vector<int>>ancestor;
    int Log;

    TreeAncestor(int n, vector<int>& parent) {
        Log= log2(n)+1;
        ancestor.resize(n,vector<int>(Log+1,-1));
        for(int i=0;i<n;i++){
            ancestor[i][0]=parent[i];
        }
        for(int j=1;j<=Log;j++){
            for(int node=0;node<n;node++){
                if(ancestor[node][j-1]!=-1){
                    ancestor[node][j]=ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        for(int j=0;j<=Log;j++){
            if((k>>j)&1){
                node=ancestor[node][j];
                
                if(node==-1){
                    return -1;
                }
            }

        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */