#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class ReversibleString {
public:
    ReversibleString (){}
    ReversibleString (const string& str){
    s = str;
 
    }
    string ToString () const {
        return s;
    }
    void Reverse (){
        reverse (s.begin(), s.end());
    }

private:
    string s;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}

