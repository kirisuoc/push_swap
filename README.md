# Push_swap

**Push_swap** es un proyecto diseñado para crear un programa en C que ordene datos utilizando un conjunto limitado de instrucciones y buscando optimizar el número de operaciones. Este desafío combina conceptos de algoritmia, gestión de memoria y manipulación de estructuras de datos (stacks).

## Características

- **Manipulación de dos stacks**: `a` y `b`.
- **Conjunto de operaciones**: Implementación de instrucciones como `sa`, `pb`, `ra`, entre otras, para ordenar los números en el stack `a`.
- **Optimización**: Generación de la secuencia de instrucciones más corta posible para lograr el orden ascendente.
- **Validaciones**: Manejo de errores como argumentos no válidos, duplicados o fuera de rango.

## Instrucciones de uso

### Compilación

1. **Compilar el proyecto**:  
   Ejecuta `make` para generar el ejecutable `push_swap`.

2. **Ejecutar el programa**:  
   Pasa una lista de números enteros como argumento para el stack `a`.  
   ```bash
   ./push_swap 2 1 3 6 5 8
### Operaciones disponibles

- **Swap**:
  - `sa`: Intercambia los dos primeros elementos del stack `a`.
  - `sb`: Intercambia los dos primeros elementos del stack `b`.
  - `ss`: Ejecuta `sa` y `sb` al mismo tiempo.

- **Push**:
  - `pa`: Mueve el primer elemento de `b` al stack `a`.
  - `pb`: Mueve el primer elemento de `a` al stack `b`.

- **Rotate**:
  - `ra`: Rota el stack `a` hacia arriba (el primer elemento pasa al final).
  - `rb`: Rota el stack `b` hacia arriba.
  - `rr`: Ejecuta `ra` y `rb` al mismo tiempo.

- **Reverse Rotate**:
  - `rra`: Rota el stack `a` hacia abajo (el último elemento pasa al inicio).
  - `rrb`: Rota el stack `b` hacia abajo.
  - `rrr`: Ejecuta `rra` y `rrb` al mismo tiempo.

### Validaciones

El programa debe gestionar los siguientes casos:

- **Sin parámetros**: No muestra nada y devuelve el control al usuario.
- **Errores de entrada**: Muestra `Error` seguido de un salto de línea en la salida estándar de errores si:
  - Algún argumento no es un número entero.
  - Algún número está fuera del rango permitido para un entero.
  - Existen números duplicados.
  - Una instrucción no es válida.

### Pruebas de rendimiento

Para validar correctamente el proyecto, deben cumplirse las siguientes métricas:

- Ordenar 100 números aleatorios en menos de **700 operaciones**.
- Ordenar 500 números aleatorios en menos de **5500 operaciones**.

Cumplir estas condiciones es necesario para aprobar el proyecto y obtener la calificación máxima.

## Parte Bonus

El bonus incluye la creación de un programa adicional llamado **checker**, que verifica si una lista de instrucciones dada ordena correctamente el stack `a` y deja vacío el stack `b`.

## Uso de checker
   ```bash
   ./push_swap 2 1 3 6 5 8
```


### Requisitos

- **Funciones autorizadas**:
  - `read`, `write`, `malloc`, `free`, `exit`.
  - Funciones personalizadas, como `ft_printf` o equivalentes.
- **Uso de libft**: Se permite el uso de la librería **libft**, que debe incluirse dentro del proyecto con su propio Makefile.
- **Makefile**: El proyecto debe incluir un Makefile que cumpla con las siguientes reglas:
  - `all`: Compila el proyecto.
  - `clean`: Elimina los archivos intermedios generados durante la compilación.
  - `fclean`: Elimina los archivos intermedios y el binario generado.
  - `re`: Limpia y recompila el proyecto desde cero.

## Licencia

Este proyecto está bajo la licencia [MIT](LICENSE).
