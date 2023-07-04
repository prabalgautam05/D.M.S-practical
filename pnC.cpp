#include <bits/stdc++.h>
using namespace std;

class SolutionWithoutRepetition{
    private:
        void generatePermutationsWithoutRepetition(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return;
            }
            for(int i = 0; i<nums.size(); i++){
                if(!freq[i]){
                    ds.push_back(nums[i]);
                    freq[i] = 1;
                    generatePermutationsWithoutRepetition(ds, nums, ans, freq);
                    freq[i] = 0;
                    ds.pop_back();                }
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[nums.size()] = {0};
            generatePermutationsWithoutRepetition(ds, nums, ans, freq);
            return ans;
        }
        

};


class SolutionWithRepetition{
    private:
        void generatePermutationsWithRepetition(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return;
            }
            for(int i = 0; i<nums.size(); i++){
                ds.push_back(nums[i]);
                generatePermutationsWithRepetition(ds, nums, ans);
                ds.pop_back();                
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>> ans;
            vector<int> ds;
            generatePermutationsWithRepetition(ds, nums, ans);
            return ans;
        }
        

};

void output(vector<vector<int>> &ans){
    cout << "Possible permutations are: \n";
    cout << "A total of " << ans.size() << " possible permutations are generated.\n";
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout <<  endl;
    }
}

int main(){
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;
    cout << endl;
    vector<int> nums;
    for(int i = 0; i<n; i++){
        int temp;
        cout << "Enter digit [" << i+1 << "] : ";
        cin >> temp;
        nums.push_back(temp);
    }
    cout << endl;
    SolutionWithRepetition repeat;

    vector<vector<int>> display;
    display = repeat.permute(nums);
    cout << "SOLUTION WITH REPETITION\n\n";
    output(display);
    cout<< endl;

    SolutionWithoutRepetition noRepeat;

    vector<vector<int>> ndisplay;
    ndisplay = noRepeat.permute(nums);
    cout << "SOLUTION WITHOUT REPETITION\n\n";
    output(ndisplay);

    return 0;
}
