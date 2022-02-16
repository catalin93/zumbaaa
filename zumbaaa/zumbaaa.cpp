
#include <iostream>
#include<vector>

int CelMaiMareSir(std::vector <int> vect) {
	//cand se va apela functia se va introduce ca parametru vectorul de frecvente
	int max = 0;
	for (int i = 1; i < vect.size() - 1; i++)
	{
		if (vect[max] < vect[i])
			max = i;
	}
	return max;
}
int LungimeSirEliminat(int iMax_m, std::vector <int> frecv_m, std::vector <int> cifra_m)
{
	int n = 0;
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
	} while (n < 20); //todo: while ((n < frecv_m.size()) / 2);
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
	int f = 1;
	for (int i = 0; i < a.size()-1; i++)
	{
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
	int iMax;
	iMax = CelMaiMareSir(frecv);
	std::cout << std::endl;
	std::cout << "Cel mai mare sir se afla pe pozitia "<<iMax << std::endl;
	int n = 0;
	n=LungimeSirEliminat(iMax, frecv, cifra);
	std::cout << "Latimea sirului ce trebuie eliminat este " << n << std::endl;


}

