typedef  list<array<int,3>>::iterator list_it;

class LFUCache {

    
    unordered_map<int,list_it> key_it;
    unordered_map<int,list<array<int,3>>> used_it;
    int capacity;
    int least_freq;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        least_freq = 1;
    }
    
    int get(int key) {
        if(key_it.find(key)==key_it.end())  return -1;
        array<int,3> a = *key_it[key];
        used_it[a[2]].erase(key_it[key]);
        a[2]++;
        used_it[a[2]].push_front(a);
        key_it[key] = used_it[a[2]].begin();
        return a[1];
    }
    

    void put(int key, int value) {
        if(key_it.find(key) != key_it.end()){
            array<int,3> a = *key_it[key];
            used_it[a[2]].erase(key_it[key]);
            a[2]++;
            a[1]=value;
            used_it[a[2]].push_front(a);
            key_it[key] = used_it[a[2]].begin();
            return;
        }
        else if(key_it.size()==capacity){
            while(used_it[least_freq].empty())     least_freq++;
            array<int,3> p = used_it[least_freq].back();
            used_it[least_freq].pop_back();
            key_it.erase(p[0]);
        }
        used_it[1].push_front({key,value,1});
        key_it[key] = used_it[1].begin();
        least_freq = 1;
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
