#include <bits/stdc++.h>
using namespace std;

void generateList(int list[], int n){
    for(int i = 0; i<n; i++){
        int temp;
        cout << "Enter the element at index [" << i << "] : ";
        cin >> temp;
        list[i] = temp;
    }
}

bool checkCompGraph(int list[], int n){
    for(int i = 0; i<n; i++){
        int m = sqrt(n);
        cout << i%(n+1);
        if(i%(m+1)==0){
            continue;
        }

        if(list[i] != 1){
            return false;
        }
    }
    return true;
}

int main(){
    cout << "Check if a given graph is a complete graph using the Adjacency List representation\n\n";
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "\n\n";
    n = pow(n,2);
    int list[n];
    generateList(list, n);
    bool result = checkCompGraph(list, n);
    if(result == true){
        cout << "The given graph is a complete graph.";
    }
    else{
        cout << "The given graph is not a complete graph.";
    }
    return 0;
}
