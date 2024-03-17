let User_num = 100;
let Washer_num = 10;

// 洗濯機を使っている人のユーザー番号
let User_ID = Array(Washer_num + 1).fill(0);

// 洗濯機の残り時間（ミリ秒単位）
let remain_time = Array(Washer_num + 1).fill(0);

// 洗濯開始時刻
let Start_time = Array(Washer_num + 1).fill(new Date());

function main() {
    while (true) {
        let AorB = prompt("AまたはBを入力してください（終了するには別の文字を入力）:");
        if (AorB === 'A') {
            let N = parseInt(prompt("ユーザーIDを入力してください:"), 10);
            let M = parseInt(prompt("洗濯機番号を入力してください:"), 10);
            let T = parseInt(prompt("洗濯時間を分単位で入力してください:"), 10);

            User_ID[M] = N;
            remain_time[M] = T * 60 * 1000; // 分からミリ秒へ変換
            Start_time[M] = new Date();
        } else if (AorB === 'B') {
            let d2 = new Date();
            let N = parseInt(prompt("ユーザーIDを入力してください:"), 10);
            let NinM = 0;

            for (let i = 1; i <= Washer_num; i++) {
                if (User_ID[i] === N) {
                    NinM = i;
                    break;
                }
            }

            if (NinM === 0) { // 自分が洗濯中でない
                for (let i = 1; i < Washer_num + 1; ++i) {
                    if (User_ID[i] === 0) {
                        alert("空き");
                    } else {
                        let t = Start_time[i].getTime() + remain_time[i] - d2.getTime();
                        alert(t + "ミリ秒");
                    }
                }
            } else { // 自分が洗濯中
                if (Start_time[NinM].getTime() + remain_time[NinM] < d2.getTime()) { // 洗濯完了
                    alert("洗濯完了");
                } else {
                    let t = Start_time[NinM].getTime() + remain_time[NinM] - d2.getTime();
                    alert(t + "ミリ秒");
                }
            }
        } else {
            break;
        }
    }
}

main();
