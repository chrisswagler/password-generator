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
vector<char> getCharsFromUser();

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

        //get types of characters to include
        string password;
        vector<char> characters;
        do {
            string types;
            cout << "Enter types of characters to include:\n"
                 << "u - uppercase\n"
                    "l - lowercase\n"
                    "n - numeric \n"
                    "c - custom\n";
            getline(cin, types);

            for (char i: types) {
                vector<char> toAdd;
                switch (i) {
                    case 'u':
                        toAdd = getCharsInRange(65, 90);
                        break;
                    case 'l':
                        toAdd = getCharsInRange(97, 122);
                        break;
                    case 'n':
                        toAdd = getCharsInRange(48, 57);
                        break;
                    case 'c':
                        toAdd = getCharsFromUser();
                        break;
                    default:
                        //ignore invalid input for now
                        break;
                }
                characters.insert(characters.end(), toAdd.begin(), toAdd.end());
            }
        } while (characters.empty());

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

/**
 * Gets vector of characters from user input, regardless of repeat characters.
 * @return vector of characters
 */
vector<char> getCharsFromUser() {
    vector<char> characters;
    string input;
    cout << "Enter characters to add: ";
    getline(cin, input);
    for (char i : input) {
        characters.push_back(i);
    }
    return characters;
}

//TODO: consider using set instead of vector
//TODO: exception throwing