#include <array>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

using namespace std;

enum Gender {
    MALE,
    FEMALE
};

class Student {

private:
    long id;            // Unique ID
    string name;        // Name of student
    Gender gender;      // Gender of student
    string courseCode;  // Course code (CIIC or ICOM)
    double gpa;         // GPA of student

public:
    Student(long id, const string &name, Gender gender, double gpa){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->courseCode = "";
        this->gpa = gpa;
    }

    Student(long id, const string &name, Gender gender, string courseCode, double gpa){
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->courseCode = courseCode;
        this->gpa = gpa;
    }

    Student(){}

    static string toString(Student& s){
        string genderLetter = (s.gender  == MALE ? "M" : "F");
        return string("{" + to_string(s.id) + "," + s.name + "," + genderLetter + "," + to_string(s.gpa) + "}");
    }

    template <typename Iterator>
    static string toString(Iterator begin, Iterator end){
        string result = "{";
        for (auto it=begin; it!=end; it++) {
            result += toString(*it) + ",";
        }
        result += "}";
        return result;
    }

    static string toString(vector<long>& v){
        string result = "{";
        for (long id : v) {
            result += to_string(id) + ",";
        }
        result += "}";
        return result;
    }

    // Getters
    long getID() const {return id;}
    string getName() const {return name;}
    Gender getGender() const {return gender;}
    double getGPA() const {return gpa;}
    string getCourseCode() const {return courseCode;}

    //Setters
    void setName(string name){this->name = name;}
    void setGender(Gender gender){this->gender = gender;}
    void setGPA(double gpa){this->gpa = gpa;}
    void setCourseCode(string code){this->courseCode = code;}

    // EXERCISES

    template <typename Iterator> static double maxStudentGPA(Iterator begin, Iterator end);
    template <typename Iterator> static double minStudentGPA(Iterator begin, Iterator end);
    template <typename Iterator> static double averageGPA(Iterator begin, Iterator end, int N);
    template <typename Iterator> static vector<long> countStudents(Iterator begin, Iterator end, string code);
    template <typename Iterator> static vector<Student> removeByID(Iterator begin, Iterator end, long ID);
    template <typename Iterator> static vector<Student> updateStudent(Iterator begin, Iterator end, const Student &s);
    template <typename Iterator> static vector<Student> findStudents(Iterator begin, Iterator end, float gpa);
    template <typename Iterator1, typename Iterator2> static vector<Student> honorIdentifier(Iterator1 v1_begin, Iterator1 v1_end, Iterator2 v2_begin, Iterator2 v2_end);
   
};

/*
* EXERCISE: #1A
*
* Returns the highest GPA value possessed by any Student in the given list 
* starting at the begin iterator up to and not including the end iterator.
*  
*/
template <typename Iterator>
double Student::maxStudentGPA(Iterator begin, Iterator end)
{
    double maxGPA = 0;
    for(auto i = begin; i != end; i++) {
        if(i->getGPA() > maxGPA) {
            maxGPA = i->getGPA();
        }
    }
    return  maxGPA;
}


/*
* EXERCISE: #1B
*
* Returns the lowest GPA value possessed by any Student in the given list.
* starting at the begin iterator up to and not including the end iterator.
*
*/
template <typename Iterator>
double Student::minStudentGPA(Iterator begin, Iterator end)
{
    double minGPA = 4.0;
    for(auto i = begin; i != end; i++) {
        if(i->getGPA() < minGPA) {
            minGPA = i->getGPA();
        }
    }
    return  minGPA;
}

/* 
* Exercise #1C
*
* For the first N students, calculate the average GPA
* starting at the begin iterator up to and not including the end iterator.
* 
* Formula: average = sum / N
*    Assume N is greater than 0
*/
template <typename Iterator>
double Student::averageGPA(Iterator begin, Iterator end, int N){
    
    double sum = 0;
    double average;

    for(auto i = begin; i != begin+N ; i++) {
        sum = sum + i->getGPA();
    } 
    average = sum/N;
    return average; // Dummy return

}

/**
 * 
* EXERCISE #2
*
* Given a course code, you must return a vector that contains 
* only the unique ID of the Students that have that particular course code
* starting at the begin iterator up to and not including the end iterator.
*
*/
template <typename Iterator>
vector<long> Student::countStudents(Iterator begin, Iterator end, string code){

    vector<long> result;

    for(auto i = begin; i != end; i++) {
        if(i->getCourseCode() == code) {
            result.push_back(i->getID());
        }
    }

    return result;
}

/*
* EXERCISE #3
* 
* Return a vector that contains all the Students that have a GPA greater
* or equal to the GPA passed as the parameter
* starting at the begin iterator up to and not including the end iterator.
* 
* Assume the list contains at least one such element
*/
template <typename Iterator>
vector<Student> Student::findStudents(Iterator begin, Iterator end, float gpa){

    vector<Student> result;

    for(auto i = begin; i != end; i++) {
        if(i->getGPA() >= gpa) {
            result.push_back(*i);
        }
    }

    return result;
}

/*
* EXERCISE: #4
*
* Return a new vector that has the same elements as the original container	
* starting at the begin iterator up to and not including the end iterator.
* but with the Student of the given ID removed.
*
*/
template <typename Iterator>
vector<Student> Student::removeByID(Iterator begin, Iterator end, long ID){

    vector<Student> result;

    for(auto i = begin; i != end; i++) {
        if(i->getID() != ID) {
            result.push_back(*i);
        }
    }

    return result;
}

