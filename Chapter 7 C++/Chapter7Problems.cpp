#include <iostream>
#include <cmath>
#include "Chapter7Problems.h"
#include <string>
#include <fstream>


int main()
{
	chapter7Problems *p1 = new chapter7Problems();
	p1->payroll();
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

void chapter7Problems::largerThanN(int nums[], int size, int n) {
	//This function will display all numbers in an array, which will be passed through as an argument, that are greater than the number n
	/*Test Code (for int main() function):

	  int numbers[8] = {1,2,3,4,5,6,7,8};
	  p1->largerThanN(numbers, 8, 5);

	*/
		std::cout << "The values in the array that are greater than " << n << " are: " << std::endl;
		for (int index = 0; index < size; index++){
			if (nums[index] > n)
				std::cout << nums[index] << std::endl;
	}
}

void chapter7Problems::monkeyBusiness() {
	/*This function will store the amount of food (in pounds) eaten by monkeys from user input (assuming all values are different) into a two-dimensional 
	array and create a report consisting of: the average amount of food eaten per day by the whole family of monkeys, greatest and least amount of food eaten in a week
	by a monkey */
	double food[3][5];
	double averageDayEaten = 0;
	double totalMonkey1 = 0, totalMonkey2 = 0, totalMonkey3 = 0;
	double monday = 0, tuesday = 0, wednesday = 0, thursday = 0, friday = 0;
	double averageM, averageT, averageW, averageTh, averageF;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			int monkey = i + 1;
			int day = j + 1;
			std::cout << "Enter the amount of food (in pounds) eaten by monkey " << monkey << " on Day " << day << ": ";
			std::cin >> food[i][j];

			//Input validation: Value cannot be negative
			while (food[i][j] < 0) {
				std::cout << "Value cannot be negative. Try again." << std::endl;
				std::cin >> food[i][j];
			}

			//Calculate total amount of food eaten each day
			if (j == 0)
				monday = monday + food[i][j];
			else if (j == 1)
				tuesday = tuesday + food[i][j];
			else if (j == 2)
				wednesday = wednesday + food[i][j];
			else if (j == 3)
				thursday = thursday + food[i][j];
			else
				friday = friday + food[i][j];
		}

		//Calculate total amount of food eaten by each monkey
		if (i == 0) {
			for (int i = 0; i < 1; i++)
				for (int j = 0; j < 5; j++)
					totalMonkey1 = totalMonkey1 + food[i][j];
		}
		else if (i == 1) {
			for (int i = 1; i < 2; i++)
				for (int j = 0; j < 5; j++)
					totalMonkey2 = totalMonkey2 + food[i][j];
		}
		else if (i == 2) {
			for (int i = 2; i < 3; i++)
				for (int j = 0; j < 5; j++)
					totalMonkey3 = totalMonkey3 + food[i][j];
		}
	}

	//Calculate average amount of food eaten per day by the whole family of monkeys
	averageM = monday / 3;
	averageT = tuesday / 3;
	averageW = wednesday / 3;
	averageTh = thursday / 3;
	averageF = friday / 3;

	//Display the average amount of food eaten per day by the whole family of monkeys
	std::cout << "The average amount of food eaten per day by the whole family of monkeys on Day 1 (Monday): " << averageM << std::endl;
	std::cout << "The average amount of food eaten per day by the whole family of monkeys on Day 2 (Tuesday): " << averageT << std::endl;
	std::cout << "The average amount of food eaten per day by the whole family of monkeys on Day 3 (Wednesday): " << averageW << std::endl;
	std::cout << "The average amount of food eaten per day by the whole family of monkeys on Day 4 (Thursday): " << averageTh << std::endl;
	std::cout << "The average amount of food eaten per day by the whole family of monkeys on Day 5 (Friday): " << averageF << std::endl;

	//Compare values to find which monkey ate the most and least within a week
	if ((totalMonkey1 > totalMonkey2 && totalMonkey1 > totalMonkey3) && (totalMonkey2 < totalMonkey3)) {
		std::cout << "The monkey that ate the most throughout the week is Monkey 1." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 2." << std::endl;
	}
	else if ((totalMonkey1 > totalMonkey2 && totalMonkey1 > totalMonkey3) && (totalMonkey3 < totalMonkey2)) {
		std::cout << "The monkey that ate the most throughout the week is Monkey 1." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 3." << std::endl;
	}
	else if ((totalMonkey2 > totalMonkey1 && totalMonkey2 > totalMonkey3) && (totalMonkey1 < totalMonkey3)) {
		std::cout << "The monkey that ate the most throughout the week is Monkey 2." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 1." << std::endl;
	}
	else if ((totalMonkey2 > totalMonkey1 && totalMonkey2 > totalMonkey3) && (totalMonkey3 < totalMonkey1)) {
		std::cout << "The monkey that ate the most throughout the week is Monkey 2." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 3." << std::endl;
	}
	else if ((totalMonkey3 > totalMonkey1 && totalMonkey3 > totalMonkey3) && (totalMonkey1 < totalMonkey2)) {
		std::cout << "The monkey that ate the most throughout the week is Monkey 3." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 1." << std::endl;
	}
	else {
		std::cout << "The monkey that ate the most throughout the week is Monkey 3." << std::endl;
		std::cout << "The monkey that ate the least throughout the week is Monkey 2." << std::endl;
	}	
}

