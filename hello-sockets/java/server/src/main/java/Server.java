import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private String port;
    private ServerSocket socket;
    Server(String port) {
        this.port = port;
    }

    public void run() {
        try {
            bind();
            Client client = accept();
            client.recvHello();
            client.sendHello();
            client.close();
            close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void bind() throws IOException {
        int nPort = Integer.valueOf(this.port);
        this.socket = new ServerSocket(nPort);
    }

    private Client accept() throws IOException {
        Socket clientSocket = this.socket.accept();
        return new Client(clientSocket);
    }

    private void close() throws IOException{
        this.socket.close();
    }
}
