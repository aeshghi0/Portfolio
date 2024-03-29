

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void GetName(string &n1, char &g1);
float Average(int numHeads, int totalFlips);
void Output(int totalFlips, float perc);
bool FlipCoin();



#endif /* HEADER_H_ */
