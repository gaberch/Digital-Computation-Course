//Question 3

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

bool checkIfPreferred(string check)
{
    ifstream fin("prefer.dat");
    string name;
    for (int i = 0; i < 10; i++)
    {
        fin >> name;
        if(check == name)
             return true;
    }
    return false;
}

double perimRect(double L, double W)
{
    return L + L + W + W;
}

double areaRect(double L, double W)
{
    return L * W;
}

double perimTri(double s1, double s2, double s3)
{
    return s1 + s2 + s3;
}

double areaTri(double s1, double s2, double s3)
{
    double p = perimTri(s1,s2,s3)/2;
    return sqrt(p * (p-s1) * (p-s2) * (p-s3));
}

double perimSect(double r, double a)
{
    return (a/360) * 2 * M_PI * r;
}

double areaSect(double r, double a)
{
    return (a/360) * M_PI * r * r;
}

double perimQuad(double s1, double s2, double diag, double s3, double s4)
{
    return s1 + s2 + s3 + s4;
}

double areaQuad(double s1, double s2, double diag, double s3, double s4)
{
    return areaTri(s1,s2,diag) + areaTri(s3,s4,diag);
}


int main()
{

    ifstream fin("jobs.dat");
    ofstream fout("results.txt");
    
    int jobNum;
    double Parea, Pcost, Flength, Fcost, s1, s2, s3, s4, diag, a;
    double jobCost, tax;
    bool needsP, needsF;
    string name, shape;
    
    fout << fixed << setprecision(2);
    fout << setw(6) << "Job #" << setw(7) << "P Area" << setw(10) << "P Cost"
         << setw(9) << "F Length" << setw(10) << "F Cost" << setw(9) << "Tax"
         << setw(14) << "Preferred?" << setw(11) << "Total Cost" << endl;
    
    while(fin >> jobNum >> name >> needsP >> needsF >> shape)
    {
        jobCost = Parea = Pcost = Flength = Fcost = 0;
        
        if(shape == "tri")
        {
            fin >> s1 >> s2 >> s3;
            
            if(needsP)
            {
                Parea = areaTri(s1, s2, s3);
                Pcost = ceil(Parea) * 18.5;
                jobCost += Pcost;
            }
            
            if(needsF)
            {
                Flength = perimTri(s1, s2, s3);
                Fcost = (ceil(Flength) * 26) + 120;
                jobCost += Fcost;
            }
        }
        
        if(shape == "rect")
        {
            fin >> s1 >> s2;
            
            if(needsP)
            {
                Parea = areaRect(s1, s2);
                Pcost = ceil(Parea) * 18.5;
                jobCost += Pcost;
            }
            
            if(needsF)
            {
                Flength = perimRect(s1,s2);
                Fcost = (ceil(Flength) * 26) + 120;
                jobCost += Fcost;
            }
        }
        
        if(shape == "quad")
        {
            fin >> s1 >> s2 >> diag >> s3 >> s4;
            
            if(needsP)
            {
                Parea = areaQuad(s1, s2, diag, s3, s4);
                Pcost = ceil(Parea) * 18.5;
                jobCost += Pcost;
            }
            
            if(needsF)
            {
                Flength = perimQuad(s1, s2, diag, s3, s4);
                Fcost = (ceil(Flength) * 26) + 120;
                jobCost += Fcost;
            }
        }
        
        if(shape == "sect")
        {
            fin >> s1 >> a;
            
            if(needsP)
            {
                Parea = areaSect(s1, a);
                Pcost = ceil(Parea) * 18.5;
                jobCost += Pcost;
            }
            
            if(needsF)
            {
                Flength = perimSect(s1, a);
                Fcost = (ceil(Flength) * 26) + 120;
                jobCost += Fcost;
            }
        }
        
        if(checkIfPreferred(name))
            jobCost *= 0.9;
            
        tax = jobCost * 0.13;
        jobCost += tax;
        
       fout << setw(6) << jobNum << setw(7) << Parea << setw(10) << Pcost
         << setw(9) << Flength << setw(10) << Fcost << setw(9) << tax
         << setw(11) << checkIfPreferred(name) << setw(14) << jobCost << endl;
        
    }
    return 0;
}

/*
 
 Output:
 
 Job # P Area    P Cost F Length    F Cost      Tax    Preferred? Total Cost
 7100   6.00    111.00    12.00    432.00    63.53          1        552.23
 7101   9.60    185.00     0.00      0.00    24.05          0        209.05
 7102   2.36     55.50     0.00      0.00     6.49          1         56.44
 7103   0.00      0.00   116.00   3136.00   407.68          0       3543.68
 7104   0.00      0.00    31.42    952.00   111.38          1        968.18
 7105  70.16   1313.50     0.00      0.00   170.76          0       1484.26
 7106  72.30   1350.50    99.40   2720.00   529.16          0       4599.67
 7107 197.04   3663.00     0.00      0.00   428.57          1       3725.27
 7108  80.64   1498.50     0.00      0.00   194.81          0       1693.31
 7109  89.92   1665.00    16.81    562.00   289.51          0       2516.51
 7110   8.39    166.50     0.00      0.00    19.48          1        169.33
 7111   3.90     74.00     9.00    354.00    55.64          0        483.64
 7112   0.00      0.00    83.40   2304.00   299.52          0       2603.52
 
 */

