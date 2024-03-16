#include <bits/stdc++.h>
#include <chrono>
using namespace std;
//#include <atcoder/all> 
//using namespace atcoder;
#define repp(i,l,r)for(int i=(l);i<(r);i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (long long i = 0; i < (long long)(n); i++)
const int INF = 1e9;
#define MOD 1000000007
using ll = long long;
using ld = long double;
//const ll INF = 1e18;
//using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<char, char>;
using PPP = pair<long long, long long>;

int User_num = 100;
int Washer_num = 10;

int main() {
    int N, M, T;

    vector<int> User_ID(Washer_num+1);//洗濯機を使っている人のユーザー番号
    vector<int> remain_time(Washer_num+1);//洗濯機の残り時間(洗濯時間)

    char AorB;
    cin >> AorB;
    if(AorB == 'A'){
        cin >> N >> M >> T;
        User_ID[M] = N;
        remain_time[M] = T;

    }else{
        cin >> N;
        
        if(d1 + remain_time[] - d2 < 0){//自分が洗濯中でない
         for(int i = 1; i < Washer_num+1; ++i){
            if(User_ID[i] == 0){
                cout << "空き" << endl;
            }else{
                cout << d1 + remain_time[i] - d2 << endl;
            }
         }
        }else{//自分が洗濯中
        cout << d1 + remain_time[N] - d2 << endl;
        }
    }


}