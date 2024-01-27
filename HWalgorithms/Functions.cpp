#include "Functions.h"

void WriteToFile(fstream& file1, fstream& file2, int& size)
{
	file2 << size << "\n";

	int temp;
	for (int i = 0; i < size; i++)
	{
		file1 >> temp;
		file2 << temp << " ";
	}
	file2 << "\n";
}

void WriteToFile(fstream& file, int* arr, int n)
{
	file << n << '\n';

	for (int i = 0; i < n; i++)
	{
		file << arr[i] << " ";
	}
	file << '\n';
}

void ReadFromFile(fstream& fs, int* arr, int n)
{
	for (int i = 0; i < n; i++)
		fs >> arr[i];
}

void mergeArrayToFile(int* arr1, int size1, int* arr2, int size2, fstream& output)
{
	int i = 0;
	int j = 0;
	output << size1 + size2 << "\n";

	while (i < size1 && j < size2)
	{

		if (arr1[i] < arr2[j])
		{
			output << arr1[i] << " ";
			i++;
		}
		else
		{
			output << arr2[j] << " ";
			j++;
		}
	}

	while (i < size1)
	{
		output << arr1[i] << " ";
		i++;
	}
	while (j < size2)
	{
		output << arr2[j] << " ";
		j++;
	}
}

void mergeFiles(fstream& file1, fstream& file2, fstream& output)
{
	////auto start = chrono::high_resolution_clock::now();
	file1.seekp(0);
	file2.seekp(0);

	int f1n;
	int f2n;
	file1 >> f1n;
	file2 >> f2n;

	int i = 0;
	int j = 0;
	output << f1n + f2n << "\n";

	int t1, t2;
	file1 >> t1;
	file2 >> t2;

	while (i < f1n && j < f2n)
	{

		if (t1 < t2)
		{
			output << t1 << " ";
			file1 >> t1;
			i++;
		}
		else
		{
			output << t2 << " ";
			file2 >> t2;
			j++;
		}
	}

	while (i < f1n)
	{
		output << t1 << " ";
		file1 >> t1;
		i++;
	}
	while (j < f2n)
	{
		output << t2 << " ";
		file2 >> t2;
		j++;
	}
}

inline void createFile(fstream& input, int n, int max)
{
	input << n << '\n';

	for (int i = 0; i < n; i++)
	{
		input << rand() % (max + 1) << ' ';
	}
	input << '\n';
}

void createFileInterface(fstream& input)
{
	cout << "Введите параметры создаваемого файла" << endl;
	int size;
	cout << "Введите максимальное число: ";
	cin >> Max;
	cout << "Введите размер файла: ";
	cin >> size;


	cout << "Создание файла началось" << endl;
	auto start = chrono::high_resolution_clock::now();

	createFile(input, size, Max);

	cout << "Создание файла закончено" << endl;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "На создание файла ушло: " << elapsed.count() << " секунд" << endl;
}

void sortHalfOfFile(fstream& input, int* arr1, int s1, int* arr2, int s2, fstream& output)
{
	arr1 = new int[s1];
	arr2 = new int[s2];
	/*fstream temp1(temp11, fstream::out | fstream::in | fstream::trunc);
	fstream temp2(temp22, fstream::out | fstream::in | fstream::trunc);*/
	///////////////////////////////////////////////////////////////

	int n;

	//if (temp1.is_open() && temp2.is_open())
	//{
		///////////////////////////////////////////////////////////////

		//WriteToFile(input, temp1, s1);

		//temp1.seekp(0);
		//temp1 >> n;

		//ReadFromFile(temp1, arr1, n);
		//arr1 = countSort(arr1, n, Max);
		
		ReadFromFile(input, arr1, s1);
		arr1 = countSort(arr1, s1, Max);

		//////////////////////////////////////////////////////////////

		//WriteToFile(input, temp2, s2);

		//temp2.seekp(0);
		//temp2 >> n;

		//ReadFromFile(temp2, arr2, n);
		//arr2 = countSort(arr2, n, Max);

		ReadFromFile(input, arr2, s2);
		arr2 = countSort(arr2, s2, Max);

		//////////////////////////////////////////////////////////////

		mergeArrayToFile(arr1, s1, arr2, s2, output);

		//////////////////////////////////////////////////////////////
	//}

	delete[] arr1;
	delete[] arr2;
	//temp1.close();
	//temp2.close();
}

void sortFile(fstream& input)
{
	cout << "Сортировка файла начата" << endl;
	auto start = chrono::high_resolution_clock::now();

	int size;
	input >> size;

	int s1 = size / 4;
	int s2 = (size - s1) / 3;
	int s3 = (size - s1 - s2) / 2;
	int s4 = (size - s1 - s2 - s3);

	int* arr1 = nullptr;
	int* arr2 = nullptr;

	fstream temp3(temp33, fstream::out | fstream::in | fstream::trunc);
	fstream temp4(temp44, fstream::out | fstream::in | fstream::trunc);

	if (temp3.is_open() && temp4.is_open())
	{
		auto start2 = chrono::high_resolution_clock::now();
		sortHalfOfFile(input, arr1, s1, arr2, s2, temp3);

		auto end2 = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed2 = end2 - start2;
		cout << "Первая половина файла отсортирована. Затраченное время: " << elapsed2.count() << " секунд" << endl;


		start2 = chrono::high_resolution_clock::now();
		sortHalfOfFile(input, arr1, s3, arr2, s4, temp4);

		end2 = chrono::high_resolution_clock::now();
		elapsed2 = end2 - start2;
		cout << "Вторая половина файла отсортирована. Затраченное время: " << elapsed2.count() << " секунд" << endl;


		input.close();
		input.open(Input, fstream::out | fstream::trunc);

		cout << "Объединение в один файл начато" << endl;
		start2 = chrono::high_resolution_clock::now();
		mergeFiles(temp3, temp4, input);
		end2 = chrono::high_resolution_clock::now();
		elapsed2 = end2 - start2;
		cout << "Объединение закончено. Затраченное время: " << elapsed2.count() << " секунд" << endl;
	}

	//std::remove(temp11);
	//std::remove(temp22);
	temp3.close();
	temp4.close();
	std::remove(temp33);
	std::remove(temp44);

	cout << "Сортировка файла закончена" << endl;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "На сортировку файла ушло: " << elapsed.count() << " секунд" << endl;
}

void clearAndClose(fstream& F, string nameF)
{
	F.close();
	F.open(nameF, fstream::trunc);
	F.close();
}