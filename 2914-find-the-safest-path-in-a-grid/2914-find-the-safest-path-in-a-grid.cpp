class Solution {
public:
    vector<pair<int,int>>directions={{0,-1},{0,1},{-1,0},{1,0}};
    bool dfs(int i,int j,int maxsafe,vector<vector<bool>>&visited,vector<vector<int>>&mintheifdistance){
        int n=visited.size();
        visited[i][j]=true;
        if(i==n-1&&j==n-1){
            return true;
        }
        for(auto &dirs:directions){
            int i_=i+dirs.first;
            int j_=j+dirs.second;
            if(i_>=0&&i_<n&&j_>=0&&j_<n&&!visited[i_][j_]&&mintheifdistance[i_][j_]>=maxsafe&&dfs(i_,j_,maxsafe,visited,mintheifdistance)){
                return true;
            }
        }
        return false;


    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<vector<int>>mintheifdistance(n,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>que; //{pair of indice,distance}
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                mintheifdistance[i][j]=0;
                que.push({{i,j},0});
                }
            }

        }
        while(!que.empty()){
            int m=que.size();
            while(m--){
                int i=que.front().first.first;
                int j=que.front().first.second;
                int dis=que.front().second;
                que.pop();
                if(mintheifdistance[i][j]<dis){
                    continue;
                }
                for(auto &dirs:directions){
                    int i_= i+dirs.first;
                    int j_ = j + dirs.second;
                    if(i_>=0&&i_<n&&j_<n&&j_>=0&&mintheifdistance[i_][j_]>dis+1){
                        mintheifdistance[i_][j_]=dis+1;
                        que.push({{i_,j_},dis+1});

                    }
                }
                

            }
        }
      //  for(int i=0;i<n;i++){
       //     for(int j=0;j<n;j++){
        //        cout<<mintheifdistance[i][j]<<" ";
      //      }
      //      cout<<endl;
      //  }
        int lo=0;
        int hi=mintheifdistance[0][0];
        int mid;
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
    
        while(lo<=hi){
            mid=(lo+hi)/2;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    visited[i][j]=false;
                }
            }
            if(dfs(0,0,mid,visited,mintheifdistance)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }

            
            
        }
      //  for(int i=0;i<n;i++){
      //       for(int j=0;j<n;j++){
       //           visited[i][j]=false;
        //       }
       //   }
        //return dfs(0,0,2,visited,mintheifdistance);
        return ans;
        

        
    }
};