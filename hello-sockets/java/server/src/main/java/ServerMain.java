public class ServerMain {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.printf("Uso: java -jar <jar> <port>%n");
            return;
        }
        System.out.printf("Servidor en el puerto %s%n", args[0]);
        Server server = new Server(args[0]);
        server.run();
    }
}
