#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
const string question = "?";
const string pancakes = "pancakes";

string meals[ maxn ];

int CalculateMinimum( int n, int len ){
    int ret = 0;

    int cntPancakes = 0;
    int lastQuestion = 0;

    for( int i = 1; i <= n; i++ ){
        if( meals[ i ] == question ){
            lastQuestion = i;
        }

        if( meals[ i ] == pancakes ){
            cntPancakes++;
        }

        else if( meals[ i ] == question ){
            lastQuestion = i;
        }

        if( i >= len ){
            if( meals[ i - len ] == pancakes ){
                cntPancakes--;
            }

            if( cntPancakes == 0 ){
                if( i - lastQuestion >= len ){
                    return -1;
                }

                else{
                    ret++;
                    meals[ lastQuestion ] = pancakes;

                    cntPancakes++;
                    lastQuestion = 0;
                }
            }
        }
    }

    return ret;
}

int main(){
    int test;
    cin >> test;

    while( test-- ){
        int n, len;
        char input[ 15 ];
        cin >> n >> len;

        cin.ignore();

        for( int i = 1; i <= n; i++ ){
            scanf("%s", input);
            meals[ i ] = string(input);
        }

        int ans = CalculateMinimum( n, len );
        cout << ans << endl;
    }
}