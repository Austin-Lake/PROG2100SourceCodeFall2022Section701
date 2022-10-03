#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <regex>
using namespace std;

// Validate whether cpp file path is a valid path for Windows & Unix.
bool validCppFile(string& path) {
    regex cppPath(R"([a-zA-Z]:[\\/](?:[a-zA-Z0-9]+[\\/])*([a-zA-Z0-9]+\.cpp))");
    bool isValid = regex_match(path, cppPath);

    if (isValid)
        return true;

    return false;
}

// Checks whether path is a Windows or Unix path based on back or forward slash.
bool isWindows(string& path) {
    string pathName = path.substr(path.find_last_of("/\\"));
    char pathOS = pathName.front();

    if (pathOS == '\\')
        return true;

    return false;
}

// Validate whether html path is a valid path for Windows & Unix.
bool validHtmlPath(string path) {
    regex htmlPath(R"([a-zA-Z]:[\\\/](?:[a-zA-Z0-9]+[\\\/])*)");
    string::iterator it = path.end();
    char lastChar = *(it-1);

    if (lastChar != '\\' && lastChar != '/') {
        if (isWindows(path))
            path += '\\';
        else
            path += '/';
    }

    bool isValid = regex_match(path, htmlPath);

    if (isValid)
        return true;

    return false;
}

int main(int argc, char **argv) {

    // Argument and path variables.
    string fileArgOne, fileArgTwo;
    string cppPath, htmlPath;
    string cppArgument = "-cpp";
    string htmlArgument = "-html";

    // Check number of arguments.
    if (argc != 3 && argc != 5) {
        cout << R"(Invalid number of arguments, Example: -cpp C:\File.cpp and/or -html C:\Program Files or
                    -cpp C:/File.cpp and/or -html C:/Program Files)" << endl;
        return 1;
    }

    // If number of arguments equal 3 then only cpp file is provided and write html file to same path.
    if (argc == 3) {
        fileArgOne = argv[1];
        remove(fileArgTwo.c_str());

        if (fileArgOne == cppArgument) {
            cppPath = argv[2];
            if (!validCppFile(cppPath)) {
                cout << R"(Invalid path, cpp file path doesn't exist, Example: C:\File.cpp or C:/File.cpp)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid argument, Example: -cpp C:\File.cpp or -cpp C:/File.cpp)" << endl;
            return 1;
        }
    }
    // If arguments equal 5 then cpp and html both provided,
    // read from cpp path and write to html path regardless of order arguments are provided.
    else {
        fileArgOne = argv[1];
        fileArgTwo = argv[3];

        if (fileArgOne == cppArgument) {
            cppPath = argv[2];
            if (!validCppFile(cppPath)) {
                cout << R"(Invalid path, cpp file path doesn't exist, Example: C:\File.cpp or C:/File.cpp)" << endl;
                return 1;
            }
        }
        else if (fileArgOne == htmlArgument) {
            htmlPath = argv[2];
            if (!validHtmlPath(htmlPath)) {
                cout << R"(Invalid path, html path doesn't exist, Example: C:\Program Files or C:/Program Files)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid arguments, Example: -cpp C:\File.cpp -html C:\Program Files or
                        -cpp C:/File.cpp -html C:/Program Files)" << endl;
            return 1;
        }

        if (fileArgTwo == cppArgument) {
            cppPath = argv[4];
            if (!validCppFile(cppPath)) {
                cout << R"(Invalid path, cpp file path doesn't exist, Example: C:\File.cpp or C:/File.cpp)" << endl;
                return 1;
            }
        }
        else if (fileArgTwo == htmlArgument) {
            htmlPath = argv[4];
            if (!validHtmlPath(htmlPath)) {
                cout << R"(Invalid path, html path doesn't exist, Example: C:\Program Files or C:/Program Files)" << endl;
                return 1;
            }
        }
        else {
            cout << R"(Invalid arguments, Example: -cpp C:\File.cpp -html C:\Program Files or
                        -cpp C:/File.cpp -html C:/Program Files)" << endl;
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
    try
    {
        string line;

        cppFile.open(cppPath);

        if (cppFile.is_open()) {
            while (getline(cppFile, line))
                cppText += line + "\n";

            cppFile.close();
        }
        else
        {
            throw;
        }
    }
    catch (...)
    {
        cout << "Cpp file can't be opened, make sure file name in path is correct.";
        return 1;
    }


    // Process every character and convert each symbol.
    for (char i : cppText) {
        string fileChar = string(1,i);

        if (fileChar == lChevron)
            fileChar = lChevronSymbol;
        else if (fileChar == rChevron)
            fileChar = rChevronSymbol;

        htmlText += fileChar;
    }

    // Create html file and write all data to it.
    string htmlExtension = ".html";

    if (htmlPath.empty()) {
        if (isWindows(cppPath))
            htmlPath = rawPath + '\\' + rawName + htmlExtension;
        else
            htmlPath = rawPath + '/' + rawName + htmlExtension;
    }
    else {
        if (isWindows(htmlPath)) {
            if (lastChar != '\\')
                htmlPath += '\\' + rawName + htmlExtension;
            else
                htmlPath += rawName + htmlExtension;
        }
        else {
            if (lastChar != '/')
                htmlPath += '/' + rawName + htmlExtension;
            else
                htmlPath += rawName + htmlExtension;
        }
    }

    try
    {
        htmlFile.open(htmlPath);

        if (htmlFile.is_open()) {
            htmlFile << "<PRE>" << endl;
            htmlFile << htmlText;
            htmlFile << "</PRE>";
            htmlFile.close();
        }
        else
        {
            throw;
        }
    }
    catch (...)
    {
        cout << "Html file can't be created and written to, make sure path is correct.";
        return 1;
    }

    return 0;
}