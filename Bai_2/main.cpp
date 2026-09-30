#include <iostream>
#include <utility> 

using namespace std;

void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]); 
            }
        }
    }
}

int main() {
    int n, a[100];

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap cac so: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sapXepTangDan(a, n);

    cout << "Day so tang dan: \n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

    
