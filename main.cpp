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
    char query_type;
    while(true){
        cout << "クエリタイプを入力してください" << endl;
        cout << "\tA: 洗濯開始クエリ" << endl;
        cout << "\tB: 空き状況確認クエリ" << endl;
        cout << "\tC: 洗濯状況確認&回収クエリ" << endl;
        cout << "\tそれ以外: プログラム終了" << endl;
        cin >> query_type;
        if(query_type == 'A'){
            cout << "ユーザー番号、洗濯機番号、洗濯時間(分)を空白区切りで入力してください" << endl;
            cin >> N >> M >> T;
            if(User_ID[M] != 0){
                cout << "洗濯機" << M << "は使用中です" << endl;
                continue;
            }
            User_ID[M] = N;
            remain_time[M] = (chrono::minutes)T;
            Start_time[M] = std::chrono::system_clock::now();
        }else if(query_type == 'B'){
            chrono::system_clock::time_point d2 = std::chrono::system_clock::now();
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
            cout << "ユーザー番号と洗濯機番号を空白区切りで入力してください" << endl;
            int N, M;
            cin >> N >> M;
            if(User_ID[M] == N){
                auto now = std::chrono::system_clock::now();
                if(now < Start_time[M] + remain_time[M]){
                    auto rest = Start_time[M] + remain_time[M] - now;
                    auto rest_min = std::chrono::duration_cast<std::chrono::minutes>(rest).count();
                    if(rest_min > 0){
                        cout << "残り" << rest_min << "分" << endl;
                    }else{
                        cout << "残り1分未満" << endl;
                    }
                }else{
                    User_ID[M] = 0;
                    cout << "洗濯は完了しています。洗濯物を回収しました" << endl;
                }
            }else{
                cout << "ユーザー" << N << "は洗濯機" << M << "を使用していません" << endl;
            }
        }else{
            return 0;
        }
    }
}