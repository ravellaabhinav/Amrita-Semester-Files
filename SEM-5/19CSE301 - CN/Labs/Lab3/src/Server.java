import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server
{
    public static void main(String[] args)
    {
        int port = 9092;

        try {
            ServerSocket server = new ServerSocket(port);

            while(true) {
                System.out.println("Waiting for clients on port " + port);
                Socket client = server.accept();

                System.out.println("Got connection from "+client.getInetAddress()+":"+client.getPort());

                BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));
                PrintWriter	writer = new PrintWriter(client.getOutputStream());

                writer.println("Welcome to my server");
                writer.flush();

                String	message = reader.readLine();

                while (!(message == null || message.equalsIgnoreCase("exit"))) {
                    System.out.println("MessageReceived: "+message);
                    message = message.toLowerCase();
                    int a=0, b=0, c=0;
                    for (int i = 0; i<message.length(); i++)
                    {
                        if(message.charAt(i)=='a'||message.charAt(i)=='e'||message.charAt(i)=='i'||message.charAt(i)=='o'||message.charAt(i)=='u')
                        {
                            a = a+1;
                        }
                        if(message.charAt(i)==' ')
                        {
                            c = c+1;
                        }
                    }
                    {
                        writer.println("Vowels in message: " + a);
                        writer.println("Number of chars: "+message.length());
                        writer.println("Number of words: " + (c+1));
                        writer.flush();
                    }


                    message = reader.readLine();
                }
                client.close();
            }
        } catch(Exception ex) {
            System.out.println("Connection error: "+ex);
        }
    }
}