#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * EXERCISE 1
 * 
 * Reverse String: Reverse the characters of a string recursively.
 * 
 * Example: 
 *      string = "ICOM"
 *      reverse string = "MOCI".
 * 
 */
 
static string reverseStringHelper(const string &str, int index, string result) {
    if(str.size() == result.size()) {
        return result;
    }
    result.push_back(str[index]);
    return reverseStringHelper(str, index - 1, result);
}
string reverseString(const string &str){

    return reverseStringHelper(str, str.size() - 1, "");
}

/**
 * EXERCISE 2
 * 
 * Sum the digits of a given number.
 * 
 * Example:
 *      Number = 13
 *      Sum_of_digits = 1 + 3 = 4
 * 
 *      Number = 123
 *      Sum_of_digits = 1 + 2 + 3 = 6
 * 
 */

int sumDigits(const int num){
    if(num % 10 == 0) {
        return num;
    }
    return num%10 + sumDigits(num/10); 
}

/**
 * EXERCISE 3 
 * 
 * Decimal To Binary: For a given decimal number, calculate it's binary representation.
 * 
 * To convert:
 *      When dec == 0 -> 0
 *      Otherwise 10 * [10 * (...) + dec mod 2] + dec mod 2
 * 
 */
static int decimalToBinary(int dec){
    if(dec == 0) {
        return dec;
    }

    return dec%2 + (10 * decimalToBinary(dec/2));
}
    // 4 mod 2 = 0   //
    // 4 / 2 = 2
    // 2 mod 2 = 0   //
    // 2 / 2 = 1
    // 1 mod 2 = 1   //
    // 1 / 2 = 0


/**
 * EXERCISE 4
 * 
 * Palindrome
 * 
 * A palindrome is a word, sentence, verse, or even number that reads 
 * the same backward or front. It derives from Greek roots that 
 * literally mean “running back” (palin is “again, back,” and dromos, “running.”)
 * 
 * e.g. noon, civic, racecar, tattarrattat
*/
static bool isPalindromeHelper(string word, int start, int end) {
    if(start > end) {
        return true;
    }
    if(word[start] == word[end]) {
        return isPalindromeHelper(word, start + 1, end - 1);
    } else { 
        return false;
    }
}

bool isPalindrome(string word){
    return isPalindromeHelper(word, 0, word.size() - 1); 
}

/**
 * EXERCISE 5
 * 
 * The least common multiple (lcm) of two numbers is the smallest number which can be divided by both numbers.
 * By example: lcm(2,3) = 6. Find the lcm(a,b) using the relation lcm(a,b) = a*b/gcd(a,b) 
 * 
 * Hint: Use the Euclidean algorithm: The greatest common denominator of values a and b also divides their difference.
 * 
 * For any (a, b) we have: 
 *      If a > b: gcd(a,b) is the same as gcd(b, a%b)
 *      Analyze example: For hints on edge cases. 
 * 
 */

static int gcd(int a, int b){
    if(a == 0) {
        return b;
    }
    if(b == 0) {
        return a;
    } 

    if(a == b) {
        return a;
    }

    if(a > b) {
        return gcd(b, a%b);
    } else {
        return gcd(a, b%a);
    }
}

int lcm(int a, int b){  
  return a*b/gcd(a,b); 
}

/**
 * EXERCISE 6
 * 
 * Reverse the digits of a given number recursively.
 * Example: 
 *      input = 12
 *      output = 21
 * Hint: If the integer number 123 is divided by 10, the quotient is 123 / 10 = 12, but the remainder is 123 % 10 = 3.
 * Hint: Use a helper function.
 * 
 */

// static int reverseNumberHelper(const int num, int newNum) {
//     if (num == 0) {
//         return newNum;
//     }
//     newNum = newNum * 10 + num % 10;
//     return reverseNumberHelper(num / 10, newNum);
// }
// int reverseNumber(const int num){
//     return reverseNumberHelper(num, 0); 
// }

// static int reverseNumberHelper1(string newNum1, int index, string newNum2) {
//     if(index < 0) {
//         //return stoi(newNum2);
//         int newNum3 = stoi(newNum2);
//         newNum3 = newNum3* -1;
//         return newNum3;
//     }
//     newNum2.push_back(newNum1[index]);
//     return reverseNumberHelper1(newNum1, index - 1, newNum2);
// }
// static int reverseNumberHelper2(string newNum1, int index, string newNum2) {
//     if(index < 0) {
//         return stoi(newNum2);
//     }
//     newNum2.push_back(newNum1[index]);
//     return reverseNumberHelper2(newNum1, index - 1, newNum2);
// }
// int reverseNumber(const int num){
//     if(num < 0) {
//         string newNum1 = to_string(num);
//         return reverseNumberHelper1(newNum1, newNum1.size()-1, ""); 
//     }
//     if(num >= 0) {
//         string newNum1 = to_string(num);
//         return reverseNumberHelper2(newNum1, newNum1.size()-1, "");         
//     }
// }


static int reverseNumberHelper2(string newNum1, int index, string newNum2) {
    if(index < 0) {
        return stoi(newNum2);
    }
    newNum2.push_back(newNum1[index]);
    return reverseNumberHelper2(newNum1, index - 1, newNum2);
}
int reverseNumber(const int num){
    if(num < 0) {
        string newNum1 = to_string(num);
        return -1 * reverseNumberHelper2(newNum1, newNum1.size()-1, ""); 
    }
    if(num >= 0) {
        string newNum1 = to_string(num);
        return reverseNumberHelper2(newNum1, newNum1.size()-1, "");         
    }
}

