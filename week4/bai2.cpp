#include <iostream>
using namespace std;

const int M = 7;
//  Hash table dung dia chi mo (Open Addressing)

class HashTable {
private:
    int table[M];
    int state[M]; // 0: empty, 1: occupied, 2: deleted

    int hashFunction(int key) {
        return ((key % M) + M) % M;
    }

public:
    HashTable() {
        for (int i = 0; i < M; i++) {
            state[i] = 0;
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        int firstDeleted = -1;

        for (int i = 0; i < M; i++) {
            int pos = (index + i) % M;

            if (state[pos] == 1) {
                if (table[pos] == key) {
                    cout << "Key already exists!\n";
                    return;
                }
            }
            else if (state[pos] == 2) {
                if (firstDeleted == -1)
                    firstDeleted = pos;
            }
            else {
                if (firstDeleted != -1)
                    pos = firstDeleted;

                table[pos] = key;
                state[pos] = 1;
                return;
            }
        }

        if (firstDeleted != -1) {
            table[firstDeleted] = key;
            state[firstDeleted] = 1;
            return;
        }

        cout << "Hash table is full!\n";
    }

    bool search(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < M; i++) {
            int pos = (index + i) % M;

            if (state[pos] == 0)
                return false;

            if (state[pos] == 1 && table[pos] == key)
                return true;
        }

        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < M; i++) {
            int pos = (index + i) % M;

            if (state[pos] == 0) {
                cout << "Key not found!\n";
                return;
            }

            if (state[pos] == 1 && table[pos] == key) {
                state[pos] = 2;
                cout << "Key removed!\n";
                return;
            }
        }

        cout << "Key not found!\n";
    }

    void display() {
        for (int i = 0; i < M; i++) {
            cout << i << ": ";

            if (state[i] == 1)
                cout << table[i];
            else if (state[i] == 2)
                cout << "DELETED";
            else
                cout << "EMPTY";

            cout << '\n';
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

    cout << "Search 24: " << ht.search(24) << '\n';

    return 0;
}
