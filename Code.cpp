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

    virtual string GetCode(){
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

class nif:public code{
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

class cc:public code{
    int temp[12] = {};
    int result = 0,cont = 0,j;
    string tmp;
    char tm;
    public:
    
    cc(string code, string description){
        Code = code;
        Description = description;
    }

    bool checkCC(string code){
        for (int i=0; i<code.length();i++){
            if (isdigit(code[i])){
                tmp = code[i];
                temp[i] = stoi(tmp);         
            }
            else {
                tm=code[i];
                temp[i]=tm-55;
            }
            cout<<" "<<temp[i];
            cont++;
            
        }
        cout<<" size"<<cont;
        for (int i=0;i<cont;i++){
            if (cont%2 == 0){
                if (i%2 == 0){
                    temp[i] = temp[i] * 2;
                    if (temp[i]>=10)
                        temp[i] = temp[i]-9;
                    result+=temp[i];
                }
                else{
                    result+=temp[i];
                }
                cout<<" "<<temp[i];
            }
            else{
                if (i%2 >0){
                   temp[i] = temp[i] * 2;
                    if (temp[i]>=10)
                        temp[i] = temp[i]-9;
                    result+=temp[i]; 
                }
                else{
                    result+=temp[i];
                }
                
            }

            
            //cout<<" "<<temp[i]; 
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
    //cout<<novonif.checkNif("236133128")<<endl;
    //cout<<novonif.GetCode();  81918011ZZ2 127608435ZW5
    cout<<novocode.checkCC("127793496ZX0")<<endl;
                            
    return 0;
}
