import java.io.*;
import java.net.*;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Client {
	public static void main(String[] args) {
		final int PORT = 3000;
		try {
			var serverSocket = new ServerSocket(PORT);
			System.out.println("サーバーがポート " + PORT + " で実行されています");

			while (true) {
				var socket = serverSocket.accept();
				//System.out.println("クライアントが接続しました: " + socket);

				// クライアントからのデータを受信
				BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				var message = input.readLine();
				//System.out.println("クライアントからのメッセージ: " + message);
				//現在時刻を表示
				var sdf = new SimpleDateFormat("HH:mm:ss");
				System.err.println(sdf.format(new Date())+"洗濯機が空きました。");

				// クライアントにレスポンスを送信
				var output = new PrintWriter(socket.getOutputStream(), true);
				output.println("サーバーからのレスポンス: Hello from Java Server!");

				// クライアントとの接続を閉じる
				socket.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}