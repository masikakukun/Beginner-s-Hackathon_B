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
    vector<int> User_ID(Washer_num+1);//洗濯機を使っている人のユーザー番号
    vector<chrono::minutes> remain_time(Washer_num+1);//洗濯機の残り時間(洗濯時間)
    vector<chrono::system_clock::time_point> Start_time(Washer_num+1);
    chrono::minutes time_ahead = chrono::minutes{0};
    char query_type;
    while(true){
        cerr << "クエリタイプを入力してください" << endl;
        cerr << "\tA: 洗濯開始クエリ" << endl;
        cerr << "\tB: 空き状況確認クエリ" << endl;
        cerr << "\tC: 洗濯状況確認&回収クエリ" << endl;
        cerr << "\tD: 時間進行クエリ" << endl;
        cerr << "\tそれ以外: プログラム終了" << endl;
        cin >> query_type;
        if(query_type == 'A'){
            cerr << "ユーザー番号、洗濯機番号、洗濯時間(分)を空白区切りで入力してください" << endl;
            int N, M, T;
            cin >> N >> M >> T;
            assert(1 <= N && N <= User_num && 1 <= M && M <= Washer_num && 1 <= T && T <= 1000);
            if(User_ID[M] != 0){
                cout << "洗濯機" << M << "は使用中です" << endl;
            }else{
                User_ID[M] = N;
                remain_time[M] = chrono::minutes{T};
                Start_time[M] = std::chrono::system_clock::now() + time_ahead;
                cout << "ユーザー" << N << "が洗濯機" << M << "を" << T << "分間使い始めました。" << endl;
            }
        }else if(query_type == 'B'){
            chrono::system_clock::time_point d2 = std::chrono::system_clock::now() + time_ahead;
            for(int i = 1; i < Washer_num+1; ++i){
                if(User_ID[i] == 0){
                    cout << "洗濯機" << i << ":空き" << endl;
                }else{
                    if(d2 < Start_time[i] + remain_time[i]){
                        auto t = Start_time[i] + remain_time[i] - d2;
                        auto t_minutes = std::chrono::duration_cast<std::chrono::minutes>(t).count();
                        if(t_minutes > 0){
                            cout << "洗濯機" << i << ":(使用中 残り" << t_minutes << "分)" << endl;
                        }else{
                            cout << "洗濯機" << i << ":(使用中 残り1分未満)" << endl;
                        }
                    }else{
                        cout << "洗濯機" << i << ":(洗濯後未回収)" << endl;
                    }
                }
            }
        }else if(query_type == 'C'){
            cerr << "ユーザー番号と洗濯機番号を空白区切りで入力してください" << endl;
            int N, M;
            cin >> N >> M;
            assert(1 <= N && N <= User_num && 1 <= M && M <= Washer_num);
            if(User_ID[M] == N){
                auto now = std::chrono::system_clock::now() + time_ahead;
                if(now < Start_time[M] + remain_time[M]){
                    auto rest = Start_time[M] + remain_time[M] - now;
                    auto rest_min = std::chrono::duration_cast<std::chrono::minutes>(rest).count();
                    if(rest_min > 0){
                        cout << "ユーザー" << N << "の洗濯機" << M << "は" << "残り" << rest_min << "分" << endl;
                    }else{
                        cout << "ユーザー" << N << "の洗濯機" << M << "は残り1分未満" << endl;
                    }
                }else{
                    User_ID[M] = 0;
                    cout << "ユーザー" << N << "の洗濯機" << M << "は洗濯完了しています。洗濯物を回収しました" << endl;
                }
            }else{
                cout << "ユーザー" << N << "は洗濯機" << M << "を使用していません" << endl;
            }
        }else if(query_type == 'D'){
            cerr << "進めたい時間(分)を入力してください" << endl;
            int t;
            cin >> t;
            assert(t >= 0);
            time_ahead += chrono::minutes{t};
            cout << "時間を" << t << "分進めました。" << endl;
        }else{
            return 0;
        }
        cout << endl;
    }
}