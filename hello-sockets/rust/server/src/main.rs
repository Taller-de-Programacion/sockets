mod client;
mod server;

use server::Server;
use std::io;
use std::env;

const PORT_ARG: usize = 1;

fn main() -> io::Result<()> {
    // El equivalente a sys.argv
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        println!("Uso:\n./server <puerto>");
        // Corto la ejecución
        return Ok(());
    }

    let port_string = format!("127.0.0.1:{}", args[PORT_ARG].to_string());

    println!("Conectando {}", port_string);

    // Los signos de pregunta son formas cortas de
    // Si el método devuelve un error, retornar el error.
    // Si el método devuelve Ok, desenvolver el contenido dentro de ese ok.
    let mut server = Server::new(&port_string)?;

	let mut client = server.accept()?;    

    let msg = "hello server".to_string();
    println!("Enviado {}", msg);
    let mut response = client.recibir()?;
    client.enviar(&msg)?;
    println!("Recibido {}", response);
    Ok(())
}
