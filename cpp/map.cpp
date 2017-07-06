#include <iostream>
#include <string>

using namespace std;

struct lelem {
    string data;
    int key;
    lelem *next;
};

// Realizes a map with a linked list
class Map {
    private:
        lelem* head;

    public:
        Map();
        ~Map();
        bool insert(int k, string data);
        bool remove(int k);
        string getData(int k);
};

Map::Map() {
    head = NULL;
}

Map::~Map() {
    if (head) { 
        lelem *tmp = head;
        while (tmp) {
            head = tmp;
            delete head;
            tmp = tmp->next;
        }
    }
}

bool Map::insert(int k, string d) {
    try {
        lelem *item = new lelem;
        item->data = d;
        item->key = k;
        item->next = head;
        head = item;
        cout << "Inserting k = " << k << ", v = " << d << endl;
        return true;
    } catch (...) {
        return false;
    }
}

bool Map::remove(int k) {
    bool out = false;

    if (head) {
        lelem *tmp = head;
        lelem *prev = NULL;
        
        while (tmp && tmp->key != k) {
            prev = tmp;
            tmp = tmp->next;
        }

        if (tmp && tmp->key == k) {
            cout << "Remove = TRUE. Removing k = " << tmp->key << ", v = " << tmp->data << endl;
            if (prev)
                prev->next = tmp->next;
            else
                head = NULL;
            delete tmp;
            out = true;
        } else {
            cout << "Remove = FALSE. Not found.\n";
        }
    } else {
        cout << "Remove = FALSE. Empty.\n";
    }
    return out;
}

string Map::getData(int k) {
    string out = "";

    if (head) {
        lelem *tmp = head;
        while (tmp && tmp->key != k) {
            tmp = tmp->next;
        }

        if (tmp && tmp->key == k) {
            out = tmp->data;
        }
    }

    cout << "Returning " << out << endl;
    return out;
}

int main() {
    Map map;
    map.insert(1, "test");
    map.getData(2);
    return 0;
}