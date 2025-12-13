class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<int> resInd;
        for(int i=0; i<n; ++i){
            if(isActive[i]){
                if(businessLine[i] == "electronics" || 
                  businessLine[i] == "grocery" ||
                  businessLine[i] == "pharmacy" ||
                  businessLine[i] == "restaurant"){
                    bool check = !code[i].empty();
                    for(auto c : code[i]){
                        if(c == '_' || (c >= 'A' && c <='Z') || 
                          (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                            check = true;
                        } else {
                            check = false;
                            break;
                        }
                    }
                    if(check){
                        resInd.push_back(i);
                    }
                }
            }
        }
        // businessLine only four type, can compare first char is enough
        sort(resInd.begin(), resInd.end(), [&](int a, int b){
           return  (businessLine[a] < businessLine[b]) || 
                    (businessLine[a][0] == businessLine[b][0] && code[a] < code[b]);
        });
        vector<string> res;
        for(auto ind : resInd){
            res.push_back(code[ind]);
        }
        return res;
    }
};