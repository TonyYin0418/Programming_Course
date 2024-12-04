#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
	multiset<string> ms;
	ifstream inFile("/Users/tonyyin/Library/Mobile\ Documents/com\~apple\~CloudDocs/1_CLASS/3_程序设计/Experiment/Exp5/Exp5/multiset\ for\ student/names.txt");
	ofstream outFile("/Users/tonyyin/Library/Mobile\ Documents/com\~apple\~CloudDocs/1_CLASS/3_程序设计/Experiment/Exp5/Exp5/multiset\ for\ student/output.txt");
	string txtLine;
	while (getline(inFile, txtLine))
	{
        ms.insert(txtLine);
		//请填写程序
	}
    int num = 1;
//    for(multiset<string>::iterator it = ms.begin(); it != ms.end(); it++) {
    for(auto it:ms) {
//        outFile << num << " " << *it << endl;
        outFile << num << " " << it << endl;
        num++;
    }
	//请填写程序
	inFile.close();
	outFile.close();
	return 0;
}
