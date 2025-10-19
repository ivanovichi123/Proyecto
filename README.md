# Organizador de granja de vacas

Este programa tiene la función de guardar dos tipos de datos relacionados con las vacas de una granja:  

1. **Un número entero**: Representa la cantidad de litros de leche que produce cada vaca al mes.  
2. **Un string**: Corresponde al nombre de la respectiva vaca.

El propósito principal es tener un mejor control y orden sobre la eficiencia de las vacas, permitiendo identificar cuáles producen más leche y cuáles producen menos lo cual facilita su ordenamiento de manera más rápida, clara y visual.  

El programa también permite guardar un conjunto de clientes en una fila, que es una estructura de datos de tipo queue. Cada cliente tiene dos valores asociados:

1. **Un string**: Representa el nombre del cliente.
2. **Un número entero**: Representa el rango de litros de leche que desea comprar de la vaca

En el programa el usuario es capaz de hacer 9 funciones:
1. **Ver informacion**: Muestra la lista de los litros y nombre de las vacas.
2. **Ordenar datos de manera ascendente**: Ordena los litros de manera ascendente.
3. **Ordenar datos de manera descendente**: Ordena los litros de manera descendente
4. **Agregar otra vaca**: Agrega los litros y nombre de una nueva vaca a sus respectivas listas.
5. **Quitar una vaca**: Quita una vaca de la lista de litros y nombre.
6. **Ver proximo cliente**: Muestra al cliente que esta al frente de la fila.
7. **Ver fila de clientes**: Muestra a todos los clientes de la fila.
8. **Vender vaca**: Quita una vaca y un cliente de sus respectivas listas, simpre y cuando los litros de la vaca correspondan al rango del cliente.
9. **Abrir tienda**: Agrega 5 clientes a la fila.

## SICT0301: Evalúa los componentes

Se utiliza el algoritmo Merge Sort para ordenar los litros de leche de las vacas de forma ascendente y descendente.  

### Análisis de complejidad de Merge Sort:
- **Caso promedio:**  
  - Complejidad temporal **O(n log n)**: En promedio Merge Sort divide el arreglo en mitades iguales y combina los resultados en cada nivel de la recursión manteniendo un rendimiento no tan malo.

- **Mejor caso:**  
  - Complejidad temporal **O(n log n)**: A pesar de haber un arreglo ya está ordenado Merge Sort sigue dividiendo y combinando las mitades por lo que su complejidad no mejora.

- **Peor caso:**  
  - Complejidad temporal **O(n log n)**:): Aunque el arreglo esté completamente desordenado Merge Sort siempre realiza las mismas divisiones y combinacioes lo cual hace que mantenga su tiempo de ejecución estable. 

Merge Sort es eficiente en todos los casos debido a la complejidad que tiene, lo que lo hace util para ordenar datos.  

### Análisis de complejidad de Queue:

- **Acceso:**
  - Complejidad temporal **O(n)**:  Para acceder a un elemento específico dentro de la cola es necesario recorrerla desde el frente, ya que no se puede acceder directamente a una posición intermedia.

- **Búsqueda:**
  - Complejidad temporal **O(n)**:  Para encontrar un elemento específico se debe revisar cada uno desde el frente hasta el final de la cola.

- **Inserción:**
  - Complejidad temporal **O(1)**:  Agregar un nuevo elemento al final de la cola no requiere recorrerla, por lo que la operación es constante.

- **Eliminación:**
  - Complejidad temporal **O(1)**:  Quitar el primer elemento de la fila también es inmediato, ya que se elimina directamente el primero.

La estructura de datos Queue es eficiente para manejar información en orden FIFO: First In, First Out.  


## SICT0302: Toma de decisiones

Se eligió el método de Merge Sort para ordenar los elementos tanto en orden ascendente como descendente porque:  
- Es más eficiente en promedio que algoritmos simples como Bubble Sort o Insertion Sort, ya que su complejidad es O(n log n).
- Merge Sort mantiene una complejudad de tiempo estable incluso con grandes cantidades de datos o cuando los elementos están muy desordenados.
- Divide la lista en partes más pequeñas y luego las combina de forma ordenada, lo que asegura que el resultado final siempre esté correctamente ordenado sin importar el estado inicial de los datos.

Se eligió la estructura de datos lineal de tipo queue para manejar a los clientes porque:
- Es congruente con la realidad, ya que el primer cliente que llega es el primero en ser atendido.
- Facilita agregar nuevos clientes al final de la fila y retirar a los ya atendidos del inicio de forma eficiente.
- Representa de manera clara y lógica el flujo natural de espera en una fila.
