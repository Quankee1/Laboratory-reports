#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* fp = fopen("F1.txt", "r");
	if (fp == NULL)
	{
		perror("Ошибка!");
		return 1;
	}

	char buff[100];
	int count_str = 0;

	while (fgets(buff, sizeof(buff), fp) != NULL) 
		count_str++;
	

	string**  words = new string * [count_str]; 
	int* count_w = new int[count_str];
	fseek(fp, 0, SEEK_SET);

	for (int i = 0; i < count_str; i++)
	{
		int pos = ftell(fp);
		fgets(buff, sizeof(buff), fp);
		char* p = strtok(buff, " \t\n");
		int w = 0;

		while (p != NULL)
		{
			w++;
			p = strtok(NULL, " \t\n");
		}
		words[i] = new string[w];
		count_w[i] = w;

		fseek(fp, pos, SEEK_SET);

		fgets(buff, sizeof(buff), fp);
		p = strtok(buff, " \t\n");
		for (int j = 0; j < w; j++)
		{
			words[i][j] = p; // Сохраняем слово
			p = strtok(NULL, " \t\n");
		}
	}
	fclose(fp);

	FILE* in = fopen("F2.txt", "w");
	if (in == NULL)
	{
		perror("Ошибка открытия файла F2.txt");
		return 1;
	}


	for (int i = 0; i < count_str; i++)
	{
		bool flag = false;
		for (int j = 0; j < count_w[i] && flag == false; j++)
		{
			int k = j + 1;
			while (flag != true && k < count_w[i])
			{
				if (words[i][j] == words[i][k])
					flag = true;
				k++;
			}
		}
		if (flag)
		{
			for (int j = 0; j < count_w[i]; j++)
			{
				fprintf(in, "%s ", words[i][j].c_str());
			}
			fprintf(in, "\n");
		}
	}
	fclose(in);
	
	int max_i = 0, max_j = 0, count_d = 0, max = 0;
	for (int i = 0; i < count_str; i++)
	{
		for (int j = 0; j < count_w[i]; j++)
		{
			for (int k = 0; k < words[i][j].size(); k++)
			{
				if (words[i][j][k] >= '0' && words[i][j][k] <= '9')
				{
					count_d++;
				}
			}
			if (count_d > max)
			{
				max = count_d;
				max_i = i;
				max_j = j;
			}
			count_d = 0;
		}
	}
	cout << "Слово с наибольшим количеством цифр находится: " << max_i+1 << " строка и " << max_j+1 << " по порядку в этой строке.";

	for (int i = 0; i < count_str; i++)
		delete[] words[i];
	delete[] words;
	delete[] count_w;

	return 0;
}