#include <iostream>
#include <cmath>
#include "Chapter7Problems.h"
#include <string>

int main()
{
	chapter7Problems *p1 = new chapter7Problems();
	p1->chipsAndSalsa();
	system("pause");
	return 0;
}

void chapter7Problems::smallLargeArray()
{
	//This function will display the largest and smallest values stored in an array out of 10 elements
	double arrayValue[10];
	for (int i = 0; i < 10; i++){
		std::cout << "Please enter a value." << std::endl;
		std::cin  >> arrayValue[i];
		}
	double largest = arrayValue[0];
	double smallest = arrayValue[0];
	for (int i = 0; i < 9; i++){
		if (largest <= arrayValue[i+1])
			largest = arrayValue[i+1];
		else if (smallest > arrayValue[i+1])
			smallest = arrayValue[i+1];	
		}
	std::cout << "The largest value in the array is: " << largest << std::endl;
	std::cout << "The smallest value in the array is: " << smallest << std::endl;
}

void chapter7Problems::rainfallStatistics() {
	//This function will display the total rainfall for the year, average monthly rainfall, and months with highest and lowest rainfall
	double rainfall[12];
	double totalRainfall = 0;

	//Receive user input and calculates total rainfall for the year
	for (int i = 1; i < 13; i++) {
		std::cout << "Please enter the total rainfall for month " << i << ": ";
		std::cin >> rainfall[i - 1];

		//Input Validation: Values cannot be negative
		while (rainfall[i - 1] < 0) {
			std::cout << "Value cannot be negative. Try again." << std::endl;
			std::cin >> rainfall[i - 1];
		}
		//Running total of rainfall
		totalRainfall = totalRainfall + rainfall[i - 1];
	}

	//Calculates the month with lowest and highest rainfall (ASSUMING ALL VALUES ARE DIFFERENT)
	int largestMonth = 1;
	int smallestMonth = 1;
	double largest = rainfall[0];
	double smallest = rainfall[0];
	for (int i = 0; i < 11; i++) {
		if (largest <= rainfall[i + 1]) {
			largest = rainfall[i + 1];
			largestMonth = i + 2;
		}
		else if (smallest > rainfall[i + 1]) {
			smallest = rainfall[i + 1];
			smallestMonth = i + 2;
		}
	}

	//Calculates the average monthly rainfall
	double avgMonthlyRainfall = totalRainfall / 12;

	//Display total rainfall for the year, average monthly rainfall, months with highest and lowest rainfall
	std::cout << "Total rainfall for the year: " << totalRainfall << std::endl;
	std::cout << "Average monthly rainfall: " << avgMonthlyRainfall << std::endl;
	std::cout << "Month with highest rainfall: " << largestMonth << std::endl;
	std::cout << "Month with lowest rainfall: " << smallestMonth << std::endl;
}

void chapter7Problems::chipsAndSalsa() {
	//This function uses two parallel arrays to keep track of jars sold for 5 different types of salsa, total sales, and  names of highest and lowest selling products
	std::string salsa[5] = { "mild","medium","sweet","hot","zesty" };
	int jarsSold[5];
	int totalJarsSold = 0;
	for (int i = 0; i < 5; i++) {
		std::cout << "Enter the amount of jars sold for " << salsa[i] << ": ";
		std::cin >> jarsSold[i];

		//Input Validation: Values cannot be negative
		while (jarsSold[i] < 0) {
			std::cout << "Value cannot be negative. Try again." << std::endl;
			std::cin >> jarsSold[i];
		}

		//Running total of jars sold
		totalJarsSold = totalJarsSold + jarsSold[i];
	}

	//Calculates the type of salsa with highest and lowest jar sales (ASSUMING ALL VALUES ARE DIFFERENT)
	std::string highestSale = salsa[0];
	std::string lowestSale = salsa[0];
	double largest = jarsSold[0];
	double smallest = jarsSold[0];
	for (int i = 0; i < 4; i++) {
		if (largest <= jarsSold[i + 1]) {
			largest = jarsSold[i + 1];
			highestSale = salsa[i + 1];
		}
		else if (smallest > jarsSold[i + 1]) {
			smallest = jarsSold[i + 1];
			lowestSale = salsa[i + 1];
		}
	}
	
	//Display the sales for each salsa type, total amount of jars sold, type of salsa with the highest and lowest amount of jars sold
	for (int i = 0; i < 5; i++) {
		std::cout << "Total amount of jars sold for " << salsa[i] << ": " << jarsSold[i] << std::endl;
	}
	std::cout << "Total amount of jars sold altogether: " << totalJarsSold << std::endl;
	std::cout << "Salsa with the highest amount of jars sold: " << highestSale << std::endl;
	std::cout << "Salsa with the lowest amount of jars sold: " << lowestSale << std::endl;
}

chapter7Problems::chapter7Problems()
{
}