#pragma once
#include<iostream>
#include<stack>
using namespace std;
enum Symbol
{
	OP_SYMBOL,
	OP_NUM,
	ADD,
	SUB,
	MUL,
	DIV,
};

struct cell
{
	int _symbol;
	int _value;
};

cell RNPArry[]={
				 {OP_NUM,12},{OP_NUM,3},{OP_NUM,4},{OP_SYMBOL,ADD},{OP_SYMBOL,MUL},{OP_NUM,6},
				 {OP_SYMBOL,SUB},{OP_NUM,8},{OP_NUM,2},{OP_SYMBOL,DIV},{OP_SYMBOL,ADD}
               };


