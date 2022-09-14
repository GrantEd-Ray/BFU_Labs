#include <iostream>

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
}
