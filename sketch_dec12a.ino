// Symbolic Constants
#define LED0  11
#define LED1   9
#define LED2   6
#define LED3   3

#define SW0   12
#define SW1    8
#define SW2    7
#define SW3    4
#define TEMP  A0 
#define POT   A1
#define LIGHT A2

#define ANAINMAX 1023  // enter the max value for analog reads here
#define ANAOUTMAX 255 // enter the max value for analog writes here

#define BAUD 9600

#define SAMPLES 100

int MEASUREDELAY = 0;

/////////////////////////////////////////////////////////////////////////////
// setup
void setup()
{
  pinMode( LED0, OUTPUT );
  pinMode( LED1, OUTPUT );
  pinMode( LED2, OUTPUT );
  pinMode( LED3, OUTPUT );
  
  pinMode( SW0,   INPUT_PULLUP );
  pinMode( SW1,   INPUT_PULLUP );
  pinMode( SW2,   INPUT_PULLUP );
  pinMode( SW3,   INPUT_PULLUP );
  pinMode( TEMP,  INPUT_PULLUP ); 
  pinMode( POT,   INPUT_PULLUP );
  pinMode( LIGHT, INPUT_PULLUP );
  
  Serial.begin( BAUD ); 
  
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// wait_for_start
// Waits for a keypress in the Serial window
void wait_for_start()
{
  Serial.print("Press and release switch 0\n");
  while( HIGH == digitalRead(SW0) ) {}

  Serial.print("Release switch 0\n");
  while( LOW == digitalRead(SW0) ) {}
}

/////////////////////////////////////////////////////////////////////////////
// read_switches
// Reads the state of the four switches and updates passed in variables
void read_switches( int *switch0, int *switch1, int *switch2, int *switch3 )
{
  *switch0 = digitalRead( SW0 ); 
  *switch1 = digitalRead( SW1 );
  *switch2 = digitalRead( SW2 );
  *switch3 = digitalRead( SW3 );
}

/////////////////////////////////////////////////////////////////////////////
// read_pot
// Reads the potentiometer and returns its value as a percentage of the range
float read_pot( int port )
{
  float pot = analogRead( port );
  float percentage = pot / ANAINMAX; 
  return percentage;
}

/////////////////////////////////////////////////////////////////////////////
// read_temp
// Reads the temp sensor and returns its value as a percentage of the range
float read_temp( int port )
{
  int temp = analogRead( port );
  return (float)temp / (float)ANAINMAX;
}

/////////////////////////////////////////////////////////////////////////////
// read_light
// Reads the light sensor and returns its value as a percentage of the range
float read_light( int port )
{
  int light = analogRead( port );
  return (float)light / (float)ANAINMAX;
}

/////////////////////////////////////////////////////////////////////////////
// set_LEDs
void set_LEDs( int switch0, int switch1, int switch2, int switch3, 
               float pot, float temperature, float light )
{
  if( LOW == switch0 ) //Added = to make it ==
  {
    analogWrite( LED0, pot * ANAOUTMAX );
  }
  else
  {
    digitalWrite( LED0, LOW );
  }

  if( LOW == switch1 )
  {
    analogWrite( LED1, temperature * ANAOUTMAX );  
  }
  else
  {
    digitalWrite( LED1, LOW );
  }

  if( LOW == switch2 )
  {
    analogWrite( LED2, light * ANAOUTMAX );  
  }
  else
  {
    digitalWrite( LED2, LOW );
  }
  analogWrite( LED3, ((pot + temperature + light) / 3.0) * ANAOUTMAX );
}

/////////////////////////////////////////////////////////////////////////////
// print_stats
// prints settings to console window
void print_stats( int switch0, int switch1, int switch2, int switch3, 
                  float pot, float temperature, float light, 
                  int MEASUREDELAY )
{
  static int counter = 0;
  Serial.print("time:  ");
  Serial.print(MEASUREDELAY);
  Serial.print(" ms\n");
  Serial.print("switch0: ");
  Serial.print(switch0);
  Serial.print("\n");
  Serial.print("switch1: ");
  Serial.print(switch1);
  Serial.print("\n");
  Serial.print("switch2: ");
  Serial.print(switch2);
  Serial.print("\n");
  Serial.print("switch3: ");
  Serial.print(switch3);
  Serial.print("\n");
  Serial.print("potentiometer: ");
  Serial.print(pot);
  Serial.print("\n");
  Serial.print("temperature: ");
  Serial.print(temperature);
  Serial.print("\n");
  Serial.print("light: ");
  Serial.print(light);
  Serial.print("\n");
  Serial.print("---------------------------\n");
  // a command is missing here.  Roughly how often does this run?  How does
  // that relate to the time?
}

/////////////////////////////////////////////////////////////////////////////
// mark_end
// marks the end of a run
void mark_end() //Pretty sure this should be void
{
  Serial.print("ENDENDENDENDENDENDENDENDENDENDENDENDENDEND\n");
  Serial.end();
}


void loop()
{
  int switch0 = 0;
  int switch1 = 0;
  int switch2 = 0;
  int switch3 = 0;
  
  float temperature = 0;
  float pot = 0;
  float light = 0;
  
  int counter = 0;
  
  wait_for_start(); 
  
  for( counter = 0; counter < SAMPLES; ++counter )
  {
    read_switches( &switch0, &switch1, &switch2, &switch3 );
    pot = read_pot( POT );
    temperature = read_temp( TEMP );
    light = read_light( LIGHT );
    
    set_LEDs( switch0, switch1, switch2, switch3, pot, temperature, light );
    print_stats( switch0, switch1, switch2, switch3, 
                 pot, temperature, light, MEASUREDELAY );

    delay(40);   // 40 millisecond gap between each data collection
    MEASUREDELAY += 40;  // increments measure delay 
  }
  
  mark_end();
}



