#pragma once
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "ArraySort.h"
#include "FileNamesAndVariables.h"

using namespace std;


// ������������ size ����� �� file1 � file2 
void WriteToFile(fstream& file1, fstream& file2, int& size);

// ������������ ���������� ������� � ������� n � ����
void WriteToFile(fstream& file, int* arr, int n);

// ������ n ����� �� ����� � ������
void ReadFromFile(fstream& fs, int* arr, int n);

// ���������� ��������������� ������� (arr1 , arr2) � ��������������� ���� (output)
void mergeArrayToFile(int* arr1, int size1, int* arr2, int size2, fstream& output);

// ���������� ��������������� ����� (file1, file2) � ������� ��������������� ����(output)
void mergeFiles(fstream& file1, fstream& file2, fstream& output);

// ���������� ��������� ����� � ��������� ��� ����
inline void createFile(fstream& input, int n, int max);

// ������������ �������������� � ������
void createFileInterface(fstream& input);

// 1)��������� �������� ����� (input) , ��������� � 
// 2)��������� ������ �������� ����� (input) , ��������� � 
// 3)���������� ��� �������� � ���� ���� (output)
void sortHalfOfFile(fstream& input, int* arr1, int s1, int* arr2, int s2, fstream& output);

// ��������� ����
void sortFile(fstream& input);

// ������� ���������� ����� � ��������� ���
void clearAndClose(fstream& F, string nameF);