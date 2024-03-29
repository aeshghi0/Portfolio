/*
 * header.h
 *
 *  Created on: May 8, 2019
 *      Author: alieshghi
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;


void GetInput(string &name, int &rounds);

char GetAndCheckPlay(string name);

char GetCompPlay();

bool CheckWin(char userChoice, char compChoice);

void OutputWin(string user, bool matchResult);

void OutputMatchWinner(string user, int winNum, int turns);



#endif /* HEADER_H_ */
