#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> squareMatrix(n, vector<int>(n));
    cout << "Fill the elements in matrix\n\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int temp;
            cout << "Enter the element at index [" << i << "][" << j << "]: ";
            cin >> temp;
            squareMatrix[i][j] = temp;
        }
    }
    return squareMatrix;
}

bool checkCompGraph(vector<vector<int>> matrix){
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[i].size(); j++){
            if(i==j){
                continue;
            }
            if(matrix[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cout << "Check if a given graph is a complete graph using the Adjacency Matrix representation\n\n";
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "\n\n";
    vector<vector<int>> matrix = generateMatrix(n);
    bool result = checkCompGraph(matrix);
    if(result == true){
        cout << "The given graph is a complete graph.";
    }
    else{
        cout << "The given graph is not a complete graph.";
    }
}
