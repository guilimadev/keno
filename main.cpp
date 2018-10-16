#include <iostream>
#include <iterator>
#include <algorithm>  
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <typeinfo>
#include "kenobet.h"

float payout(int size, int hits){
	if(size == 1){
		if(hits == 0){
			return 0.0;
		}
		else{
			return 1.0;
		}
	}

	if(size == 2){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 1.0;
		}
		else{
			return 9.0;
		}
	}


	if(size == 3){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 1.0;
		}
		else if(hits == 2){
			return 2.0;
		}
		else{
			return 16.0;
		}
	}

	if(size == 4){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 0.5;
		}
		else if(hits == 2){
			return 2.0;
		}
		else if(hits == 3){
			return 6.0;
		}
		else{
			return 12.0;
		}
	}

	if(size == 5){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 0.5;
		}
		else if(hits == 2){
			return 1.0;
		}
		else if(hits == 3){
			return 3.0;
		}
		else if(hits == 4){
			return 15.0;
		}
		else{
			return 50.0;
		}
	}

	if(size == 6){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 0.5;
		}
		else if(hits == 2){
			return 1.0;
		}
		else if(hits == 3){
			return 2.0;
		}
		else if(hits == 4){
			return 3.0;
		}
		else if(hits == 5){
			return 30.0;
		}
		else{
			return 75.0;
		}
	}

	if(size == 7){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 0.5;
		}
		else if(hits == 2){
			return 0.5;
		}
		else if(hits == 3){
			return 1.0;
		}
		else if(hits == 4){
			return 6.0;
		}
		else if(hits == 5){
			return 12.0;
		}
		else if(hits == 6){
			return 36.0;
		}
		else{
			return 100.0;
		}
	}

	if(size == 8){
		if(hits == 0){
			return 0.0;
		}
		else if(hits == 1){
			return 0.5;
		}
		else if(hits == 2){
			return 0.5;
		}
		else if(hits == 3){
			return 1.0;
		}
		else if(hits == 4){
			return 3.0;
		}
		else if(hits == 5){
			return 6.0;
		}
		else if(hits == 6){
			return 19.0;
		}
		else if(hits == 7){
			return 90.0;
		}
		else{
			return 720.0;
		}
	}



}

int main(void){

	int nums[20]{0};
	int rand_num;	

	srand(time(NULL));
		
	

	std::ifstream myfile("bet.txt");


	std::string wage;
	std::string s_rounds;
	std::string bets;
	
	std::getline(myfile, wage);
	std::getline(myfile, s_rounds);
	std::getline(myfile, bets);
	std::istringstream os(bets);

	KenoBet a;
	
	// Placing the bets
	number_type i;
	while(os >> i)
		a.add_number(i);

	auto rounds = std::stoi(s_rounds);
	auto wage_total = std::stof(wage);

	a.set_wage(wage_total);

	auto wage_per_round = wage_total / rounds;

	float wage_part[rounds];

	for (int i = 0; i < rounds; ++i)
	{
		wage_part[i] = wage_per_round;
	}

	int temprounds = rounds;

	for (auto i = 0; i < a.size(); ++i)
	{
		std::cout << a.get_spots()[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Wage: " << a.get_wage() << std::endl;
	std::cout << "Wage per round: " << wage_per_round << std::endl << std::endl;
	
	std::cout << "Starting the game!!!" << std::endl;
	while(temprounds > 0){
		int acertos = 0;
		

		for (int i = 0; i < 20; ++i)
		{
			rand_num = rand() % 80 + 1;
			int contagem = 0;

			for(int j = 0; j < 20; j++){
				if(nums[j] != rand_num){
					contagem++;
				}
			}

			if(contagem == 20){
				nums[i] = rand_num;
			}
			else{
				i--;
			}
		}
		std::sort(std::begin(nums), std::end(nums));
		for (int i = 0; i < 20; ++i)
		{
			std::cout << nums[i] << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < a.size(); ++j)
			{
				if(a.get_spots()[j] == nums[i]){
					acertos++;
				}
			}
		}
		wage_part[temprounds - 1] = wage_part[temprounds - 1] * payout(a.size(), acertos);	
		std::cout << "Wage after this round: " << wage_part[temprounds - 1] << std::endl;
		std::cout << "Number of hits: " << acertos << std::endl << "------------------------------" << std::endl;
		temprounds--;
	}
	int final_wage = 0;
	
	for (int i = 0; i < rounds; ++i)
	{
			final_wage = final_wage + wage_part[i];		
	}
	std::cout << "Your final wage was: " << final_wage << std::endl << "------------------------------" << std::endl;

	std::cout << "Clearing bets..." << std::endl;

	a.reset();

	


	return 0;
}