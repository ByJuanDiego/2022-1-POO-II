# Task #3: Libreria Estandar
**course:** Programación III  
**unit:** 2  
**cmake project:** prog3_unit2_standar_library_v2022_1

## Instructions
Subir a gradescope los siguientes archivos:
- `P1.h` y `P1.cpp`
- `P2.h` y `P2.cpp`
- `P3.h` y `P3.cpp`
- `P4.h` y `P4.cpp`
- `P5.h` y `P5.cpp`
- `P6.h` y `P6.cpp`
- `P7.h` y `P7.cpp`
- `P8.h` y `P8.cpp`
- `P9.h` y `P9.cpp`

## Question #1 - split_range (2 points)

Generar una función template `split_range`, que reciba como parámetros un contenedor y un número `n` y permita dividir el contenedor en `n` contenedores, si el valor `n` no es múltiplo del tamaño del contenedor, los ítems restantes de la división deberán ser almacenados en el último contenedor. El resultado o valor de retorno deberá ser un contenedor que contenga los contenedores devueltos, siendo vector el contenedor por defecto, el template tendrá la posibilidad de personalizar en contenedor de resultado.

**Use Case:**
```cpp
dequeue<int> v1 = {1, 2, 3, 4, 5, 6, 7};
auto resultado = split_range(v1, 3};
    // resultado[0] = {1, 2};
    // resultado[1] = {3, 4};
    // resultado[2] = {5, 6, 7};
 ```

## Question #2 - sum_range (2 points)

Escribir una función template `sum_range` que permita la suma de los valores de 2 contenedores. Si uno de los contenedores es de menor tamaño, el contenedor de menor tamaño se sumará repetidamente con otro contenedor hasta completar el tamaño del mayor.

**Use Case #1:**
```cpp
vector<int> v1 = {1, 3, 4};
vector<int> v2 = {4, 5, 6};
auto v3 = sum_range(v1, v2}; // {5, 8, 10}
```
**Use Case #2:**
```cpp
list<int> v1 = {1, 2, 3, 4, 5};
list<int> v2 = {10, 20};
auto v3 = sum_range(v1, v2}; // {11, 22, 13, 24, 15}
```
## Question #3 - delete_range (2 points)

Escribir una función template `delete_items` que permita eliminar un valor específico o una lista de valores de un contenedor secuencial:

**Use Case #1:**
```cpp
vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v3 = delete_range(v1, 1); // {3, 4, 3, 2, 3, 4, 6, 5}
```
**Use Case #2:**
```cpp
list<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v3 = delete_range(v1, {1, 4});	 // {3, 3, 2, 3, 6, 5}
```

## Question #4 - delete_duplicated (2 points)

Escribir una función template `delete_duplicated` que permita eliminar todos los valores duplicados:

**Use Case #1:**
```cpp
vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5}; 
auto v2 = delete_duplicated(v1);        // {1, 3, 4, 2, 6, 5}
```
**Use Case #2:**
```cpp
list<int> v3 = {1, 1, 1, 1, 3, 2, 2, 2, 2, 5}; 
auto v4 = delete_duplicated(v3);	    // {1, 3, 2, 5}
```


## Question #5 - unpack (2 points)

La librería estándar de C++ brinda un contenedor simple conocido como `std::tuple`, que permite almacenar valores de diferente tipo, ejemplo:
```cpp
std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
```
El acceso a sus valores es por medio de la función template `std::get` cuyo parámetro de template se utiliza para identificar la posición de alguno de sus valores.
```cpp
std::cout << std::get<0>(tup1) << endl; // 1321
std::cout << std::get<1>(tup1) << endl; // Jose
std::cout << std::get<2>(tup1) << endl; // Perez
std::cout << std::get<3>(tup1) << endl; // 1.68
```
Lenguajes como python brindan un mecanismo conocido como unpack que permita asignar valores de un contenedor a variable con nombres significativos. Por ejemplo en python:
```python
tup1 = (1321, 'Jose', 'Perez', 1.68)
id, first_name, last_name, height = tup1
print(id, name, last_name, height)
```

Diseñar y desarrollar la función template `unpack` que permita desempaqueta los valores de una tupla en variables individuales.

**Use Case:**
```cpp
std::tuple<int, string, string, double> tup1 = {1321, "Jose", "Perez", 1.68};
int key; 
string first_name; 
string last_name; 
double height;
unpack(key, first_name, last_name, height) = t1;
std::cout << key <<  " "<< first_name << last_name << height << endl;
```

## Question #6 - zip (2 points)
En python existe una función denominada `zip` que permite recibir un número variado de contenedores del mismo tipo y agrupar los valores de una misma fila generando tuplas por cada fila con los valores de cada contenedor.
Generar un function template similar, pero en vez de tuplas generé un `std::vector` con los valores correspondientes de cada fila.

**Use Case #1:**
```cpp
std::list<int> v1 = { 11, 12, 13 };
std::list<int> v2 = { 21, 22, 23 };
std::list<int> v3 = { 31, 32, 33 };
auto result = zip(v1, v2, v3);
// result sería del tipo: list<vector<int>>
for (const auto& row : result) {
    for (const auto& value : row)
        std::cout << value << " ";
    std::cout << std::endl;
}
// lo impreso sería:
//	11 21 31
//	12 22 32
//	13 23 33
```

## Question #7 - rotate_range (2 points)
Escribir una función template `rotate_range` que permite rotar los valores de un contenedor una cantidad determinada, esta función recibe 2 parámetros un contenedor, y un valor entero, en caso sea positivo los valores rotará hacia la derecha, en caso negativo los valores rotaran a la izquierda:

**Use Case #1:**
```cpp
vector<int> v1 = {1, 2, 3, 4, 5, 6}; 
auto v3 =rotate_range(v1, 2);   		// {5, 6, 1, 2, 3, 4}
```
**Use Case #2:**
```cpp
list<int> v1 = {10, 20, 30, 40, 50}; 
auto v3 = rotate_range(v1, -2);	 	// {30, 40, 50, 10, 20}
```

## Question #8 -  (2 points)

Escribir una función `filter_codes` que lea de un archivo una lista de códigos y que retorne de forma ordenada todos aquellos códigos que empiecen un carácter, el contenedor de retorno por default es un `std::vector` pero podrá seleccionarse cualquier otro repositorio secuencial (`std::deque`, `std::list` o `std::forward_list`).

**NOTA:** Los códigos están conformados por 4 letras en minúsculas iniciales y 3 digito de 0 a 9.

**Use Case #1:**
```cpp
vector<string> codes = filter_codes('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #2:**
```cpp
auto codes = filter_codes<list>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #3:**
```cpp
auto codes = filter_codes<deque>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

**Use Case #4:**
```cpp
auto codes = filter_codes<forward_list>('data.txt', 'c'); 
    // Si el archivo data.txt tuviera los siguientes códigos: "cabd123", "abxz345", "cdbe546", "defz918"
    // codes almacenaría ordenadamente: "cabd123", "cdbe546"
```

## Question #9 - TO BE DEFINED  (4 points)
