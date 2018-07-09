#include <iostream>

using namespace std;

#include "fraction.hpp"

void fraction::setup(int n, int d) {
	this->num = n;
	this->denom = d;
}

void fraction::display() {
	cout << this->num << "/" << this->denom;
}

fraction fraction::add(fraction* other) {
	// Temporary variables
	int resultNum, resultDenom;

	// Do the math
	resultNum = (this->num * other->denom) + (other->num * this->denom);
	resultDenom = this->denom * other->denom;

	// Set up the result
	fraction result;
	result.setup(resultNum, resultDenom);
	return result;
}

fraction fraction::subtract(fraction* other) {
	// Temporary variables
	int resultNum, resultDenom;

	// Do the math
	resultNum = (this->num * other->denom) - (other->num * this->denom);
	resultDenom = this->denom * other->denom;

	// Set up the result
	fraction result;
	result.setup(resultNum, resultDenom);
	return result;
}

fraction fraction::multiply(fraction* other) {
	// Temporary variables
	int resultNum, resultDenom;

	// Do the math
	resultNum = this->num   * other->num;
	resultDenom = this->denom * other->denom;

	// Set up the result
	fraction result;
	result.setup(resultNum, resultDenom);
	return result;
}

fraction fraction::divide(fraction* other) {
	// Temporary variables
	int resultNum, resultDenom;

	// Do the math
	resultNum = this->num   * other->denom;
	resultDenom = this->denom * other->num;

	// Set up the result
	fraction result;
	result.setup(resultNum, resultDenom);
	return result;
}
