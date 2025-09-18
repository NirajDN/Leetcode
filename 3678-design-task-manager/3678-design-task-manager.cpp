class TaskManager {
public:
    set<pair<long long,int>> set ;
    map<int , pair<long long,int>> map ;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i : tasks) {
            int task = i[1] ;
            int userId = i[0] ;
            int prior = i[2] ;
            map[task] = {prior , userId} ;
            set.insert({prior , task}) ;
        }
    }
    
    void add(int userId, int task, int prior) {
        map[task] = {prior , userId} ;
        set.insert({prior , task}) ;
    }
    
    void edit(int taskId, int newPriority) {
        long long oldPrior = map[taskId].first ;
        int userId = map[taskId].second ;
        auto it = set.find({oldPrior , taskId}) ;
        set.erase(it) ;
        set.insert({newPriority , taskId}) ;
        map[taskId].first = newPriority ;
    }
    
    void rmv(int taskId) {
        //cout << "map size " << map.size() << endl ;
        long long oldPrior = map[taskId].first ;
        int userId = map[taskId].second ;
        auto it = set.find({oldPrior , taskId}) ;
        set.erase(it) ;
        map.erase(taskId) ;
        //cout << "map size " << map.size() << endl ;
    }
    
    int execTop() {
        if(set.size() == 0 ) {
            return -1 ;
        }
        auto it = set.rbegin() ;
        pair<long long , int> p = *it ;
        //cout << p.first << " " << p.second ;
        // rmv(p.second) ;
        int val =  map[p.second].second ;
        rmv(p.second) ;
        return val ;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */