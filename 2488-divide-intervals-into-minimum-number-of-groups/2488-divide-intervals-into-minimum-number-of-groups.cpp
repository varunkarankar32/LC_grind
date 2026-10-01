#define P pair<int,int> 
class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        priority_queue<P,vector<P>,greater<P>>pq;
       int currsize=0;
        vector<vector<vector<int>>>vec;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
            if(vec.size()==0){
                
                pq.push({end,0});
                vec.push_back({{}});
                vec[0].push_back(temp);
                continue;

                
            }
            auto toppair=pq.top();

            
            if(start<=toppair.first){
                
                pq.push({end,vec.size()});
                vec.push_back({{}});
                vec[vec.size()-1].push_back(temp);

            }
            else{
                vec[toppair.second].push_back(temp);
                pq.pop();
                pq.push({end,toppair.second});
            

                
            }
        }
        return vec.size();

    }
};