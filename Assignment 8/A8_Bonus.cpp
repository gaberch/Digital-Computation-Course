//Gabe Richard
//Bonus Question

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int readFile(ifstream & fin, id[][2])
{
   int count = 0;
	for (int i=0, i < 100 && fin >> id[i][0], i++)
	{
		for (int j=0, j < 2, j++)
			id[i][j]++;
		count ++;
	}
	return count;
}

void output(ofstream & fout, num, id[][2])
{
	for (int i=0, i<num, i++)
	{
		for (int j=0, j<2, j++)
			fout << setw (8) << id[i][j];
		fout << endl;
   }
}

int main()
{
	ifstream fin ("ids_in.txt");
	ofstream fout("ids_out.txt");
	int id[100][2], num =0;
	
	
	if (!fin)
	{
		cout << "File not found" << endl;
		system ("pause");
		return -1;
	}	

	num = readFile(fin,id);
	output (fout,num,id)
	system ("pause");
	return 0;
}
	