void chapter7Problems::numberAnalysis() {
	/*This function will read data from a file inputted by the user, and display the highest number, lowest number,
	total of numbers in the array, and the average of the numbers in the array*/
	int count = 0;
	const int ARRAY_SIZE = 100;
	double numbers[ARRAY_SIZE];
	std::ifstream inputFile;
	std::string filename;
	std::cout << "Enter the filename: ";
	std::cin >> filename;

	//Open file
	inputFile.open(filename);

	//Input validation: Make sure file can be opened
	while (!inputFile) {
		std::cout << "There was an error in opening the file. Try again. \n";
		std::cin >> filename;
		inputFile.open(filename);
	}

	//As long as file can be read, store data from file into array then close the file
	while (count < ARRAY_SIZE && inputFile >> numbers[count])
		count++;
	inputFile.close();
	
	//Find highest and lowest number in the array
	double highest = numbers[0];
	double lowest = numbers[0];
	for (int i = 0; i < count; i++) {
		if (numbers[i] >= highest)
			highest = numbers[i];
		else if (numbers[i] < lowest)
			lowest = numbers[i];
	}
	std::cout << "The highest number in this array is: " << highest << std::endl;
	std::cout << "The lowest number in this array is: " << lowest << std::endl;
	
	//Display the total of numbers in the array along with the average
	double total = 0, average;
	for (int i = 0; i < count; i++) {
		total = total + numbers[i];
	}
	average = total / (count);
	std::cout << "The total of the numbers in the array is: " << total << std::endl;
	std::cout << "The average of the numbers in the array is: " << average << std::endl;
}

void chapter7Problems::magicSquare(int nums[][COLS], int ROWS) {
	/*This function will determine if a two-dimensional array (passed as a function argument)
	  is considered a Lo Shu magic square: the sum of each row, column, and diagonal must all add up to the same
	  number. */

	/*Test Code (for int main() function):
	
	const int COLS = 3, ROWS = 3;
	int numbers[3][3];
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			std::cout << "Enter a value for the " << i << " row and " << j << " column: ";
			std::cin >> numbers[i][j];
			while (numbers[i][j] < 0 || numbers[i][j] > pow(COLS,2)) {
				std::cout << "Value cannot be negative or greater than columns multiplied by rows. Try again." << std::endl;
				std::cin >> numbers[i][j];
			}
		}
	}
	p1->magicSquare(numbers, 3);

	*/

	int total1 = 0, total2 = 0, total3 = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (i == 0)
				total1 = total1 + nums[i][j];
			else if (i == 1)
				total2 = total2 + nums[i][j];
			else
				total3 = total3 + nums[i][j];
		}
	}
	if (total1 != total2 || total1 != total3)
		std::cout << "The given two-dimensional array is not a magic square." << std::endl;
	else
		std::cout << "The given two-dimensional array is a magic square!" << std::endl;
}

void chapter7Problems::payroll() {
	//This function will asks the user for an employee's hours, pay rate, and calculate their respective wages
	long int empID[] = { 5658845,4520125,7895122,8777541,8451277,1302850,7580489 };
	int hours[7];
	double payRate[7], wages[7];

	//Gathering hours for each respective employee ID
	for (int i = 0; i < 7; i++) {
		std::cout << "Enter the hours worked for Employee " << empID[i] << ": ";
		std::cin >> hours[i];

		//Input Validation: Hours cannot be negative
		while (hours[i] < 0) {
			std::cout << "Value cannot be negative. Try again." << std::endl;
			std::cin >> hours[i];
		}

		//Gathering pay rates for each respective employee ID
		std::cout << "Enter the pay rate for Employee " << empID[i] << ": ";
		std::cin >> payRate[i];

		//Input Validation: Pay rate cannot be less than 15.00
		while (payRate[i] < 15.00) {
			std::cout << "Value cannot be less than 15.00. Try again." << std::endl;
			std::cin >> payRate[i];
		}

		//Calculate wages for each respective employee and store into an array
		wages[i] = hours[i] * payRate[i];
	}

	for (int i = 0; i < 7; i++) {
		std::cout << "The gross wages for Employee " << empID[i] << " are: $" << wages[i] << std::endl;
	}
}

chapter7Problems::chapter7Problems()
{
}