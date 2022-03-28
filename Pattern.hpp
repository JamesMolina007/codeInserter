#include <vector>
#include <string>
#include <utility>

#pragma once

using namespace std;

class Pattern{
	private:
		vector< pair<string,string> > lines;
	public:
		Pattern(){
			
		}
		vector< pair<string,string> > getPattern(){ 
			return lines; 
		}
		void addPattern(string first, string second){ 
			lines.push_back(make_pair(first,second)); 
		}
};