document.title="バックエンド(共有端末)"

//洗濯機の数
const washer_num=6
//時刻
var global_time=0;//これをフロントエンドに送信したい
const time_interval=60;//1分毎に時刻が1増える

//洗濯機の空き状況
var washer_status=new Array(washer_num);//これをフロントエンドに送信したい
//空き状況を設定する
//0なら空き、それ以外なら残り時間
washer_status.fill(0);

onRefresh();

//1分毎に時刻を更新
setInterval(time_tick,time_interval*1000);

//更新処理
function onRefresh(){
	//時刻を表示
	var time_content=document.getElementById("global_time")
	time_content.innerHTML="時刻:"+global_time;
	//洗濯機の空き状況を表示
	let unused_count=0;
	for (let i=0;i<washer_num;i++){
		var id="l"+(i+1);
		var button=document.getElementById(id);
		var status_span=document.getElementById(id+"_status");
		//洗濯機が空いている場合
		if (washer_status[i]==0){
			//ボタンを有効化
			button.disabled=false;
			//ボタンの背景を緑に
			button.style.backgroundColor="lightgreen";
			//ボタンの右に空き状況を表示
			status_span.innerHTML="空き";
		}else{
			//ボタンを無効化
			button.disabled=true;
			//ボタンの背景を赤に
			button.style.backgroundColor="lightcoral";
			//ボタンの右に残り時間を表示
			status_span.innerHTML="使用中:残り"+washer_status[i]+"分";
		}
	}
}

//洗濯機ボタンを押したときの処理
function LaundryButton(){
	//ボタンのIDを取得
	//TODO: eventは非推奨
	var id=event.target.id;
	//何分洗濯するかを入力させる
	var time=prompt("何分洗濯しますか？");
	//入力がキャンセルされた場合
	if (time==null){
		return;
	}
	//入力が数字でない場合
	if (isNaN(time)){
		alert("数字を入力してください");
		return;
	}
	//入力が0以下の場合
	if (time<=0){
		alert("1分以上を入力してください");
		return;
	}
	//正しく入力されたとき 空き状況を更新
	washer_status[parseInt(id[1])-1]=time;
	onRefresh();
}

//時刻を1進める
function time_tick(){
	global_time++;
	for (let i=0;i<washer_num;i++){
		if (washer_status[i]!=0){
			washer_status[i]--;
			if (washer_status[i]==0){
				sendMessage("洗濯機"+(i+1)+"が空きました");
			}
		}
	}
	//新しいデータを書き込む
	onRefresh();
}

function sendMessage(msg) {
    const message = "msg";
    const xhr = new XMLHttpRequest();
    xhr.open("POST", "http://localhost:3000", true);
    xhr.setRequestHeader("Content-Type", "text/plain");
    xhr.onreadystatechange = function() {
        if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
            document.getElementById("response").innerText = xhr.responseText;
        }
    };
    xhr.send(message);
}