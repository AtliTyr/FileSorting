#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "Functions.h"
#include "ArraySort.h"
#include "FileNamesAndVariables.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));

	//////////////////////////////////////////////////////
	fstream input(Input, ios_base::out | ios_base::trunc);
				
	if (input.is_open())
	{
		createFileInterface(input);
		input.close();
		//////////////////////////////////////////////////////

		input.open(Input, ios_base::in);

		if (input.is_open())
		{
			sortFile(input);
		}
		input.close();

		//////////////////////////////////////////////////////
	}
	return 0;
}