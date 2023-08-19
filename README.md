# get_nex_line - gmacias-
El objetivo de este proyecto es simple: programar una función que de vuelva una línea leída de un file descriptor.
### Indice
* [Que es get_next_line?](#que-es-get_next_line)
* [Que utilizamos?](#que-utilizamos)
* [Como funciona?](#como-funciona)
* [Como utilizamos la libreria?](#como-utilizamos-la-libreria)

### Que es get_next_line?
get_next_line es un projecto de [42][1] donde creamos una función capaz de leer, linea por linea, un archivo cada vez que
se llame a la funcion.

<b>El rototipo de la función debe ser la siguiente:</b>

```C
char	*get_next_line(int fd)
```

### Que utilizamos?
En nuestro ft_printf tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     													|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 											|
| read |  Lee el contenido del archivo del sistema seleccionado.               									|


### Como funciona?

La meta es crear una libreria que contenga todo nuestro codigo para poder utilizarlo en futuros proyectos llamado: *libftprintf.a*

Para crear esta libreria seguimos los siguientes pasos:

	git clone https://github.com/gjmacias/ft_printf
	cd ft_printf
	make

Al revisar el directorio, en alguna parte encontraras la libreria: *libftprintf.a*

### Como utilizamos la libreria?

Para utilizarlo primero debes de  tener la libreria: *libftprintf.a*.
Luego debes añadirlo en el compilador, primero la ruta de libftprintf.a y luego el nombre de la libreria

`gcc archivos.c -L<ruta de libftprintf.a> -lftprintf`

-L tomara la ubicacion de la libreria<br>
-l tomara el nombre de la libreria. en este caso seran los caracteres que vegan despues de `lib` de tu libreria.

y eso seria todo!

# Quizás pueda interesarte!

### - Para ver mi progresion en 42 🌠
[AQUÍ](https://github.com/gjmacias/42BCN)

### - Mi perfil de 42 👾
[AQUÍ](https://profile.intra.42.fr/users/gmacias-)

### - Mis proyectos personales 🧐
[AQUÍ🗒️](https://github.com/gjmacias/autoproyectos)

# Contacto 📥

◦ Email: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"
