#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

class Collections {
    private:
    public:
        class Customer { 
            private:
                string id; int items; 
            public:
                Customer (string id, int items) { this->id = id; this->items = items;};
                string getId() { return this->id; };
                int getItems() { return this-> items;};
            };
        template <typename T> static set<T> intersection( set<T> A, set<T> B);
        template <typename T> static vector<T> removeDuplicates(vector<T> v);
        static int calculateProcessingTime(queue<Customer> customers);
        static string hotPotato(queue<string> participants, int t);
        template <typename T> static void removeElementFromStack(stack<T>& stack, T element);
        static string reverseStringUsingStack(string str);
        template <typename T> static map<T, int> countOccurrences(vector<T> vec);
        static map<string, int> averageWeatherInIsland(map<string, map<string, int>> stateMap);
        static void filter(vector<int> &v, function<bool(int)> f);
        static function<double(double)> generatePolynomial(vector<double> coefficients);

        static void print(set<string> s) {
            for (auto i : s) cout << i << " ";
        }

        static void print(vector<string> v) {
            for (auto i : v) cout << i << " ";
        }

        static void print(queue<string> q) {
            while (!q.empty()) {
                cout << q.front() << " ";
                q.pop();
            }
        }

        static void print(stack<string> s) {
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }

        static void print(map<string, int> m) {
            for (auto i : m) cout << i.first << " " << i.second << " ";
        }

        static void print(vector<int> v) {
            for (auto i : v) cout << i << " ";
            cout << endl;
        }
};

/*---------------------------------------------------------------------------------------*/

