#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > ii;

const int inf = 1 << 30;
const int maxr = 4;
const int maxn = (1 << ( maxr * maxr )) + 5;

int dist[ maxn ];
string b[ maxr ];
vector < ii > G[ maxn ];
set < ii > pq;

int ConvertBoardToBitmask( int r, int c ){
    int msk = 0;

    for( int i = 0; i < r; i++ ){
        for( int j = 0; j < c; j++ ){
            int bit = ( b[ i ][ j ] == 'B' );

            msk = ( msk << 1 ) | bit;
        }
    }

    return msk;
}

void GenerateGraph( int r, int c, int c1, int c2 ){
    int upto = 1 << ( r * c );

    for( int i = 0; i < upto; i++ ){
        G[ i ].clear();
    }

    for( int msk = 0; msk < upto; msk++ ){
        for( int i = 0; i < r; i++ ){
            for( int j = 1; j < c; j++ ){
                int bit1 = c * i + ( j - 1 );
                int msk1 = 1 << bit1;

                int bit2 = c * i + j;
                int msk2 = 1 << bit2;
                
                int nmsk = msk ^ msk1 ^ msk2;

                G[ msk ].push_back( ii( c1, nmsk ) );
            }
        }

        for( int i = 1; i < r; i++ ){
            for( int j = 0; j < c; j++ ){
                int bit1 = c * ( i - 1 ) + j;
                int msk1 = 1 << bit1;

                int bit2 = c * i + j;
                int msk2 = 1 << bit2;
                
                int nmsk = msk ^ msk1 ^ msk2;

                G[ msk ].push_back( ii( c2, nmsk ) );
            }
        }
    }
}

string ConvertToBinary( int u, int n ){
    string ret = "";

    while( n > 1 ){
        int bit = u & 1;
        ret += to_string( bit );

        u >>= 1;
        n >>= 1;
    }

    return ret;
}

int Dijkstra( int st, int n ){
    for( int i = 0; i < n; i++ ){
        dist[ i ] = inf;
    }

    dist[ st ] = 0;
    pq.insert( ii( 0, st ) );

    while( ! pq.empty() ){
        ii unode = * pq.begin();
        pq.erase( unode );

        int u = unode.second;

        for( ii vnode : G[ u ] ){
            int w = vnode.first;
            int v = vnode.second;

            if( dist[ u ] + w < dist[ v ] ){
                pq.erase( ii( dist[ v ], v ) );

                dist[ v ] = dist[ u ] + w;
                pq.insert( ii( dist[ v ], v ) );
            }
        }
    }

    int whiteCost = dist[ 0 ];
    int blackCost = dist[ n - 1 ];

    if( whiteCost >= 0 && blackCost >= 0 ){
        return min( whiteCost, blackCost );
    }

    if( whiteCost < 0 ){
        return blackCost;
    }

    if( blackCost < 0 ){
        return whiteCost;
    }

    return -1;
}

int main(){
    int test;
    cin >> test;

    while( test-- ){
        int r, c;
        cin >> r >> c;

        long long c1, c2;
        cin >> c1 >> c2;

        cin.ignore();

        for( int i = 0; i < r; i++ ){
            cin >> b[ i ];
        }

        int msk = ConvertBoardToBitmask( r, c );
        GenerateGraph( r, c, c1, c2 );

        int n = 1 << ( r * c );
        int cost = Dijkstra( msk, n );

        int ans = ( cost == inf ) ? -1 : cost;
        cout << ans << endl;
    }

    return 0;
}