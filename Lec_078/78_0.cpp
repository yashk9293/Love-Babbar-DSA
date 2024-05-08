// map - O(log n)
// unordered_map - O(1)

#include <bits/stdc++.h>
using namespace std;    

int main() {
    // Creation
    map<string, int> M;

    // Insertion
    // method 1
    pair<string, int> pair1 = make_pair("white", 2);
    M.insert(pair1);

    // method 2
    pair<string, int> pair2("black", 3);
    M.insert(pair2);

    // method 3
    M["red"] = 4;

    // Printing
    cout << "Before updation : white = " << M["white"] << endl;

    // Updation
    M["white"] = 10;    
    cout << "After updation : white = " << M.at("white") << endl;

    // cout << M.at("orange") << endl;           terminate called after throwing an instance of 'std::out_of_range'
    cout << M["orange"] << endl;
    cout << M.at("orange") << endl;

    // Size
    cout << "Size : " << M.size() << endl;

    // Check presence
    cout << M.count("yellow") << endl;
    cout << M.count("white") << endl;

    // Removal
    M.erase("white");
    cout << "Size : " << M.size() << endl;

    // Traversal
    for(auto i : M) {
        cout << i.first << " & " << i.second << endl;
    }

    // Iterator
    /*
    unordered_map<string, int> :: iterator it = M.begin();
    while(it != M.end()) {
        cout << it.first << " , " << it.second << endl;
        it++;
    }
    */
    
    return 0;
}


// Output :-

// Before updation : white = 2
// After updation : white = 10
// 0
// 0
// Size : 4
// 0
// 1
// Size : 3
// black & 3
// orange & 0
// red & 4