// EXERCISE #1
// Given two sets, A and B, return a set containing all elements of A that also belong to B.
template <typename T>
set<T> Collections::intersection( set<T> A, set<T> B){
    set<T> intersection;

    // YOUR CODE HERE
    for (auto itA = A.begin(); itA != A.end(); ++itA) {
        for (auto itB = B.begin(); itB != B.end(); ++itB) {
            if (*itA == *itB) {
                intersection.insert(*itA);
            }
        }
    }

    return intersection; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #2
// Given a vector of type T, return a NEW vector that has all duplicate elements removed.
// WARNING: YOU MUST USE A SET TO REMOVE THE DUPLICATES

template <typename T>
vector<T> Collections::removeDuplicates(vector<T> v) {

    // YOUR CODE HERE
    set<T> noDuplicate;
    for (const T& element : v) {
        noDuplicate.insert(element);
    }

    vector<T> result(noDuplicate.begin(), noDuplicate.end());
    return  result;

}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #3
// Given a queue of type Customer, calculate the amount of time it 
// takes to process each customer. A Customer is processed when their 
// items are processed. Each item takes 1 second to process. You must
// return the amount of time (in seconds) that it takes to process all 
// customers.
// WARNING: You may not use any additional containers.  The parameter
// queue must end up with all its original customers in the same order.
//
// HINT: Try removing Customers from the top and reinserting them at the end
//
int Collections::calculateProcessingTime(queue<Collections::Customer> customers) {

    // YOUR CODE HERE
    int sum = 0;
    for(int i = 0; i < customers.size(); i++) {
        Customer temp = customers.front();
        sum += temp.getItems();
        customers.pop();
        customers.push(temp);
    }
    return sum; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #4
// Given a queue of strings representing the names of the participants
// and a time "t", simulate a game of hot potato using a circular queue.
//
// In a game of hot potato, a potato is passed around in a circle.
// This means the last person to hold the potato will pass it to 
// whoever is next in the queue. The potato will be passed around 
// t times and the last person holding the potato is eliminated. 
// This process is then repeated with the remaining players until only
// one player (the winner) remains.
//
// HINT: Use a (circular) queue keeping the person holding the potato at the front
//
// Function hotPotato returns the name  of the winner
//
string Collections::hotPotato(queue<string> participants, int t) {
    // YOUR CODE HERE
    string winner;
    while(participants.size() != 1) {
        for(int i = 0; i < t; i++) {
            string temp = participants.front();
            participants.pop();
            participants.push(temp);
        }
        participants.pop();
    }
    winner = participants.front();
    //cout << "winner: " << winner << endl;

    return winner; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #5: removeElementFromStack
// Given a stack of element type T, and an element of type T, 
// remove the first instance of the element */

// WARNING: You may only use stack containers for any credit
//
// Hint: Use auxiliary stack to temporarily store  elements on top
// of the  element to be removed.
//
template <typename T>
void Collections::removeElementFromStack(stack<T>& sourceStack, T element) {

    // YOUR CODE HERE
    stack<T> temp;
    int count = 0;
    while(!sourceStack.empty()) {
        if(sourceStack.top() == element && count == 0) {
            sourceStack.pop();
            count = 1;
        } else {
            temp.push(sourceStack.top());
            sourceStack.pop();
        }
    }
    while(!temp.empty()) {
        sourceStack.push(temp.top());
        temp.pop();
    }

}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #6: reverseStringUsingStack
// Given a string, reverse the string using a stack. 
// The  function must return the reversed string.

string Collections::reverseStringUsingStack(string str) {

    // YOUR CODE HERE
    stack<char> temp;
    string result = "";

    for(int i = 0; i < str.size(); i++) {
        temp.push(str[i]);
    }
    while(!temp.empty()) {
        result += temp.top();
        temp.pop();
    }
    return result; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #7: countOccurrences (using Map)
// Given a vector of type T, return a map that contains the number of 
// occurrences of each element.
//
template <typename T>
map<T, int> Collections::countOccurrences(vector<T> vec) {
    map<T, int> res;

    for (int i = 0; i < vec.size(); i++) {
        // If the element is already in the map, increment its count
        // Otherwise, add it to the map with a count of 1
        auto it = res.find(vec[i]);
        if (it != res.end()) {
            // Element found in the map, increment the count
            it->second++;
        } else {
            // Element not found, add it to the map with a count of 1
            res[vec[i]] = 1;
        }
    }

    return res; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #8: averageWeatherInState (using Map)
// In the United States, each state is subdivided into counties. Each 
// county has a name, and average temperature. Given a map of 
// type <string, map<string, int>>, return a map that contains the average
// temperature of each state. The outer map contains each state as keys, 
// and the value of each key in the map is a map containing the counties
// of that state as keys and the average temperature in each county as values.
//
// Example of the state map: {"California": {{"Los Angeles", 70}, {"San Francisco", 60}, {"San Diego", 80}}

map<string, int> Collections::averageWeatherInIsland(map<string, map<string, int>> island) {

    // YOUR CODE HERE
    map<string, int> average;

    for(auto i : island) {
        int temp = 0;
        int counties = 0;
        for(auto j : i.second) {
            temp += j.second;
            counties++;
        }
        average.insert(pair<string, int>(i.first, temp/counties));
    }

    return average; // Dummy return
}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #9: filter
// Given a vector v of integers and a function f that returns a boolean value,
// removes f from v all elements x such that f(x) is false.
//
void Collections::filter(vector<int> &v, function<bool(int)> f) {

    // YOUR CODE HERE
    v.erase(remove_if(v.begin(), v.end(), 
        [f](int x) { return !f(x);}), 
        v.end());

}

/*---------------------------------------------------------------------------------------*/

// EXERCISE #10: generatePolynomial
// Given a vector of n coefficients, return a function that denotes a 
// polynomial of degree n-1. For example, given the coefficients 
// {2.0, -4.3, 0, 7} the polynomial returned should be (2.0x^3 - 4.3x^2 + 7). 
// Evaluating this polynomial at x = 5 should give 149.5.

function<double(double)> Collections::generatePolynomial(vector<double> coefficients) {

    return [coefficients](double x) {
        double result = 0.0;
        int degree = coefficients.size() - 1;

        for (int i = degree; i >= 0; --i) {
            result += coefficients[i]*pow(x, degree - i);
        }

        return result;
    };

}

/*---------------------------------------------------------------------------------------*/


// TESTS
void testEx1() {
    // EXERCISE #1
    cout << "Exercise 1" << endl;
    
    // Test 1
    set<string> strawhats;
    strawhats.insert("Luffy");
    strawhats.insert("Zoro");
    strawhats.insert("Sanji");
    strawhats.insert("Usopp");
    strawhats.insert("Nami");
    strawhats.insert("Chopper");
    strawhats.insert("Robin");
    strawhats.insert("Franky");
    strawhats.insert("Brook");
    strawhats.insert("Jimbei");

    set<string> strawhatsStrongest;
    strawhatsStrongest.insert("Luffy");
    strawhatsStrongest.insert("Zoro");
    strawhatsStrongest.insert("Sanji");

    bool fail = false;
    cout << "Test 1 ";
    set<string> result = Collections::intersection(strawhats, strawhatsStrongest);
    if(result == strawhatsStrongest) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result);
        cout << " instead of ";
        Collections::print(strawhatsStrongest);
    }


    // Test 2
    set<string> strawhats2;
    strawhats2.insert("Luffy");
    strawhats2.insert("Zoro");
    strawhats2.insert("Sanji");
    strawhats2.insert("Usopp");
    strawhats2.insert("Nami");
    strawhats2.insert("Chopper");
    strawhats2.insert("Robin");
    strawhats2.insert("Franky");
    strawhats2.insert("Brook");
    strawhats2.insert("Jimbei");

    set<string> strawhatsStrongest2;
    strawhatsStrongest2.insert("Usopp");
    strawhatsStrongest2.insert("Brook");
    strawhatsStrongest2.insert("Nami");

    cout << "Test 2 ";
    set<string> result2 = Collections::intersection(strawhats2, strawhatsStrongest2);
    if(result2 == strawhatsStrongest2) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result2);
        cout << " instead of ";
        Collections::print(strawhatsStrongest2);
    }

    // Test 3
    set<string> strawhats3;
    strawhats3.insert("Luffy");
    strawhats3.insert("Zoro");
    strawhats3.insert("Sanji");
    strawhats3.insert("Usopp");
    strawhats3.insert("Nami");
    strawhats3.insert("Chopper");
    strawhats3.insert("Robin");
    strawhats3.insert("Franky");
    strawhats3.insert("Brook");
    strawhats3.insert("Jimbei");
    
    set<string> strawhatsStrongest3;
    strawhatsStrongest3.insert("Luffy");

    cout << "Test 3 ";
    set<string> result3 = Collections::intersection(strawhats3, strawhatsStrongest3);
    if(result3 == strawhatsStrongest3) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result3);
        cout << " instead of ";
        Collections::print(strawhatsStrongest3);
    }

}

