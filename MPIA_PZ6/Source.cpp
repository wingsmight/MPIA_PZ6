#define CATCH_CONFIG_RUNNER
#define COUNT 10

#include "catch.hpp"
#include "change.h"
#include "timer.h"
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;

std::vector<long long> denominations_rubles{ 1,2,5,10,50,100,200,500,1000,2000,5000 };
Timer t;

void measure(int n) {
	float time = 0;
	for (int c = 0; c < COUNT; c++)
	{
		long long summi = 0;
		for (int i = 1; i <= n; i++) {
			summi = summi * 10 + (rand() % 9 + 1);
		}
		t.start();
		get_change(denominations_rubles, summi);
		time += t.getTime();
	}

	std::cout << "Time: ";
	std::cout << std::scientific << time / COUNT;
	std::cout << " sec. in " << n << std::endl;
}

int main(int argc, char* argv[])
{
	Catch::Session().run(argc, argv);

	printf("lg(Summ)\tTime\n");
	for (int i = 1; i < 9; i++) {
		measure(i);
	}
	_getch();
	return 1;
}