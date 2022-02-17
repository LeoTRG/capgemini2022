/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// Var Glob

vector<string> Vtemp;
int Ttemp;


void permute(string a, int l, int r)  // Calcula todos os anagramas possíveis a aprtir da STRING do arranjo inicial ex.: Entrada OV saídas OV e VO (tam da saída é fatorial do tam da entrada)
{
    // Base case
    if (l == r)
    {
        Vtemp.resize(Vtemp.size()+1);
        Vtemp[Ttemp]=a;
        Ttemp++;
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}

        
int main()
{ 
    string palavra;
    cout << "Digite uma palavra ou conjunto de caracteres: "; //Quanto maior o número de caractes mais tempo demora, dada a relação fatorial da geração de anagramas
    getline(cin, palavra);  
    
    int Nper = palavra.size()-1; // grupos de até quantas letras serão gerados. ex. OVO -> 2, i.e. grupos com 1 letra e 2 letras (O,V,O,OV,VO)
    int Ntemp=0;
    int ktemp=0;                 // define o tamanho do vetor de arranjos iniciais
    int contelem=0;              // Iteração que dará o resultado desejado
    
    for(auto i=0;i<palavra.size()-1;i++) // calcula o numero de arranjos possíveis. ex.: OVO -> Ntemp = 5 (O,V,O,OV,VO)
    {
        Ntemp=Ntemp+palavra.size()-i;
    }
    
    
    //vetor onde aparecerão os arranjos possíveis da palavra original ex.: OVO -> O V O OV VO
    
    vector<string> v(Ntemp); 
     
    for(auto i=1;i<=Nper;i++)
    {
        for(auto j=0;j<palavra.size()-i+1;j++)
        {
            for(auto k=0;k<i;k++)
            {
                v[ktemp]=v[ktemp]+palavra[j+k];
            }
            ktemp++;
        }
    } 
    
    vector<string> anagramas; // Vetor com todas as possibilidades de anagramas dos arranjos iniciais;
    vector<string> anagramasPerm;
     
    anagramas=v;

     float ContPer=0;
     int auxcont=0;
     
     for(auto i=0;i<anagramas.size();i++)
     {
        Ttemp=0;
        Vtemp.clear();
        permute(anagramas[i], 0, anagramas[i].size()-1); // a cada iteração deste loop Vtemp assumirá as possibilidade de anagrama de um dos arranjos iniciais.
        
        for(auto ii=0;ii<Vtemp.size();ii++)
        {
            for(auto jj=0;jj<Vtemp.size();jj++)
            {
                if(ii!=jj)
                {
                    if(Vtemp[ii]==Vtemp[jj])
                    {
                        Vtemp[ii]="?";
                    }
                }
            }
        }
        Vtemp.erase(std::remove(begin(Vtemp), end(Vtemp), "?"), end(Vtemp));
        
        anagramasPerm.insert( anagramasPerm.end(), Vtemp.begin(), Vtemp.end() );
     }
     
     
     //Realiza os testes para identificar os pares
     
        for(auto l=0; l<v.size(); l++)
        {
            for(auto r=0;r<anagramasPerm.size();r++)
            {
                    if(v[l]==anagramasPerm[r])
                    {
                        contelem++;
                    }
            }
        }
        
        // modifica o vetor para apresentar apenas possibilidades únicas de cada anagrama. Ex. VOO gera OVO e OVO (alternando a posição do 1o e 2o "O"), remove-se resultados dobrados.

        for(auto ll=0;ll<anagramas.size();ll++)
        {
            for(auto rr=0;rr<anagramas.size();rr++)
            {
                if(ll!=rr)
                {
                  if(anagramas[rr]==v[ll])
                  {
                    anagramas[ll]="?";
                  }
                }
            }
        }
        
      anagramas.erase(std::remove(begin(anagramas), end(anagramas), "?"), end(anagramas));
      
      //Nova modificação para remoção de resultados dobrados, envolvendo letras soltas. Ex. OVO -> só se faz necessário a análise de 1 "O".
      
      for(auto ll=0;ll<v.size();ll++)
      {
          for(auto rr=0; rr<v.size();rr++)
          {
            if(ll!=rr && ll<=rr && v[ll]==v[rr] && v[ll].size()==1 && v[rr].size()==1)
            {
                contelem--;
            }  
          }
      }
        
     
     cout << (contelem)-v.size() << "\n"; //tamanho do vetor anagramas desconta o cálculo de possibilidades repetidas ex.: Em OVO o primeiro O não é PAR dele mesmo.
     
    return 0;
    
    /*OBS.: Existe um erro nos exemplos dados para esse exercício 3. No Exemplo "OVO" o resultado esperado seria "3" pois teriamos os subconjuntos "O","OV" e "VO"
            seguindo esta mesma lógica, o exemplo seguinte "IFAILUHKQQ" não deve retornar o valor "3" como consta no material, mas sim o valor "4".
            com os subconjuntos "I","Q","IFA" e "AFI". 
            
            O programa apresentado seguiu a lógica do primeiro exemplo. Caso fosse considerado correto o segundo exemplo o resultado para OVO deveria ser "2" e 
            não "3" como apresentado. */
    

}