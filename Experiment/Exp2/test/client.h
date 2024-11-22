//
//  client.h
//  Exp2
//
//  Created by TonyYin on 2024/11/2.
//

#include <string>
using namespace std;

class CLIENT {
public:
    CLIENT(const string& _s);
    ~CLIENT();
    void changeServerName(string s) ;
    static int getClientNum() const;
private:
    string serverName;
    static int clientNum;
};
