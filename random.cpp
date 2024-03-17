#include<iostream>
#include<time.h>
#include<chrono>
#include<unistd.h>
#include<fstream>
#include<vector>
using namespace std;


int main(){
    vector<pair<int, int>> stock;
    ofstream writing_file;
    string filename ="query.txt";
    writing_file.open(filename, std::ios::out);
    srand((unsigned int)time(NULL));
    for (int i=1;i<=100;i++){

        int q = rand()%4+1;
        char query;
        if (q==1){
            query = 'A';
            int N = rand()%100+1;
            int M = rand()%10+1;
            int T = rand()%100+1;
            writing_file << query << endl; 
            writing_file << N << " " << M << " " << T << endl;
            stock.push_back(make_pair(N,M));
        }
        if (q==2){
            query = 'B';
            writing_file << query << endl;        
        }
        if (q==3){
            query ='C';
            writing_file << query << endl;
            int n = stock.size();
            if (n!=0){
            int p = rand()%n;
            int N = stock[p].first;
            int M = stock[p].second;
            stock.erase(stock.begin()+p);
            writing_file << N << " " << M << endl;
            }  
        }
        
        if (q==4){
            query = 'D';
            int T = rand()%100+1;
            writing_file << query << endl;
            writing_file << T << endl;

        }
        int t = rand()%10+1;
        //sleep(t);
    }
    return 0;
}