void testEx2() {

    // EXERCISE #2
    cout << "Exercise 2" << endl;
    
    vector<string> strawhats;
    strawhats.push_back("Usopp");
    strawhats.push_back("Usopp");
    strawhats.push_back("Nami");
    strawhats.push_back("Chopper");
    strawhats.push_back("Chopper");
    strawhats.push_back("Chopper");

    cout << "Test 1 ";
    vector<string> result = Collections::removeDuplicates(strawhats);
    set<string> expected = {"Usopp", "Nami", "Chopper"};
    set<string> resultSet(result.begin(), result.end());
    if(resultSet == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result);
        cout << " instead of ";
        Collections::print(expected);
    }

    // Test 2
    vector<string> strawhats2;
    strawhats2.push_back("Usopp");
    strawhats2.push_back("Nami");
    strawhats2.push_back("Nami");
    strawhats2.push_back("Luffy");
    strawhats2.push_back("Luffy");

    cout << "Test 2 ";
    vector<string> result2 = Collections::removeDuplicates(strawhats2);
    set<string> expected2 = {"Usopp", "Nami", "Luffy"};
    set<string> resultSet2(result2.begin(), result2.end());
    if(resultSet2 == expected2) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result2);
        cout << " instead of ";
        Collections::print(expected2);
    }

    // Test 3
    vector<string> strawhats3;
    strawhats3.push_back("Usopp");
    strawhats3.push_back("Nami");
    strawhats3.push_back("Chopper");
    strawhats3.push_back("Robin");
    strawhats3.push_back("Franky");

    cout << "Test 3 ";
    vector<string> result3 = Collections::removeDuplicates(strawhats3);
    set<string> expected3 = {"Usopp", "Nami", "Chopper", "Robin", "Franky"};
    set<string> resultSet3(result3.begin(), result3.end());
    if(resultSet3 == expected3) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(result3);
        cout << " instead of ";
        Collections::print(expected3);
    }
 
}

