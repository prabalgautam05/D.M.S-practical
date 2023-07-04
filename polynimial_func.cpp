#include <bits/stdc++.h>
using namespace std;

void initialize(double array[], int n){
    int t = n-1;
    for(int i = 0; i<n; i++){
        cout << "Enter the coefficient of n*" << t << " : ";
        cin >> array[i];
        t--;
    }
}

void solution(double array[], int n, int size){
    double ans = 0.0;
    int t = size - 1;
    for(int i = 0; i<size; i++){
        ans += array[i]*(pow(n,t));
        t--;
    }
    cout << "The answer is: " << ans;
}

int main(){
    int size;
    cout << "Enter the degree  of polynomial: ";
    cin >> size;
    double array[size];
    cout << endl;
    initialize(array, size);
    int n;
    cout << "\nEnter the value of n to calculate the value of polynomial: ";
    cin >> n; 
    solution(array, n, size);
    return 0;
}
