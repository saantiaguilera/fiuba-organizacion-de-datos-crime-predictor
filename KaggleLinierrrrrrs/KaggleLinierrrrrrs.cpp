// KaggleLinierrrrrrs.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Parser.h"

int main() {
	Parser *parser = new Parser;
	return parser->readFile();
}