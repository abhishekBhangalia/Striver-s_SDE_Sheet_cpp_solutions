#include <bits/stdc++.h> 

class max_heap{
    vector<int> arr;
    int size;

    public:
    max_heap(){
        size = 0;
        arr.push_back(-1);
    }

    
    void insert(int x){
        size++;
        if(size == arr.size()){
            arr.push_back(x);
        }
        else    arr[size] = x;

        int i = size;
        while(i>1){
            int parent = i/2;
            if(arr[i]>arr[parent]){
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else    return;
        }
    }

    int del(){
        swap(arr[1],arr[size]);
        size --;

        int i = 1;
        while(i<size){
            int lchild = 2*i;
            int rchild = 2*i+1;
            int greatest = i;
            if(lchild <= size and arr[lchild]>arr[greatest]){
                greatest = lchild;
            }
            if(rchild <= size and arr[rchild]>arr[greatest]){
                greatest = rchild;
            }
            if(greatest != i){
                swap(arr[i],arr[greatest]);
                i = greatest;
            }
            else    break;
        }
        return arr[size+1];
    }

    void print(){
        for(int i = 0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


class min_heap{
    vector<int> arr;
    int size;

    public:
    min_heap(){
        size = 0;
        arr.push_back(-1);
    }

    
    void insert(int x){
        size++;
        if(size == arr.size()){
            arr.push_back(x);
        }
        else    arr[size] = x;

        int i = size;
        while(i>1){
            int parent = i/2;
            if(arr[i]<arr[parent]){
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else    return;
        }
    }

    int del(){
        swap(arr[1],arr[size]);
        size --;

        int i = 1;
        while(i<size){
            int lchild = 2*i;
            int rchild = 2*i+1;
            int smallest = i;
            if(lchild <= size and arr[lchild]<arr[smallest]){
                smallest = lchild;
            }
            if(rchild <= size and arr[rchild]<arr[smallest]){
                smallest = rchild;
            }
            if(smallest != i){
                swap(arr[i],arr[smallest]);
                i = smallest;
            }
            else    break;
        }
        return arr[size+1];
    }

    void print(){
        for(int i = 0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    min_heap h;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(q[i].size()>1){
            h.insert(q[i][1]);
        }
        else{
            ans.push_back(h.del());
        }
    }
    // h.print();
    return ans;

}

