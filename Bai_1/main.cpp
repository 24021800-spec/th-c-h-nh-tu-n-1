#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu N: ";
    cin >> n;
    
    vector<int> a(n);
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    cout << "Tong cac phan tu trong day: " << sum << endl;
    return 0;
}
// Độ phức tạp thuật toán là: O(n).
