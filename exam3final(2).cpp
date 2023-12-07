#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Externs to avoid lack of prototype warnings
extern string removeDigits(string word);
extern int countPattern(string sentence, string pattern);
extern string removePatternNTimes(string sentence, string pattern, int n);
extern bool isVowel(char letter);



/* Exercise 1A
 * Returns a copy of the given sentence with ALL digits (0-9) removed.
 * If the string has no digits it should return an identical copy of original sentence.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */
string removeDigitsHeper(string word, int index) {
    if(word.size() < index) {
        return word;
    }
    if(isdigit(word[index])) {
        word.erase(word.begin()+index);
        return removeDigitsHeper(word, index);
    } else {
        return removeDigitsHeper(word, index + 1);
    }
}
string removeDigits(string word) {
    // YOUR CODE
    return removeDigitsHeper(word, 0); // Dummy
}


/* Exercise 2A
 * Returns the number of times that the given pattern appears in the given sentence.
 * Multiple of the pattern may overlap.  For instance the patter "HH" appears three
 * three times in sentence "HHHH" at positions 0, 1, and 2.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */

int countPatternHelper(string sentence, string pattern, int index) {
    // YOUR CODE
    if(sentence.size() < index) {
        return 0;
    }
    if (sentence.substr(index, pattern.length()) == pattern) {
        return 1 + countPatternHelper(sentence, pattern, index + 1);
    } else {
        return countPatternHelper(sentence, pattern, index + 1);
    }
}
int countPattern(string sentence, string pattern) {
    // YOUR CODE
    
    return countPatternHelper(sentence, pattern, 0);
}

/* Exercise 3A
 * Returns a copy of the given sentence with the first N occurrences of the given 
 * pattern removed.  You may assume that pattern occurences will not overlap.
 * If pattern doesn't exist should return an identical copy of original sentence.
 * MUST BE RECURSIVE.  NON-RECURSIVE FUNCTIONS WILL NOT RECEIVE ANY POINTS
 */

string removePatternNTimesHelper(string sentence, string pattern, int n, int index) {
    if(sentence.size() < index || n == 0) {
        return sentence;
    }

    if (sentence.substr(index, pattern.length()) == pattern) {
        sentence.erase(sentence.begin()+index, sentence.begin()+index+pattern.length());
        cout << sentence << " " << n << " " << index << endl;
        return removePatternNTimesHelper(sentence, pattern, n-1, index);
    } else {
        cout << sentence << " " << n << " " << index << endl;
        return removePatternNTimesHelper(sentence, pattern, n, index + 1);
    } 
}
string removePatternNTimes(string sentence, string pattern, int n) {
    
    return removePatternNTimesHelper(sentence, pattern, n, 0);
}

/* Exercise 4A
 * Return ALL sentences that can be formed including SOME of the given words
 *
 */

vector<string> genAllSentencesHelper(vector<string> words, vector<string> result, int index) {

    //vector<string> result;  
    if(words.size() == index) {
        return result;
    }
    string newWord = words[index];
    for(int i = 0; i < words.size(); i++) {
        if(i != index) {
            newWord += " " + words[i];
            //cout << newWord << endl;
            result.push_back(newWord);
        }
        if(i == index) {
            result.push_back(words[index]);
            //cout << words[index] << endl;
        }
    }
    if(words.size() > 2) {
        string newWord2 = words[index];
        for(int i = words.size() - 1; i > -1; i--) {
            if(i != index) {
                newWord2 += " " + words[i];
                //cout << newWord2 << endl;
                result.push_back(newWord2);
            }
        }
    }
    return genAllSentencesHelper(words, result, index + 1);

}
vector<string> genAllSentences(vector<string> words) {
    vector<string> result;  

    return genAllSentencesHelper(words, result, 0);
}
  
int main() {

    // cout << "Hello World" << endl;

    // // Exercise 1A
    // cout << "Hello1!Hello2$Hello3% removed digits: " << removeDigits("Hello1!Hello2$Hello3%") << endl;
    // cout << "0Hello1!Hello2$Hello3%44 removed digits: " << removeDigits("0Hello1!Hello2$Hello3%44") << endl;
    // cout << "1234567890 removed digits: " << removeDigits("1234567890") << endl;

    // // Exercise 2A
    // cout << "Occurrences of 'hh' in 'hhhh': " << countPattern("hhhh", "hh") << endl;
    // cout << "Occurrences of 'he' in 'hello': " << countPattern("hello", "he") << endl;
    // cout << "Occurrences of 'llo' in 'hello': " << countPattern("hello", "llo") << endl;
    // cout << "Occurrences of 'ell' in 'hello': " << countPattern("hello", "ell") << endl;
    // cout << "Occurrences of 'hello' in 'hellohellohello': " << countPattern("hellohellohello", "hello") << endl;

    // Exercise 3A
    // cout << "HelloHelloHello removed 1 times: " << removePatternNTimes("HelloHelloHello", "Hello",1) << endl;
    // cout << "HelloHelloHello removed 2 times: " << removePatternNTimes("HelloHelloHello", "Hello",2) << endl;
    // cout << "HelloHiHelloHello removed 2 times: " << removePatternNTimes("HelloHiHelloHello", "Hello",2) << endl;
    // cout << "HelloHelloHello removed 4 times: " << removePatternNTimes("HelloHelloHello", "Hello",4) << endl;

      // Exercise 4
    vector<string> words {"Hello", "World"};
    vector<string> sentences = genAllSentences(words);
    for (string s : sentences) {
        cout << "{ \"Hello\", \"World\" } Next sentence: [" << s << "]" << endl;
    }

    vector<string> words2 {"Hello"};
    vector<string> sentences2 = genAllSentences(words2);
    for (string s : sentences2) {
        cout << "{ \"Hello\" } Next sentence: [" << s << "]" << endl;
    }

    vector<string> words3 {"Good", "Morning", "Vietnam"};
    vector<string> sentences3 = genAllSentences(words3);
    for (string s : sentences3) {
        cout << "{ \"Good\", \"Morning\", \"Vietnam\" } Next sentence: [" << s << "]" << endl;
    }
  
}