/*
* EXERCISE #5
*
* Return a new vector that has the same elements as the original container 
* starting at the begin iterator up to and not including the end iterator,
* but with the given Student's data updated. If the Student is not present, 
* add it to the resulting vector.
* 
* Remember that each Student has an unique identifier
*/

// template <typename Iterator>
// vector<Student> Student::updateStudent(Iterator begin, Iterator end, const Student &s){

//     vector<Student> result;
//     bool nf = false;
//     for(auto i = begin; i != end; i++) {
//         if(i->getID() == s.getID()) {
//             result.push_back(s);
//             nf = true;
//         }
//         if(i->getID() != s.getID()) {
//             result.push_back(*i);
//         }
//     }
//     if(nf == false) {
//         result.push_back(s);
//     }
//     return result;
// }

template <typename Iterator>
vector<Student> Student::updateStudent(Iterator begin, Iterator end, const Student &s){

    vector<Student> result;
    bool nf = false;
    for(auto i = begin; i != end; i++) {
        if(i->getID() == s.getID()) {
            result.push_back(s);
            nf = true;
        } else {
            result.push_back(*i);
        }
    }
    if(nf == false) {
        result.push_back(s);
    }
    return result;
}

/*
* BONUS EXERCISE
*
* Find all Students in both containers that qualify to be a part of the honor roll
* starting at the begin iterator up to and not including the end iterator of both containers. 
* Students may only qualify to be part of the honor roll if they have a GPA of 3.5 or higher.
*
* REQUIREMENT: You may only make use of a single loop, but you may assume that both containers have equal length.
* 
*/
template <typename Iterator1, typename Iterator2>
vector<Student> Student::honorIdentifier(Iterator1 v1_begin, Iterator1 v1_end, Iterator2 v2_begin, Iterator2 v2_end){

    vector<Student> result;
    auto i1 = v1_begin;
    auto i2 = v2_begin;
    while(i1 != v1_end && i2 != v2_end) {
        if(i1->getGPA() >= 3.5) {
            result.push_back(*i1);
        }
         if(i2->getGPA() >= 3.5) {
            result.push_back(*i2);
        }
        i1++;
        i2++;
    }

    return result;
}



int main() {

    Student s1(0, "Bienve", MALE, 3.0);
    Student s2(1, "Jose Juan", MALE, 2.8);
    Student s3(2, "Ana", FEMALE, 3.5);

    Student s4(3, "Ariel", FEMALE,"CIIC", 4.0);
    Student s5(4, "Mulan", FEMALE, "ICOM", 3.56);
    Student s6(5, "Aladdin", MALE, "CIIC", 3.1);

    vector<Student> testVector1{s1, s2, s3};
    list<Student> testList1{s1, s2, s3};
    array<Student,3> testArray1{s4, s5, s6};

    // auto t1Begin = testVector1.begin();
    // auto t1End = testVector1.end();

    // auto t2Begin = testArray1.begin();
    // auto t2End = testArray1.end();

    cout << "---------TESTS---------" << endl;

    // cout << "\n----Exercise #1A----" << endl;
    // cout << "Maximum GPA of testVector1: " << Student::maxStudentGPA(testVector1.begin(), testVector1.end()) << endl;
    // cout << "Maximum GPA of testList1: " << Student::maxStudentGPA(testList1.begin(), testList1.end()) << endl;

    // cout << "\n----Exercise #1B----" << endl;
    // cout << "Minimum GPA: " << Student::minStudentGPA(testVector1.begin(), testVector1.end()) << endl;

    // cout << "\n----Exercise #1C----" << endl;
    // cout << "Average GPA of N Students: " << Student::averageGPA(testVector1.begin(), testVector1.end(), 2) << endl;

    // cout << "\n----Exercise #2----" << endl;
    // vector<long> result =  Student::countStudents(testArray1.begin(), testArray1.end(), "ICOM");
    // cout << "ID of Students with code: " << Student::toString(result) << endl;

    // cout << "\n----Exercise #3----" << endl;
    // vector<Student> temp = Student::findStudents(testList1.begin(), testList1.end(), 3.50);
    // cout << "Students with a GPA of 3.5 or above: " << Student::toString(temp.begin(), temp.end()) << endl;

    // cout << "\n----Exercise #4----" << endl;
    // cout << "Before removing ID: " << Student::toString(testArray1.begin(), testArray1.end()) << endl;
    // vector<Student> temp3 = Student::removeByID(testArray1.begin(), testArray1.end(), 5);
    // cout << "After removing: " << Student::toString(temp3.begin(), temp3.end()) << endl;

    cout << "\n----Exercise #5----" << endl;
    Student temp1(6, "Mariela", FEMALE, 2.3);
    cout << "Before Updating: " << Student::toString(testArray1.begin(), testArray1.end()) << endl;
    vector<Student> temp4_vec = Student::updateStudent(testArray1.begin(), testArray1.end(), temp1);
    cout << "After Updating: " << Student::toString(temp4_vec.begin(), temp4_vec.end()) << endl;

    cout << "\n-------Last Exercise-------" << endl;
    vector<Student> temp2 = Student::honorIdentifier(testVector1.begin(), testVector1.end(), testArray1.begin(), testArray1.end());
    cout << "Students in honor roll: " << Student::toString(temp2.begin(), temp2.end()) << endl;
    
}
