#include<iostream>
#include<time.h>
#include<chrono>
#include<unistd.h>
#include<fstream>
using namespace std;

int main(){
    ofstream writing_file;
    string filename ="query.txt";
    writing_file.open(filename, std::ios::out);
    srand((unsigned int)time(NULL));
    for (int i=1;i<=100;i++){
        int q = rand()%3+1;
        char query;
        if (q==1){
            query = 'A';
            int N = rand()%100+1;
            int M = rand()%10+1;
            int T = rand()%100+1;
            writing_file << query << endl; 
            writing_file << N << " " << M << " " << T << endl;
        }
        if (q==2){
            query = 'B';
            writing_file << query << endl;        
        }
        if (q==3){
            query ='C';
            writing_file << query << endl;
            int N = rand()%100+1;
            int M = rand()%10+1;
            writing_file << N << M << endl;
        }
        int t = rand()%10+1;
        sleep(t);
    }
    return 0;
}
