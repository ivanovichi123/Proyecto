# Guardador de Vacas

Este programa tiene la función de guardar dos tipos de datos relacionados con las vacas de una granja:  

1. **Un número entero**: Representa la cantidad de litros de leche que produce cada vaca al mes.  
2. **Un string**: Corresponde al nombre de la respectiva vaca.  

El propósito principal es tener un mejor control y orden sobre la eficiencia de las vacas, permitiendo identificar cuáles producen más leche y cuáles producen menos lo cual facilita su ordenamiento de manera más rápida, clara y visual.  

## SICT0301: Evalúa los componentes

Se utiliza el algoritmo Quick Sort para ordenar los litros de leche de las vacas de forma ascendente y descendente.  

### Análisis de complejidad de Quick Sort:
- **Caso promedio:**  
  - Complejidad temporal **O(n log n)**: El pivote suele dividir la lista en partes iguales lo que hace que el ordenamiento sea rápido y eficiente.  

- **Mejor caso:**  
  - Complejidad temporal **O(n log n)**: El pivote siempre divide la lista exactamente a la mitad logrando la mayor eficiencia posible.  

- **Peor caso:**  
  - Complejidad temporal **O(n^2)**: El pivote divide mal osea que este termina siempre al inicio o al final, por lo que el ordenamiento se repite muchas veces y se vuelve más lento.  

Quick Sort es eficiente en la mayoría de los casos debido a la complejidad que tiene, lo que lo hace util para ordenar datos.  

## SICT0302: Toma de decisiones

Se eligió el método de Quick Sort para ordenar los elementos tanto en orden ascendente como descendente porque:  
- Es más eficiente en promedio que otros algoritmos simples como Bubble Sort o Insertion Sort.  
- Quick Sort puede ordenar muchos datos rápidamente sin que el programa se vuelva lento.
- Quick Sort no necesita copiar toda la lista ya que solo reorganiza los elementos en su lugar, lo cual hace que sea eficiente para ordenar datos.