void testEx3() {
    // EXERCISE #3
    cout << "Exercise 3" << endl;

    queue<Collections::Customer> strawhats;
    strawhats.push(Collections::Customer("Luffy", 1));
    strawhats.push(Collections::Customer("Zoro", 2));
    strawhats.push(Collections::Customer("Sanji", 3));
    strawhats.push(Collections::Customer("Usopp", 4));
    strawhats.push(Collections::Customer("Nami", 5));
    strawhats.push(Collections::Customer("Chopper", 6));

    cout << "Test 1 ";
    int res = Collections::calculateProcessingTime(strawhats);
    res == 21 ? cout << "PASS" << endl : cout << "FAIL with " << res << " instead of 21" << endl;
    queue<Collections::Customer> strawhats2;
    strawhats2.push(Collections::Customer("Luffy", 1));
    strawhats2.push(Collections::Customer("Zoro", 2));
    strawhats2.push(Collections::Customer("Sanji", 3));

    cout << "Test 2 ";
    int res2 = Collections::calculateProcessingTime(strawhats2);
    res2 == 6 ? cout << "PASS" << endl : cout << "FAIL with " << res2 << " instead of 6" << endl;

    queue<Collections::Customer> strawhats3;
    strawhats3.push(Collections::Customer("Luffy", 1));
    strawhats3.push(Collections::Customer("Zoro", 2));
    strawhats3.push(Collections::Customer("Sanji", 3));
    strawhats3.push(Collections::Customer("Usopp", 4));

    cout << "Test 3 ";
    int res3 = Collections::calculateProcessingTime(strawhats3);
    res3 == 10 ? cout << "PASS" << endl : cout << "FAIL with " << res3 << " instead of 10" << endl;

}

void testEx4() {

    // EXERCISE #4
    cout << "Exercise 4" << endl;
    
    // Test 1
    queue<string> strawhats;
    strawhats.push("Luffy");
    strawhats.push("Zoro");
    strawhats.push("Sanji");
    strawhats.push("Usopp");
    strawhats.push("Nami");
    strawhats.push("Chopper");
    strawhats.push("Robin");
    strawhats.push("Franky");
    strawhats.push("Brook");
    strawhats.push("Jimbei");

    cout << "Test 1 ";
    string res = Collections::hotPotato(strawhats, 20);
    res.compare("Jimbei") == 0 ? cout << "PASS" << endl : cout << "FAIL with " << res << " instead of Jimbei" << endl;

    // Test 2
    queue<string> strawhats2;
    strawhats2.push("Luffy");
    strawhats2.push("Zoro");
    strawhats2.push("Sanji");
    strawhats2.push("Usopp");
    strawhats2.push("Nami");
    strawhats2.push("Chopper");
    strawhats2.push("Robin"); 
    strawhats2.push("Franky"); 
    strawhats2.push("Brook");
    strawhats2.push("Jimbei");

    cout << "Test 2 ";
    string res2 = Collections::hotPotato(strawhats2, 7);
    res2.compare("Luffy") == 0 ? cout << "PASS" << endl : cout << "FAIL with " << res2 << " instead of Luffy" << endl;

    // Test 3
    queue<string> strawhats3;
    strawhats3.push("Luffy");
    strawhats3.push("Zoro");
    strawhats3.push("Sanji");
    strawhats3.push("Usopp");
    strawhats3.push("Nami");
    strawhats3.push("Chopper");
    strawhats3.push("Robin");
    strawhats3.push("Franky");
    strawhats3.push("Brook");
    strawhats3.push("Jimbei");

    cout << "Test 3 ";
    string res3 = Collections::hotPotato(strawhats3, 70);
    res3.compare("Usopp") == 0 ? cout << "PASS" << endl : cout << "FAIL with " << res3 << " instead of Usopp" << endl;

}

