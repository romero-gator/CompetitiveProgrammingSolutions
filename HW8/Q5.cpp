class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& b, vector<int>& s, vector<int>& t) {
        int n = b.size(), i, diff = 0, mr = s[0], mc = s[1], mxx = 10000;
        bool fs = false, ft = false;
        set<vector<int>> blocked, vis;
        queue<vector<int>> q;

        for (int i = 0; i < n; i++) {
            blocked.insert(b[i]);
        }
        
        q.push({s[0],s[1]});
        vis.insert({s[0],s[1]});
        
        while (q.size()) {
            vector<int> p = q.front();
            q.pop();
            diff = max({diff, abs(p[1]-s[1]), abs(p[0]-s[0])});
            
            if (p == t) {
                return 1;
            }
                
            if (diff >= b.size()){
                fs = true;
                break;
            }
            
            if (p[0]+1 < mxx && blocked.find({p[0]+1,p[1]}) == blocked.end() && vis.find({p[0]+1,p[1]}) == vis.end()) {
                q.push({p[0]+1, p[1]});
                vis.insert({p[0]+1, p[1]});
            }
            
            if (p[1]+1 < mxx && blocked.find({p[0],p[1]+1}) == blocked.end() && vis.find({p[0],p[1]+1}) == vis.end()) {
                q.push({p[0], p[1]+1});
                vis.insert({p[0], p[1]+1});
            }
            
            if(p[0] && blocked.find({p[0]-1,p[1]}) == blocked.end() && vis.find({p[0]-1,p[1]}) == vis.end()) {
                q.push({p[0]-1, p[1]});
                vis.insert({p[0]-1, p[1]});
            }
            
            if (p[1] && blocked.find({p[0],p[1]-1}) == blocked.end() && vis.find({p[0],p[1]-1}) == vis.end()) {
                q.push({p[0], p[1]-1});
                vis.insert({p[0], p[1]-1});
            }
        }
        
        if (!fs) {
            return 0;
        }
        
        mr = t[0];
        mc = t[1];

        while (q.size()) {
            q.pop();
        }
        
        vis.clear();
        
        q.push({t[0], t[1]});
        vis.insert({t[0], t[1]});
        diff = 0;
        
        while (q.size()) {
            vector<int> p = q.front();
            q.pop();
            
            diff = max({diff, abs(p[1]-t[1]), abs(p[0]-t[0])});
            
            if (p == s) {
                return 1;
            }
            
            if (diff >= b.size()) {
                ft = 1;
                break;
            }
            
            if (p[0]+1 < mxx && blocked.find({p[0]+1,p[1]}) == blocked.end() && vis.find({p[0]+1,p[1]}) == vis.end()) {
                q.push({p[0]+1, p[1]});
                vis.insert({p[0]+1, p[1]});
            }
            
            if (p[1]+1 < mxx && blocked.find({p[0],p[1]+1}) == blocked.end() && vis.find({p[0],p[1]+1}) == vis.end()) {
                q.push({p[0], p[1]+1});
                vis.insert({p[0], p[1]+1});
            }
            
            if (p[0] && blocked.find({p[0]-1,p[1]}) == blocked.end() && vis.find({p[0]-1,p[1]}) == vis.end()){
                q.push({p[0]-1, p[1]});
                vis.insert({p[0]-1, p[1]});
            }
            
            if (p[1] && blocked.find({p[0],p[1]-1}) == blocked.end() && vis.find({p[0],p[1]-1}) == vis.end()){
                q.push({p[0], p[1]-1});
                vis.insert({p[0], p[1]-1});
            }
        }
        
        if (!ft) {
            return 0;
        }
            
        return 1;
    }
};