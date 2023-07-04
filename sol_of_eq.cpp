#include <bits/stdc++.h>
using namespace std;

void generateSolutions(int n, int targetSum, vector<int>& solution, int currentIndex, int currentSum){
    if(currentIndex == n){
        if(currentSum == targetSum){
            for (int i = 0; i<n; i++){
                cout << solution[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for(int i = 0; i <= targetSum - currentSum; i++){
        solution[currentIndex] = i;
        generateSolutions(n, targetSum, solution, currentIndex + 1, currentSum + i);
    }
}

int main(){
    int n, targetSum;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the target sum (C<=10): ";
    cin >> targetSum;

    vector<int> solution(n);
    cout << "\nThe possible combinations are: ";
    generateSolutions(n, targetSum, solution, 0, 0);

    return 0;
}