void testEx5() {

    // EXERCISE #5
    cout << "Exercise 5" << endl;

    // Test 1
    stack<string> strawhats;
    strawhats.push("Luffy");
    strawhats.push("Zoro");
    strawhats.push("Sanji");
    strawhats.push("Usopp");
    strawhats.push("Nami");
    strawhats.push("Chopper");
    strawhats.push("Robin");
    strawhats.push("Franky");
    strawhats.push("Brook");
    strawhats.push("Jimbei");

    stack<string> expected;
    expected.push("Luffy");
    expected.push("Zoro");
    expected.push("Sanji");
    expected.push("Usopp");
    expected.push("Nami");
    expected.push("Chopper");
    expected.push("Franky");
    expected.push("Brook");
    expected.push("Jimbei");

    cout << "Test 1 ";
    Collections::removeElementFromStack(strawhats, (string) "Robin");
    if(strawhats == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(strawhats);
        cout << " instead of ";
        Collections::print(expected);
    }

    // Test 2
    stack<string> strawhats2;
    strawhats2.push("Luffy");
    strawhats2.push("Zoro");
    strawhats2.push("Sanji");
    strawhats2.push("Usopp");
    strawhats2.push("Nami");
    strawhats2.push("Chopper");
    strawhats2.push("Robin");
    strawhats2.push("Franky");
    strawhats2.push("Brook");
    strawhats2.push("Jimbei");

    stack<string> expected2;
    expected2.push("Luffy");
    expected2.push("Zoro");
    expected2.push("Sanji");
    expected2.push("Usopp");
    expected2.push("Nami");
    expected2.push("Chopper");
    expected2.push("Robin");
    expected2.push("Franky");
    expected2.push("Brook");
    
    cout << "Test 2 ";
    Collections::removeElementFromStack(strawhats2, (string) "Jimbei");
    if(strawhats2 == expected2) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(strawhats2);
        cout << " instead of ";
        Collections::print(expected2);
    }

    // Test 3
    stack<string> strawhats3;
    strawhats3.push("Luffy");
    strawhats3.push("Zoro");
    strawhats3.push("Sanji");
    strawhats3.push("Usopp");
    strawhats3.push("Nami");
    strawhats3.push("Chopper");
    strawhats3.push("Robin");
    strawhats3.push("Franky");
    strawhats3.push("Brook");
    strawhats3.push("Jimbei");

    stack<string> expected3;
    expected3.push("Luffy");
    expected3.push("Zoro");
    expected3.push("Sanji");
    expected3.push("Usopp");
    expected3.push("Nami");
    expected3.push("Robin");
    expected3.push("Franky");
    expected3.push("Brook");
    expected3.push("Jimbei");

    cout << "Test 3 ";
    Collections::removeElementFromStack(strawhats3, (string) "Chopper");
    if(strawhats3 == expected3) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(strawhats3);
        cout << " instead of ";
        Collections::print(expected3);
    }
    
}

void testEx6() {

    // EXERCISE #6
    cout << "Exercise 6" << endl;

    // Test 1
    cout << "Test 1 ";
    string res = Collections::reverseStringUsingStack("Luffy");
    res == "yffuL" ? cout << "PASS" << endl : cout << "FAIL with " << res << " instead of yffuL" << endl;

    // Test 2
    cout << "Test 2 ";
    string res2 = Collections::reverseStringUsingStack("Zoro");
    res2 == "oroZ" ? cout << "PASS" << endl : cout << "FAIL with " << res2 << " instead of oroZ" << endl;

    // Test 3
    cout << "Test 3 ";
    string res3 = Collections::reverseStringUsingStack("Sanji");
    res3 == "ijnaS" ? cout << "PASS" << endl : cout << "FAIL with " << res3 << " instead of ijnaS" << endl;

}

