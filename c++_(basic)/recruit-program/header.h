
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
using namespace std;

bool    TheAcceptableHeight(int height, char gender);
bool    TheAcceptableWeight(int weight, char gender);
char    GenderErrorCheck();
int     IsWeightValid();
int     IsHeightValid();

#endif /* HEADER_H_ */
