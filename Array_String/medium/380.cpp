class RandomizedSet {
public:
    vector<int> rs;
    unordered_map<int, bool> m;

    RandomizedSet() {
        srand( time(NULL) );
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end() && m[val]) return false;
        rs.push_back(val);
        m[val] = true;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end() || !m[val]) return false;
        rs.erase(find(rs.begin(), rs.end(), val));
        m[val] = false;
        return true;
    }
    
    int getRandom() {
        return rs[rand()%rs.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
