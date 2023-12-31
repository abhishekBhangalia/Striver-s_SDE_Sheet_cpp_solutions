// Stack class.
class Stack {
    int * arr;
    int front;
    int size;
    
public:

    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        front = 0;
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(! isFull())
            arr[front++] = num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty())   return -1;
        return arr[--front];
        
    }
    
    int top() {
        // Write your code here.
        if(isEmpty())   return -1;
        return arr[front-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return front == 0;
    }
    
    int isFull() {
        // Write your code here.
        return front == size;
    }
    
};

