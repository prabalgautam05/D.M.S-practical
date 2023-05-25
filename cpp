#include <iostream>
#include <vector>
#include <algorithm>

class Set {
private:
    std::vector<int> elements;

public:
    // Add an element to the set
    void addElement(int element) {
        if (!isMember(element))
            elements.push_back(element);
    }

    // Remove an element from the set
    void removeElement(int element) {
        elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    }

    // Check whether an element belongs to the set or not
    bool isMember(int element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    // List all elements of the power set
    std::vector<std::vector<int>> powerSet() const {
        std::vector<std::vector<int>> result;
        int n = elements.size();
        int subsets = pow(2, n);

        for (int i = 0; i < subsets; i++) {
            std::vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1)
                    subset.push_back(elements[j]);
            }
            result.push_back(subset);
        }

        return result;
    }

    // Check whether a set is a subset of another set
    bool isSubset(const Set& other) const {
        for (int element : elements) {
            if (!other.isMember(element))
                return false;
        }
        return true;
    }

    // Perform the union of two sets
    Set unionSet(const Set& other) const {
        Set resultSet = *this;

        for (int element : other.elements) {
            resultSet.addElement(element);
        }

        return resultSet;
    }

    // Perform the intersection of two sets
    Set intersectionSet(const Set& other) const {
        Set resultSet;

        for (int element : elements) {
            if (other.isMember(element))
                resultSet.addElement(element);
        }

        return resultSet;
    }

    // Calculate the complement of the set
    Set complement(const Set& universalSet) const {
        Set resultSet = universalSet;

        for (int element : elements) {
            resultSet.removeElement(element);
        }

        return resultSet;
    }

    // Perform set difference (A - B)
    Set difference(const Set& other) const {
        Set resultSet;

        for (int element : elements) {
            if (!other.isMember(element))
                resultSet.addElement(element);
        }

        return resultSet;
    }

    // Perform symmetric difference (A XOR B)
    Set symmetricDifference(const Set& other) const {
        Set resultSet = unionSet(other);
        Set intersection = intersectionSet(other);

        for (int element : intersection.elements) {
            resultSet.removeElement(element);
        }

        return resultSet;
    }

    // Calculate the cartesian product of two sets
    std::vector<std::pair<int, int>> cartesianProduct(const Set& other) const {
        std::vector<std::pair<int, int>> result;

        for (int element1 : elements) {
            for (int element2 : other.elements) {
                result.push_back(std::make_pair(element1, element2));
            }
        }

        return result;
    }
};

int main() {
    Set set1;
    Set set2;

    // Add elements to the sets
    set1.addElement(1);
    set1.addElement(2);
    set1.addElement(3);

    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);

    // Check if an element belongs to the set
    std::cout << "Is 2 a member of set1? " << std::boolalpha << set1.isMember(2) << std::endl; // Output: true
    std::cout << "Is 4 a member of set1? " << std::boolalpha << set1.isMember(4) << std::endl; // Output: false

    // List all elements of the power set
    std::vector<std::vector<int>> powerSet1 = set1.powerSet();
    std::cout << "Power Set of set1: " << std::endl;
    for (const auto& subset : powerSet1) {
        for (int element : subset) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // Check if set2 is a subset of set1
    std::cout << "Is set2 a subset of set1? " << std::boolalpha << set1.isSubset(set2) << std::endl; // Output: false

    // Perform union and intersection of two sets
    Set unionSet = set1.unionSet(set2);
    Set intersectionSet = set1.intersectionSet(set2);

    std::cout << "Union of set1 and set2: ";
    for (int element : unionSet.elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Intersection of set1 and set2: ";
    for (int element : intersectionSet.elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Calculate the complement of set1
    Set universalSet;
    universalSet.addElement(1);
    universalSet.addElement(2);
    universalSet.addElement(3);
    universalSet.addElement(4);

    Set complementSet = set1.complement(universalSet);
    std::cout << "Complement of set1: ";
    for (int element : complementSet.elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Perform set difference and symmetric difference
    Set differenceSet = set1.difference(set2);
    Set symmetricDiffSet = set1.symmetricDifference(set2);

    std::cout << "Set difference (set1 - set2): ";
    for (int element : differenceSet.elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "Symmetric difference (set1 XOR set2): ";
    for (int element : symmetricDiffSet.elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Calculate the cartesian product of set1 and set2
    std::vector<std::pair<int, int>> cartesianProd = set1.cartesianProduct(set2);
    std::cout << "Cartesian product of set1 and set2: " << std::endl;
    for (const auto& pair : cartesianProd) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
