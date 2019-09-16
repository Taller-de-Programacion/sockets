use std::io;
use std::net::TcpStream;
use std::io::{Read, Write};
/// Estructura que representa al cliente
pub struct Cliente{
    socket: TcpStream
}

/// Implemento los métodos del cliente
impl Cliente {
    /// Devuelvo un objeto io::Result con dos posibles resultados
    /// * `Ok(Cliente)`: el cliente está conectado correctamente
    /// * `io::Error`: ocurrió un error al conectarse 
    pub fn new(socket: TcpStream) -> Cliente {
        // Esto es equivalente a return Ok(Cliente {socket: socket})
        Cliente {socket}
    }

    /// Envía el contenido de `request` a través del socket
    pub fn enviar(&mut self, request: &String) -> io::Result<()> {
        self.socket.write_all(&request.as_bytes())?;
        Ok(())
    }

    /// Recibe la respuesta a través del socket
    pub fn recibir(&mut self) -> io::Result<(String)> {
        let mut mensaje = String::new();
        self.socket.read_to_string(&mut mensaje)?;
        Ok(mensaje)
    }
}
