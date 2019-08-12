//Question 1

int buttonValue(int button)
{
  while (nNxtButtonPressed == -1)
  button = nNxtButtonPressed;
  while (nNxtButtonPressed != -1);
  return button;
}

void run(int button)
{
  if (button == 2)
  {
    for (int count = 0; count < 4; count ++)
    {
      motor[motorC] = 50;
      motor[motorA] = 50;
      wait1Msec(3000);
      motor[motorA] = -50;
      wait1Msec(900);
    }
  }
  else if (button == 1)
  {
    for (int i = 0; i < 4; i ++)
    {
      motor[motorC]= 50;
      motor[motorA] = 50;
      wait1Msec(3000);
      motor[motorC] = -50;
      wait1Msec(900);
    }
  }
  motor[motorA] = 0;
  motor[motorC] = 0;
}

task main ()
{
  int button;
  while (button != 3)
  {
    button = buttonValue(nNxtButtonPressed);
    if (button != 3)
    	run(button);
  }
  nxtDisplayString(0, "Tues 25");
  wait1Msec(2000);
}