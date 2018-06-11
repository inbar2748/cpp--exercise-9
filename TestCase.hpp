#pragma once
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

class TestCase
{
public:

	ostream *stream;
	string caseName;

	int passed, failed;
	
	//constructor
	TestCase(string c, ostream &os) {
		stream = &os;
		caseName = c;
		passed = 0;
		failed = 0;
	}
	template <typename T> TestCase check_equal(T x, T y) {
		if (x == y) passed++;
		else {
			(*stream) << caseName << ": " << "Failure in test #" << (passed + failed + 1) << ": " << x << " should equal " << y << "!" << endl;
			failed++;
		}
		return (*this);
	}
	

	template <typename T> TestCase check_different(T x, T y) {
		if (x != y) passed++;
		else {
			(*stream) << caseName << ": " << "Failure in test #" << (passed + failed + 1) << ": " << x << " should not equal " << y << "!" << endl;
			failed++;
		}
		return (*this);
	}


	template <typename T, typename K, typename Function> TestCase check_function(Function f, K x, T y) {
		
		if (f(x) == (T)y) passed++;
		else {
			(*stream) << caseName << ": " << "Failure in test #" << (passed + failed + 1) << ":  Function should return " << (T)y << " but returned " << f(x) << "!" << endl;
			failed++;
		}
		return (*this);
	}

	template <typename T> TestCase check_output(T x, string y) {
		stringstream str_x;
		str_x << x;
		if (str_x.str() == y) passed++;
		else {
			(*stream) << caseName << ": " << "Failure in test #" << (passed + failed + 1) << ": " << "string value should be " << y << " but is " << str_x.str() << "!" << endl;
			failed++;
		}
		return (*this);
	}
	
	void print() {
	(*stream) << caseName << ": " << failed << " -failed, " << passed << "- passed, " << (passed + failed) << " -total." << endl ;
}

};

