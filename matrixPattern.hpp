#include "Pattern.hpp"
#include "Coder.hpp"
#include <utility>
#include <vector>

#pragma once

class matrixPattern{
    private:
        vector<Pattern*> matrixElements;
    public:
        matrixPattern(){}
        void addElement(Pattern *elemento){
            matrixElements.push_back(elemento);
        }

        Pattern* getLastPattern(){
            return matrixElements[matrixElements.size()-1];
        }

        void insertIntoPattern(int index, string first, string second){
            matrixElements[index]->addPair(first, second);
        }

        void insertIntoLastPattern(string first, string second){
            matrixElements[matrixElements.size()-1]->addPair(first, second);
        }

        void insertIntoPattern(pair<string,string> element){
            matrixElements[matrixElements.size()]->addPair(element);
        }

        void insertIntoLastPattern(pair<string,string> element){
            matrixElements[matrixElements.size()-1]->addPair(element);
        }

        void matrixToCode(string path, bool withCPP){
            for(int i = 0; i < matrixElements.size(); i++){
                vector< pair<string,string> > patterns = matrixElements[i]->getPattern();
                Coder c(path + "\\" + patterns[0].second, withCPP);
                c.addPragma();
                c.addNameSpace();
                c.addClass(patterns[0].second, matrixElements[i]->getPattern());
                if(withCPP)
                    c.createCPPS(patterns[0].second, matrixElements[i]->getPattern());
            }
        }
        

        string toString(){
            string returnable = "";
			for(Pattern* patterns : matrixElements)
                returnable +=  patterns->toString() + "\n";
            return returnable;
        }
};