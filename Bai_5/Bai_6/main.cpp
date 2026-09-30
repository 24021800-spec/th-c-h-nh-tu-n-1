#include <iostream>

using namespace std;

void inDay(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void xoaPhanTu(int a[], int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri k = " << k << " khong hop le de xoa!" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}
void chenPhanTu(int a[], int &n, int y, int m) {
    if (m < 0 || m > n) {
        cout << "Vi tri m = " << m << " khong hop le de chen!" << endl;
        return;
    }
    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }

    a[m] = y;

    n++;
}

int main() {
    int n, a[1000]; 

    cout << "Nhap so luong phan tu N: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu cua day:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "\n--- DAY SO BAN DAU ---" << endl;
    inDay(a, n);

    int k;
    cout << "\nNhap vi tri k can xoa (chi so tu 0): ";
    cin >> k;
    xoaPhanTu(a, n, k);
    cout << "Day so sau khi xoa: ";
    inDay(a, n);
    int y, m;
    cout << "\nNhap gia tri y can chen: ";
    cin >> y;
    cout << "Nhap vi tri m can chen (chi so tu 0): ";
    cin >> m;
    chenPhanTu(a, n, y, m);
    cout << "Day so sau khi chen " << y << " vao vi tri " << m << ": ";
    inDay(a, n);

    return 0;
}
