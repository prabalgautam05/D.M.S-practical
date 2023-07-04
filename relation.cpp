#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createMatrix() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;
    cout << endl;

    vector<vector<int>> matrix(rows, vector<int>(columns, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int value;
            cout << "Enter the value for matrix[" << i << "][" << j << "]: ";
            cin >> value;
            matrix[i][j] = value;
        }
        cout << endl;
    }
    return matrix;
}

void displayMatrix(vector<vector<int>> matrix){
    cout << "Matrix is: \n";
    for(int i = 0; i<matrix.size(); i++){
        cout << "[ ";
        for(int j = 0; j<matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

class RELATION{
    private:
        vector<vector<int>> matrix;

    public:
        

        RELATION(vector<vector<int>> relation_matrix){
            matrix = relation_matrix;
        }

        bool isReflexive(){
            for(int i = 0; i<matrix.size(); i++){
                if(matrix[i][i] != 1){
                    return false;
                }
            }
            return true;
        }

        bool isSymmetric(){
            for(int i = 0; i<matrix.size(); i++){
                for(int j = 0; j<matrix.size(); j++){
                    if(matrix[i][j] != matrix[j][i]){
                        return false;
                    }
                }
            }
            return true;
        }

        bool isAntiSymmetric(){
            for(int i = 0; i<matrix.size(); i++){
                for(int j = 0; j<matrix.size(); j++){
                    if(matrix[i][j] != -matrix[j][i]){
                        return false;
                    }
                }
            }
            return true;
        }

        bool isTransitive(){
            for(int i = 0; i<matrix.size(); i++){
                for(int j = 0; j<matrix.size(); j++){
                    if(matrix[i][j] == 1){
                        for(int k = 0; k<matrix.size(); k++){
                            if(matrix[j][k] == 1 && matrix[i][k] != 1){
                                return false;
                            }
                        }

                    }
                }
            }
            return true;
        }
};

int main(){
    vector<vector<int>> relationMatrix;

    relationMatrix = createMatrix();
    displayMatrix(relationMatrix);


    RELATION check(relationMatrix);
    cout << "\n\nCheck the matrix: \n";

    cout << "Reflexive: ";
    if(check.isReflexive()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    cout << "Symmetric: ";
    if(check.isSymmetric()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    cout << "AntiSymmetric: ";
    if(check.isAntiSymmetric()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    cout << "Transitive: ";
    if(check.isTransitive()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    cout << "\nThe given relation is: ";
    if(check.isReflexive() && check.isSymmetric() && check.isTransitive()){
        cout << "Equivalance Relation\n";
    }
    else if(check.isReflexive() && check.isAntiSymmetric() && check.isTransitive()){
        cout << "Partial Order relation\n";
    }
    else{
        cout << "None";
    }
    return 0;    
}
