#include <bits/stdc++.h>
using namespace std;


class SET {
public:
    void isMember(set <int> elements) {
        bool temp = false;
        int n;
        cout<<"Write the element to check for in the list: ";
        cin>>n;
        set<int>::iterator t;
        for(t = elements.begin(); t != elements.end(); t++){
            if (n == *t){
                temp = true;
            }
        }
        if(temp == true){
            cout<<"TRUE";
        }
        else{
            cout<<"FALSE";
        }
        
    }
    void generatePowerSet(const set<int>& elements){
        set<int> subset;
        auto index = elements.begin();
        printPowerSet(elements, subset, index);
    }
    void printPowerSet(const set<int>& S, set<int>& subset, const set<int>::iterator& index){
        cout<<"{";
        for (auto itr = subset.begin(); itr != subset.end(); itr++) {
            cout << *itr <<" ";
        }
        cout << "}" << endl;

        for (auto i = index; i != S.end(); i++) {
        subset.insert(*i);
        printPowerSet(S, subset, next(i));
        subset.erase(*i);
        }
    }

    bool isSubset(const set<int>& elements, const set<int>& subset){
        for (const auto& element : subset) {
            if (elements.find(element) == elements.end()) {
                return false;
            }
        }
        return true;
    }

    void printUnion(const set<int>& elements, const set<int>& elements2){
        set<int> unionSet;
        set_union(elements.begin(), elements.end(), elements2.begin(), elements2.end(), inserter(unionSet, unionSet.begin()));
        cout<<"Union Set: {";
        for(const auto& element : unionSet){
            cout << element << " ";
        }
        cout<<"}"<<endl;
    }

    void printIntersection(const set<int>& elements, const set<int> elements2){
        set<int> intersectionSet;

        for (const auto& element : elements){
            if (elements2.count(element) >0){
                intersectionSet.insert(element);
            }
        }
        cout<<"Intersection Set: {";
        for(const auto& element : intersectionSet){
            cout << element << " ";
        }
        cout<<"}"<<endl;
    }

    void printComplement(const set<int>& elements, int universeSize){
        set<int> complementSet;
        for (int i = 1; i <= universeSize; ++i){
            if (elements.find(i) == elements.end()){
                complementSet.insert(i);
            }
        }
        cout<<"Compliment Set: {";
        for(auto const& element : complementSet){
            cout<< element << " ";
        }
        cout<<"}\n";
    }
    void printSetDifference(const set<int>& elements, const set<int>& elements2){
        set<int> setDifference;
        set_difference(elements.begin(), elements.end(),elements2.begin(),elements2.end(),inserter(setDifference,setDifference.begin()));

        cout<<"Set Difference: {";
        for(auto const& element : setDifference){
            cout << element <<" ";
        }
        cout<<"}\n";
    }
    void printCartesianProduct(const set<int>& elements, const set<int>& elements2){

        cout<<"Cartesian Product:  {";
        for(auto const& element1 : elements){
            for(auto const& element2 : elements2){
                cout<<"{ "<<element1<<" , "<<element2<<"}, ";
            }
        }
        cout<<"}";
    }
};




int main(){
    set <int> elements = {1,2,3,4,8};
    SET test;
    cout<<"Check whether an element belongs to the set or not and return value as true/false\n\n";
    test.isMember(elements);

    cout<<"\n\nList all the elements of the power set of a set";
    test.generatePowerSet(elements);

    cout<<"\n\nCheck whether one is the subset of other or not";
    set<int> subset = {1,6};
    cout<<"Is {1,6} a subset of \'elements\'?" <<endl<<(test.isSubset(elements, subset) ? "Yes":"No")<<endl;
    
    cout<<endl;
    set <int> elements2 = {5,6,7,8,9,10,23,45,7,2,99};
    test.printUnion(elements, elements2);
    
    test.printIntersection(elements, elements2);

    int universeSize = elements.size();
    test.printComplement(elements, universeSize);

    test.printSetDifference(elements,elements2);

    test.printCartesianProduct(elements,elements2);

    return 0;
}
