#pragma once

using namespace std;

class pepe{
    private:
        string var2;
        string var4;
    public:
        pepe();
        string getVar2(){
            return var2;
        }
        void setVar2(string var2){
            this->var2 = var2;
        }
        string getVar4(){
            return var4;
        }
        void setVar4(string var4){
            this->var4 = var4;
        }
};