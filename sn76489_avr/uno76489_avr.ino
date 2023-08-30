void setup() {
  // sn76489

  /*
   *      d5 p1  ad13
   *      d6 p2  ad12
   *      d7 p3  ad11
   *      rd p4  ad
   *      we p1  ad
   *      ce p1  ad
   *      aout 2*2
   *      gnd to all
   *      
   *      vcc p16
   *      d4  p15 ad8
   *      clk p14 ad9 4MHZ to all
   *      d3  p13 ad10
   *      d2  p12 ad2 
   *      d1 p11  ad3
   *      d0 p10 ad4
   *      nc
   * 
   * a0-a3 - controls
   * 
   */

  initMusdriver();
  
  #define SN_D0 PD4
  #define SN_D1 PD3
  #define SN_D2 PD2
  #define SN_D3 PB2
  #define SN_D4 PB0
  #define SN_D5 PB5
  #define SN_D6 PB4
  #define SN_D7 PB3
  #define SN_WE PD5

  #define CHP_SEL_1 PC0
  #define CHP_SEL_2 PC1
  #define CHP_SEL_3 PC2
  #define CHP_SEL_4 PC3

  #define SN76489_C 4
  
  
  /* clocker */
  TCNT1 = 0;
  TCCR1B = B00001001;
  TCCR1A = B01000000;
  OCR1A = 1; // CLK frequency = 4 MHz
  DDRB |= (1 << DDB1);//pinMode(9, OUTPUT); // 9 pin for clock
  /* clocker end*/
  /* set pins */
  // data bus to output and set low level
  /**/
  DDRD |= (1 << DDD4);  PORTD &= ~(1 << PD4);//4 pin arduino
  DDRD |= (1 << DDD3);  PORTD &= ~(1 << PD3);//3
  DDRD |= (1 << DDD2);  PORTD &= ~(1 << PD2);//2
  DDRB |= (1 << DDB5);  PORTB &= ~(1 << PB5);//13
  DDRB |= (1 << DDB4);  PORTB &= ~(1 << PB4);//12
  DDRB |= (1 << DDB3);  PORTB &= ~(1 << PB3);//11 
  DDRB |= (1 << DDB2);  PORTB &= ~(1 << PB2);//10
  DDRB |= (1 << DDB0);  PORTB &= ~(1 << PB0);//8
  //bus-select chipt
  DDRC |= (1 << DDC0);  PORTC &= ~(1 << PC0);
  DDRC |= (1 << DDC1);  PORTC &= ~(1 << PC1);
  DDRC |= (1 << DDC2);  PORTC &= ~(1 << PC2);
  DDRC |= (1 << DDC3);  PORTC &= ~(1 << PC3);
  DDRD |= (1 << DDD5);  PORTD &= ~(1 << PD5);//8//pinMode(SN_WE, OUTPUT); digitalWrite(SN_WE, LOW);


  muteChannels( 0,0); //mute all channels of SN76489
  muteChannels( 0,0);
  
  PORTC &= ~(1 << CHP_SEL_1);//digitalWrite(CHP_SEL_1, 0);  // LOW for select
  PORTC &= ~(1 << CHP_SEL_2);//digitalWrite(CHP_SEL_2, 0);
  PORTC &= ~(1 << CHP_SEL_3);//digitalWrite(CHP_SEL_3, 0);
  PORTC &= ~(1 << CHP_SEL_4);//digitalWrite(CHP_SEL_4, 0);
  /**/
}

void loop() {
  Serial.println("qweqwe");
  //readPakage()
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
muteChannels(0,0);
}

void sendByte(byte b)
{
  PORTD |= (1 << SN_WE);        //digitalWrite(SN_WE, HIGH);
  //PutByte(b);
  digitalWrite(SN_D0, (b&1)?HIGH:LOW);
  digitalWrite(SN_D1, (b&2)?HIGH:LOW);
  digitalWrite(SN_D2, (b&4)?HIGH:LOW);
  digitalWrite(SN_D3, (b&8)?HIGH:LOW);
  digitalWrite(SN_D4, (b&16)?HIGH:LOW);
  digitalWrite(SN_D5, (b&32)?HIGH:LOW);
  digitalWrite(SN_D6, (b&64)?HIGH:LOW);
  digitalWrite(SN_D7, (b&128)?HIGH:LOW);
  PORTD &= ~(1 << SN_WE);       //digitalWrite(SN_WE, LOW);
  delay(1);
  PORTD |= (1 << SN_WE);        //digitalWrite(SN_WE, HIGH);
}
//==============================================================
void muteChannels(int chip ,int channel)
{
  
  switch(chip){
    case 0: //to all chip
      Serial.println("all up");
      digitalWrite(CHP_SEL_1, 0);  // LOW for select
      digitalWrite(CHP_SEL_2, 0);
      digitalWrite(CHP_SEL_3, 0);
      digitalWrite(CHP_SEL_4, 0);
      break;
    case 1: //to 1st chip
      break;
    case 2: //to 2nd chip
      break;
    case 3: //to 3d chip
      break; 
    case 4: //to 4 chip
      break;           
  }
  switch(channel)
  {
    case 0:// to all chanells
      sendByte(0x9F); //mute channel 0
      sendByte(0xBF); //mute channel 1
      sendByte(0xDF); //mute channel 2
      sendByte(0xFF); //mute noise channel
      break;
    case 1:
      sendByte(0x9F); //mute channel 0
      break;
    case 2:
      sendByte(0xBF); //mute channel 1
      break;
    case 3:
      sendByte(0xDF); //mute channel 2
      break;
    case 4:
      sendByte(0xFF); //mute channel 3
      break;      
  }
}

void resetChip(char b){
  if( b == 0);// можно завести заглушку со свободного порта на res или JUMP to 0,0
}

void noteOn(char channel, char inst, char note){
  
}

void noteOff(char channel, char inst){
  
}
void setTone(byte channel, uint16_t freq)
{
  uint16_t f76489;
  f76489 = 4000000UL/(32*freq); /*compute 10-bit tone freq*/
  //----------------------------------------------------------------------
  switch(channel)               /*send 1st byte to channel 1, 2, or 3*/
  {
    case 1: sendByte(0x80 | (f76489 & 0x0F)); break;
    case 2: sendByte(0xA0 | (f76489 & 0x0F)); break;
    case 3: sendByte(0xC0 | (f76489 & 0x0F));
  }
  sendByte(f76489>>4);          /*send 2nd byte*/
  //----------------------------------------------------------------------
  switch(channel)               /*max audio @ channel 1, 2, or 3*/
  {
    case 1: sendByte(0x90); break;
    case 2: sendByte(0xB0); break;
    case 3: sendByte(0xD0);
  }
}

void noiseOn(boolean noiseType, byte shiftRate)
{
  if(noiseType==0)
  {
    sendByte(0xE0|shiftRate);     /*perioic noise*/
    sendByte(0xF0);
  }
  else
  {
    sendByte(0xE4|shiftRate);     /*white noise*/
    sendByte(0xF0);
  }
}
