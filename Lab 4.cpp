/*#include <iostream>

int main() 
{
	int i;
	bool has12 = false;
	std::cin >> i;

	int s[i];
	for (int x = 0; x < i; x++) {
		srand(time(NULL));
		s[x] = rand() % 10000;
		std::cout << s[x];
		
		int tmp = s[x];
		int dig_sum = 0;
		while (tmp > 0)
		{
			dig_sum += (tmp % 10);
			tmp /= 10;
		}
		if (dig_sum == 12) {
			has12 = true;
		}
	}

	if (has12 == true)
	{
		for (int a = 0; a < i - 1; a++)
			for (int b = a + 1; b < i; b++)
				if (s[a] > s[b])
					std::swap(s[a], s[b])
	}

	for (int x = 0; x < i; x++)
		std::cout << s[x];
}
*/

#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int mas[n];
	int mas_exp[n];
	int mas_sum[n];

	for (int i = 0; i < n; i++) {
		srand(time(NULL));
		mas[i] = rand() % 1000;

		int tmp = mas[i];
		int dig_sum = 0;
		int dig_exp = 1;
		while (tmp > 0)
		{
			dig_sum += (tmp % 10);
			dig_exp *= (tmp % 10);
			tmp /= 10;
		}

		mas_exp[i] = dig_exp;
		mas_sum[i] = dig_sum;

		std::cout << mas[i];
	}

	for (int x = 0; x < n - 1; x++)
		for (int y = x + 1; y < n; y++)
			if ((mas_exp[x] > mas_exp[y]) ||
				(mas_exp[x] == mas_exp[y] && mas_sum[x] > mas_sum[y]) ||
				(mas_exp[x] == mas_exp[y] && mas_sum[x] == mas_sum[y] && mas[x] > mas[y]))
			{
				std::swap(mas_exp[x], mas_exp[y]);
				std::swap(mas_sum[x], mas_sum[y]);
				std::swap(mas[x], mas[y])
			}

	for (int i = 0; i < n; i++) {
		std::cout << mas[i];
	}
}



/*#include <iostream>

int main()
{
	int s[5][5] = { {51, 27, 34, 88, 100}, {83, 12, 28, 9, 17}, {74, 14, 40, 45, 41}, {32, 75, 64, 96, 83}, {13, 36, 53, 3, 100} };
	
	int count[5] = {0, 0, 0, 0, 0};
	for (int n = 0; n < 5; n++) {
		for (int m = 0; m < 5; m++) {
			if (s[m][n] % 10 == 3) {
				count[n]++;
			}
			std::cout << s[n][m] << " ";
		}
		std::cout << "" << std::endl;
	}

	std::cout << "" << std::endl;
	
	int min = 6;
	int min_ind = 0;
	for (int p = 0; p < 5; p++) {
		if (count[p] < min) {
			min = count[p];
			min_ind = p;
		}
	}
	
	for (int b = 0; b < 5; b++) {
		if (b != min_ind) {
			for (int a = 0; a < 5; a++) {
				s[a][b] = -17;
			}
		}
		
	}
	
	for (int n = 0; n < 5; n++) {
		for (int m = 0; m < 5; m++) {
			std::cout << s[n][m] << " ";
		}
		std::cout << "" << std::endl;
	}
}*/
