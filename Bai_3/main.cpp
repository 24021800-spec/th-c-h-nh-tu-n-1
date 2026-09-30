#include <iostream>
using namespace std;
long long tinhGiaiThua(int n) {
    long long giaiThua = 1;
    for (int i = 1; i <= n; i++) {
        giaiThua *= i;
    }
    return giaiThua;
}
int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    if (n < 0) {
        cout << "so am khong co !" << endl;
    } else {
        cout << n << "! = " << tinhGiaiThua(n) << endl;
    }
    return 0;
}
