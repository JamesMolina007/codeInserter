#pragma once

using namespace std;

class Pattern{
	private:
		vector< pair<string,string> > elementPair;
	public:
		Pattern(){
		}

		Pattern(string first, string second){
			elementPair.push_back(make_pair(first,second)); 
		}

		Pattern(pair<string,string> pairs){
			elementPair.push_back(pairs);
		}

		vector< pair<string,string> > getPattern(){ 
			return elementPair; 
		}
		void addPair(string first, string second){ 
			elementPair.push_back(make_pair(first,second)); 
		}

		void addPair(pair<string,string> pairs){
			elementPair.push_back(pairs);
		}

		string toString(){
			string returnable = "";
			for(pair<string,string> pairs : elementPair)
				returnable += pairs.first + " " + pairs.second + "\n";
			return returnable;
		}

};