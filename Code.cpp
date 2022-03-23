#include <iostream>
#include <ctime>
#include <string>
#include <cstring>


using namespace std;

class code{
    protected:
    string Code;
    string Description;
    public:

    code(){

    }

    code(string code, string description){
        Code  = code;
        Description = description;
    }

    string GetCode(){
        return Code;
    }

    void setCode(string code){
        Code = code;
    }

    string getDescription(){
        return Description;
    }

    void setDescription(string description){
        Description = description;
    }

    string getCode(){
        //cout<<"Code: "+Code+" Description: "+Description<<endl; 
        return Code + Description;
    } 

};

class nif:code{
    public:
    
    nif(string code, string description){
        Code = code;
        Description = description;
    }

    bool checkNif(string code){
        int nif = stoi(code),result = 0,resto = 0;
        
        for(int i=9;i>=1;i--){
            code[i]=nif%10;
            nif/=10;
        }
        if((nif<=999999999||nif>999999999)&&((code[1]==1||code[1]==2||code[1]==3)||(code[1]==4&&code[2]==5)||(code[1]==5)||(code[1]==6)||(code[1]==7&&code[2]==0)||(code[1]==7&&code[2]==4)||(code[1]==7&&code[2]==5)||(code[1]==8)||(code[1]==9))){
            return true;
        }
        else
            return false;
    }

};

class cc:code{
    char array[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int temp[12] = {};
    int result = 0;
    string tmp;
    public:
    
    cc(string code, string description){
        Code = code;
        Description = description;
    }

    bool checkCC(string code){
        for (int i=0; i<sizeof(code);i++){
            if (isdigit(code[i])){
                tmp = code[i];
                temp[i] = stoi(tmp);
            }
            else{
                for(int j=0;j<sizeof(array);j++){
                    if (code[i] == array[j]){
                        temp[i] = j+10;
                    }
                }
            }
        }
        for (int i=0;i<12;i++){
            if ((i+1)%2 != 0){
                temp[i] = temp[i] * 2;
                if (temp[i]>10)
                    temp[i] = temp[i]-9;
            }
            result +=temp[i];
        }
        if (result%10 == 0)
            return true;
        else
            return false;
            

       
    }

};

int main(){

    cc novocode = cc ("123456789","qwerty");
    nif novonif = nif ("325478590","asdfgh");
    //cout<<novonif.checkNif("123456789");
    cout<<novonif.checkNif("238933128")<<endl;
    cout<<novocode.checkCC("122393496ZX0")<<endl;

    return 0;
}
