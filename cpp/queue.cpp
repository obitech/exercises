#include <iostream>

using namespace std;

struct lelem {
    int data;
    lelem *next;
};

class Queue {
    private:
        int size;
        lelem *head;
        lelem *tail;

    public:
        Queue();
        ~Queue();
        bool empty();
        void enqueue(int d);
        int dequeue();
        int getSize();
        void stat();
};

Queue::~Queue() {
    if (head) { 
        lelem *tmp = head;
        while (tmp) {
            head = tmp;
            delete head;
            tmp = tmp->next;
        }
    }
}

Queue::Queue() {
    head = NULL;
    size = 0;
}

void Queue::stat() {
    cout << "Head: " << head << endl;
    cout << "Tail: " << tail << endl;
}

bool Queue::empty() {
    cout << "Queue empty: " << size << endl;
    return size == 0 ? true : false;
}

void Queue::enqueue(int d){
    lelem *item = new lelem;
    item->data = d;

    if (!head) {
        head = item;
    } else {
        lelem *tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = item;
    }

    tail = item;
    item->next = NULL;
    size++;
    cout << "Inserting: " << item->data << endl;

}

int Queue::dequeue() {
    int out = -9999;
    if (size == 0) {
        cout << "Queue is empty.";
    } else if (size == 1) {
        out = head->data;
        head = tail = NULL;
    } else {
        out = head->data;
        head = head->next;
    }
    size--;
    cout << "Removing: " << out << endl;
    
    return out;

}

int Queue::getSize() {
    cout << "Size: " <<size << endl;
    return size;
}

int main() {
    Queue q;
    int a = 5;
    int b = 6;
    int c = 3;
    q.enqueue(a);
    q.enqueue(b);
    q.enqueue(c);
    q.getSize();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    

    return 0;
}