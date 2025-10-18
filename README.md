# Guardador de Vacas

Este programa tiene la función de guardar dos tipos de datos relacionados con las vacas de una granja:  

1. **Un número entero**: Representa la cantidad de litros de leche que produce cada vaca al mes.  
2. **Un string**: Corresponde al nombre de la respectiva vaca.  

El propósito principal es tener un mejor control y orden sobre la eficiencia de las vacas, permitiendo identificar cuáles producen más leche y cuáles producen menos lo cual facilita su ordenamiento de manera más rápida, clara y visual.  

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

## SICT0302: Toma de decisiones

Se eligió el método de Merge Sort para ordenar los elementos tanto en orden ascendente como descendente porque:  
- Es más eficiente en promedio que algoritmos simples como Bubble Sort o Insertion Sort, ya que su complejidad es O(n log n).
- Merge Sort mantiene una complejudad de tiempo estable incluso con grandes cantidades de datos o cuando los elementos están muy desordenados.
- Divide la lista en partes más pequeñas y luego las combina de forma ordenada, lo que asegura que el resultado final siempre esté correctamente ordenado sin importar el estado inicial de los datos.
