#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

template<typename T>
string to_string(const T& obj)
{
    stringstream ss;
    ss << obj;
    return ss.str();
}

bool sprawdz(int liczba)
{
    string text = to_string(liczba);
    int licznik=0;
    for(int i=0; i<text.length(); i++)
	{
		if(text[i] == '0' || text[i] == '1')
		{
			licznik++;
		}
	}
    if(licznik==text.length())
	{
		return true;
	}
	
	return false;
}

int liczba_k(int n,int k)
{
	bool z;
    k=1;
    int zmienna=1;
    z = sprawdz(n);
    if (z==false)
	{
    	do
		{	
		k++;
		zmienna=n*k;
		if(zmienna >= 1000000) 
		{
			cout<<"Zbyt duza wartosc k"<<endl;
			return 0;
		}
		
		}while(sprawdz(zmienna) == false);
	
	}
	
	return k;
}

void slownie(int n, int k)
{
	string jednosci[10]={"","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
	string nastki[10]={"","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemnascie ",
                   "osiemnascie ","dziewietnascie "};
	string dziesiatki[10]={"","dziesiec ","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemdziesiat ",
                      "osiemdziesiat ","dziewiecdziesiat "};
	string setki[11]={"","sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset "};

	
	int podzielona[7]; 
	int tab[7];
	int wartosc,zmienna, dlugosc=0;
	wartosc=k;
	
    for (int i = 0; i < 7; i++)
	{
		podzielona[i] = wartosc%10;
		wartosc = wartosc/10;
		//cout<<i<<" "<<podzielona[i]<<endl;
	} 
	cout<<endl;
	
    for (int i=0; i<7; i++)
	{
		tab[6-i]=podzielona[i];		
	}
	/* for (int i=0; i<7; i++)
	{
	    cout<<i<<" "<<tab[i]<<endl;	
	}*/
	
	for(int i=0; i<7; i++)
	{
		
		zmienna=tab[i];
		if(tab[0]==0 && tab[1]==0 && tab[2] == 1)
		{
			cout << "tysiąc ";
		}
		else
		{
			if(i==0 && tab[i] == 1 )
			{
				cout<<"milion ";
			}
			if(i==1 && tab[i]!=0  && tab[i+2] == 0)
			{
				if(i==1 && tab[i] != 0 )
				{
					cout<<setki[zmienna]<<" ";
	  	   	    }	
				if(i==2 && tab[i] != 0 )
				{
			  	  cout<<dziesiatki[zmienna]<<" ";
				}
				cout<<"tysiecy "<<endl;
			}
			else
			{
				if(i==1 && tab[i] != 0 )
				{
					cout<<setki[zmienna]<<" ";
	  	  	    }	
				if(i==2 && tab[i] != 0 )
				{
  	  	  	  	    if(tab[i]==1)
					{
						zmienna=tab[i+1];
						cout<<nastki[zmienna]<<" tysiecy ";
					}
					else
					{
						cout<<dziesiatki[zmienna]<<" ";
					}
				}
				
				if(i==3 && tab[i-1] != 1 && tab[i]!=0 )
				{
					cout<<jednosci[zmienna]<<" tysiace ";
				}
			}
			
	    
			if(i==4 && tab[i] != 0 )
			{
				cout<<setki[zmienna]<<" ";
			}
			if(i==5 && tab[i] != 0 )
			{
				if(tab[i]==1)
				{
					zmienna=tab[i+1];
					cout<<nastki[zmienna]<<" ";
				}
				else
				{
					cout<<dziesiatki[zmienna]<<" ";
				}
			}
			if(i==6 && tab[i-1] != 1 )
			{
				cout<<jednosci[zmienna]<<" ";
			}
		}

	  }	
		
}


int main(int argc, char *argv[])
{
	int n;
        n=atoi(argv[1]);
	int k;

    k=liczba_k(n, k);
    cout<<"Liczba k wynosi: "<<k<<endl;
    
    cout<<"Slownie: ";
    slownie(n,k);
    cout<<endl<<endl;

    return 0;
}
