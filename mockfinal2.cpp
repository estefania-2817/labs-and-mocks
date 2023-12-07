  
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;
    string homeTown;

    public:
    int getId() const { return id; }
    string getFirstName() { return firstName; }
    string getLastName()  { return lastName; }
    string getHomeTown() { return homeTown; }
    Student(int id, string fn, string ln, string ht): id(id), firstName(fn), lastName(ln), homeTown(ht) {}

    bool operator<(const Student &s2) const
    {
        return (this->getId() < s2.getId());
    }

};

// EXERCISE 4
// Returns a set of strings including all the unique towns where all the
// different students live.

// set<string> uniqueHomeTowns(const vector<Student> &students)
// {
//     set<string> result;

//     for(int i = 0; i < students.size(); i++) {
//         result.emplace(students[i].getHomeTown());
//     }

//     return result;  
// }

set<string> uniqueHomeTowns(const vector<Student> &students)
{
    set<string> result;

    for (Student s : students) {
        result.insert(s.getHomeTown());
    }

    return result;  
}


// EXERCISE 5
// Returns a NEW vector of students sorted in telephone directory order, meaning that
// they should be sorted by last name first and then by first name.  Names should be
// sorted lexicopgraphically using the default < operator of the string class.
// FOR FULL CREDIT YOU MUST USE THE sort FUNCTION IN THE ALGORHTM.H module of the STL
// AND PRIVIDE AN APPROPRIATE LAMBDA EXPRESSION TO THIS FUNCTION TO ACCOMPLISH THE 
// SORTING
vector<Student> sortByPhoneDirectory(const vector<Student> &students)
{
    // YOUR CODE HERE
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), 
        [] (Student &s1, Student &s2) {
            if (s1.getLastName() != s2.getLastName()) {
                return s1.getLastName() < s2.getLastName();
            } else {
                return s1.getFirstName() < s2.getFirstName();
            }
        } );
    
    return sortedStudents; // Dummy return. Please replace.
}



// EXERCISE 6
// Returns a NEW stack of students containing only the students who live in
// the given parameter home town.  The order of the students in the new stack
// should be preserved.  That is students in the new stack should remain below
// students who were higher up in the original stack.  See tests for examples.
stack<Student> homeTownStack(stack<Student> &students, string homeTown)
{
    stack<Student> temp;
    stack<Student> result;
    while(!students.empty()) {
        if(students.top().getHomeTown() == homeTown) {
            temp.push(students.top());
            students.pop();
        } else{
            students.pop();

        }
    }
    while(!temp.empty()) {
        result.push(temp.top());
        temp.pop();        
    }
    return result; // Dummy return. Please replace.
}


