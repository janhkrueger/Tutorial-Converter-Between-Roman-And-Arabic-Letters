#include <iostream>
#include <vector>
#include <ctype.h>
  
using namespace std; 

    string convertIntToRoman(int integerValueToConvert) {

        /**
         * Das hier ist das für diese Lösung kritische Sache.
         * Die Sonderfälle, ein Step vor den nächstgrößeren.
         * Mathe, 5 Klasse Herr Diszberger ;)
         */
        const std::string romanLetters[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        const int integerValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        /**
         * Das hier sieht hässlich aus.
         * Könnten aber die zwei Guinness auf einen Joghurt sein
         */
        std::string result = "";

        /**
         * Die 13 ist hier hart hinterlegt, ein romanLetters.size() würde nur unnötig 
         * Rechenzeit benötigen. Es ist bekannt und die Länge ist fix, nicht dynamisch.
         */
        for (int i = 0; i < 13; ++i) {
            while(integerValueToConvert - integerValues[i] >= 0) {
                result += romanLetters[i];
                integerValueToConvert -= integerValues[i];
            }
        }
        return result;
    }


    int convertRomanToInt(std::string romanNumberToConvert) {
        int convertedValue = 0;
        /**
         * Hier die Gegenüberstellung Römische Ziffer mit Arabischen Lettern.
         * Wichtig: Die Sonderformen, CM, CD, XC, XL, IX, IV mit betrachtet.
         * Wichtig2: Die Reihenfolge ist wichtig damit die höchsten, wie M, 
         * zuerst aus dem String genommen werden.
         */
        vector<pair<std::string, int>> romanLettersAndIntRepresenation( {
            {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
            {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}        
        });

        while (romanNumberToConvert.size() > 0) { //Only when greater zero

            for (auto i = romanLettersAndIntRepresenation.begin(); i != romanLettersAndIntRepresenation.end(); ++ i) { //Iterator from Start to the End of romanLettersAndIntRepresenation
                auto find = romanNumberToConvert.find(i->first); // Search the RomanLetter in the String
                if (find == 0) { //If it is on the first position
                    convertedValue += i->second; //Add the Arabic represenation to the integer value
                    romanNumberToConvert = romanNumberToConvert.substr(find + i->first.size()); // and reduce the String with the first stiff
                }
            }
        }

        return convertedValue;
    }

// Lösung durch die find() langsam, geht schneller. Aber sind drei Guinness.


int main(int argc, char *argv[]) {  
    std::string userInputConvertableNumber = argv[1];


    if( isdigit(userInputConvertableNumber[0]) ) {
        std::cout << "Wert als Integer " << userInputConvertableNumber << " : Als römische Zíffer " << convertIntToRoman( stoi (userInputConvertableNumber) ) << std::endl;
    }
    else {
        std::cout << "Wert als römische Zahl " << userInputConvertableNumber << " : Als Integer " << convertRomanToInt( userInputConvertableNumber ) << std::endl;
    }


    return 0;  
}
