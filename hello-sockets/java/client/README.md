# Servidor Hola mundo Java

Servidor "Hola mundo" en java. Espera a que se conecte un cliente y una vez que se conecta, lee 12 bytes del socket.

## Compilación

Ejecutar `gradle build` para compilar.

## Ejecución

Para ejecutar el jar generado, ejecutar

~~~{.bash}
java -jar build/libs/server.jar <puerto>
~~~

Ejemplo

~~~{.bash}
java -jar build/libs/server.jar 8080
~~~

