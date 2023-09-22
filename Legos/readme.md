El programa se usa por medio de una matriz
Se ingresan los datos de esta manera:
{{nombre, tipo de pieza, cantidad de piezas, cantidad de objetos}}
Los objetos son los cuartos, cocinas, etc...
Las piezas son paredes y demás

Orden-------------
El orden de construcción es:
-Cimientos-Cuartos-Cocina-Cielo raso- Techo-Terraza-Piscina

Principios--------
El programa utiliza una clase llamada lista, la cual tiene métodos de clases virtuales, las cuales se llaman "Stack" y "Queue", gracias a estas clases se pueden usar métodos de pilas y colas para llevar control de la construcción

También se tiene un archivo.h llamado Objetos, acá se encuentran las clases de cada parte de la casa con sus metodos y variables para validaciones

El archivo Node.h se encarga de gestionar los espacios en la lista ya que es una lista enlazada