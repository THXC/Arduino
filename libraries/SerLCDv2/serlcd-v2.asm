
; CC5X Version 3.1I, Copyright (c) B Knudsen Data
; C compiler for the PICmicro family
; ************   7. Jan 2005  16:37  *************

	processor  16F688
	radix  DEC

INDF        EQU   0x00
PCL         EQU   0x02
STATUS      EQU   0x03
FSR         EQU   0x04
PORTA       EQU   0x05
TRISA       EQU   0x85
PCLATH      EQU   0x0A
Carry       EQU   0
Zero_       EQU   2
RP0         EQU   5
RP1         EQU   6
IRP         EQU   7
T0IF        EQU   2
T0IE        EQU   5
GIE         EQU   7
OPTION_REG  EQU   0x81
PORTC       EQU   0x07
SPBRG       EQU   0x13
RCREG       EQU   0x14
TXSTA       EQU   0x16
RCSTA       EQU   0x17
CMCON0      EQU   0x19
TRISC       EQU   0x87
OSCCON      EQU   0x8F
ANSEL       EQU   0x91
EEDATA      EQU   0x9A
EEADR       EQU   0x9B
EECON2      EQU   0x9D
PEIE        EQU   6
RCIF        EQU   5
EEIF        EQU   7
RCIE        EQU   5
RD          EQU   0
WR          EQU   1
WREN        EQU   2
EEPGD       EQU   7
letter      EQU   0x27
cursor_position EQU   0x28
splash_enable EQU   0x29
backlight_counter EQU   0x2A
brightness_setting EQU   0x2B
Backlight_Setting EQU   0x2C
LCD_Width   EQU   0x2E
LCD_Lines   EQU   0x2F
EL1         EQU   0x30
EL2         EQU   0x31
EL3         EQU   0x32
EL4         EQU   0x33
CP1         EQU   0x34
CP2         EQU   0x35
CP3         EQU   0x36
CP4         EQU   0x37
RX_In       EQU   0x38
Displayed_Letters EQU   0x39
s1_save     EQU   0x70
s2          EQU   0x20
s3          EQU   0x21
sv_FSR      EQU   0x22
i           EQU   0
c           EQU   0x25
d           EQU   0x23
incoming_string EQU   0x23
x           EQU   0x24
x_2         EQU   0x23
y           EQU   0x25
z           EQU   0x26
e_address   EQU   0x23
e_data      EQU   0x23
e_address_2 EQU   0x24
temp_GIE    EQU   0
ci          EQU   0x25

	GOTO main

  ; FILE D:\Pics\code\16F630\SerLCD\serlcd-v2.c
			;/*
			;    1-16-04
			;    Copyright Spark Fun Electronics© 2004
			;    
			;    Uses 16F688 to drive Parallel LCD with Serial Commands.
			;    
			;    For educational and hobbyist use only. NOT for commerical use.
			;
			;    Thanks to Olimex for providing the original C test code for the PIC-MT-C w/ 16F873
			;    
			;    1-17-04 Started migrating 16F873A code to 16F630
			;
			;    1-17-04pm Works well from user keyboard input. No busy flag checking yet.
			;              Ok, busy flag works.
			;
			;    1-19-04 Got commands to pass through after decimal 254 is seen. The special 8-bit data
			;            mode command is also correctly ignored.
			;            
			;    1-30-04 v1.1 Added 16x4 line support
			;    
			;    2-10-04 v1.2 Added BL Control. Moved to direct RC0-RC3 = D4-D7 mapping. This significantly
			;            improved timing between characters.
			;    
			;    2-12-04 Added EEPROM recording of Backlight State. Also added Super Special
			;            Command input. Pass the '|' character to the LCD, then pass '1' to turn
			;            on/off backlight.
			;            
			;            Added universal support for any LCD upto 4 lines, 40 characters wide.
			;            
			;    2-16-04 New PCBs v1.1 - Replaced some if statements with EL1, EL2, etc, in the 4 line wrapping 
			;            routine to try to speed things up.
			;            
			;    2-17-04 v1.3 Timing has now been nearly reduced to within one stop bit. In the past, 
			;            wrapping characters were some times lost because of the time required to relocate 
			;            the cursor. Now almost all characters are seen, every time, every location. 
			;            There are stuff certain combinations that cause a character miss.
			;    
			;    3-3-04 New PCB - 1.1a. BL Control has been routed to PGC - bad idea. Causes problems with programming.
			;           Unit must be powered +5V while programming to get it to work. Will move this line on next revision.
			;           
			;    4-5-04 Customer reported problems with interface. Baud rate was too low. The test bed was running 
			;           at much too low of a speed. The test bed has been corrected, the code must now be tweaked.
			;           
			;    4-14-04 Added a special command 8 that will re-initialize the LCD. There are certain circumstances (low
			;            power) where the PIC will keep running, but the LCD will shut down. 
			;
			;    6-1-04 Re-routed some pins for a smoother PCB layout. Firmware had to be updated.
			;
			;    7-7-04 Added support for 40x2 displays
			;    
			;    12-15-04 New version - SerLCD v2 using 16F688
			;             Incoming characters buffered
			;             PWM of back light
			;             Turning off splash screen
			;             Higher data speeds
			;             
			;             We now use the 16F688 with onboard UART and internal 8MHz oscillator. The internal oscillator is much
			;             tighter tolerance and the UART interrupt is used. The incoming characters are automatically buffered,
			;             up to 80 characters can be stored at a time in case the LCD is busy doing other things.
			;             
			;             The backlight is now pulse width modulated. What this means is you can set how bright the backlight is
			;             from 0 (off) to 30 (completely on). This will greatly effect how much current the module uses while 
			;             retaining part of the ability to see in low light conditions. The backlight defaults to maximum 
			;             output (brightest) unless otherwise configured by the user. To control the backlight, send the 'special
			;             command' character (124) followed by 0b.100?.???? where ?? is the value from 0-30.
			;             
			;             You can now turn off the splash screen. Send the 'special command' character 124 followed by decimal 9.
			;             The splash screen option will toggle and will take effect the next time the LCD is initialized (power-up).
			;    
			;*/
			;#define Clock_8MHz
			;#define Baud_9600
			;//#define DEBUG
			;
			;#include "d:\Pics\c\16F688.h"  // device dependent interrupt definitions
			;#include "d:\Pics\c\int16CXX.H"
			;
			;#pragma config|= 0x31C4 //Internal 8MHz Oscilator, PWRT
			;
			;//LCD Type
			;#define Display_16x2    0
			;#define Display_16x4    1
			;
			;//Hardware port definitions
			;#define     RS              PORTA.5
			;#define     R_W             PORTA.4
			;#define     BL_Control      PORTA.2
			;#define     E               PORTA.0
			;
			;#define     D4              PORTC.0
			;#define     D5              PORTC.1
			;#define     D6              PORTC.2
			;#define     D7              PORTC.3
			;
			;//Constant definitions
			;#define     FALSE       0
			;#define     TRUE        1
			;
			;#define     LCD_BACKLIGHT_SETTING   0
			;#define     LCD_WIDTH_SETTING       1
			;#define     LCD_LINE_SETTING        2
			;#define     LCD_BRIGHTNESS_SETTING  3
			;#define     LCD_SPLASH_ENABLE       4
			;
			;#define     CLR_DISP        0b.0000.0001 //Clear display
			;
			;#define     CUR_HOME        0b.0000.0010    //Move cursor home and clear screen memory
			;#define     CUR_RIGHT       0b.0001.0100    //Move cursor one to right
			;#define     CUR_LEFT        0b.0001.0000    //Move cursor one to left
			;
			;#define     SCROLL_RIGHT    0b.0001.1100    //Scroll entire screen right one space
			;#define     SCROLL_LEFT     0b.0001.1000    //Scroll entire screen left one space
			;
			;#define     DISP_ON         0b.0000.1100    //Turn visible LCD on
			;#define     DISP_OFF        0b.0000.1000    //Turn visible LCD off
			;
			;#define     UNDERLINE_ON    0b.0000.1110    //Turn on underlined cursor
			;#define     UNDERLINE_OFF   0b.0000.1100    //Turn off underlined cursor
			;
			;#define     BLINKCUR_ON     0b.0000.1101    //Turn on blinking box cursor
			;#define     BLINKCUR_OFF    0b.0000.1100    //Turn off blinking box cursor
			;
			;#define     DUALCUR_ON      0b.0000.1111    //Turn on blinking box and underline cursor
			;#define     DUALCUR_OFF     0b.0000.1100    //Turn off blinking box and underine cursor
			;
			;#define     SET_CURSOR      0b.1000.0000    //SET_CURSOR + X : Sets cursor position to X
			;
			;#define     ENTRY_INC       0b.0000.0110 //
			;#define     DD_RAM_ADDR     0b.1000.0000 //
			;#define     DD_RAM_ADDR2    0b.1100.0000 //
			;#define     CG_RAM_ADDR     0b.0100.0000 //
			;
			;//Global variable declarations
			;uns8 letter;
			;uns8 cursor_position;
			;uns8 splash_enable;
			;
			;uns8 backlight_counter;
			;uns8 brightness_setting;
			;uns8 Backlight_Setting;
			;
			;uns8 LCD_Type;
			;uns8 LCD_Width;
			;uns8 LCD_Lines;
			;uns8 EL1, EL2, EL3, EL4;
			;uns8 CP1, CP2, CP3, CP4;
			;
			;uns8 RX_In;
			;uns8 Displayed_Letters;
			;
			;#pragma rambank 1
			;#define BUFFER_SIZE 80
			;uns8 RX_Array[BUFFER_SIZE];
			;#pragma rambank 0
			;//End Global variable declarations
			;
			;
			;//Interrupt Vectors
			;#pragma origin 4
	ORG 0x0004
			;interrupt serverX( void)
			;{
serverX
			;    int_save_registers
	MOVWF s1_save
	SWAPF STATUS,W
	BCF   0x03,RP0
	BCF   0x03,RP1
	MOVWF s2
	MOVF  PCLATH,W
	MOVWF s3
	CLRF  PCLATH
			;    char sv_FSR = FSR;  // save FSR if required
	MOVF  FSR,W
	MOVWF sv_FSR
			;
			;    if(RCIF) //If we have received something from the computer store it in the RX_Array array
	BTFSS 0x0C,RCIF
	GOTO  m001
			;    {
			;        RX_In++;
	INCF  RX_In,1
			;        if(RX_In == BUFFER_SIZE) RX_In = 0;
	MOVF  RX_In,W
	XORLW .80
	BTFSC 0x03,Zero_
	CLRF  RX_In
			;        
			;        RX_Array[RX_In] = RCREG;
	MOVLW .160
	ADDWF RX_In,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  RCREG,W
	MOVWF INDF
			;    }
			;
			;    if(T0IF) //TMR0 Overflow Interrupt - Occurs every 1024us ~1ms
m001	BTFSS 0x0B,T0IF
	GOTO  m004
			;    {
			;        backlight_counter++;
	INCF  backlight_counter,1
			;
			;        if(backlight_counter == 30)
	MOVF  backlight_counter,W
	XORLW .30
	BTFSS 0x03,Zero_
	GOTO  m002
			;        {
			;            backlight_counter = 0; //30ms pulse width period
	CLRF  backlight_counter
			;            
			;            BL_Control = 1; //Kick on the back light
	BSF   PORTA,2
			;        }    
			;
			;        //Turn off back light after its assigned duration
			;        else if(backlight_counter == brightness_setting) BL_Control = 0; 
	GOTO  m003
m002	MOVF  backlight_counter,W
	XORWF brightness_setting,W
	BTFSC 0x03,Zero_
	BCF   PORTA,2
			;        
			;        T0IF = 0; //Clear Interrupt Flag
m003	BCF   0x0B,T0IF
			;    }
			;    
			;    FSR = sv_FSR;               // restore FSR if saved
m004	MOVF  sv_FSR,W
	MOVWF FSR
			;    int_restore_registers 
	MOVF  s3,W
	MOVWF PCLATH
	SWAPF s2,W
	MOVWF STATUS
	SWAPF s1_save,1
	SWAPF s1_save,W
			;}
	RETFIE
			;
			;//Function declarations
			;void boot_up(void);
			;void send_char(uns8);
			;void send_cmd(uns8);
			;void special_commands(void);
			;void delay_ms(uns16);
			;void send_string(const char* incoming_string);
			;void delay_ms(uns16);
			;void LCD_wait(void);
			;uns8 onboard_eeread(uns8 e_address);
			;void onboard_eewrite(uns8 e_data, uns8 e_address);
			;void init_lcd(void);
			;
			;//End Function declarations
			;
			;void main(void)
			;{
_const1
	MOVWF ci
	MOVLW .27
	SUBWF ci,W
	BTFSC 0x03,Carry
	RETLW .0
	CLRF  PCLATH
	MOVF  ci,W
	ADDWF PCL,1
	RETLW .32
	RETLW .32
	RETLW .83
	RETLW .112
	RETLW .97
	RETLW .114
	RETLW .107
	RETLW .70
	RETLW .117
	RETLW .110
	RETLW .46
	RETLW .99
	RETLW .111
	RETLW .109
	RETLW .0
	RETLW .32
	RETLW .32
	RETLW .83
	RETLW .101
	RETLW .114
	RETLW .76
	RETLW .67
	RETLW .68
	RETLW .32
	RETLW .118
	RETLW .50
	RETLW .0
main
			;
			;    //Initialize LCD and PIC
			;    boot_up();
	BSF   0x03,RP0
	BCF   0x03,RP1
	CALL  boot_up
			; 
			;    while(1)
			;    {
			;        //sleep(); //Wait for incoming command to wake us up...
			;        //nop(); //Executes after wake-up and before INTF runs
			;        
			;        if(RX_In != Displayed_Letters)
	BCF   0x03,RP0
m005	MOVF  RX_In,W
	XORWF Displayed_Letters,W
	BTFSC 0x03,Zero_
	GOTO  m005
			;        {
			;            Displayed_Letters++;
	INCF  Displayed_Letters,1
			;            if(Displayed_Letters == BUFFER_SIZE) Displayed_Letters = 0;
	MOVF  Displayed_Letters,W
	XORLW .80
	BTFSC 0x03,Zero_
	CLRF  Displayed_Letters
			;
			;            letter = RX_Array[Displayed_Letters];
	MOVLW .160
	ADDWF Displayed_Letters,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  INDF,W
	MOVWF letter
			;
			;
			;            //Check for special LCD command
			;            //===============================================================
			;            if (letter == 254)
	XORLW .254
	BTFSS 0x03,Zero_
	GOTO  m009
			;            {
			;                //Wait for the next letter
			;                while(RX_In == Displayed_Letters);
m006	MOVF  RX_In,W
	XORWF Displayed_Letters,W
	BTFSC 0x03,Zero_
	GOTO  m006
			;                
			;                //Look at the next letter
			;                Displayed_Letters++;
	INCF  Displayed_Letters,1
			;                if(Displayed_Letters == BUFFER_SIZE) Displayed_Letters = 0;
	MOVF  Displayed_Letters,W
	XORLW .80
	BTFSC 0x03,Zero_
	CLRF  Displayed_Letters
			;
			;                letter = RX_Array[Displayed_Letters];
	MOVLW .160
	ADDWF Displayed_Letters,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  INDF,W
	MOVWF letter
			;                
			;                //Ignore the one command that will send the LCD into 8-bit mode
			;                if ( (letter >> 4) != 3 ) //If not 0b.0000.0011, then send it to LCD
	SWAPF letter,W
	ANDLW .15
	XORLW .3
	BTFSC 0x03,Zero_
	GOTO  m007
			;                    send_cmd(letter);
	MOVF  letter,W
	CALL  send_cmd
			;                    
			;                //Correct cursor position variable if certain commands are received
			;                if (letter == CLR_DISP)
m007	DECFSZ letter,W
	GOTO  m008
			;                    cursor_position = 0;
	CLRF  cursor_position
			;                else if (letter.7 == 1) //Move cursor command
	GOTO  m005
m008	BTFSS letter,7
	GOTO  m005
			;                    cursor_position = letter & 0b.0111.1111; //Ignore first bit - obtain address
	MOVLW .127
	ANDWF letter,W
	MOVWF cursor_position
			;            }    
			;            //===============================================================
			;
			;            //Super Special LCD Commands
			;            //===============================================================
			;            else if (letter == 124) //This is the '|' character above '\'
	GOTO  m005
m009	MOVF  letter,W
	XORLW .124
	BTFSS 0x03,Zero_
	GOTO  m011
			;            {
			;                //Wait for the next letter
			;                while(RX_In == Displayed_Letters);
m010	MOVF  RX_In,W
	XORWF Displayed_Letters,W
	BTFSC 0x03,Zero_
	GOTO  m010
			;
			;                //Look at the next letter
			;                Displayed_Letters++;
	INCF  Displayed_Letters,1
			;                if(Displayed_Letters == BUFFER_SIZE) Displayed_Letters = 0;
	MOVF  Displayed_Letters,W
	XORLW .80
	BTFSC 0x03,Zero_
	CLRF  Displayed_Letters
			;
			;                letter = RX_Array[Displayed_Letters];
	MOVLW .160
	ADDWF Displayed_Letters,W
	MOVWF FSR
	BCF   0x03,IRP
	MOVF  INDF,W
	MOVWF letter
			;
			;                special_commands();
	CALL  special_commands
			;            }
			;            //===============================================================
			;
			;            //All else, just print it to the LCD and adjust the cursor position
			;            //===============================================================
			;            else
	GOTO  m005
			;            {   
			;                #ifdef DEBUG  
			;                    if (letter == '+') brightness_setting++;
			;                    if (brightness_setting > 30) brightness_setting = 0;
			;                    
			;                    if( letter == 'A')
			;                    {
			;                        letter = 0b.1000.0000 | 15;
			;                        special_commands();
			;                    }
			;                #endif
			;                    
			;                send_char(letter);
m011	MOVF  letter,W
	CALL  send_char
			;    
			;                cursor_position++;
	INCF  cursor_position,1
			;    
			;                //When the cursor gets to the end of one line, it must
			;                //advance to the next visual line
			;                //===============================================================
			;                if (cursor_position == EL1) //End of line one
	MOVF  cursor_position,W
	XORWF EL1,W
	BTFSS 0x03,Zero_
	GOTO  m013
			;                {
			;                    if(LCD_Lines == 1)
	DECFSZ LCD_Lines,W
	GOTO  m012
			;                    {
			;                        cursor_position = 0; //Return to beginning of line 1
	CLRF  cursor_position
			;                        send_cmd(CP1);
	MOVF  CP1,W
	CALL  send_cmd
			;                    }
			;                    else
	GOTO  m005
			;                    {
			;                        cursor_position = 64; //Beginning of line 2
m012	MOVLW .64
	MOVWF cursor_position
			;                        send_cmd(CP2);
	MOVF  CP2,W
	CALL  send_cmd
			;                    }
			;                }
			;                
			;                else if (cursor_position == EL2) //End of line 2
	GOTO  m005
m013	MOVF  cursor_position,W
	XORWF EL2,W
	BTFSS 0x03,Zero_
	GOTO  m015
			;                {
			;                    if(LCD_Lines == 2)
	MOVF  LCD_Lines,W
	XORLW .2
	BTFSS 0x03,Zero_
	GOTO  m014
			;                    {
			;                        cursor_position = 0; //Return to line 1
	CLRF  cursor_position
			;                        send_cmd(CP1);
	MOVF  CP1,W
	CALL  send_cmd
			;                    }
			;                    else
	GOTO  m005
			;                    {
			;                        cursor_position = LCD_Width; //Beginning of line 3
m014	MOVF  LCD_Width,W
	MOVWF cursor_position
			;                        send_cmd(CP3);
	MOVF  CP3,W
	CALL  send_cmd
			;                    }
			;                }
			;                
			;                else if (cursor_position == EL3) //End of line 3
	GOTO  m005
m015	MOVF  cursor_position,W
	XORWF EL3,W
	BTFSS 0x03,Zero_
	GOTO  m016
			;                {
			;                    cursor_position = EL2; //Beginning of line 4 is the end of line 2
	MOVF  EL2,W
	MOVWF cursor_position
			;                    send_cmd(CP4);
	MOVF  CP4,W
	CALL  send_cmd
			;                }
			;                
			;                else if (cursor_position == EL4) //End of line 4
	GOTO  m005
m016	MOVF  cursor_position,W
	XORWF EL4,W
	BTFSS 0x03,Zero_
	GOTO  m005
			;                {
			;                    cursor_position = 0; //Beginning of line 1
	CLRF  cursor_position
			;                    send_cmd(CP1);
	MOVF  CP1,W
	CALL  send_cmd
			;                }
			;                //===============================================================
			;            }
			;            //===============================================================
			;                
			;
			;        }//End regular character printing
			;            
			;   }//End infinite loop
	GOTO  m005
			;
			;}//End Main
			;
			;//This is called when the control character is received.
			;//The control character is 124 or '|' (above the '\' on standard US layout keyboards)
			;void special_commands(void)
			;{
special_commands
			;
			;    //Backlight control
			;    if (letter == 1)
	DECFSZ letter,W
	GOTO  m017
			;    {
			;        Backlight_Setting = 1; //Turn on backlight setting
	MOVLW .1
	MOVWF Backlight_Setting
			;        BL_Control = Backlight_Setting; //Turn on backlight
	MOVF  Backlight_Setting,W
	BTFSS 0x03,Zero_
	BSF   PORTA,2
	BTFSC 0x03,Zero_
	BCF   PORTA,2
			;        onboard_eewrite(Backlight_Setting, LCD_BACKLIGHT_SETTING); //Record to EEPROM
	MOVWF e_data
	MOVLW .0
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 2)
	GOTO  m028
m017	MOVF  letter,W
	XORLW .2
	BTFSS 0x03,Zero_
	GOTO  m018
			;    {
			;        Backlight_Setting = 0; //Turn off backlight setting
	CLRF  Backlight_Setting
			;        BL_Control = Backlight_Setting; //Turn off backlight
	MOVF  Backlight_Setting,W
	BTFSS 0x03,Zero_
	BSF   PORTA,2
	BTFSC 0x03,Zero_
	BCF   PORTA,2
			;        onboard_eewrite(Backlight_Setting, LCD_BACKLIGHT_SETTING); //Record to EEPROM
	MOVWF e_data
	MOVLW .0
	CALL  onboard_eewrite
			;    }
			;    
			;    //LCD type commands
			;    else if(letter == 3)
	GOTO  m028
m018	MOVF  letter,W
	XORLW .3
	BTFSS 0x03,Zero_
	GOTO  m019
			;    {
			;        LCD_Width = 20;
	MOVLW .20
	MOVWF LCD_Width
			;        onboard_eewrite(LCD_Width, 1);
	MOVWF e_data
	MOVLW .1
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 4)
	GOTO  m028
m019	MOVF  letter,W
	XORLW .4
	BTFSS 0x03,Zero_
	GOTO  m020
			;    {
			;        LCD_Width = 16;
	MOVLW .16
	MOVWF LCD_Width
			;        onboard_eewrite(LCD_Width, 1);
	MOVWF e_data
	MOVLW .1
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 5)
	GOTO  m028
m020	MOVF  letter,W
	XORLW .5
	BTFSS 0x03,Zero_
	GOTO  m021
			;    {
			;        LCD_Lines = 4;
	MOVLW .4
	MOVWF LCD_Lines
			;        onboard_eewrite(LCD_Lines, 2);
	MOVWF e_data
	MOVLW .2
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 6)
	GOTO  m028
m021	MOVF  letter,W
	XORLW .6
	BTFSS 0x03,Zero_
	GOTO  m022
			;    {
			;        LCD_Lines = 2;
	MOVLW .2
	MOVWF LCD_Lines
			;        onboard_eewrite(LCD_Lines, 2);
	MOVWF e_data
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 7)
	GOTO  m028
m022	MOVF  letter,W
	XORLW .7
	BTFSS 0x03,Zero_
	GOTO  m023
			;    {
			;        LCD_Lines = 1;
	MOVLW .1
	MOVWF LCD_Lines
			;        onboard_eewrite(LCD_Lines, 2);
	MOVWF e_data
	MOVLW .2
	CALL  onboard_eewrite
			;    }
			;    else if(letter == 8) //Re-init command
	GOTO  m028
m023	MOVF  letter,W
	XORLW .8
	BTFSS 0x03,Zero_
	GOTO  m024
			;    {
			;        init_lcd();
	CALL  init_lcd
			;    }
			;
			;    //Turn on/off splash screen
			;    else if(letter == 9)
	GOTO  m028
m024	MOVF  letter,W
	XORLW .9
	BTFSS 0x03,Zero_
	GOTO  m027
			;    {
			;        if (splash_enable == 1) splash_enable = 0;
	DECFSZ splash_enable,W
	GOTO  m025
	CLRF  splash_enable
			;        else splash_enable = 1;
	GOTO  m026
m025	MOVLW .1
	MOVWF splash_enable
			;        
			;        onboard_eewrite(splash_enable, LCD_SPLASH_ENABLE); //Record to EEPROM
m026	MOVF  splash_enable,W
	MOVWF e_data
	MOVLW .4
	CALL  onboard_eewrite
			;    }
			;
			;    //Back light brightness settings
			;    else if(letter >= 128)
	GOTO  m028
m027	MOVLW .128
	SUBWF letter,W
	BTFSS 0x03,Carry
	GOTO  m028
			;    {
			;        brightness_setting = letter & 0b.0001.1111; //Brightness is a value from 0-29 only (5-bit)
	MOVLW .31
	ANDWF letter,W
	MOVWF brightness_setting
			;        onboard_eewrite(brightness_setting, LCD_BRIGHTNESS_SETTING); //Record to EEPROM
	MOVWF e_data
	MOVLW .3
	CALL  onboard_eewrite
			;    }
			;    
			;    
			;    //LCD_Width is the number of seen characters
			;    //EL1 is End Line 1 - Normally LCD_Width
			;    //EL2 is End Line 2 - Normally 64 + LCD_Width
			;    //EL3 is End Line 3 - LCD_Width + LCD_Width
			;    //EL4 is End Line 4 - 64 + LCD_Width + LCD_Width
			;
			;    EL1 = LCD_Width;
m028	MOVF  LCD_Width,W
	MOVWF EL1
			;    EL2 = 64 + LCD_Width;
	MOVLW .64
	ADDWF LCD_Width,W
	MOVWF EL2
			;    EL3 = LCD_Width + LCD_Width;
	MOVF  LCD_Width,W
	ADDWF LCD_Width,W
	MOVWF EL3
			;    EL4 = 64 + LCD_Width + LCD_Width;
	MOVLW .64
	ADDWF LCD_Width,W
	ADDWF LCD_Width,W
	MOVWF EL4
			;    
			;    //CP1 = Cursor Position 1 - 0 Always
			;    //CP1 = CP1 & 0b.1000.000 - this is to set the DRAM command
			;    //CP2 = 64 Always = 0b.1000.0000 | 64
			;    //CP3 = LCD_width = 0b.1000.0000 | LCD_Width
			;    //CP4 = 64 + LCD_Width = 0b.1000.0000 | (64 + LCD_Width)
			;    
			;    CP1 = 0b.1000.0000 | 0;
	MOVLW .128
	MOVWF CP1
			;    CP2 = 0b.1000.0000 | 64;
	MOVLW .192
	MOVWF CP2
			;    CP3 = 0b.1000.0000 | LCD_Width;
	MOVLW .128
	IORWF LCD_Width,W
	MOVWF CP3
			;    CP4 = 0b.1000.0000 | (LCD_Width + 64);
	MOVLW .64
	ADDWF LCD_Width,W
	IORLW .128
	MOVWF CP4
			;    
			;}
	RETURN
			;
			;//Initializes the various ports and interrupts
			;//Also inits the LCD
			;void boot_up(void)
			;{
boot_up
			;    OSCCON = 0b.0111.0000; //Setup internal oscillator for 8MHz
	MOVLW .112
	MOVWF OSCCON
			;    while(OSCCON.2 == 0); //Wait for frequency to stabilize
m029	BTFSS OSCCON,2
	GOTO  m029
			;    
			;    //Setup Ports
			;    ANSEL = 0b.0000.0000; //Disable ADC on all pins
	CLRF  ANSEL
			;    CMCON0 = 0b.0000.0111; //Turn off comparator on RA port 
	MOVLW .7
	BCF   0x03,RP0
	MOVWF CMCON0
			;
			;    PORTA = 0b.0000.0000;
	CLRF  PORTA
			;    TRISA = 0b.0000.0000; //0 = Output, 1 = Input
	BSF   0x03,RP0
	CLRF  TRISA
			;
			;    PORTC = 0b.0000.0000;
	BCF   0x03,RP0
	CLRF  PORTC
			;    TRISC = 0b.0010.0000; //0 = Output, 1 = Input (RX on RC5)
	MOVLW .32
	BSF   0x03,RP0
	MOVWF TRISC
			;
			;    //OPTION.7 = 0; //Enable weak pull-ups
			;
			;    //Init LCD
			;    init_lcd();
	CALL  init_lcd
			;
			;    Displayed_Letters = 0;
	CLRF  Displayed_Letters
			;    RX_In = 0;
	CLRF  RX_In
			;    
			;    //Setup the hardware UART module and interrupts
			;    //=============================================================
			;    SPBRG = 51; //8MHz for 9600 inital communication baud rate
	MOVLW .51
	MOVWF SPBRG
			;
			;    TXSTA = 0b.0000.0100; //Disable Transmit
	MOVLW .4
	MOVWF TXSTA
			;    RCSTA = 0b.1001.0000; //Receive enable, 8-bit asych continous receive mode
	MOVLW .144
	MOVWF RCSTA
			;
			;    RCIF = 0;
	BCF   0x0C,RCIF
			;    RCIE = 1;
	BSF   0x03,RP0
	BSF   0x8C,RCIE
			;    PEIE = 1;
	BSF   0x0B,PEIE
			;    //=============================================================
			;
			;    //Setup TMR0 and interrupts
			;    OPTION_REG = 0b.1101.0001; //Give Timer0 prescalar of 4
	MOVLW .209
	MOVWF OPTION_REG
			;    T0IE = 1;
	BSF   0x0B,T0IE
			;
			;    GIE = 1; //Enable global interrupts
	BSF   0x0B,GIE
			;    
			;}
	RETURN
			;
			;//Initializes the 4-bit parallel interface to the HD44780
			;void init_lcd(void)
			;{
init_lcd
			;    RS = 0;               
	BCF   0x03,RP0
	BCF   PORTA,5
			;    R_W = 0;
	BCF   PORTA,4
			;
			;    //Tell the LCD we are using 4bit data communication
			;    //===============================================================
			;    delay_ms(50);
	MOVLW .50
	MOVWF x_2
	CLRF  x_2+1
	CALL  delay_ms
			;    PORTC = 0b.0000.0011;
	MOVLW .3
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    delay_ms(5);
	MOVLW .5
	MOVWF x_2
	CLRF  x_2+1
	CALL  delay_ms
			;    PORTC = 0b.0000.0011;
	MOVLW .3
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    delay_ms(1);
	MOVLW .1
	MOVWF x_2
	CLRF  x_2+1
	CALL  delay_ms
			;    PORTC = 0b.0000.0011;
	MOVLW .3
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    delay_ms(5);
	MOVLW .5
	MOVWF x_2
	CLRF  x_2+1
	CALL  delay_ms
			;    PORTC = 0b.0000.0010;
	MOVLW .2
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    send_cmd(DISP_ON);
	MOVLW .12
	CALL  send_cmd
			;    send_cmd(CLR_DISP);
	MOVLW .1
	CALL  send_cmd
			;    //===============================================================
			;    //LCD Init Complete
			;    
			;    //Retrieve last Backlight state
			;    //===============================================================
			;    Backlight_Setting = onboard_eeread(LCD_BACKLIGHT_SETTING);
	MOVLW .0
	CALL  onboard_eeread
	MOVWF Backlight_Setting
			;    if (Backlight_Setting > 1) Backlight_Setting = 1; //Default
	MOVLW .2
	SUBWF Backlight_Setting,W
	BTFSS 0x03,Carry
	GOTO  m030
	MOVLW .1
	MOVWF Backlight_Setting
			;    onboard_eewrite(Backlight_Setting, LCD_BACKLIGHT_SETTING); //Record to EEPROM
m030	MOVF  Backlight_Setting,W
	MOVWF e_data
	MOVLW .0
	CALL  onboard_eewrite
			;    BL_Control = Backlight_Setting; //Turn on/off the backlight
	MOVF  Backlight_Setting,W
	BTFSS 0x03,Zero_
	BSF   PORTA,2
	BTFSC 0x03,Zero_
	BCF   PORTA,2
			;    //===============================================================
			;    
			;    //Retrieve backlight brightness setting
			;    //===============================================================
			;    brightness_setting = onboard_eeread(LCD_BRIGHTNESS_SETTING);
	MOVLW .3
	CALL  onboard_eeread
	MOVWF brightness_setting
			;    if (brightness_setting > 30) brightness_setting = 30; //Turn LCD backlight on to brightest by default
	MOVLW .31
	SUBWF brightness_setting,W
	BTFSS 0x03,Carry
	GOTO  m031
	MOVLW .30
	MOVWF brightness_setting
			;    onboard_eewrite(brightness_setting, LCD_BRIGHTNESS_SETTING); //Record to EEPROM
m031	MOVF  brightness_setting,W
	MOVWF e_data
	MOVLW .3
	CALL  onboard_eewrite
			;    //===============================================================
			;
			;    //Retrieve last LCD Type
			;    //===============================================================
			;    LCD_Width = onboard_eeread(LCD_WIDTH_SETTING);
	MOVLW .1
	CALL  onboard_eeread
	MOVWF LCD_Width
			;    if (LCD_Width > 80) LCD_Width = 16; //Default
	MOVLW .81
	SUBWF LCD_Width,W
	BTFSS 0x03,Carry
	GOTO  m032
	MOVLW .16
	MOVWF LCD_Width
			;    onboard_eewrite(LCD_Width, LCD_WIDTH_SETTING); //Record to EEPROM
m032	MOVF  LCD_Width,W
	MOVWF e_data
	MOVLW .1
	CALL  onboard_eewrite
			;
			;    //Set end lines
			;    EL1 = LCD_Width;
	MOVF  LCD_Width,W
	MOVWF EL1
			;    EL2 = 64 + LCD_Width;
	MOVLW .64
	ADDWF LCD_Width,W
	MOVWF EL2
			;    EL3 = LCD_Width + LCD_Width;
	MOVF  LCD_Width,W
	ADDWF LCD_Width,W
	MOVWF EL3
			;    EL4 = 64 + LCD_Width + LCD_Width;
	MOVLW .64
	ADDWF LCD_Width,W
	ADDWF LCD_Width,W
	MOVWF EL4
			;
			;    //Set cursor positions
			;    CP1 = 0b.1000.0000 | 0;
	MOVLW .128
	MOVWF CP1
			;    CP2 = 0b.1000.0000 | 64;
	MOVLW .192
	MOVWF CP2
			;    CP3 = 0b.1000.0000 | LCD_Width;
	MOVLW .128
	IORWF LCD_Width,W
	MOVWF CP3
			;    CP4 = 0b.1000.0000 | (LCD_Width + 64);
	MOVLW .64
	ADDWF LCD_Width,W
	IORLW .128
	MOVWF CP4
			;
			;    LCD_Lines = onboard_eeread(LCD_LINE_SETTING);
	MOVLW .2
	CALL  onboard_eeread
	MOVWF LCD_Lines
			;    if (LCD_Lines > 8) LCD_Lines = 2; //Default
	MOVLW .9
	SUBWF LCD_Lines,W
	BTFSS 0x03,Carry
	GOTO  m033
	MOVLW .2
	MOVWF LCD_Lines
			;    onboard_eewrite(LCD_Lines, LCD_LINE_SETTING); //Record to EEPROM
m033	MOVF  LCD_Lines,W
	MOVWF e_data
	MOVLW .2
	CALL  onboard_eewrite
			;    //===============================================================
			;    
			;    //Display splash screen if enabled
			;    //===============================================================
			;    splash_enable = onboard_eeread(LCD_SPLASH_ENABLE);
	MOVLW .4
	CALL  onboard_eeread
	MOVWF splash_enable
			;    if (splash_enable > 1) splash_enable = 1; //Default to show splash screen
	MOVLW .2
	SUBWF splash_enable,W
	BTFSS 0x03,Carry
	GOTO  m034
	MOVLW .1
	MOVWF splash_enable
			;    onboard_eewrite(splash_enable, LCD_SPLASH_ENABLE); //Record to EEPROM
m034	MOVF  splash_enable,W
	MOVWF e_data
	MOVLW .4
	CALL  onboard_eewrite
			;
			;    if (splash_enable == 1)
	DECFSZ splash_enable,W
	GOTO  m035
			;    {
			;        send_string("  SparkFun.com");
	CLRF  incoming_string
	CALL  send_string
			;        send_cmd(SET_CURSOR + 64);
	MOVLW .192
	CALL  send_cmd
			;        send_string("  SerLCD v2");
	MOVLW .15
	MOVWF incoming_string
	CALL  send_string
			;        delay_ms(750);
	MOVLW .238
	MOVWF x_2
	MOVLW .2
	MOVWF x_2+1
	CALL  delay_ms
			;        send_cmd(CLR_DISP);
	MOVLW .1
	CALL  send_cmd
			;    }
			;    //===============================================================
			;    
			;    cursor_position = 0;
m035	CLRF  cursor_position
			;}    
	RETURN
			;
			;//Checks the busy flag and waits until LCD is ready for next command
			;void LCD_wait(void)
			;{
LCD_wait
			;    bit i = 1;
	BSF   0x26,i
			;    
			;    TRISC = 0b.0010.1111; //0 = Output, 1 = Input (RX on RC5)
	MOVLW .47
	BSF   0x03,RP0
	MOVWF TRISC
			;
			;    R_W = 1; //Tell LCD to output status
	BCF   0x03,RP0
	BSF   PORTA,4
			;    RS = 0;               
	BCF   PORTA,5
			;
			;    while(i == 1)
m036	BTFSS 0x26,i
	GOTO  m037
			;    {
			;        E = 1; 
	BSF   PORTA,0
			;        i = D7; //Read data bit 7 - Busy Flag
	BCF   0x26,i
	BTFSC PORTC,3
	BSF   0x26,i
			;        E = 0;
	BCF   PORTA,0
			;    
			;        E = 1; E = 0; //Toggle E to get the second four bits of the status byte - but we don't care
	BSF   PORTA,0
	BCF   PORTA,0
			;    }
	GOTO  m036
			;    
			;    TRISC = 0b.0010.0000; //0 = Output, 1 = Input (RX on RC5)
m037	MOVLW .32
	BSF   0x03,RP0
	MOVWF TRISC
			;}
	BCF   0x03,RP0
	RETURN
			;
			;//Sends an ASCII character to the LCD
			;void send_char(uns8 c)
			;{
send_char
	MOVWF c
			;    LCD_wait();
	CALL  LCD_wait
			;    
			;    R_W = 0; //set LCD to write
	BCF   PORTA,4
			;    RS = 1; //set LCD to data mode
	BSF   PORTA,5
			;    
			;    PORTC = c >> 4;
	SWAPF c,W
	ANDLW .15
	MOVWF PORTC
			;    E = 1; E = 0; //Toggle the Enable Pin
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    PORTC = c;
	MOVF  c,W
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;}
	RETURN
			;
			;//Sends an LCD command
			;void send_cmd(uns8 d)
			;{
send_cmd
	MOVWF d
			;    LCD_wait();
	CALL  LCD_wait
			;
			;    //TRISC = 0b.0000.0000;   //0 = Output, 1 = Input
			;
			;    R_W = 0; //set LCD to write
	BCF   PORTA,4
			;
			;    PORTC = d >> 4;
	SWAPF d,W
	ANDLW .15
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;
			;    PORTC = d;
	MOVF  d,W
	MOVWF PORTC
			;    E = 1; E = 0;
	BSF   PORTA,0
	BCF   PORTA,0
			;}
	RETURN
			;
			;//Sends a given string to the LCD. Will start printing from
			;//current cursor position.
			;void send_string(const char *incoming_string)
			;{
send_string
			;    uns8 x;
			;    
			;    for(x = 0 ; incoming_string[x] != '\0' ; x++)
	CLRF  x
m038	MOVF  x,W
	ADDWF incoming_string,W
	CALL  _const1
	XORLW .0
	BTFSC 0x03,Zero_
	GOTO  m039
			;        send_char(incoming_string[x]);
	MOVF  x,W
	ADDWF incoming_string,W
	CALL  _const1
	CALL  send_char
	INCF  x,1
	GOTO  m038
			;}
