#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "ArraySort.h"
#include "FileNamesAndVariables.h"

using namespace std;


// Переписывает size чисел из file1 в file2 
void WriteToFile(fstream& file1, fstream& file2, int& size);

// Переписывает содержимое массива в размере n в файл
void WriteToFile(fstream& file, int* arr, int n);

// Запись n чисел из файла в массив
void ReadFromFile(fstream& fs, int* arr, int n);

// Объединяет отсортированные массивы (arr1 , arr2) в отсортированный файл (output)
void mergeArrayToFile(int* arr1, int size1, int* arr2, int size2, fstream& output);

// Объединяет отсортированные файлы (file1, file2) в больший отсортированный файл(output)
void mergeFiles(fstream& file1, fstream& file2, fstream& output);

// Генерирует случайные числа и заполняет ими файл
inline void createFile(fstream& input, int n, int max);

// Обеспечивает взаимодействие с файлом
void createFileInterface(fstream& input);

// 1)Считывает четверть файла (input) , сортирует её 
// 2)Считывает вторую четверть файла (input) , сортирует её 
// 3)Объединяет обе четверти в один файл (output)
void sortHalfOfFile(fstream& input, int* arr1, int s1, int* arr2, int s2, fstream& output);

// Сортирует файл
void sortFile(fstream& input);

// Очищает содержимое файла и закрывает его
void clearAndClose(fstream& F, string nameF);