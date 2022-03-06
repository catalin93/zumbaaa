
#include <iostream>
#include<vector>
#include <algorithm>

int CelMaiMareSir(std::vector <int> vect) {
	//cand se va apela functia se va introduce ca parametru vectorul de frecvente
	int max = vect[0];
	for (int i = 1; i < vect.size(); i++)
	{
		if (vect[max] < vect[i])
			max = i;
	}
	// se returneaza pozitia pe care se gaseste cel mai mare element
	return max;
}
int LungimeSirEliminat(int iMax_m, std::vector <int> frecv_m, std::vector <int> cifra_m)
{  // daca este pe pozitia 0 ne da eroare
	int n = 0;
	if (iMax_m == 0)
	{
		return n;
	}
	do {
		if (cifra_m[iMax_m - n - 1] == cifra_m[iMax_m + n + 1])
		{
			if ((frecv_m[iMax_m - n - 1] + frecv_m[iMax_m + n + 1]) >=3)
				n++;
			else
				return n;
		}
		else
			return n;
	} while (n < 20); //todo: while (n < (frecv_m.size() / 2));
	return n;

}

int main()
{
	std::vector <int> a;	
	std::vector <int> frecv;
	std::vector <int> cifra;
	int val;
	while (std::cin>>val)
	{
		if (val < 0)
			break;
	
		if ((val / 10) < 1)
			a.push_back(val);
	}
	for (auto it: a)
	{
		std::cout << it << "-";
	}
	std::cout << std::endl;
	int f = 1; //todo:: f = 1 cred ca ar trebui sa fie in for
	for (int i = 0; i < a.size()-1; i++)
	{  // todo: daca avem un element unic la sfarsit nu calculeaza bine frecventa
		if ((a[i]==a[i+1])&&((i+1)!=(a.size()-1)))
		{
			f++;
		}
		else if ((i + 1) == (a.size() - 1))
		{
			f++;
			frecv.push_back(f);
			cifra.push_back(a[i]);
		}
		else
		{
			frecv.push_back(f);
			cifra.push_back(a[i]);
			f = 1;
		}
	}
	

	std::cout << "Vectorul de frecvente este: \n";
	for (auto it : frecv)
	{
		std::cout << it << "-";
	}
	std::cout << "\nVectorul de cifre este: \n";
	for (auto it : cifra)
	{
		std::cout << it << "-";
	}


	int iMax=0;
	iMax = std::max_element(frecv.begin(), frecv.end()) - frecv.begin();
	int max;
	max = frecv[iMax];
	while (max >= 3)
	{
		std::cout << std::endl;
		std::cout << "Cel mai mare sir se afla pe pozitia " << iMax << std::endl;
		int n;
		n = LungimeSirEliminat(iMax, frecv, cifra);
		std::cout << "Latimea sirului ce trebuie eliminat este " << n << std::endl;
		// aici este o problema
		frecv.erase(frecv.begin() + iMax - n , frecv.begin() + iMax +n+1);
		std::cout << "Vectorul NOU de frecvente este: \n";
		for (auto it : frecv)
		{
			std::cout << it << "-";
		}
		
		cifra.erase(cifra.begin() + iMax - n, cifra.begin() + iMax+n+1 );
		std::cout << std::endl;
		std::cout << "Vectorul NOU de cifre este: \n";
		for (auto it : cifra)
		{
			std::cout << it << "-";
		}

		std::cout << std::endl;
		std::cout << "Vectorul NOU este: \n";
		for (int i = 0; i < cifra.size(); i++)
		{
			int x = 0;
			// Posibil ceva erori de aici
			while (x < frecv[i])
			{
				std::cout << cifra[i] << "-";
				x++;
			}
		}

		iMax = std::max_element(frecv.begin(), frecv.end()) - frecv.begin();
		max = frecv[iMax];
	}

}

