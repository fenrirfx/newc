#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>


using namespace std;

class contacts{
    protected:
    string Name;
    string BirthDate;
    string Email;
    string PhoneNumber;
    public:
    contacts(){

    }

    contacts(string name, string birthdate, string email, string phonenumber){
        Name = name;
        BirthDate = birthdate;
        Email = email;
        PhoneNumber = phonenumber;
    }

    void SetName(string name){
        Name = name;
    }

    string GetName(){
        return Name;
    }

    void SetBirthDate(string birthdate){
        BirthDate =birthdate;
    }

    string GetBirthDate(){
        return BirthDate;
    }

    void SetEmail(string email){
        Email = email;
    }

    string GetEmail(){
        return Email;
    }

    void SetPhoneNumber(string phonenumber){
        PhoneNumber = phonenumber;
    }

    string GetPhoneNumber(){
        return PhoneNumber;
    }

    void GetDetails(){
        cout<<"Nome: "<<Name<<endl;
        cout<<"Birthdate:"<<BirthDate<<endl;
        cout<<"Email: "<<Email<<endl;
        cout<<"Phonenumber: "<<PhoneNumber<<endl;
    } 

};

int main(){

    int Opt,contador = 0;
    char op; char a[200];
    string nome, birthdate, phonenumber, email, pesquisa,temp1,temp2,temp3,temp4;
    vector<contacts> contact;
    contacts cont;

    do 
    {
        cout<<"Escolha a Opção"<<endl;
        cout<<"1 - Add Contacts"<<endl;
        cout<<"2 - List Contacts"<<endl;
        cout<<"3 - Search Contacts"<<endl;
        cout<<"4 - Edit Contacts"<<endl;
        cout<<"5 - Remove Contacts"<<endl;
        cout<<"6 - Quit"<<endl;
        cout<<"Opção: ";
        cin>>Opt;
        getchar();

        switch (Opt)
        {
        case 1:
            cout<<"Insira um nome: ";
            cin.getline(a,200,'\n');
            nome = a;
            cont.SetName(nome);
            cout<<"Insira o ano de nascimento: ";
            cin.getline(a,200,'\n');
            birthdate = a;
            cont.SetBirthDate(birthdate);
            cout<<"Insira o telefone: ";
            cin.getline(a,200,'\n');
            phonenumber = a;
            cont.SetPhoneNumber(phonenumber);
            cout<<"Insira um email: ";
            cin.getline(a,200,'\n');
            email = a;
            cont.SetEmail(email);
            contact.push_back(cont);
            break;
        case 2:
            if (contact.size()==0)
                cout<<"Não existem registos"<<endl;
            else{
                for (contacts c:contact)
                    c.GetDetails();
            }  
            break;
        case 3:
            cout<<"Insira um nome / email / contacto para pesquisa: ";
            cin>>pesquisa;
            for (contacts c:contact){
                if (pesquisa == c.GetName() or pesquisa == c.GetEmail() or pesquisa == c.GetPhoneNumber()){
                    cout<<"Encontrado registo!!"<<endl;
                    c.GetDetails();
                    contador++;
                }
            }
                if (contador == 0)
                    cout<<"Não foram encontrados registos"<<endl;
            
            contador = 0;
            break;
        case 4:
            cout<<"Insira um nome / email / contacto para pesquisa: ";
            cin>>pesquisa;
            for (contacts c:contact){
                contador++;
                if (pesquisa == c.GetName() or pesquisa == c.GetEmail() or pesquisa == c.GetPhoneNumber()){
                    temp1=c.GetName();temp2=c.GetBirthDate();temp3=c.GetPhoneNumber();temp4=c.GetEmail();
                    contact.erase(contact.begin()+contador,contact.begin()+contador+1);
    
                    cout<<"Pretende alterar o Nome?:(S/N)";
                    cin>>op;
                    getchar();
                    if (op=='S' or op =='s'){
                        cout<<"Insira um nome: ";
                        cin.getline(a,200,'\n');
                        nome = a;
                        cont.SetName(nome);
                    }
                    else
                        cont.SetName(temp1);
                    cout<<"Pretende alterar o Ano de Nascimento?:(S/N)";
                    cin>>op;   
                    getchar();
                    if (op=='S' or op =='s'){
                        cout<<"Insira o ano de nascimento: ";
                        cin.getline(a,200,'\n');
                        birthdate = a;
                        cont.SetBirthDate(birthdate);
                    }
                    else
                        cont.SetBirthDate(temp2);
                    cout<<"Pretende alterar o telefone?:(S/N)";
                    cin>>op;
                    getchar();
                    if (op=='S' or op =='s'){
                        cout<<"Insira o telefone: ";
                        cin.getline(a,200,'\n');
                        phonenumber = a;
                        cont.SetPhoneNumber(phonenumber);
                    }
                    else
                        cont.SetPhoneNumber(temp3);
                    cout<<"Pretende alterar o email?:(S/N)";
                    cin>>op;
                    getchar(); 
                    if (op=='S' or op =='s'){
                        cout<<"Insira um email: ";
                        cin.getline(a,200,'\n');
                        email = a;
                        cont.SetEmail(email);
                    }
                    else
                        cont.SetEmail(temp4);
                contact.push_back(cont);
                }

            }
            if (contador == 0)
                    cout<<"Não foram encontrados registos"<<endl;
            contador = 0;
            break;
        case 5:
        cout<<"Insira um nome / email / contacto para pesquisa: ";
        cin>>pesquisa;
        for (contacts c:contact){
                contador++;
                if (pesquisa == c.GetName() or pesquisa == c.GetEmail() or pesquisa == c.GetPhoneNumber()){
                    contact.erase(contact.begin()+contador,contact.begin()+contador+1);
                }
                else 
                    cout<<"Não foi encontrado qualquer registo!!"<<endl;
            }
            contador = 0;
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }
    while (Opt!=6);
    return 0;
}