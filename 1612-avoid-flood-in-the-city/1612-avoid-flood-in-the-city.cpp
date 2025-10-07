class Solution {
public:
    vector<int> avoidFlood(vector<int>& r) {
        list<int> zero_pos;
        int n =  r.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> freq;

        for(int i = 0;i<n;i++)
        {
            if(r[i]==0)
            zero_pos.push_back(i);
            else
            {
                if(freq.find(r[i])==freq.end())
                freq[r[i]]  = i;
                else
                {
                    vector<int> tmp;
                    while(zero_pos.size()>0 && zero_pos.front()<freq[r[i]])
                    {
                        tmp.push_back(zero_pos.front());
                        zero_pos.pop_front();
                    }
                    if(zero_pos.size()==0) return {};
                    else
                    {
                        ans[zero_pos.front()] = r[i];
                        zero_pos.pop_front();
                        freq[r[i]] = i;
                        for(int j = tmp.size()-1;j>=0;j--) zero_pos.push_front(tmp[j]);
                    }
                }
            }
        }
        while(!zero_pos.empty())
        {
            ans[zero_pos.front()] = 1;
            zero_pos.pop_front();
        }
        return ans;
        
    }
};