
#include <iostream>
#include<vector>


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




}

