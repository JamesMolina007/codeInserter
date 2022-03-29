#pragma once

using namespace std;

class conejo{
    private:
        int var3;
        int var5;
        int var6;
    public:
        conejo();
        int getVar3(){
            return var3;
        }
        void setVar3(int var3){
            this->var3 = var3;
        }
        int getVar5(){
            return var5;
        }
        void setVar5(int var5){
            this->var5 = var5;
        }
        int getVar6(){
            return var6;
        }
        void setVar6(int var6){
            this->var6 = var6;
        }
};