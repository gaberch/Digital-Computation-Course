//Question 2

void position(int latDeg, int latMin, int longDeg, int longMin, double & x, double & y);
{
	x = 111*cos(latDeg+latMin/60.0)*(longDeg+longMin/60.0);
	y = 111*(latDeg+latMin/60.0);
}

int getShipData(ifstream & finShip, string ship[], double x[], double y[], double speedK[]);
{
    int latDeg, latMin, longDeg, longMin, count = 0;
    for (int i = 0; i < 50 && fin >> ship[i]; i++)
	{
		fin >> ship[i] >> latDeg >> latMin >> longDeg >> longMin >> speedK[i]; 
     position (latDeg, latMin, longDeg, longMin, x[i], y[i]);
		count++;
   }
return count;
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double timeShip(double x1, double y1, double x2, double y2, double speedK)
{
  speedK *= 1.8536;
  if (speedK == 0)
	return 0;
  else
   return dist(x1,y1,x2,y2)/speedK;
}

void shipCheck (int num, double x1[], double y1[], double speedK[], double x2, double y2, int & ship_num, double & time)
{
	double min_dist = 5000;
   int min_dist_index = 0;
	for (int i =0; i < num, i++)
	{
		if (min_distance > dist(x1

	
int main()
{
	