/**
 * EXERCISE 7
 *
 * Contains function: Given a vector v of strings and a target string, return if the target is in v.
 * If target is in v return the index, otherwise return -1.
 * 
 * HINT: Use a helper function to complete the implementation, search always starts in index 0.
 */

static int findIndexHelper(vector<string> v, string target, int index) {
    if(v.size() == index) {
        return -1;
    }
    if(v[index] == target) {
        return index;
    }

    return findIndexHelper(v, target, index + 1);

}
static int findIndex(vector<string> v, string target){
    return findIndexHelper(v, target, 0);
}

/**
 * EXERCISE 8
 *
 *
 * Complete the findMax() method. This method receives a vector of positive
 * integers, and should return the max value present in the vector.
 * If the vector is empty, return -1
 *
 * NOTE: You must use recursion. Iterative methods will fail test cases.
 *
 * Hint:
 * What is the max value of a vector of size 1?
 * You might want to define a helper method <img class="icon emoticon" alt="smile" title="smile" src="https://online.upr.edu/theme/image.php/boost/core/1697506420/s/smiley" />
 */
static int findMaxHelper(vector<int> nums, int index, int max){
    if(nums.size() == 0) {
        return -1;
    }
    if(nums[index] > max && nums[index] > 0){
        max = nums[index];
    }  
    if(nums.size() == index) {
        return max;
    }
    return findMaxHelper(nums, index + 1, max);
}
int findMax(vector<int> nums){
    return findMaxHelper(nums, 0, 0);
}

int main(){

    cout << boolalpha << endl;

    // Test Exercise 1
    cout << "------- EXCERCISE 1 -------" << endl;
    string test = "house";
    cout << "Before reverse: " << test << endl;
    cout << "After reverse: " << reverseString(test) << endl;
    cout << "\n";
    test = "home alone";
    cout << "Before reverse: " << test << endl;
    cout << "After reverse: " << reverseString(test) << endl;
    cout << "\n";

    // Test Exercise 2
    cout << "------- EXCERCISE 2 -------" << endl;
    cout << "Sum of digits 1934: " << sumDigits(1934) << endl;
    cout << "Sum of digits 59: " << sumDigits(59) << endl;
    cout << "Sum of digits -4: " << sumDigits(-4) << endl;
    cout << "Sum of digits 7476: " << sumDigits(7476) << endl;
    cout << "\n";

    // Test Exercise 3
    cout << "------- EXCERCISE 3 -------" << endl;
    cout <<  "Decimal to Binary " << 25 << " = " <<  decimalToBinary(25) << endl;
    cout <<  "Decimal to Binary " << 10 << " = " <<  decimalToBinary(10) << endl;
    cout <<  "Decimal to Binary " << 7 << " = " <<  decimalToBinary(7) << endl;
    cout <<  "Decimal to Binary " << 120 << " = " <<  decimalToBinary(120) << endl;
    cout << "\n";

    // Test Exercise 4
    cout << "------- EXCERCISE 4 -------" << endl;
    cout << "Is Palindrome: " << isPalindrome("racecar") << endl;
    cout << "Is Palindrome: " << isPalindrome("cheese") << endl;
    cout << "Is Palindrome: " << isPalindrome("girafarig") << endl;
    cout << "Is Palindrome: " << isPalindrome("madeyoulook") << endl;
    cout << "\n";

    // Test Exercise 5
    cout << "------- EXCERCISE 5 -------" << endl;
    cout << "lcm(" + to_string(30) + "," + to_string(7) + ") = " << lcm(30,7) << endl;
    cout << "lcm(" + to_string(12) + "," + to_string(8) + ") = " << lcm(12,8) << endl;
    cout << "lcm(" + to_string(15) + "," + to_string(60) + ") = " << lcm(15,60) << endl;
    cout << "lcm(" + to_string(7) + "," + to_string(0) + ") = " << lcm(7,0) << endl;
    cout << "lcm(" + to_string(11) + "," + to_string(121) + ") = " << lcm(11,121) << endl;
    cout << "\n";

    // Test Exercise 6
    cout << "------- EXCERCISE 6 -------" << endl;
    cout << "Reverse of 8721: " << reverseNumber(8721) << endl;
    cout << "Reverse of 12: " << reverseNumber(12) << endl;
    cout << "Reverse of -1: " << reverseNumber(-1) << endl;
    cout << "Reverse of 987654321: " << reverseNumber(987654321) << endl;
    cout << "\n";

    // Test Exercise 7
    cout << "------- EXCERCISE 7 -------" << endl;
    vector<string> v{"Cpp", "Is", "The", "Best"};
    string target = "The";
    cout << "Index of \"The\"? " << findIndex(v, target) << endl;

    v = {"Java", "Has", "No", "Pointers", "Though"};
    target = "What about Python?";
    cout << "Index of \"What about Python?\" ? " << findIndex(v, target) << endl;
    cout << "\n";

    // Test Exercise 8
    cout << "------- EXCERCISE 8 -------" << endl;
    vector<int> v1{1, 2, 3, 4, 5};      // 5: End
    vector<int> v2{8, 9, 10, 6, 7};     // 10: Middle
    vector<int> v3{15, 14, 13, 12, 11}; // 15: Start
    vector<int> v4{1,1,1,1};

    cout << "Max of v1: " << findMax(v1) << endl;
    cout << "Max of v2: " << findMax(v2) << endl;
    cout << "Max of v3: " << findMax(v3) << endl;
    cout << "Max of v4: " << findMax(v4) << endl;

    cout << "\n";

    //Testing
    cout << "Max of 10: " << 123%10 << endl;
    cout << "Max of 100: " << 123%100 << endl;
    cout << "Max of 1000: " << 123%1000 << endl;

}
