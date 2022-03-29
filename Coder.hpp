#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Pattern.hpp"
#include <utility>
#include <cctype>

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

        void addClassName(string name, vector< pair<string,string> > input){
            newClass << "class " << name << "{\n";
            addPrivates(input);
            addPublics(input);
            newClass << "};"; 
        }

        void addPrivates(vector< pair<string,string> > input){
            newClass << "    " << "private:\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class") newClass << "        " << pairs.first << " " << pairs.second << ";\n";
        }

        void addPublics(vector< pair<string,string> > input){
            newClass << "    " << "public:\n";
            newClass << "        " << input[0].second << "();\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class"){
                    newClass << "        " << pairs.first << " get" << (char)toupper(pairs.second[0]) << pairs.second.substr(1, pairs.second.size()-1) << "();\n";
                    newClass << "        " << "void set" << (char)toupper(pairs.second[0]) << pairs.second.substr(1, pairs.second.size()-1) << "(" << pairs.first <<");\n";
                } 
        }
};