#include<iostream>
using namespace std;
void xoahang(int &m, int n, int a[][100], int k){
    for(int i = k; i < m - 1; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = a[i+1][j];
        }
    }

    m--;
}
int main(){
    int m, n;
    cin >> m >> n;

    int a[100][100];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;

    xoahang(m, n, a, k);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//Độ phức tạp thuật toán là O(mn).
