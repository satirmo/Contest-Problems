#include <bits/stdc++.h>

using namespace std;

string ProcessString( string s, string t ){
    int len = t.size();

    while( true ){
        int idx = s.find( t );

        if( idx == -1 ){
            break;
        }

        s.erase( idx, len );
    }

    return s;
}

int main(){
    int test;
    cin >> test;

    cin.ignore();

    while( test-- ){
        string s, t;
        cin >> s >> t;

        string ans = ProcessString( s, t );
        cout << ans << endl;
    }
}