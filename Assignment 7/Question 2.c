//Question 2

int spin()
{
    nMotorEncoder[motorA] = 0;
    
    motor[motorA] = 50;
    motor[motorC] = -50;
    
    while (SensorValue[S4] < 50);
    while (SensorValue[S4] > 50);
    
    motor[motorA] = 0;
    motor[motorC] = 0;
    return nMotorEncoder[motorA];
}

task main()
{
  SensorType[S4] = sensorSONAR;
  while(SensorValue[S4] > 50);

  float average = 0;
  int encoder_cnt = 0;
  encoder_cnt = spin();

  for (int i = 0; i < 4; i++)
  {
    encoder_cnt = spin();
    nxtDisplayString(i, "%d", encoder_cnt);
    average += encoder_cnt;
  }

  average = average/1440;
  nxtDisplayString(4, "Average: %f",average);
  nxtDisplayString(5, "Tues 25");
  while(nNxtButtonPressed == -1);
}

/*

Output:

1777
1780
1774
1776
Average: 4.935417
Tues 25

This output is useful when you would want to make a robot turn a specific number of degrees more efficiently and less time consuming as opposed to testing out different motor speeds at different wait times. The number can be used to set the specific number of degrees you would like to turn and incorporate it in a loop or a function.

*/
    