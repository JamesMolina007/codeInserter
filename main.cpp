 
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <regex>
#include "Pattern.hpp"

using namespace std;

vector< Pattern > matrixPatterns;

void tokenizer(ifstream file){
	
}

void readFile(char *fileName){
	string line;
	ifstream file(fileName);
	while( getline(file, line) ){
		char *tok = strtok( const_cast<char*>(line.c_str()), " ");
		while(tok != NULL){
			string linea = tok;
			regex re("[\t]");
			sregex_token_iterator first{linea.begin(), linea.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
			vector<string> tokens{first, last};
			for(int i = 0; i < tokens.size(); i++){
				cout << i << ": " << tokens[i] << endl;
			}
			tok = strtok(NULL, " ");
		}
	}
}


int main(int argc, char** argv) {
	readFile(argv[1]);
	return 0;
}
