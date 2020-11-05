#ifndef _RED_AND_BLACK_H_
#define _RED_AND_BLACK_H_

#include <string>
#include <vector>

using namespace std;

void help();

vector<string> getLine(string& str);

vector<double> sortingNumbers(vector<double>& tmpVector);

vector<double> removeNumber(vector<double>& tmpVector, double& number);

void printToFile(string& name, bool& plus, vector<double>& tmpNumbers);

void print(vector<double>& tmpNumbers);

void error(string& comand);

void redAndBlack();

#endif