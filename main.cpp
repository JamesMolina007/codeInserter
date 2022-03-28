 
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>
#include "Pattern.hpp"

using namespace std;

vector< Pattern > matrixPatterns;

void insertPair(string first, string second){

}

void insertable(vector<string> tokens, string line){
	vector<string> tokenPair;
	for(string token : tokens)
		if(!token.empty())
			tokenPair.push_back(token);
	if(tokenPair.size() != 2){
		cerr << "Inaceptable Input: " << line << endl;
		exit(0);
	}
}

void tokenizer(string line){
	regex re("[\t ]");
	sregex_token_iterator first{line.begin(), line.end(), re, -1}, last;
	vector<string> tokens{first, last};
	insertable(tokens, line);
}

void readFile(char *fileName){
	string line;
	ifstream file(fileName);
	while( getline(file, line) )
		tokenizer(line);
}


int main(int argc, char** argv) {
	readFile(argv[1]);
	return 0;
}
