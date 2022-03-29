#include <regex>
#include "matrixPattern.hpp"

using namespace std;

matrixPattern *mp = new matrixPattern();

void error(string line){
	if(line.size() > 0){
		cerr << "Inaceptable Input: " << line << endl;
		exit(0);
	}
}

void printer(){
	cout << mp->toString() << endl;
}

void save(string path, int withCPP){
	if(withCPP == 1)
		mp->matrixToCode(path, true);
	else
		mp->matrixToCode(path, false);
}

string toLowerCase(string s){
	string returnable = "";
	for(char c : s)
		returnable += tolower(c);
	return returnable;
}

void clasificator(string first, string second, string line){
	if( !isalpha(first[0]) || !isalpha(second[0]) )
		error(line);
	if ( toLowerCase(first) == "class")
		mp->addElement(new Pattern(make_pair(first, second)));
    else
		mp->insertIntoLastPattern(make_pair(first, second));
}

void insertable(vector<string> tokens, string line){
	vector<string> tokenPair;
	for(string token : tokens)
		if(!token.empty())
			tokenPair.push_back(token);
	if(tokenPair.size() != 2)
		error(line);
	else
		clasificator(tokenPair[0], tokenPair[1], line);
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
	if(argc != 3 && argc != 4){
		cerr << '\t' << "Error al ejecutar!" << endl;
		cerr << '\t' << "Argumentos proporcionados de forma incorrecta" << endl;
		cerr << '\t' << '\t' <<  "ejecutable.exe [readFile] [savePath] [1 = with cpp]" << endl;
	}else{
		readFile(argv[1]);
		printer();
		argc == 4 ? save(argv[2], strtol(argv[3], NULL, 10)) : save(argv[2], 0);
	}
	return 0;
}
