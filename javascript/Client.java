import java.io.*;
import java.net.*;
import java.util.Date;

public class Client {
    public static void main(String[] args) {
        final int PORT = 3000;

        try {
            ServerSocket serverSocket = new ServerSocket(PORT);
            System.out.println("サーバーがポート " + PORT + " で実行されています");

            while (true) {
                Socket socket = serverSocket.accept();
                //System.out.println("クライアントが接続しました: " + socket);

                // クライアントからのデータを受信
                BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String message = input.readLine();
                //System.out.println("クライアントからのメッセージ: " + message);
                //現在時刻を表示
                System.out.println("現在時刻: "+new Date());
                System.err.println("洗濯機が空きました。");

                // クライアントにレスポンスを送信
                PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
                output.println("サーバーからのレスポンス: Hello from Java Server!");

                // クライアントとの接続を閉じる
                socket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}