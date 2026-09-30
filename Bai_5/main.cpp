#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Nhap so luong phan tu N: ";
    cin >> n;
    if (n <= 0) {
        cout << "N phai la so nguyen duong!" << endl;
        return 0;
    }
    vector<double> a(n);
    double tong = 0;
    cout << "Nhap " << n << " so thuc:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i]; 
    }
    double trungBinh = tong / n;
    cout << "\nGia tri trung binh cua day: " << trungBinh << endl;
    cout << "Cac gia tri lon hon hoac bang trung binh:\n";
    for (int i = 0; i < n; i++) {
        if (a[i] >= trungBinh) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
