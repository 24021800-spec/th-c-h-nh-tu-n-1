#include<iostream>
using namespace std;
void xoaphantu(int &n, int a[],int k){
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=k;i<n-1;i++){
        a[i] = a[i+1];
        }
        n--;
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
    }
}
void themphantu(int &n,int a[],int m,int y){
    for(int i=n-1 ;i>=m;i--){
        a[i+1]=a[i];
    }
    a[m]=y;
    n++;
    for(int i=0;i<n;i++){
        cout << a[i];
    }
}
int main(){
    int n,m,y;
    cin >>n>>m>>y;
    int a[1000];
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    themphantu(n,a,m,y);
 return 0;
}
// Độ phức tạp thuật toán là O(n).
