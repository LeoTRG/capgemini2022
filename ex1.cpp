/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main()
{
    
    string nin;
    int n;

    cout << "uma quantidade:";
    getline(cin, nin);

    n=stoi(nin);

    int tam = (n*n)+n;
    vector <string> escada(tam);

    int i=0;
    int j=0;

    
    for(i=0; i<n ;i++)
    {
        
        for(j=0;j<n+1;j++)
        {
            if(j>=(n-i-1))
            {
                escada[(i*(n+1))+j]='*';
                
            }
            else
            {
                escada[(i*(n+1))+j]=' ';
            }
            
        }
    }
    
   for(auto i=1;i<n;i++)
    {
     escada[(i*n)+i-1]='\n';
    }
    
    escada.pop_back(); 

   for(int i=0;i<tam-1;i++)
    {
     cout<<escada[i];
    }
    cout<<"\n"<<"\n"<<"\n"<<escada[escada.size()];
    
    

return 0;
}

/*OBS.: Estou apresentando abaixo da escada a última posição do vetor tem como resultado *, evidenciando que não existe um espaço no final do vetor. */