int main() {

    // EXERCISE #4 Tests
    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez", "Mayaguez"));
    testStudents.push_back( Student(25, "Juan", "Perez", "Humacao"));
    testStudents.push_back( Student(21, "Amanda", "Vazquez", "Guaynabo"));
    testStudents.push_back( Student(32, "Fernando", "Davis", "Guaynabo"));
    testStudents.push_back( Student(65, "Joshua", "Cruz", "Ponce"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz", "Guaynabo"));
    testStudents.push_back( Student(54, "Fatima", "Puig", "Cabo Rojo"));
    testStudents.push_back( Student(11, "Diego", "Maradona", "Ponce"));
    testStudents.push_back( Student(99, "Ana", "Cruz", "Hormigueros"));
    testStudents.push_back( Student(76, "Rey", "Cotto", "Hormigueros"));

    set<string> uniqueHTs = uniqueHomeTowns(testStudents);
    cout << "Count of Unique Home Towns: " << ((uniqueHTs.size() == 6) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Mayaguez") == 1) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Humacao") == 1) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Guaynabo") == 1) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Ponce") == 1) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Cabo Rojo") == 1) ? "Passed" : "Failed") << endl;
    cout << "Home Town Exists: " << ((count(uniqueHTs.begin(), uniqueHTs.end(), "Hormigueros") == 1) ? "Passed" : "Failed") << endl;


    // EXERCISE #5 Tests
    testStudents.clear();
    testStudents.push_back( Student(10, "Bienve", "Velez", "Mayaguez"));
    testStudents.push_back( Student(25, "Juan", "Perez", "Humacao"));
    testStudents.push_back( Student(21, "Amanda", "Vazquez", "Guaynabo"));
    testStudents.push_back( Student(32, "Fernando", "Davis", "Guaynabo"));
    testStudents.push_back( Student(65, "Joshua", "Cruz", "Ponce"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz", "Guaynabo"));
    testStudents.push_back( Student(54, "Fatima", "Puig", "Cabo Rojo"));
    testStudents.push_back( Student(11, "Diego", "Maradona", "Ponce"));
    testStudents.push_back( Student(99, "Ana", "Cruz", "Hormigueros"));
    testStudents.push_back( Student(76, "Rey", "Cotto", "Hormigueros"));

    vector<Student> sortedStudents = sortByPhoneDirectory(testStudents);
    cout << "Sorted Vector Size:" << ((sortedStudents.size() == 10) ? "Passed" : "Failed") << endl;
    cout << "Student 0 in Sorted Vector:" << ((sortedStudents[0].getId() == 76) ? "Passed" : "Failed") << endl;
    cout << "Student 1 in Sorted Vector:" << ((sortedStudents[1].getId() == 99) ? "Passed" : "Failed") << endl;
    cout << "Student 2 in Sorted Vector:" << ((sortedStudents[2].getId() == 65) ? "Passed" : "Failed") << endl;
    cout << "Student 3 in Sorted Vector:" << ((sortedStudents[3].getId() == 32) ? "Passed" : "Failed") << endl;
    cout << "Student 4 in Sorted Vector:" << ((sortedStudents[4].getId() == 11) ? "Passed" : "Failed") << endl;
    cout << "Student 5 in Sorted Vector:" << ((sortedStudents[5].getId() == 43) ? "Passed" : "Failed") << endl;
    cout << "Student 6 in Sorted Vector:" << ((sortedStudents[6].getId() == 25) ? "Passed" : "Failed") << endl;
    cout << "Student 7 in Sorted Vector:" << ((sortedStudents[7].getId() == 54) ? "Passed" : "Failed") << endl;
    cout << "Student 8 in Sorted Vector:" << ((sortedStudents[8].getId() == 21) ? "Passed" : "Failed") << endl;
    cout << "Student 9 in Sorted Vector:" << ((sortedStudents[9].getId() == 10) ? "Passed" : "Failed") << endl;

    // EXERCISE #6 Tests
    stack<Student> studentsStack;
    studentsStack.push( Student(10, "Bienve", "Velez", "Mayaguez"));
    studentsStack.push( Student(65, "Juan", "Perez", "Humacao"));
    studentsStack.push( Student(21, "Amanda", "Vazquez", "Guaynabo"));
    studentsStack.push( Student(32, "Fernando", "Davis", "Guaynabo"));
    studentsStack.push( Student(65, "Joshua", "Cruz", "Ponce"));
    studentsStack.push( Student(43, "Alejandra", "Munoz", "Guaynabo"));
    studentsStack.push( Student(54, "Fatima", "Puig", "Cabo Rojo"));
    studentsStack.push( Student(65, "Diego", "Maradona", "Ponce"));
    studentsStack.push( Student(65, "Ana", "Cruz", "Hormigueros"));
    studentsStack.push( Student(76, "Rey", "Cotto", "Hormigueros"));

    stack<Student> filteredStack = homeTownStack(studentsStack, "Guaynabo");
    cout << "Filtered Stack Size:" << ((filteredStack.size() == 3) ? "Passed" : "Failed") << endl;
    cout << "Student at top in Filtered Sstack:" << ((filteredStack.top().getId() == 43) ? "Passed" : "Failed") << endl;
    filteredStack.pop();
    cout << "Student at top in Filtered Sstack:" << ((filteredStack.top().getId() == 32) ? "Passed" : "Failed") << endl;
    filteredStack.pop();
    cout << "Student at top in Filtered Sstack:" << ((filteredStack.top().getId() == 21) ? "Passed" : "Failed") << endl;
    filteredStack.pop();
    cout << "Filtered Stack After Pops Size:" << ((filteredStack.size() == 0) ? "Passed" : "Failed") << endl;

}

