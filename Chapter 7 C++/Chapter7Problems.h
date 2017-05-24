#pragma once

/*For magic square function, value of COLS in header file and .cpp file must be the same! */
const int COLS = 3;

class chapter7Problems {
public:
	chapter7Problems();
	static void smallLargeArray();
	static void rainfallStatistics();
	static void chipsAndSalsa();
	static void largerThanN(int nums[], int size, int n);
	static void monkeyBusiness();
	static void numberAnalysis();
	static void magicSquare(int nums[][COLS], int ROWS);
	static void payroll();
	static void driversLicenseExam();
	static void examGrader();
	static void gradeBook();
	static void lottery();
};