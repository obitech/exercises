#include <iostream>
#include <string>

using namespace std;

struct lelem {
    int data;
    lelem *next; 
};

// 3.1 Prints linked list
void lprint(lelem *head) {
    if (!head) {
        cout << "List is empty or doesn't exist.\n";
        return;
    }

    // Pointer which is accumulating
    lelem *tmp = head;
    int pos = 0;

    while (tmp) {
        cout << (pos + 1) << ". element: " << tmp->data;
        cout << ", &tmp = " << tmp;
        cout << ", &tmp->next = " << tmp->next << endl;
        tmp = tmp->next;
        pos++;        
    }
}

// 3.2 Returns size of list
int lsize(lelem *head) {
    if (!head) {
        cout << "List is empty or doesn't exist.\n";
        return 0;
    }

    // Pointer which is accumulating
    lelem *lptr = head;
    int sum = 0;

    while (lptr) {
        sum++;
        lptr = lptr->next;
    }

    return sum;
}

// 3.3 Sums elements of list
int lsum(lelem *head) {
    if (!head) {
        return 0;
    }

    lelem *lptr = head;
    int sum = 0;

    while (lptr) {
        sum += lptr->data;
        lptr = lptr->next;
    }

    return sum;
}

// 3.4. Returns percentage of negative elements in list
float lnegs(lelem *head) {
    if (!head) {
        return 0;
    }

    float output = 0;
    int n = 0;
    lelem *lptr = head;

    while(lptr) {
        if (lptr->data < 0) {
            output++;
        }
        n++;
        lptr = lptr->next;
    }

    return output / n;
}

// 3.5 Inserts new start element, & for call by reference
void insert_front(lelem *&head, int d) {
    lelem *start = new lelem;
    start->data = d;
    start->next = head;
    head = start;
}

// 3.6 Insert last element
void insert_back(lelem *&head, int d) {
    lelem *back = new lelem;
    back->data = d;
    back->next = NULL;

    if (head) {
        lelem *lptr = head;  
        while(lptr->next) {
            lptr = lptr->next;
        }

        lptr->next = back;          
    }

    else {
        head = back;
    }

}

// 3.7 Remove front
void remove_front(lelem *&head) {
    if (!head) {
        cout << "List is empty or doesn't exist.\n";
        return;
    }
    delete head;
    head = head->next;
}

// 3.8 Remove back
void remove_back(lelem *&head) {
    if (!head) {
        cout << "List is empty or doesn't exist.\n";
        return;
    }

    // If only 1 element in list
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    lelem *tmp = head;

    // If more elements in list
    while(tmp->next->next) {
        tmp = tmp->next;
    }

    delete tmp->next;
    tmp->next = NULL;

    return;
}

// 3.9 Delete list
void delete_list(lelem *&head) {
    lelem *temp = head->next;

    if (!temp) {
        delete head;
        head = NULL;
    }

    while (temp) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// 3.12 Insert an element into a sorted list
void insert_sorted(lelem *&head, int d) {

    // List is empty or d is smallest element
    if (!head || d < head->data) {
        insert_front(head, d);
        return;
    }

    lelem *tmp = head;

    // next element is not last and d is still bigger than next element
    while(tmp->next && d > tmp->next->data) {
        tmp = tmp->next;
    }

    // TODO: Check case where d is to be inserted as last element
    lelem * newlelem = new lelem;
    newlelem->data = d;
    newlelem->next = tmp->next;
    tmp->next = newlelem;
}

// 3.13 Remove element with specific data
bool remove_data(lelem *&head, int data){
    lelem *tmp = head;
    lelem *save;

    // Head is element to be found
    if (head->data == data) {
        remove_front(head);
        return true;
    }

    while (tmp->next != NULL) {
        // Element was found
         if (tmp->next->data == data) {
            save = tmp->next;

            // If it's last element
            if (!tmp->next->next) {
                tmp->next = NULL;
                remove_back(head);
                return true;
            }

            // If it's not the last element
            tmp->next = save->next;

            delete save;
            return true;
        }
        tmp = tmp->next;
    }

    // No element wasn't found
    return false;
}

// 3.14 Remove all elements which have data d, return int with how many have been deleted
int remove_data_all(lelem *&head, int d) {
    int count = 0;
    bool success = true;

    while (success) {
        success = remove_data(head, d);
        
        if (success) {
            count++;
        }
    }

    return count;
}

// 3.16 Print a list recursively
void lprint_rec(lelem *head) {
    if (head == NULL) {
        cout << endl;
        return;
    }

    // Uncomment this to print list backwards
    lprint_rec(head->next);

    cout << head->data << endl;

    // Comment this out to print list backwards
    //lprint_rec(head->next);

}

int main() {
    lelem *head = NULL;
    lelem *head2 = NULL;
    lprint(head);

    insert_front(head, 2);
    insert_front(head, 5);
    insert_front(head, -3);
    insert_front(head, -8);
    insert_front(head, 23);
    insert_front(head, 205);

    lprint(head);

    cout << lnegs(head) << endl;

    remove_front(head);
    lprint(head);

    cout << endl;

    remove_front(head);
    lprint(head);

    cout << endl;

    insert_back(head, 666);
    lprint(head);

    cout << endl;

    insert_back(head2, 8008);
    lprint(head2);

    cout << endl;

    lprint_rec(head);

    return 0;
}