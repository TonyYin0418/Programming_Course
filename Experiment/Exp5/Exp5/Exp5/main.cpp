/*
cd /Users/tonyyin/Library/Developer/Xcode/DerivedData/Exp5-enixjafhxrxkhechlfmxeojzqybp/Build/Products/Debug
 ./exp5 names.txt output.txt
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    const char *sourceFile = argv[1];
    const char *destinationFile = argv[2];

    ifstream src(sourceFile, ios::binary | ios::in | ios::beg);
    if (!src.is_open()) {
        cerr << "Error: 输入文件不存在" << endl;
        return -1;
    }

    ifstream check(destinationFile, ios::in);
    if (check.is_open()) {
        cerr << "Error: 输出文件已存在" << endl;
        return -1;
    }
    check.close();

    ofstream dest(destinationFile, ios::binary | ios::out);
//    src.seekg(0, ios::beg);
    const size_t bufferSize = 4096;
    char buffer[bufferSize];

    while (!src.eof()) {
        src.read(buffer, bufferSize);
        streamsize bytesRead = src.gcount();
        dest.write(buffer, bytesRead);
    }
    cout << "Successful" << endl;
    
    src.close();
    dest.close();
    return 0;
}
