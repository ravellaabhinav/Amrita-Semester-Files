import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class Client
{
    public static void main(String[] args) {

        int port = 9092;

        try {
            String host = InetAddress.getLocalHost().getHostName();
            Socket client = new Socket(host, port);

            PrintWriter writer = new PrintWriter(client.getOutputStream());
            BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));

            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

            System.out.println(reader.readLine()); //read welcome message

            String message;

            while (true) {
                System.out.print("Enter message to echo or Exit to end : ");
                message = stdin.readLine();

                if (message == null || message.equalsIgnoreCase("exit"))
                    break;

                writer.println(message);
                writer.flush();
                System.out.println("Echo from server: \n"+reader.readLine());
                System.out.println(reader.readLine());
                System.out.println(reader.readLine());
            }
            client.close();

        }catch (Exception ex) {
            System.out.println("Exception: "+ex);
        }
    }
}