#include <iostream>

using namespace std;

struct lelem {
    int data;
    int prio;
    lelem *next;
};

class PrioQueue {
    private:
        int size;
        lelem *head;
        lelem *tail;

    public:
        PrioQueue();
        ~PrioQueue();
        bool empty();
        void enqueue(int d, int p);
        int dequeue();
        int getSize();
        void stat();
};

PrioQueue::~PrioQueue() {
    if (head) { 
        lelem *tmp = head;
        while (tmp) {
            head = tmp;
            delete head;
            tmp = tmp->next;
        }
    }
}

PrioQueue::PrioQueue() {
    head = NULL;
    size = 0;
}

void PrioQueue::stat() {
    cout << "Head: " << head << endl;
    cout << "Tail: " << tail << endl;
}

bool PrioQueue::empty() {
    cout << "PrioQueue empty: " << size << endl;
    return size == 0 ? true : false;
}

void PrioQueue::enqueue(int d, int p){
    lelem *item = new lelem;
    item->data = d;
    item->prio = p;
    item->next = NULL;

    if (!head) {
        head = tail = item;
    } else if (p > head->prio) {
        // Insert front
        item->next = head;
        head = item;
    } else {
        lelem *tmp = head;
        // Move forward until right position is found
        while (tmp->next && p > tmp->prio) {
            tmp = tmp->next;
        }
        // Inserted item is not last element
        if (tmp->next != NULL) {
            item->next = tmp->next;
        } else {
            tail = item;
        }
        tmp->next = item;
    }
    
    size++;
    cout << "Inserting: " << item->data << ", Prio: " << item->prio << endl;
}

int PrioQueue::dequeue() {
    int out = -9999;
    int prio = 0;
    if (size == 0) {
        cout << "PrioQueue is empty.";
        return -9999;
    } else if (size == 1) {
        out = head->data;
        prio = head->prio;
        head = tail = NULL;
    } else {
        out = head->data;
        prio = head->prio;
        head = head->next;
    }
    size--;
    cout << "Removing: " << out << ", Prio: " << prio << endl;
    
    return out;

}

int PrioQueue::getSize() {
    cout << "Size: " <<size << endl;
    return size;
}

int main() {
    PrioQueue q;

    q.enqueue(4, 10);
    q.enqueue(0, 1);
    q.enqueue(1, 2);
    q.enqueue(2, 2);
    q.enqueue(3, 3);
    q.dequeue();

    return 0;
}