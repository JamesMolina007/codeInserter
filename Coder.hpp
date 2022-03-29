#include <fstream>
#include <iostream>
#include "Pattern.hpp"

#pragma once

using namespace std;

class Coder{
    private:
        string path;
        bool withCPP;
        ofstream newClass;
        ofstream newSourceClass;
        
    public:
        Coder(){
        }

        Coder(string path, bool withCPP){
            this->path = path;
            this->withCPP = withCPP;
            newClass.open(path + ".hpp");
            if(withCPP)
                newSourceClass.open(path + ".cpp");
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

        void addClass(string name, vector< pair<string,string> > input){
            newClass << "class " << name << "{\n";
            addPrivates(input);
            addPublics(input);
            newClass << "};"; 
        }

        void addPrivates(vector< pair<string,string> > input){
            string blank4(4, ' ');
            string blank8(8, ' ');
            newClass << blank4 << "private:\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class") newClass << blank8 << pairs.first << " " << pairs.second << ";\n";
        }

        void addPublics(vector< pair<string,string> > input){
            string blank4(4, ' ');
            string blank8(8, ' ');
            newClass << blank4 << "public:\n";
            newClass << blank8 << input[0].second << "();\n";
            for(pair<string,string> pairs : input)
                if(pairs.first != "class")
                    addMethods(pairs.first, pairs.second);
            cout << "Header " << input[0].second << " created\n";
        }

        void addMethods(string first, string second){
            addSet(first, second);
            addGet(first, second);
        }

        void addSet(string first, string second){
            string blank8(8, ' ');
            string blank12(12, ' ');
            newClass << blank8 << "void set" << (char)toupper(second[0]) << second.substr(1, second.size()-1) << "(" << first << " " << second << ")";
            if(withCPP)
                newClass << ";\n";
            else
                newClass << "{\n" << blank12 << "this->" << second << " = " << second << ";\n" << blank8 << "}\n";
        }

        void addGet(string first, string second){
            string blank8(8, ' ');
            string blank12(12, ' ');
            newClass << blank8 << first << " get" << (char)toupper(second[0]) << second.substr(1, second.size()-1) << "()";
            if(withCPP)
                newClass << ";\n";
            else
                newClass << "{\n" << blank12 << "return " << second << ";\n" << blank8 << "}\n";
        }

        void createCPPS(string className, vector< pair<string,string> > input){
            newSourceClass << "#include \"" << className << ".hpp\"\n\n";
            newSourceClass << className << "::" << className << "(){\n}\n\n";
            for(pair<string,string> pairs : input){
                if(pairs.first != "class"){
                    string blank4(4, ' ');
                    //Add setter
                    newSourceClass << "void " << className << "::" << "set" << (char)toupper(pairs.second[0]) << pairs.second.substr(1, pairs.second.size()-1) << "(" << pairs.first << " " << pairs.second << ")";
                    newSourceClass << "{\n" << blank4 << "this->" << pairs.second << " = " << pairs.second << ";\n}\n\n\n";

                    //Add getter
                    newSourceClass << pairs.first << " " << className << "::" << "get" << (char)toupper(pairs.second[0]) << pairs.second.substr(1, pairs.second.size()-1) << "()";
                    newSourceClass << "{\n" << blank4 << "return " << pairs.second << ";\n}\n\n\n";
                }
            }
            cout << "CPP " << className << " created\n";
        }
};