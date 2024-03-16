#include <iostream>
#include <chrono>

int main(){
    std::chrono::system_clock::time_point p = std::chrono::system_clock::now(); // 現在時刻を取得
    std::time_t t = std::chrono::system_clock::to_time_t(p); // 出力のためにtime_t型に変換
    std::cout << "p = " << std::ctime(&t) << std::endl;

    std::chrono::minutes d{50}; // 50分という時間間隔を表す
    std::chrono::system_clock::time_point q = p + d;
    std::time_t u = std::chrono::system_clock::to_time_t(q);
    std::cout << "q = " << std::ctime(&u) << std::endl; // 50分後の時刻が出力される

    if(p < q) std::cout << "p < q" << std::endl; // 比較演算子も使える
    else std::cout << "p >= q" << std::endl;
}