#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

// Test whether the file is valid by attempting to open it and then closing it once confirmed.
bool validFile(const string& path) {
    ifstream cppFile;

    cppFile.open(path);
    if(cppFile.is_open()) {
        cppFile.close();
        return true;
    }

    return false;
}

// Test whether the path is valid by creating a dummy file in the provided path
// then closing and deleting it once confirmed.
bool validPath(string path) {
    ofstream htmlFile;
    string testFile = "test.html";
    string::iterator it = path.end();
    char lastChar = *(it-1);

    if(lastChar != '\\')
        path += '\\' + testFile;
    else
        path += testFile;

    htmlFile.open(path);
    if(htmlFile.is_open()) {
        htmlFile.close();
        remove(path.c_str());

        return true;
    }

    return false;
}

int main(int argc, char **argv) {

    // Argument and path variables.
    string fileArgOne, fileArgTwo;
    string cppPath, htmlPath;

    // Check number of arguments.
    if(argc != 3 && argc != 5) {
        cout << R"(Invalid number of arguments, Example: -cpp C:\File.cpp and/or -html C:\Program Files)" << endl;
        return 1;
    }

    // If number of arguments equal 3 then only cpp file is provided and write html file to same path.
    if(argc == 3) {
        fileArgOne = argv[1];
        remove(fileArgTwo.c_str());

        if(fileArgOne == "-cpp") {
            cppPath = argv[2];
            if (!validFile(cppPath)) {
                cout << R"(Invalid file, cpp file doesn't exist or doesn't have read permissions)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid argument, Example: -cpp C:\File.cpp)" << endl;
            return 1;
        }
    }
    // If arguments equal 5 then cpp and html both provided,
    // read from cpp path and write to html path regardless of order arguments are provided.
    else {
        fileArgOne = argv[1];
        fileArgTwo = argv[3];

        if(fileArgOne == "-cpp") {
            cppPath = argv[2];
            if (!validFile(cppPath)) {
                cout << R"(Invalid file, cpp file doesn't exist or doesn't have read permissions)" << endl;
                return 1;
            }
        }
        else if(fileArgOne == "-html") {
            htmlPath = argv[2];
            if (!validPath(htmlPath)) {
                cout << R"(Invalid path, html path doesn't exist or doesn't have write permissions)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid arguments, Example: -cpp C:\File.cpp -html C:\Program Files)" << endl;
            return 1;
        }

        if(fileArgTwo == "-cpp") {
            cppPath = argv[4];
            if (!validFile(cppPath)) {
                cout << R"(Invalid file, cpp file doesn't exist or doesn't have read permissions)" << endl;
                return 1;
            }
        }
        else if(fileArgTwo == "-html") {
            htmlPath = argv[4];
            if (!validPath(htmlPath)) {
                cout << R"(Invalid path, html path doesn't exist or doesn't have write permissions)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid arguments, Example: -cpp C:\File.cpp -html C:\Program Files)" << endl;
            return 1;
        }
    }

    // Text and file variables to store and copy data.
    ifstream cppFile;
    ofstream htmlFile;
    string cppText, htmlText;

    // Get last character in html path to check for additional backslash.
    string::iterator it = htmlPath.end();
    char lastChar = *(it-1);

    // Symbols to convert.
    string lChevron = "<", rChevron = ">";
    string lChevronSymbol = "&lt", rChevronSymbol = "&gt";

    // Get all raw paths and file names.
    string rawPath = cppPath.substr(0, cppPath.find_last_of("\\/"));
    string cppFileName = cppPath.substr(cppPath.find_last_of("/\\")+1);
    size_t lastIndex = cppFileName.find_last_of(".\\");
    string rawName = cppFileName.substr(0, lastIndex);

    // Extract text from cpp file and store it.
    string line;

    cppFile.open(cppPath);

    while(getline(cppFile, line))
        cppText += line + "\n";

    cppFile.close();

    // Process every character and convert each symbol.
    for(char i : cppText) {
        string fileChar = string(1,i);

        if(fileChar == lChevron)
            fileChar = lChevronSymbol;
        else if(fileChar == rChevron)
            fileChar = rChevronSymbol;

        htmlText += fileChar;
    }

    // Create html file and write all data to it.
    if(htmlPath.empty())
        htmlPath = rawPath + '\\' + rawName + ".html";
    else {
        if(lastChar != '\\')
            htmlPath += '\\' + rawName + ".html";
        else
            htmlPath += rawName + ".html";
    }

    htmlFile.open(htmlPath);

    if(htmlFile.is_open()) {
        htmlFile << "<PRE>" << endl;
        htmlFile << htmlText;
        htmlFile << "</PRE>";
        htmlFile.close();
    }

    return 0;
}