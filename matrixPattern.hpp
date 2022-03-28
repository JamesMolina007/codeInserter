#include "Pattern.hpp"
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

        string toString(){
            string returnable = "";
			for(Pattern* patterns : matrixElements)
                returnable +=  patterns->toString() + "\n";
            return returnable;
        }
};