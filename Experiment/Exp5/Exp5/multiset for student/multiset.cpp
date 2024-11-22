#include <fstream>
#include <string>
#include <set>

using namespace std;

int main()
{
	multiset<string> ms;
	ifstream inFile("names.txt");
	ofstream outFile("output.txt");
	string txtLine;
	while (getline(inFile, txtLine))
	{
		//请填写程序
	}
	//请填写程序
	inFile.close();
	outFile.close();
	return 0;
}
