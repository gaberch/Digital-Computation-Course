void speedCon(int & initpow, int button, int count);
void incSpeed(int & initpow, int count);
void decSpeed(int & initpow, int count);
void sound(bool distCheck, bool depthCheck, int & iniPow, int & count);
bool distCheck();
bool depthCheck();



task main()
{
    SensorType[S1] = sensorTouch; //handle sensor
    SensorType[S2] = sensorTouch; //collision sensor
    SensorType[S3] = sensorSONAR; //forward check sensor
    SensorType[S4] = sensorSONAR; //depth check sensor
    int iniPow = 0, button, count = 0;

    PlaySoundFile("MS_sfx_note_01.rso");
    while (nNxtButtonPressed != 3);
    while (nNxtButtonPressed == 3);
    button = nNxtButtonPressed;
    wait1Msec(2000);
    // wait for orange button to be pressed

    PlaySoundFile("MSVoiceTouchMyS.rso");
    while (!SensorValue[S1]);
    //wait for handle to be held

    speedCon(iniPow,button,count);
    //initilizing motor power to 50
    do
    {
        if (nNxtButtonPressed == 1 || nNxtButtonPressed == 2)
        {
          button = nNxtButtonPressed;
          while (nNxtButtonPressed != -1);
          speedCon(iniPow,button,count);
        }
    sound(distCheck(), depthCheck(), iniPow, count);


    if (!SensorValue[S1])
        {
            motor[motorA] = 0;
            motor[motorB] = 0;
            motor[motorC] = 0;
            time10[1] = 0;
            PlaySoundFile("MSVoiceTouchMyS.rso");
            while (!SensorValue[S1])
            {
                if (time10[1] > 6000)
                    StopAllTasks();
            }
        }

    }
    while (SensorValue[S1]);
}



void speedCon(int & initpow, int button, int & count)
{
    if(initpow==0 && count == 0)

     { 	//setting the default speed
       count++;
       for(int i=0; i<5; i++)
        {
          incSpeed(initpow,count);
        }
     }
   else if(button==1)
   {
      incSpeed(initpow,count);
   }
   else if(button==2)
   {
      decSpeed(initpow,count);
    }
    // setting the new speed so it can be used in the while statement

}

//increase speed function
void incSpeed(int & initpow, int & count)
{
      for(int i=0; i<=9; i++)
        {
         if (distCheck() || depthCheck())
             i = 10;
         time1[0] = 0;
         ++initpow;
         motor[motorA] = -initpow;
         motor[motorB] = initpow;
         motor[motorC] = -initpow;
         while(time1[0] < 50 && !distCheck()  && !depthCheck() && SensorValue[S1]);
      }
      sound(distCheck(), depthCheck(), initpow, count);
}

//decrease speed function
void decSpeed(int & initpow, int & count)
{
   for(int i=9; i>=0; i--)
   {
         if (distCheck() || depthCheck())
           i = -1;
         time1[0] = 0;
         --initpow;
         motor[motorA] = -initpow;
         motor[motorB] = initpow;
         motor[motorC] = -initpow;
         while(time1[0] < 50 &&  !distCheck()  && !depthCheck() &&  SensorValue[S1]);
    }
    sound(distCheck(), depthCheck(), initpow, count);
}

//Sound function that check for depth and distance and executes the necessary procedures
void sound(bool distCheck, bool depthCheck, int & iniPow, int & count)
{
    if (distCheck() || depthCheck())
    {
        count = 0;
        iniPow = 0;
        motor[motorA] = 0;
        motor[motorB] = 0;
        motor[motorC] = 0;
        if (distCheck())
            PlaySoundFile("MSVoiceMoveAway.rso");
        else if(depthCheck())
            PlaySoundFile("MS_voice_Danger.rso");
        wait1Msec(3000);
        PlaySoundFile("MS_sfx_note_01.rso"); //waiting for orange button to be pressed and released once again
        while (nNxtButtonPressed != 3);
        while (nNxtButtonPressed == 3);
        speedCon(iniPow, nNxtButtonPressed,count);
     }
    
}





// SONAR SENSOR FUNCTIONS

bool distCheck()
{
    if(SensorValue[S3] < 30 || SensorValue[S2])
       return true;
    else
       return false;
}

bool depthCheck()
{
    if(SensorValue[S4] > 10)
       return true;
    else
       return false;
}