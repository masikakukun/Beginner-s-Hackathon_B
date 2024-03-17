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
    vector<chrono::minutes> remain_time(Washer_num+1);//洗濯機の残り時間(洗濯時間)
    vector<chrono::system_clock::time_point> Start_time(Washer_num+1);


    char AorB;
    cin >> AorB;
    if(AorB == 'A'){
        cin >> N >> M >> T;
        User_ID[M] = N;
        remain_time[M] = (chrono::minutes)T;
        Start_time[M] = std::chrono::system_clock::now();
    }else{

        chrono::system_clock::time_point d2 = std::chrono::system_clock::now(); 

        cin >> N;
        int NinM = 0;
        for (int i=1;i<=Washer_num;i++){
            if (User_ID[i] == N){
                NinM = i;
                break;
            }
        }
        if(NinM == 0){//自分が洗濯中でない
         for(int i = 1; i < Washer_num+1; ++i){
            if(User_ID[i] == 0){
                cout << "空き" << endl;
            }else{

                auto t = (Start_time[i] + remain_time[i] - d2);
                auto t_minutes = std::chrono::duration_cast<std::chrono::minutes>(t).count();
                cout << t_minutes<<" (minutes)" << endl;
            }
         }

        }else{//自分が洗濯中

            if (Start_time[NinM] + remain_time[NinM]  < d2){  //d1:洗濯開始時刻　d2:現在の時刻
                cout << "洗濯完了" << endl;
            }
            else {

                auto t = (Start_time[NinM] + remain_time[NinM] - d2);
                auto t_minutes = std::chrono::duration_cast<std::chrono::minutes>(t).count();
                cout << t_minutes<<" (minutes)" << endl;
            }        
        }
    }
}