mod client;

use client::Cliente;
use std::io;
use std::env;

const HOST_ARG: usize = 1;
const PORT_ARG: usize = 2;

fn main() -> io::Result<()> {
    // El equivalente a sys.argv
    let args: Vec<String> = env::args().collect();
    if args.len() < 3 {
        println!("Uso:\n./client <direccion> <puerto>");
        // Corto la ejecución
        return Ok(());
    }

    let host_url = format!("{}:{}", &args[HOST_ARG], &args[PORT_ARG]);

    println!("Conectando {}", msg);

    let mut client = Cliente::new(&host_url)?;
    let msg = "hello server".to_string();
    println!("Enviado {}", msg);
    // Los signos de pregunta son formas cortas de
    // Si el método devuelve un error, retornar el error.
    // Si el método devuelve Ok, desenvolver el contenido dentro de ese ok.
    client.enviar(&msg)?;
    let response = client.recibir()?;
    println!("Recibido {}", response);
    Ok(())
}
