
#include <iostream>
using namespace std;

const int M = 10;
int table[M];

int hashFunction(int x) {
    return ((x % M) + M) % M;
}

void insert(int x) {
    int h = hashFunction(x);
    int i = 0;

    while (i < M && table[h] != -1) {
        h = (h + 1) % M;
        i++;
    }

    if (i == M) {
        cout << "Bang bam da day!\n";
        return;
    }

    table[h] = x;
}

bool search(int x) {
    int h = hashFunction(x);
    int i = 0;

    while (i < M && table[h] != -1) {
        if (table[h] == x)
            return true;

        h = (h + 1) % M;
        i++;
    }

    return false;
}

void removeElement(int x) {
    int h = hashFunction(x);
    int i = 0;

    while (i < M && table[h] != -1) {
        if (table[h] == x) {
            table[h] = -2;
            cout << "Da xoa " << x << endl;
            return;
        }

        h = (h + 1) % M;
        i++;
    }

    cout << "Khong tim thay " << x << endl;
}

void display() {
    for (int i = 0; i < M; i++) {
        cout << i << ": ";

        if (table[i] == -1 || table[i] == -2)
            cout << "NULL";
        else
            cout << table[i];

        cout << endl;
    }
}

int main() {
    for (int i = 0; i < M; i++)
        table[i] = -1;

    int n, x, chon;

    cout << "Nhap so phan tu: ";
    cin >> n;

    cout << "Nhap mang: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(x);
    }

    do {
        cout << "\n1. Them\n";
        cout << "2. Tim kiem\n";
        cout << "3. Xoa\n";
        cout << "4. In bang bam\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;

        if (chon == 1) {
            cout << "Nhap so can them: ";
            cin >> x;
            insert(x);
        }
        else if (chon == 2) {
            cout << "Nhap so can tim: ";
            cin >> x;

            if (search(x))
                cout << "Tim thay\n";
            else
                cout << "Khong tim thay\n";
        }
        else if (chon == 3) {
            cout << "Nhap so can xoa: ";
            cin >> x;
            removeElement(x);
        }
        else if (chon == 4) {
            display();
        }

    } while (chon != 0);

    return 0;
}
