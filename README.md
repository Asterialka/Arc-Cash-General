# ARC Cache

Цель проекта: реализация алгоритма ARC-кэширования на языке Си

## Описание

ARC (Adaptive Replacement Cache) - это алгоритм кэширования, используемый для эффективного управления кэшем данных.

В основе ARC лежит идея комбинирования двух алгоритмов кэширования - LRU (Least Recently Used) и LFU (Least Frequently Used). ARC делит кэш на два списка: список LRU и список LFU. Когда требуется заменить элемент в кэше, ARC анализирует попадания и промахи кэша и адаптивно решает, какой элемент следует заменить.

ARC использует два параметра: p и c. Параметр p отвечает за размер LRU-списка, а параметр c - за размер LFU-списка. Алгоритм автоматически адаптирует эти параметры в соответствии с изменениями в образце доступа к данным.


## Структура проекта

- **list.cpp** Реализация двусвязного списка
- **hash.cpp**: Реализация хэш-таблицы
- **cash.cpp**: Главный файл, содержащий реализацию алгоритма.

В соответствующих папках hash_tests и list_tests содержатся тесты для проверки работоспособности двусвязного списка и хэш-таблицы

## Описание основных функций алгоритма ARC:

'init_cache'
```cpp
cache_ARC* init_cache(int size_of_cache);
```
Функция инициализирует кэш алгоритма ARC с заданным размером. Создает четыре пустых списка T1, T2, B1, B2 и хеш-таблицу для хранения кэша.

'ARC'

```cpp
void ARC(cache_ARC *ARC, long long int page);
```
Функция реализует алгоритм ARC для добавления страницы в кэш. Принимает указатель на кэш ARC и номер страницы page.

'replace'

```cpp
void replace(cache_ARC *arc, long long int page);
```
Функция реализует операцию замены в алгоритме ARC. Принимает указатель на кэш arc и номер страницы page.




## Требования к среде

Проект компилириуется на Windows и Linux на gcc --version: 13.1.0

## Как использовать

скачайте файлы cash.cpp, hash.cpp, list.cpp и соответствующие header-файлы. 
настройте makefile для запуска программы или
используйте компиляцию из командной строки
```bash
g++ -o cash cash.cpp
``` 
и запустите файл cash.exe. 

## Зависимые объекты
GCC compilier, Makefile для сборки
//здесь будет код 

## Как запустить тесты
Убедитесь, что файлы находятся в одной директории и перейдите к соответствующему узлу cd, где хранятся файлы проекта

Тесты хэш-таблицы: скачайте файлы из папки hash_tests: hash_test.cpp и hash_test.h
и основные файлы hash.cpp и hash.h. Затем скомпилируйте совместно:
```bash
g++ -o hash_program hash.cpp hash_tests.cpp
```
запустите исполняемый файл hash_programm.

файл generate_numbers создаёт текстовый файл numbers.txt c 10000 размером от 1 до 10000 для тестирования функций хэш-таблицы и производительности

Тесты двусвязного списка: скачайте файлы из папки list_tests и основные list.cpp, list.h
запустите исполняемый файл list-test.cpp 


 

