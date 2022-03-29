#pragma once

using namespace std;

class perro{
    private:
        int var1;
        int var2;
        int var3;
    public:
        perro();
        int getVar1(){
            return var1;
        }
        void setVar1(int var1){
            this->var1 = var1;
        }
        int getVar2(){
            return var2;
        }
        void setVar2(int var2){
            this->var2 = var2;
        }
        int getVar3(){
            return var3;
        }
        void setVar3(int var3){
            this->var3 = var3;
        }
};