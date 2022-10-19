// 692. Top K Frequent Words
//  https://leetcode.com/problems/top-k-frequent-words/submissions/
class Solution {
public:
    class comperator{
        public:
        bool operator()(pair<int, string>& a, pair<int, string>& b){
            if(a.first != b.first){
                return a.first>b.first;
            }
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto x: words) mp[x]++;
        
        vector<string> v;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comperator> pq;
        for(auto e:mp){
            if(pq.size() < k){
                pq.push({e.second, e.first});
            }
            else{
                if(pq.top().first < e.second){
                    pq.pop();
                    pq.push({e.second, e.first});
                }
                else if(pq.top().first == e.second && pq.top().second > e.first){
                    pq.pop();
                    pq.push({e.second, e.first});
                }
            }
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        reverse(v.begin(), v.end());
        return v;
        
    }
};