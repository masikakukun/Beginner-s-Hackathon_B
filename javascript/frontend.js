document.title="フロントエンド"

//洗濯機の数
const washer_num=6

//洗濯機の空き状況
var washer_status=new Array(washer_num);

//空き状況を取得したい
washer_status.fill("0");
washer_status[0]="10";
console.log(washer_status);

//const socket = new WebSocket('ws://サーバーのアドレス');


//それぞれの洗濯機の空き状況
for(let i=0;i<washer_num;i++){
	if (washer_status[i]=="0"){
	document.write("<p>洗濯機"+(i+1)+":"+"空き"+"</p>");
	}else {
	document.write("<p>洗濯機"+(i+1)+":"+"使用中 残り"+washer_status[i]+"分"+"</p>");
	}
}

//更新ボタンを押したときの処理
function onRefresh(){
	//ページをリロード
	location.reload();
	alert("更新しました")
}