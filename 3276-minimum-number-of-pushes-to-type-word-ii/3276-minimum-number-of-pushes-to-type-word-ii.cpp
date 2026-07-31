class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        for(auto &ch:word){
            mp[ch]++;
        }
        vector<int>freqs;
        for(auto it=mp.begin();it!=mp.end();it++){
            freqs.push_back(it->second);
        }
        sort(freqs.rbegin(),freqs.rend());
        int sum=0;
        for(int i=0;i<freqs.size();i++){
            int weight= (i/8)+1;
            sum+=(freqs[i]*weight);
        }
        return sum;
        
    }
};