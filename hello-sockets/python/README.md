# Servidor Hola mundo Python

Servidor "Hola mundo" en python. Espera a que se conecte un cliente y una vez que se conecta, lee 12 bytes del socket.
Notar que tiene primitivas muy similares a las de C

Puerto debe ser numérico.


## Ejecución

~~~{.bash}
python3 server.py <puerto>
~~~

Ejemplo

~~~{.bash}
python3 server.py 8080
~~~

# Cliente Hola mundo Python

## Ejecución

~~~{.bash}
python3 client.py <host> <puerto>
~~~

Ejemplo

~~~{.bash}
python3 client.py localhost 8080
~~~

