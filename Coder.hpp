#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Pattern.hpp"
#include <utility>
#include <cctype>
#include <iomanip>

#pragma once

using namespace std;

class Coder{
    private:
        string path;
        ofstream newClass;
    public:
        Coder(){
        }

        Coder(string path){
            newClass.open(path);
        }

        void setPath(string path){
            this->path = path;
        }

        string getPath(){
            return path;
        }
        

        void addPragma(){
            newClass << "#pragma once\n\n";
        }

        void addNameSpace(){
            newClass << "using namespace std;\n\n";
        }

        void addClass(string name, vector< pair<string,string> > input, bool withCPP){
            newClass << "class " << name << "{\n";
            addPrivates(input);
            addPublics(input, withCPP);
            newClass << "};"; 
        }

        void addPrivates(vector< pair<string,string> > input){
            newClass << setw(4) << "private:\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class") newClass << setw(8) << pairs.first << " " << pairs.second << ";\n";
        }

        void addPublics(vector< pair<string,string> > input, bool withCPP){
            newClass << setw(4) << "public:\n";
            newClass << setw(8) << input[0].second << "();\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class")
                    addMethods(pairs.first, pairs.second, withCPP);
            cout << "\nHeaders are created\n";
        }

        void addMethods(string first, string second, bool withCPP){
            addSet(first, second, withCPP);
            addGet(first, second, withCPP);
        }

        void addSet(string first, string second, bool withCPP){
            newClass << setw(8) << "void set" << (char)toupper(second[0]) << second.substr(1, second.size()-1) << "(" << first << " " << second << ")";
            if(withCPP)
                newClass << ";\n";
            else
                newClass << "{\n" << setw(12) << "this->" << second << " = " << second << ";\n" << setw(4) << "}\n";
        }

        void addGet(string first, string second, bool withCPP){
            newClass << setw(8) << first << " get" << (char)toupper(second[0]) << second.substr(1, second.size()-1) << "()";
            if(withCPP)
                newClass << ";\n";
            else
                newClass << "{\n" << setw(12) << "return " << second << ";\n" << setw(8) << "}\n";
        }

        void createCPPS(string className){
            cout << "\nCPPs are created\n";
        }
};