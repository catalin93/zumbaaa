
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
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i-1]==a[i])
		{
			f++;
		}
		else
		{
			frecv.push_back(f);
			cifra.push_back(a[i - 1]);
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

