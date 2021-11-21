#include <iostream>
using namespace std;
//ascii values for just numbers [48, 57]
//ascii values for all capitals [65, 90]
//ascii values for all lowercase [97, 122]
const char symbols[10] = {'!','@','#','$','%','^','&','*','?','/'};

bool checkPosInt(string str);
void makeAllCharPassword(string& password, string length);
void makeJustLetterPassword(string& password, string length);

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
        //makeAllCharPassword(password, passwordLength);
        makeJustLetterPassword(password, passwordLength);

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
    if (str == "" || str[0] == '0')
        return false;
    for (int i = 0; i < str.size(); i++) {
        if (! isdigit(str[i]))
            return false;
    }
    return true;
}

/**
 * Using all available ASCII (valid) characters, generates a random password of specified length
 *
 * @param password the password string to be modified
 * @param length the length of the desired password as a string, but has been checked to be a PosInt
 */
void makeAllCharPassword(string& password, string length) {
    for (int i = 0; i < stoi(length); i++) {
        //ascii values for all symbols [33, 126] -> 94
        char newChar = rand() % 94 + 33;
        password += newChar;
    }
}

/**
 * Generates a random password of only capital and lowercase letters of specified length
 *
 * @param password the password string to be modified
 * @param length the length of the desired password as a string, but has been checked to be a PosInt
 */
void makeJustLetterPassword(string& password, string length) {
    for (int i = 0; i < stoi(length); i++) {
        //ascii values for all capitals [65, 90] -> 26
        //ascii values for all lowercase [97, 122] -> 26
        char newChar = rand() % (26 + 26);

        //random < 26 means it should be in capitalized range
        if (newChar < 26)
            newChar += 65;
        //otherwise lowercase range
        else
            newChar += (97 - 26); //subtract 26 so that random is [0,25] then add back to range
        password += newChar;
    }
}
//use vectors?
//vector of arrays consisting of possible categories?
//map of arrays with name of characters?

//TODO: create functions / function objects? for different combos of password types
//TODO: create extensible way to allow for possible password type expansion in future
//TODO: optimize UI for entering y/n for what type of password to generate - all at once or step by step