void testEx7() {

    // EXERCISE #4
    cout << "Exercise 7" << endl;

    // Test 1
    vector<string> strawhats;
    strawhats.push_back("Usopp");
    strawhats.push_back("Usopp");
    strawhats.push_back("Nami");
    strawhats.push_back("Chopper");
    strawhats.push_back("Chopper");
    strawhats.push_back("Chopper");

    cout << "Test 1 ";
    map<string, int> res = Collections::countOccurrences(strawhats);
    map<string, int> expected = {{"Usopp", 2}, {"Nami", 1}, {"Chopper", 3}};
    if(res == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res);
        cout << " instead of ";
        Collections::print(expected);
    }

    // Test 2
    vector<string> strawhats2;
    strawhats2.push_back("Usopp");
    strawhats2.push_back("Nami");
    strawhats2.push_back("Nami");
    strawhats2.push_back("Luffy");
    strawhats2.push_back("Luffy");

    cout << "Test 2 ";
    map<string, int> res2 = Collections::countOccurrences(strawhats2);
    map<string, int> expected2 = {{"Usopp", 1}, {"Nami", 2}, {"Luffy", 2}};
    if(res2 == expected2) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res2);
        cout << " instead of ";
        Collections::print(expected2);
    }

    // Test 3
    vector<string> strawhats3;
    strawhats3.push_back("Usopp");
    strawhats3.push_back("Nami");
    strawhats3.push_back("Chopper");
    strawhats3.push_back("Robin");
    strawhats3.push_back("Franky");

    cout << "Test 3 ";
    map<string, int> res3 = Collections::countOccurrences(strawhats3);
    map<string, int> expected3 = {{"Usopp", 1}, {"Nami", 1}, {"Chopper", 1}, {"Robin", 1}, {"Franky", 1}};
    if(res3 == expected3) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res3);
        cout << " instead of ";
        Collections::print(expected3);
    }

}

void testEx8() {

    // EXERCISE #8
    cout << "Exercise 8" << endl;

    // Test 1
    map<string, map<string, int>> islands = 
    {
        {"Wano County", 
            {{"Flower Capital", 80}, 
            {"Kuri", 75}, 
            {"Udon", 85}, 
            {"Ringo", 38}, 
            {"Hakumai", 77}, 
            {"Onigashima", 90}}
        }, 
        {"Sandy Island", 
            {{"Sandora Desert", 110}, 
            {"Rainbase", 95}, 
            {"Erumalu", 100}, 
            {"Nanohana", 97}}
        }, 
        {"Drum Island",
            {{"Bighorn", 30},
            {"Cocoa Weed", 35},
            {"Robelle", 32}}
        }
    };

    cout << "Test 1 ";
    map<string, int> res = Collections::averageWeatherInIsland(islands);
    map<string, int> expected = {{"Wano County", 74}, {"Sandy Island", 100}, {"Drum Island", 32}};
    if(res == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res);
        cout << " instead of ";
        Collections::print(expected);
        cout << endl;
    }

    // Test 2
    map<string, map<string, int>> islands2 = 
    {
        {"Wano County", 
            {{"Flower Capital", 85}, 
            {"Kuri", 80}, 
            {"Udon", 90}, 
            {"Ringo", 40}, 
            {"Hakumai", 82}, 
            {"Onigashima", 95}}
        }, 
        {"Sandy Island", 
            {{"Sandora Desert", 115}, 
            {"Rainbase", 100}, 
            {"Erumalu", 105}, 
            {"Nanohana", 102}}
        }, 
        {"Drum Island",
            {{"Bighorn", 35},
            {"Cocoa Weed", 40},
            {"Robelle", 37}}
        }
    };

    cout << "Test 2 ";
    map<string, int> res2 = Collections::averageWeatherInIsland(islands2);
    map<string, int> expected2 = {{"Wano County", 78}, {"Sandy Island", 105}, {"Drum Island", 37}};
    if(res2 == expected2) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res2);
        cout << " instead of ";
        Collections::print(expected2);
        cout << endl;
    }

    // Test 3
    map<string, map<string, int>> islands_iteration_3 = 
    {
        {"Wano County", 
            {{"Flower Capital", 75}, 
            {"Kuri", 70}, 
            {"Udon", 80}, 
            {"Ringo", 35}, 
            {"Hakumai", 72}, 
            {"Onigashima", 85}}
        }, 
        {"Sandy Island", 
            {{"Sandora Desert", 105}, 
            {"Rainbase", 90}, 
            {"Erumalu", 95}, 
            {"Nanohana", 92}}
        }, 
        {"Drum Island",
            {{"Bighorn", 25},
            {"Cocoa Weed", 30},
            {"Robelle", 27}}
        }
    };

    cout << "Test 3 ";
    map<string, int> res3 = Collections::averageWeatherInIsland(islands_iteration_3);
    map<string, int> expected3 = {{"Wano County", 69}, {"Sandy Island", 95}, {"Drum Island", 27}};
    if(res3 == expected3) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL with ";
        Collections::print(res3);
        cout << " instead of ";
        Collections::print(expected3);
        cout << endl;
    }

}

