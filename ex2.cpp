/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
    string senha;
    bool maiuscula = false;
    bool minuscula = false;
    bool especial = false;
    bool numero = false;
    bool tamanho = false;
    
    string pattern = "!@#$'%'&*()_+=|<>?{}[]~-;:.,?/";
    
    cout << "Digite a senha: ";
    getline(cin, senha);
    
    if(senha.size()>5)
    {
        tamanho = true;
    }
    
    for(auto i = 0;i<senha.size();i++)
    {
        if(islower(senha[i]))
        {
            minuscula = true;
        }
        if (isupper(senha[i]))
        {
            maiuscula = true;
        }
        if (isdigit(senha[i]))
        {
            numero = true;
        }
        for(auto j=0;j<pattern.size();j++)
        {
            if (pattern[j]==senha[i])
            {
                especial = true;
            }
        }
    }

    if(minuscula && maiuscula && numero && tamanho && especial)
    {
        cout << "Sua senha foi aceita";
    }
    else
    {
        if(tamanho==false)
        {
            cout << "A senha deve ter ao menos 6 dígitos\n";
        }
        if(minuscula==false)
        {
            cout << "A senha deve conter ao menos uma letra minúscula\n";
        }
        if(maiuscula==false)
        {
            cout << "A senha deve conter ao menos uma letra maiúscula\n";
        }
        if(especial==false)
        {
            cout << "A senha deve conter ao menos um caracter especial\n";
        }
        if(numero==false)
        {
            cout << "A senha deve conter ao menos um numeral\n";
        }
    }

    return 0;
}
