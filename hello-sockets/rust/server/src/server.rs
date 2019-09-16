use crate::client::Cliente;
use std::io;
use std::net::TcpListener;

#[derive(Debug)]
pub struct Server {
    listener: TcpListener
}

impl Server {
    /// Constructor
    /// Idealmente se podría usa un referencia &Read
    /// Pero no quiero hacer muy complejo el código 
    pub fn new(port: &String) -> io::Result<Server> {
        // Abro el puerto para escuchar conexiones
        let listener = TcpListener::bind(port)?;
        Ok(Server{ listener })
    }

	pub fn accept(&mut self) -> io::Result<Cliente> {
		let (mut client, _) = self.listener.accept()?;
		Ok(Cliente::new(client))
	}    
}
