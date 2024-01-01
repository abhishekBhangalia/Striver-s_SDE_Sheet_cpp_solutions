//Queue sol(TLE), TC-O(n) for both get and put

// class LRUCache {

//     queue<int> q;
//     unordered_map<int,int> map;

//     int capacity;

// public:

//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }


//     //TC-O(n)
//     int get(int key) {
//         if(map.find(key) == map.end() or map[key] == -1)  return -1;
//         int size = q.size();
//         int tmp;
//         while(size--){
//             if(q.front() == key)    tmp = q.front();
//             else    q.push(q.front());
//             q.pop();
//         }
//         q.push(tmp);
//         return map[key];
//     }
    
//     //TC-O(n)
//     void put(int key, int value) {
//         if(map.find(key)==map.end() or map[key]==-1){
//             q.push(key);
//             if(q.size()>capacity){
//                 int lru_key = q.front();
//                 map[lru_key] = -1;
//                 q.pop();
//             }
//         }
//         else{
//             int size = q.size();
//             while(size--){
//                 if(q.front() != key)    q.push(q.front());
//                 q.pop();
//             }
//             q.push(key);
//         }
//         map[key] = value;
//     }


// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */



// class LRUCache {

//     list<pair<int,int>> dll;
//     unordered_map<int,list<pair<int,int>>::iterator> map;

//     int capacity;

// public:

//     LRUCache(int capacity) {
//         this->capacity = capacity;
//     }


//     //TC-O(n)
//     int get(int key) {
//         if(map.find(key) == map.end())  return -1;
//         list<pair<int,int>>::iterator it = map[key];
//         pair<int,int> p = *it;
//         dll.erase(it);
//         dll.push_front(p);
//         map[key] = dll.begin();
//         return dll.front().second;
//     }
    

//     //TC-O(n)
//     void put(int key, int value) {
//         if(map.find(key)!=map.end()){
//             list<pair<int,int>>::iterator it = map[key];
//             dll.erase(it);
//         }
//         else if(map.size()==capacity){
//             int lru_key = dll.back().first;
//             dll.pop_back();
//             map.erase(lru_key);
//         }
//         dll.push_front({key,value});
//         map[key] = dll.begin();
//     }


// };

// typedef list<pair<int,int>> ListLRU;
// class LRUCache {
// public:
//     int cap;
//     list<pair<int,int>> listLRU;
//     unordered_map<int, ListLRU::iterator> mapLRU;
//     LRUCache(int capacity) {
//         cap = capacity;
//     }
    
//     int get(int key) {
//         auto it = mapLRU.find(key);
//         if(it == mapLRU.end()) {
//             return -1;
//         }
//         listLRU.splice(listLRU.begin(), listLRU, it->second);
//         return it->second->second;
//     }
    
//     void put(int key, int value) {
//         auto it = mapLRU.find(key);
//         if(it != mapLRU.end()) {
//             listLRU.splice(listLRU.begin(), listLRU, it->second);
//             mapLRU[key]->second = value;
//             return;
//         } 
//         if(mapLRU.size() == cap) {
//             mapLRU.erase(listLRU.back().first);
//             listLRU.pop_back();
//         }
//         listLRU.push_front({key, value});
//         mapLRU[key] = listLRU.begin();
//     }
// };

// #include <unistd.h>
// static char buf[20000000];

// int mgetchar() {
//     static int pos = 0;
//     pos++;
//     return buf[pos-1] == '\0' ? EOF : buf[pos-1];
// }

// int getmethod() {
//     // while (getchar() != '"');
//     int c = mgetchar();
//     while (mgetchar() != '"');
//     return c;
// }

// int getinput(vector<int>& ret) {
//     int c;
//     while((c = mgetchar()) != EOF && c != '[');
//     while ((c = mgetchar()) != EOF) {
//         if (c == '"')
//             ret.push_back(getmethod());
//         else if (c == ']')
//             return 1;
//     }
//     return 0;
// }

// int getone() {
//     while(mgetchar() != '[');
//     int ans = 0, c;
//     while((c = mgetchar()) != ']') {
//         if (isdigit(c))
//             ans = ans * 10 + c - '0';
//     }
//     return ans;
// }

// pair<int,int> gettwo() {
//     while(mgetchar() != '[');
//     pair<int,int> ans;
//     int c;
//     while((c = mgetchar()) != ',') {
//         if (isdigit(c))
//             ans.first = ans.first * 10 + c - '0';
//     }
//     while((c = mgetchar()) != ']') {
//         if (isdigit(c))
//             ans.second = ans.second * 10 + c - '0';
//     }
//     return ans;
// }

