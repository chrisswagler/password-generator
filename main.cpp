#include <iostream>
#include <vector>

using namespace std;
//ascii values for just numbers [48, 57]
//ascii values for all capitals [65, 90]
//ascii values for all lowercase [97, 122]
const char symbols[10] = {'!','@','#','$','%','^','&','*','?','/'};

bool checkPosInt(string str);
string makePassword(vector<char> characters, int length);
vector<char> getCharsInRange(int low, int high);

int main() {
    srand (time(NULL)); //random seed
    string quit;

    //main loop
    do {
        string passwordLength;

        //loop to ensure inputted password length is positive int
        do {
            cout << "Enter desired password length: ";
            getline(cin, passwordLength);
            //loops again if the string is not a positive integer
        } while (!checkPosInt(passwordLength));

        //generate password
        string password;
        vector<char> characters;
        vector<char> lowercase = getCharsInRange(97,122);
        characters.insert(characters.end(), lowercase.begin(), lowercase.end());
        password = makePassword(characters, stoi(passwordLength));


        cout << "Your password is: " << password << endl;
        cout << "Enter 'q' to quit or press any key to try again: ";
        getline(cin, quit);

    } while (quit != "q");

    return 0;
}

/**
 * checks if a given string is a positive integer by only returning true if all characters in the
 * string are numbers (aka any - or . in a number will return false, and additionally any non-numeric
 * characters will return false)
 *
 * @param str the given string to compare
 * @return a boolean of whether or not the string is a positive integer
 */
bool checkPosInt(string str) {
    if (str.empty() || str[0] == '0')
        return false;
    for (char i : str) {
        if (! isdigit(i))
            return false;
    }
    return true;
}

/**
 * Given a vector of characters, generates a random sequence of specified length using those characters.
 *
 * @param characters the possible characters used in the password
 * @param length password length
 * @return the password
 */
string makePassword(vector<char> characters, int length) {
    string password;
    for (int i = 0; i < length; i++) {
        int randIdx = rand() % characters.size();
        password += characters[randIdx];
    }
    return password;
}

/**
 * Get vector of characters in provided range (inclusive)
 * @param low smallest ASCII character value
 * @param high highest ASCII character value
 * @return vector of characters
 */
vector<char> getCharsInRange(int low, int high) {
    //TODO: check for valid range
    vector<char> characters;
    for (int i = low; i <= high; i++) {
        characters.push_back(i);
    }
    return characters;
}

//TODO: create functions / function objects? for different combos of password types that return vector
//TODO: create extensible way to allow for possible password type expansion in future - custom vector pushback
//TODO: consider using set instead of vector
//TODO: optimize UI for entering y/n for what type of password to generate - all at once or step by step
//TODO: exception throwing