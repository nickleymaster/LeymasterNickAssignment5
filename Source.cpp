// https://spedsupport.tea.texas.gov/sites/default/files/2023-08/high-frequency-word-list.pdf
// https://cplusplus.com/reference/algorithm/find/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>  // for find()

using namespace std;

int main() {
    // Step 1: Open the dictionary file
    ifstream dictfile("words.txt");
    if (!dictfile) 
    {
        cerr << "Error: Could not open dictionary file." << endl;
        return 1;
    }

    // Step 2: Define a vector of strings called words
    vector<string> words;
    string dictword;


    // Step 3: Read words from the dictionary file
    while (dictfile >> dictword) 
    {
        words.push_back(dictword);
    }
    dictfile.close();

    //print the content of the words vector (got this from google)
	//just used to verify that the words were read correctly
    cout << "Dictionary words:" << endl;
    for (const string& word : words)
    {
        cout << word << endl;
    }

    // Step 4: Open the file to be spell-checked
    ifstream inputfile("input.txt");
    if (!inputfile) 
    {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    // Step 5: Check each word in the input file
    string inputword;
    while (inputfile >> inputword) 
    {
		// Check if word is in dictionary (found on https://cplusplus.com/reference/algorithm/find/)
        if (find(words.begin(), words.end(), inputword) == words.end()) 
        {
            cout << "Misspelled: " << inputword << endl;
        }
    }

    inputfile.close();
    return 0;
}