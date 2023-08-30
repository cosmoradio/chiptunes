void setup() {
  // put your setup code here, to run once:
  // sn76489

  #define SN_D0 4
  #define SN_D1 3
  #define SN_D2 2
  #define SN_D3 10
  #define SN_D4 8
  #define SN_D5 13
  #define SN_D6 12
  #define SN_D7 11
  #define SN_WE 5

  #define CHP_SEL_1 14
  #define CHP_SEL_2 15
  #define CHP_SEL_3 16
  #define CHP_SEL_4 17  
  
  /* clocker */
  TCNT1 = 0;
  TCCR1B = B00001001;
  TCCR1A = B01000000;
  OCR1A = 1; // CLK frequency = 4 MHz
  DDRB |= (1 << DDB1);pinMode(9, OUTPUT); // 9 pin for clock
  /* clocker end*/
  /* set pins */

  pinMode(SN_D0, OUTPUT); 
  pinMode(SN_D1, OUTPUT); 
  pinMode(SN_D2, OUTPUT);
  pinMode(SN_D3, OUTPUT); 
  pinMode(SN_D4, OUTPUT); 
  pinMode(SN_D5, OUTPUT);
  pinMode(SN_D6, OUTPUT); 
  pinMode(SN_D7, OUTPUT);
  digitalWrite(SN_D0, LOW);
  digitalWrite(SN_D1, LOW);
  digitalWrite(SN_D2, LOW);
  digitalWrite(SN_D3, LOW);
  digitalWrite(SN_D4, LOW);
  digitalWrite(SN_D5, LOW);
  digitalWrite(SN_D6, LOW);
  digitalWrite(SN_D7, LOW);
  pinMode(SN_WE, OUTPUT); digitalWrite(SN_WE, LOW);

  pinMode(CHP_SEL_1, OUTPUT); digitalWrite(CHP_SEL_1, LOW);
  pinMode(CHP_SEL_2, OUTPUT); digitalWrite(CHP_SEL_2, LOW);
  pinMode(CHP_SEL_3, OUTPUT); digitalWrite(CHP_SEL_3, LOW);
  pinMode(CHP_SEL_4, OUTPUT); digitalWrite(CHP_SEL_4, LOW);


  SilenceAllChannels(); //mute all channels of SN76489
  //SilenceAllChannels(); //somtimes twice need on this 
  /**/
  digitalWrite(CHP_SEL_1, 0);  
  digitalWrite(CHP_SEL_2, 1);
  digitalWrite(CHP_SEL_3, 0);
  digitalWrite(CHP_SEL_4, 1);
  /**/
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int i = 90; //tempo (beats/min) control
  //-----------------------------------------------------
  sendByte(0x8E); sendByte(0x26);
  for(byte vol=0x90; vol<=0x93; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8A); sendByte(0x22);
  for(byte vol=0x90; vol<=0x92; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8E); sendByte(0x26);
  for(byte vol=0x90; vol<=0x93; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8A); sendByte(0x2B);
  for(byte vol=0x90; vol<=0x92; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x84); sendByte(0x2E);
  for(byte vol=0x90; vol<=0x93; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x84); sendByte(0x3A);
  for(byte vol=0x90; vol<=0x92; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8F); sendByte(0x33);
  for(byte vol=0x90; vol<=0x93; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8C); sendByte(0x3D);
  for(byte vol=0x90; vol<=0x92; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x84); sendByte(0x3A);
  for(byte vol=0x90; vol<=0x93; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  delay(i*7); //pause
  //-----------------------------------------------------
  sendByte(0x8F); sendByte(0x33);
  for(byte vol=0x90; vol<=0x91; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x84); sendByte(0x2E);
  for(byte vol=0x90; vol<=0x91; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8A); sendByte(0x2B);
  for(byte vol=0x90; vol<=0x91; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8E); sendByte(0x26);
  for(byte vol=0x90; vol<=0x91; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x8E); sendByte(0x1E);
  for(byte vol=0x90; vol<=0x91; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------
  sendByte(0x82); sendByte(0x1D);
  for(byte vol=0x90; vol<=0x9F; vol++)
  {
    sendByte(vol); delay(i);
  }
  //-----------------------------------------------------

}
void PutByte(byte b)
{
  digitalWrite(SN_D0, (b&1)?HIGH:LOW);
  digitalWrite(SN_D1, (b&2)?HIGH:LOW);
  digitalWrite(SN_D2, (b&4)?HIGH:LOW);
  digitalWrite(SN_D3, (b&8)?HIGH:LOW);
  digitalWrite(SN_D4, (b&16)?HIGH:LOW);
  digitalWrite(SN_D5, (b&32)?HIGH:LOW);
  digitalWrite(SN_D6, (b&64)?HIGH:LOW);
  digitalWrite(SN_D7, (b&128)?HIGH:LOW);
}
//==============================================================
void sendByte(byte b)
{
  digitalWrite(SN_WE, HIGH);
  PutByte(b);
  digitalWrite(SN_WE, LOW);
  delay(1);
  digitalWrite(SN_WE, HIGH);
}
//==============================================================
void SilenceAllChannels()
{
  sendByte(0x9F);               /*mute channel 1*/
  sendByte(0xBF);               /*mute channel 2*/
  sendByte(0xDF);               /*mute channel 3*/
  sendByte(0xFF);               /*mute noise channel*/
}
