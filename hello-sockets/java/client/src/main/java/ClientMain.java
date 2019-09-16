import java.io.IOException;

public class ClientMain {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.printf("Uso: java -jar <jar> <port>%n");
            return;
        }
        System.out.printf("Conectando cliente a %s:%s%n", args[0], args[1]);
        try {
            Client client = new Client(args[0], args[1]);
            client.run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
