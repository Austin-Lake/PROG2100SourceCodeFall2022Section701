#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <regex>
#include <utility>
using namespace std;

// Checks whether path is a Windows or Unix path based on back or forward slash.
bool isWindows(string& path) {
    string pathName = path.substr(path.find_last_of("/\\"));
    char pathOS = pathName.front();

    if (pathOS == '\\')
        return true;

    return false;
}

// Validate whether cpp file path is a valid path for Windows & Unix.
bool validCppFile(string& path) {
    bool isValidFile;

    if (isWindows(path)) {
        regex cppFile(R"([a-zA-Z]:[\\/](?:[a-zA-Z0-9]+[\\/])*([a-zA-Z0-9]+\.cpp))");
        isValidFile = regex_match(path, cppFile);
    }
    else {
        regex cppFile(R"((/)+[a-zA-Z0-9\\-_/ ]*(.cpp))");
        isValidFile = regex_match(path, cppFile);
    }

    if (isValidFile)
        return true;

    return false;
}

// Validate whether html path is a valid path for Windows & Unix.
bool validHtmlPath(string path) {
    bool isValidPath;
    string::iterator it = path.end();
    char lastChar = *(it-1);

    if (isWindows(path)) {
        regex htmlPath(R"([a-zA-Z]:[\\\/](?:[a-zA-Z0-9]+[\\\/])*)");
        
        if (lastChar != '\\')
            path += '\\';

        isValidPath = regex_match(path, htmlPath);
    }
    else {
        regex htmlPath(R"(^(\/[\w^ ]+)+\/?$)");

        if (lastChar != '/')
            path += '/';

        isValidPath = regex_match(path, htmlPath);
    }

    if (isValidPath)
        return true;

    return false;
}

// Process every character and convert each symbol.
string replaceTags(string& text) {
    string convertedText;
    string lChevron = "<", rChevron = ">";
    string lChevronSymbol = "&lt", rChevronSymbol = "&gt";

    for (char i : text) {
        string fileChar = string(1,i);

        if (fileChar == lChevron)
            fileChar = lChevronSymbol;
        else if (fileChar == rChevron)
            fileChar = rChevronSymbol;

        convertedText += fileChar;
    }

    return convertedText;
}

struct MyCustomException : public exception {
private:
    const string message;

public:
    explicit MyCustomException(string msg) : message(std::move(msg)) {}
    string what() {
        return message;
    }
};

int main(int argc, char **argv) {
    // Check number of arguments.
    if (argc != 3 && argc != 5) {
        cout << "Invalid number of arguments.\n" R"( Windows: -cpp "C:\File.cpp" or -html "C:/File.cpp" -cpp "C:/Program Files" / Unix: -cpp "/File.cpp" or -html "/home" -cpp "/File.cpp")" << endl;
        return 1;
    }

    // Argument and path variables.
    string fileArgOne, fileArgTwo;
    string cppPath, htmlPath;
    string cppArgument = "-cpp", htmlArgument = "-html";

    // If number of arguments equal 3 then only cpp file is provided and write html file to same path.
    if (argc == 3) {
        fileArgOne = argv[1];
        remove(fileArgTwo.c_str());
        remove(htmlArgument.c_str());

        if (fileArgOne == cppArgument) {
            cppPath = argv[2];
            if (!validCppFile(cppPath)) {
                cout << "Invalid path: '" + cppPath + "', cpp file path is incorrect.\n" R"( Windows: "C:\File.cpp" / Unix: "/File.cpp")" << endl;
                return 1;
            }
        }
        else {
            cout << "Invalid argument: '" + fileArgOne + "'\n" R"( Windows: -cpp "C:\File.cpp" / Unix: -cpp "/File.cpp")" << endl;
            return 1;
        }
    }
    // If arguments equal 5 then cpp and html both provided,
    // reads from cpp path and writes to html path regardless of order arguments are provided.
    else {
        fileArgOne = argv[1];
        fileArgTwo = argv[3];

        if (fileArgOne == cppArgument) {
            cppPath = argv[2];
            if (!validCppFile(cppPath)) {
                cout << "Invalid path: '" + cppPath + "', cpp file path is incorrect.\n" R"( Windows: "C:\File.cpp" / Unix: "/File.cpp")" << endl;
                return 1;
            }
        }
        else if (fileArgOne == htmlArgument) {
            htmlPath = argv[2];
            if (!validHtmlPath(htmlPath)) {
                cout << "Invalid path: '" + htmlPath + "', html path is incorrect.\n" R"( Windows: "C:\Program Files" / Unix: "/home")" << endl;
                return 1;
            }
        }
        else {
            cout << "Invalid argument: '" + fileArgOne + "'\n" R"( Windows: -cpp "C:\File.cpp" -html "C:\Program Files" / Unix: -html "/home" -cpp "/File.cpp")" << endl;
            return 1;
        }

        if (fileArgTwo == cppArgument) {
            cppPath = argv[4];
            if (!validCppFile(cppPath)) {
                cout << "Invalid path: '" + cppPath + "', cpp file path is incorrect.\n" R"( Windows: "C:\File.cpp" / Unix: "/File.cpp")" << endl;
                return 1;
            }
        }
        else if (fileArgTwo == htmlArgument) {
            htmlPath = argv[4];
            if (!validHtmlPath(htmlPath)) {
                cout << "Invalid path: '" + htmlPath + "', html path is incorrect.\n" R"( Windows: "C:\Program Files" / Unix: "/home")" << endl;
                return 1;
            }
        }
        else {
            cout << "Invalid argument: '" + fileArgTwo + "'\n" R"( Windows: -cpp "C:\File.cpp" -html "C:\Program Files" / Unix: -html "/home" -cpp "/File.cpp")" << endl;
            return 1;
        }
    }

    // Text and file variables to store and copy data.
    ifstream cppFile;
    ofstream htmlFile;
    string cppText, htmlText;

    // Get last character in html path to check for additional back/forward slash.
    string::iterator it = htmlPath.end();
    char lastChar = *(it-1);

    // Get all raw paths and file names.
    string rawPath = cppPath.substr(0, cppPath.find_last_of("\\/"));
    string cppFileName = cppPath.substr(cppPath.find_last_of("/\\")+1);
    size_t lastIndex = cppFileName.find_last_of(".\\");
    string rawName = cppFileName.substr(0, lastIndex);

    // Extract text from cpp file and store it.
    try {
        string line;
        cppFile.open(cppPath);

        if (cppFile.is_open()) {
            while (getline(cppFile, line))
                cppText += line + "\n";

            cppFile.close();
        }
        else {
            throw MyCustomException("Cpp file can't be opened. Make sure the file has read permissions.");
        }
    }
    catch (const bad_exception& message) {
        cout << message.what() << endl;
        return 1;
    }
    catch (MyCustomException& message) {
        cout << message.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "Unknown error. Retry program..." << endl;
        return 1;
    }

    // Converts all symbols from one string and stores it into another.
    htmlText = replaceTags(cppText);

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

    try {
        htmlFile.open(htmlPath);

        if (!htmlFile.fail()) {
            htmlFile << "<PRE>" << endl;
            htmlFile << htmlText;
            htmlFile << "</PRE>";
            htmlFile.close();
        }
        else {
            throw MyCustomException("Html path can't be created and written to. Make sure the path has write permissions.");
        }
    }
    catch (const bad_exception& message) {
        cout << message.what() << endl;
        return 1;
    }
    catch (MyCustomException& message) {
        cout << message.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "Unknown error. Retry program..." << endl;
        return 1;
    }

    return 0;
}