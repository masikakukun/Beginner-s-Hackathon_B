#include<iostream>
#include<time.h>
using namespace std;
int main(){
    srand((unsigned int)time(NULL));
    for (int i=1;i<=100;i++){
        int q = rand()%2+1;
        char query;
        if (q==1){
            query = 'A';
            int N = rand()%100+1;
            int M = rand()%10+1;
            int T = rand()%100+1;
            cout << query << " " << N << " " << M << " " << T << endl;
        }
        if (q==2){
            query = 'B';
            int N = rand()%100+1;
            cout << query << " " << N << endl;
        }
    }
    return 0;
}