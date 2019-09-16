import java.io.IOException;
import java.net.Socket;

public class Client {
    private Socket socket;

    public Client(Socket clientSocket) {
        this.socket = clientSocket;
    }

    public void sendHello() throws IOException {
        this.socket.getOutputStream().write("hello client".getBytes());
    }

    public void recvHello() throws IOException{
        byte[] buf = new byte[13];
        this.socket.getInputStream().read(buf);
        buf[12] = 0;
        String msg = new String(buf);
        System.out.printf("Recibido %s%n", msg);
    }

    public void close() throws IOException{
        this.socket.close();
    }
}
