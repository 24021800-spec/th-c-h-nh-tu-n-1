
#include <iostream>
using namespace std;

const int M = 7;
// Linked list hash table

struct Node {
    int key;
    Node* next;

    Node(int value) {
        key = value;
        next = nullptr;
    }
};

class HashTable {
private:    // Nhung ham duoc khai bao voi muc dich chi de su dung trong noi bo class, khong the dung o ngoai
    Node* table[M];

    int hashFunction(int key) {     //<---
        return ((key % M) + M) % M;
    }

public:     // Nhung ham duoc khai bao co the duoc su dung o cac ham khac
    HashTable() {
        for (int i = 0; i < M; i++)
            table[i] = nullptr;
    }

    void insert(int key) {
        int index = hashFunction(key);      //<---

        if (search(key)) {
            cout << "Key already exists!\n";
            return;
        }

        Node* p = new Node(key);
        p->next = table[index];
        table[index] = p;
    }

    bool search(int key) {
        int index = hashFunction(key);
        Node* p = table[index];

        while (p != nullptr) {
            if (p->key == key)
                return true;
            p = p->next;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* p = table[index];
        Node* prev = nullptr;

        while (p != nullptr && p->key != key) {
            prev = p;
            p = p->next;
        }

        if (p == nullptr) {
            cout << "Key not found!\n";
            return;
        }

        if (prev == nullptr)
            table[index] = p->next;
        else
            prev->next = p->next;

        delete p;
    }

    void display() {
        for (int i = 0; i < M; i++) {
            cout << i << ": ";
            Node* p = table[i];

            while (p != nullptr) {
                cout << p->key << " -> ";
                p = p->next;
            }

            cout << "NULL\n";
        }
    }

    ~HashTable() {
        for (int i = 0; i < M; i++) {
            Node* p = table[i];

            while (p != nullptr) {
                Node* temp = p;
                p = p->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert(10);
    ht.insert(17);
    ht.insert(24);
    ht.insert(5);
    ht.insert(12);

    ht.display();

    cout << "Search 17: " << ht.search(17) << '\n';

    ht.remove(17);
    ht.display();

    return 0;
}
