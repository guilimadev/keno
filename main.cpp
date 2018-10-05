
#include <iostream>
#include <iterator>
#include <algorithm>  
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>


int main(void){

	int nums[20];
	int rand_num;
	int j = 0;
	int bet[]{3,5,2,65,12};

	int size_bet = std::distance(std::begin(bet), std::end(bet));

	srand(time(NULL));

	while(j < 3){
		int acertos = 0;

		for (int i = 0; i < 20; ++i)
		{
			rand_num = rand() % 80 + 1;
			nums[i] = rand_num;
		}

		for (int i = 0; i < 20; ++i)
		{
			std::cout << nums[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < size_bet; ++i)
		{
			std::cout << bet[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < size_bet; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				if(bet[i] == nums[j]){
					acertos++;
				}
			}
		}

		std::cout << "Numero de acertos: " << acertos << std::endl;
		j++;
	}	
	return 0;
}