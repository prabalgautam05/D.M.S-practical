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

void computeVertexDegree(vector<vector<int>>& matrix, vector<int>& inDegree, vector<int>& outDegree){
    int n = matrix.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == 1){
                inDegree[j] ++;
                outDegree[i] ++;
            }
        }
    }
}

int main(){
    int n;

    cout << "Compute the in-degree and out-degree of each vertex in a Directed Graph\n\n";
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    cout << "\n\n";
    vector<vector<int>> matrix = generateMatrix(n);

    vector<int> inDegree(n,0);
    vector<int> outDegree(n,0);

    computeVertexDegree(matrix, inDegree, outDegree);
    cout << "\nVertex\tIn-Degree\tOut-Degree\n";
    for(int i = 0; i<n; i++){
        cout << i << "\t" << inDegree[i] << "\t\t" << outDegree[i] << endl;        
    }
    return 0;
}
