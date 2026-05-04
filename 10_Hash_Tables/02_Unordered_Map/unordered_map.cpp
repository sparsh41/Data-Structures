#include <iostream>
#include <unordered_map> // Hash Table
#include <vector>

using namespace std;

class HashExamples {
    public:
        template <typename T>
        static void countFrequency(const vector<T>& v) {
            unordered_map<T, int> freq;

            for (const T& i : v) {
                freq[i]++;
            }

            for (const auto& f : freq) {
                cout << f.first << " : " << f.second << endl;
            }
        }

        template <typename T>
        static bool hasDuplicates(const vector<T>& v) {
            unordered_map<T, int> vals;
            
            for (const T& i : v) {
                if (vals.find(i) == vals.end()) {
                    vals[i]++;
                } 
                else {
                    return true;
                }
            }
            return false;
        }

        static char firstNonRepeatingChar(const string& s) {
            unordered_map<char, int> chars;

            for (char i : s) {
                chars[i]++;
            }

            for (const auto& ch : chars) {
                if (ch.second == 1) {
                    return ch.first;
                }
            }

            cout << "None" << endl;
            return '\0';
        }
};

int main() {
 
    unordered_map<string, int> grades;

    // Insert
    grades["Michael"] = 90;
    grades["Anna"] = 95;
    grades["John"] = 76;


    // Iterate through the table
    for (const auto& grade : grades) {
        cout << grade.first << " : " << grade.second << endl;
    }
    
    // Search - use find() method
    auto it = grades.find("John");
    if (it == grades.end()) {
        cout << "Not found\n";
    }
    else {
        cout << it->first << " : " << it->second << endl;
    }

    
    it = grades.find("Bob");
    if (it == grades.end()) {
        cout << "Not found\n";
    }
    else {
        cout << it->first << " : " << it->second << endl;
    }


    // Count frequencies of values in a vector
    cout << "\nCount Frequencies\n";
    vector<int> v {1, 2, 3, 1, 2, 2, 3, 1, 2, 1, 3, 1, 5, 12, 5, 98};
    HashExamples::countFrequency(v);
    
    // Check Duplicates
    cout << "\nCheck Duplicates\n";
    vector<string> v2 {"hello", "apple", "banana", "hey", "ban", "apple"};
    cout << HashExamples::hasDuplicates(v2) << endl;
    
    // Check for First Non-repeating Character
    cout << "\nFirst non-repeating character in abcdabcd\n";
    cout << HashExamples::firstNonRepeatingChar("abcdabcd") << endl;

    return 0;
}