void testEx9() {
    cout << "Exercise 9" << endl;

    // Test 1
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    cout << "Test 1 ";
    Collections::filter(v, [](int x) { return x % 2 == 0; });
    string res;
    for (int i : v) res.append(to_string(i) + " ");
    res.compare("2 ") == 0 ? cout << "PASS" << endl : cout << "FAIL with '" << res << "'instead of '2 '" << endl;

    // Test 2
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    cout << "Test 2 ";
    Collections::filter(v2, [](int x) { return x % 2 == 0; });
    string res2;
    for (int i : v2) res2.append(to_string(i) + " ");
    res2.compare("2 4 6 ") == 0 ? cout << "PASS" << endl : cout << "FAIL with '" << res2 << "'instead of '2 4 6 '" << endl;

    // Test 3
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(3);
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);

    cout << "Test 3 ";
    Collections::filter(v3, [](int x) { return x % 2 != 0; });
    string res3;
    for (int i : v3) res3.append(to_string(i) + " ");
    res3.compare("1 3 5 ") == 0 ? cout << "PASS" << endl : cout << "FAIL with '" << res3 << "'instead of '1 3 5 '" << endl;

}

void testEx10() {
    cout << "Exercise 10" << endl;

    // Test 1
    vector<double> coefficients;
    coefficients.push_back(2.0);
    coefficients.push_back(-4.3);
    coefficients.push_back(0);
    coefficients.push_back(7);

    cout << "Test 1 ";
    function<double(double)> polynomial = Collections::generatePolynomial(coefficients);
    double res = polynomial(5);
    res == 149.5 ? cout << "PASS" << endl : cout << "FAIL with '" << res << "'instead of '149.5'" << endl;

    // Test 2
    vector<double> coefficients2;
    coefficients2.push_back(2.0);
    coefficients2.push_back(3.6);
    coefficients2.push_back(2.1);
    coefficients2.push_back(7.6);

    cout << "Test 2 ";
    function<double(double)> polynomial2 = Collections::generatePolynomial(coefficients2);
    double res2 = polynomial2(5);
    res2 == 358.1 ? cout << "PASS" << endl : cout << "FAIL with '" << res2 << "'instead of '358.1'" << endl;

    // Test 3
    vector<double> coefficients3;
    coefficients3.push_back(2.0);
    coefficients3.push_back(3.6);
    coefficients3.push_back(2.1);
    coefficients3.push_back(7.6);

    cout << "Test 3 ";
    function<double(double)> polynomial3 = Collections::generatePolynomial(coefficients3);
    double res3 = polynomial3(0);
    res3 == 7.6 ? cout << "PASS" << endl : cout << "FAIL with '" << res3 << "'instead of '7.6'" << endl;
    
}

int main()
{
    testEx1();
    testEx2();
    testEx3();
    testEx4();
    testEx5();
    testEx6();
    testEx7();
    testEx8();
    testEx9();
    testEx10();
}