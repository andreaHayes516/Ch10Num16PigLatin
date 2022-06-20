/************************************************
** Author: Andrea Hayes
** Date: May 31,2020
** Purpose: Translate English to pig latin
** Input: English sentence
** Processing: Switch first letter to last and add 'ay'
** Output: Pig latin sentence
*************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {

    //Declare Variables
    const int SIZE = 1001;
    string sen, eng[SIZE], pig, end = "ay";

    //Get User Input
    cout << "Enter a sentence you would like translated to Pig Latin. ";
    getline(cin, sen);
    
    // Takes sentence and puts into an array of words 
    int startOfWord = 0, length=0, words = 0;
    for (int i = 0; i < sen.size(); i++) {
        if (sen[i] == ' ' || i==sen.size()-1) {
            if (length > 0) {
                eng[words] = sen.substr(startOfWord, length);
                words++;
            }
            length = 0;
        } 
        else {
            if (length == 0) {
                startOfWord = i;
            }
            length++;
        }
    }

    //Manipulates words by putting first letter last and adding 'ay'
    for (int i = 0; i < words; i++) {
        char first = eng[i].front();
        eng[i].erase(0, 1);
        eng[i].insert(eng[i].size(), 1, first);
        eng[i] = eng[i].append(end);
    }

    //Displays pig latin sentence
    for (int i = 0; i < words; i++) {
        cout << eng[i]<< " ";
   }

    return 0;
}