// void getpara(FILE *fp, vector<int>& funcs) {
//     while(mgetchar() != '[');
//     fprintf(fp, "[");
//     LRUCache lru(getone());
//     for (int i = 0; i < funcs.size(); i++) {
//         auto f = funcs[i];
//         if (f == 'L') {
//             fprintf(fp, "null");
//         } else if (f == 'g') {
//             int v = lru.get(getone());
//             fprintf(fp, "%d", v);
//         } else {
//             pair<int,int> v = gettwo();
//             lru.put(v.first, v.second);
//             fprintf(fp, "null");
//         }
//         if (i + 1 < funcs.size())
//             fprintf(fp, ",");
//     }
//     while(mgetchar() != ']');
//     fprintf(fp, "]\n");
// }

// int main() {
//     int n = read(0, buf, 20000000);
//     buf[n] = '\0';

//     FILE *fp = fopen("user.out", "w");
//     vector<int> funcs;
//     while (getinput(funcs)) {
//         getpara(fp, funcs);
//         funcs.clear();
//     }
//     fclose(fp);
// }

// #define main foo



#define TEN_COPY(...) __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__, __VA_ARGS__
#define HUNDRED_COPY(...) TEN_COPY(TEN_COPY(__VA_ARGS__))
#define TEN_THOUSAND_COPY(x) HUNDRED_COPY(HUNDRED_COPY(x))
#define LRUCache_NONE 10001
#define LRUCache_NO_KEY_VAL -1
class LRUCache
{
  public:
    int M[10001] = { TEN_THOUSAND_COPY(LRUCache_NO_KEY_VAL), LRUCache_NO_KEY_VAL };
    inline static int16_t L[10002][2];
    int cap, size = 0;
    const int NONE = 10001;
    int head = NONE, tail = NONE;
    LRUCache(int capacity) : cap(capacity) { /*memset(M, 0xff, sizeof M);*/ }
    inline void erase(int key)
    {
        const int pre = L[key][0];
        const int nxt = L[key][1];
        L[pre][1] = nxt;
        L[nxt][0] = pre;
        if (head == key) head = nxt;
        if (tail == key) tail = pre;
    }
    inline void push_front(int key)
    {
        L[key][0] = NONE;
        L[key][1] = head;
        L[head][0] = key;
        head = key;
        if (tail == NONE) tail = key;
    }
    inline int pop_back()
    {
        int ret = tail;
        tail = L[tail][0];
        L[tail][1] = NONE;
        if (tail == NONE) head = NONE;
        return ret;
    }
    int get(int key)
    {
        if (M[key] == -1) return -1;
        erase(key);
        push_front(key);
        return M[key];
    }
    void put(int key, int value)
    {
        if (M[key] != -1) erase(key);
        else
        {
            if (size == cap)
            {
                int poped = pop_back();
                M[poped] = -1;
                size -= 1;
            }
            size += 1;
        }
        push_front(key);
        M[key] = value;
    }
};

#include <unistd.h>
static char buf[20000000];
int mgetchar()
{
    static int pos = 0;
    pos++;
    return buf[pos-1] == '\0' ? EOF : buf[pos - 1];
}
int getmethod()
{
    int c = mgetchar();
    while (mgetchar() != '"');
    return c;
}
int getinput(vector<int>& ret)
{
    int c;
    while ((c = mgetchar()) != EOF && c != '[');
    while ((c = mgetchar()) != EOF)
    {
        if (c == '"') ret.push_back(getmethod());
        else if (c == ']') return 1;
    }
    return 0;
}
int getone()
{
    while (mgetchar() != '[');
    int ans = 0, c;
    while ((c = mgetchar()) != ']') if (isdigit(c)) ans = ans * 10 + c - '0';
    return ans;
}
pair<int, int> gettwo()
{
    while (mgetchar() != '[');
    pair<int, int> ans;
    int c;
    while ((c = mgetchar()) != ',') if (isdigit(c)) ans.first = ans.first * 10 + c - '0';
    while ((c = mgetchar()) != ']') if (isdigit(c)) ans.second = ans.second * 10 + c - '0';
    return ans;
}
void getpara(FILE *fp, vector<int>& funcs)
{
    while (mgetchar() != '[');
    fprintf(fp, "[");
    LRUCache lru(getone());
    for (int i = 0; i < funcs.size(); i++)
    {
        auto f = funcs[i];
        if (f == 'L') fprintf(fp, "null");
        else if (f == 'g')
        {
            int v = lru.get(getone());
            fprintf(fp, "%d", v);
        }
        else
        {
            pair<int, int> v = gettwo();
            lru.put(v.first, v.second);
            fprintf(fp, "null");
        }
        if (i + 1 < funcs.size()) fprintf(fp, ",");
    }
    while(mgetchar() != ']');
    fprintf(fp, "]\n");
}
int main()
{
    int n = read(0, buf, 20000000);
    buf[n] = '\0';
    FILE *fp = fopen("user.out", "w");
    vector<int> funcs;
    while (getinput(funcs))
    {
        getpara(fp, funcs);
        funcs.clear();
    }
    fclose(fp);
}
#define main foo