m039	RETURN
			;
			;//General short delay
			;void delay_ms(uns16 x)
			;{
delay_ms
			;    //Clocks out at 1006us per 1ms @ 8MHz
			;    uns8 y, z;
			;    for ( ; x > 0 ; x--)
m040	MOVF  x_2,W
	IORWF x_2+1,W
	BTFSC 0x03,Zero_
	GOTO  m045
			;        for ( y = 0 ; y < 4 ; y++)
	CLRF  y
m041	MOVLW .4
	SUBWF y,W
	BTFSC 0x03,Carry
	GOTO  m044
			;            for ( z = 0 ; z < 69 ; z++);
	CLRF  z
m042	MOVLW .69
	SUBWF z,W
	BTFSC 0x03,Carry
	GOTO  m043
	INCF  z,1
	GOTO  m042
m043	INCF  y,1
	GOTO  m041
m044	DECF  x_2,1
	INCF  x_2,W
	BTFSC 0x03,Zero_
	DECF  x_2+1,1
	GOTO  m040
			;}
m045	RETURN
			;
			;//Reads e_data from the onboard eeprom at e_address
			;uns8 onboard_eeread(uns8 e_address)
			;{
onboard_eeread
	MOVWF e_address
			;    //Do a read
			;    EEADR = e_address; //Set the address to read
	BSF   0x03,RP0
	MOVWF EEADR
			;    EEPGD = 0; //Point to EEPROM Memory
	BCF   0x9C,EEPGD
			;    RD = 1; //Read it
	BSF   0x9C,RD
			;    
			;    return(EEDATA); //Read that EEPROM value
	MOVF  EEDATA,W
	BCF   0x03,RP0
	RETURN
			;}    
			;
			;//Write e_data to the onboard eeprom at e_address
			;void onboard_eewrite(uns8 e_data, uns8 e_address)
			;{
onboard_eewrite
	MOVWF e_address_2
			;    bit temp_GIE = GIE;
	BCF   0x25,temp_GIE
	BTFSC 0x0B,GIE
	BSF   0x25,temp_GIE
			;    
			;    EEIF = 0; //Clear the write completion intr flag
	BCF   0x0C,EEIF
			;    EEADR = e_address; //Set the address
	BSF   0x03,RP0
	MOVWF EEADR
			;    EEDATA = e_data; //Give it the data
	BCF   0x03,RP0
	MOVF  e_data,W
	BSF   0x03,RP0
	MOVWF EEDATA
			;    EEPGD = 0; //Point to EEPROM data block?
	BCF   0x9C,EEPGD
			;    WREN = 1; //Enable EE Writes
	BSF   0x9C,WREN
			;    GIE = 0; //Disable Intrs
	BCF   0x0B,GIE
			;    
			;    //Specific EEPROM write steps
			;    EECON2 = 0x55;
	MOVLW .85
	MOVWF EECON2
			;    EECON2 = 0xAA;
	MOVLW .170
	MOVWF EECON2
			;    WR = 1;
	BSF   0x9C,WR
			;    //Specific EEPROM write steps
			;
			;    while(EEIF == 0); //Wait for write to complete
	BCF   0x03,RP0
m046	BTFSS 0x0C,EEIF
	GOTO  m046
			;    WREN = 0; //Disable EEPROM Writes
	BSF   0x03,RP0
	BCF   0x9C,WREN
			;
			;    GIE = temp_GIE; //Set GIE to its original state
	BCF   0x03,RP0
	BTFSS 0x25,temp_GIE
	BCF   0x0B,GIE
	BTFSC 0x25,temp_GIE
	BSF   0x0B,GIE
			;}
	RETURN

	ORG 0x2007
	DATA 31C4H
	END


; *** KEY INFO ***

; 0x0004 P0   47 word(s)  2 % : serverX
; 0x0158 P0   34 word(s)  1 % : boot_up
; 0x0226 P0   14 word(s)  0 % : send_char
; 0x0234 P0   13 word(s)  0 % : send_cmd
; 0x00D5 P0  131 word(s)  6 % : special_commands
; 0x024F P0   24 word(s)  1 % : delay_ms
; 0x0241 P0   14 word(s)  0 % : send_string
; 0x0210 P0   22 word(s)  1 % : LCD_wait
; 0x0267 P0    8 word(s)  0 % : onboard_eeread
; 0x026F P0   30 word(s)  1 % : onboard_eewrite
; 0x017A P0  150 word(s)  7 % : init_lcd
; 0x0056 P0  127 word(s)  6 % : main
; 0x0033 P0   35 word(s)  1 % : _const1

; RAM usage: 107 bytes (8 local), 149 bytes free
; Maximum call level: 5 (+1 for interrupt)
;  Codepage 0 has  650 word(s) :  31 %
;  Codepage 1 has    0 word(s) :   0 %
; Total of 650 code words (15 %)
