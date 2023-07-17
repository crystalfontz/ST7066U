//==============================================================================
//
//  CRYSTALFONTZ
//
//  This demo code is written for any character display that uses the Sitronix 
//  ST7066U display controller
//    https://www.crystalfontz.com/controllers/Sitronix/ST7066U/
//
//  Seeeduino, an open-source 3.3v capable Arduino clone.
//    https://www.crystalfontz.com/product/cfapn15062-seeeduino-arduino-clone-microprocessor
//    https://github.com/SeeedDocument/SeeeduinoV4/raw/master/resources/Seeeduino_v4.2_sch.pdf
//
//==============================================================================
// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// For more information, please refer to <http://unlicense.org/>
//
// Connection guide:
// ARD       | Port  | Display pin |  Function: 8-bit parallel                |
//-----------+-------+-------------+------------------------------------------+
// 5V        |       | 5V          |  POWER 5V                                |
// GND       |       | GND         |  GROUND                                  |
//-----------+-------+-------------+------------------------------------------+
// D8        | PORTB | RS/DI       |  Register Select                 (RS)    |
// D9        | PORTB | R/W         |  Read/Write                      (RW)    |
// D10       | PORTB | EN          |  Enable                          (EN)    |
// D11       | PORTB | EN2         |  Enable (second half of display) (EN2)   |
//-----------+-------+-------------+------------------------------------------+
// Data Lines
//-----------+-------+-------------+------------------------------------------+
// D0        | PORTD |  DB0         |  DATA BUS LINE                   (DB0)  |
// D1        | PORTD |  DB1         |  DATA BUS LINE                   (DB1)  |
// D2        | PORTD |  DB2         |  DATA BUS LINE                   (DB2)  |
// D3        | PORTD |  DB3         |  DATA BUS LINE                   (DB3)  |
// D4        | PORTD |  DB4         |  DATA BUS LINE                   (DB4)  |
// D5        | PORTD |  DB5         |  DATA BUS LINE                   (DB5)  |
// D6        | PORTD |  DB6         |  DATA BUS LINE                   (DB6)  |
// D7        | PORTD |  DB7         |  DATA BUS LINE                   (DB7)  |
//-----------+-------+-------------+------------------------------------------+
#include <Arduino.h>

// set if the display has 4 rows (using the second enable pin)
#define rows_4 1

//==============================================================================

// define pins on Arduino
#define RS (8)
#define RW (9)
#define EN (10)
#define datapins (PORTD)

#if rows_4
#define EN2 (11)
#endif

//==============================================================================

// define set and clear functions for pins
#define RS_MASK (0x01)
#define CLR_RS (PORTB &= ~(RS_MASK))
#define SET_RS (PORTB |= (RS_MASK))

#define RW_MASK (0x02)
#define CLR_RW (PORTB &= ~(RW_MASK))
#define SET_RW (PORTB |= (RW_MASK))

#define EN_MASK (0x04)
#define CLR_EN (PORTB &= ~(EN_MASK))
#define SET_EN (PORTB |= (EN_MASK))

#if rows_4
#define EN2_MASK (0x08)
#define CLR_EN2 (PORTB &= ~(EN2_MASK))
#define SET_EN2 (PORTB |= (EN2_MASK))
#endif

//==============================================================================

// ST7066U display controller defines
#define ST7066U_CLRDISP (0x01)
// clear display content
#define ST7066U_RETHOME (0x02)
// return to 00H in address counter
#define ST7066U_EMS(ID, S) (0x04 | (ID << 1) | (S << 0))
// define the moving direction of cursor and display
#define ST7066U_DISPONOFF(D, C, B) (0x08 | (D << 2) | (C << 1) | (B << 0))
// turn on/off display, cursor and cursor blink
#define ST7066U_FUNCSET(DL, N, F) (0x20 | (DL << 4) | (N << 3) | (F << 2))
// define interface format, number of display lines and font type

// line positions
#define LINE1 (0x80)        // first line is 00h but bit 7 is high for this command
#define LINE2 (0x80 + 0x40) // second line is 40h but bit 7 is high for this command

//==============================================================================

// prior to sending data/commands, we have to check if an internal operation is being
// carried out. the 7th data bit corresponds to the busy flag
void checkBusy()
{
    datapins = 0x80; // write the 7th bit high
    DDRD = 0x00;     // set the port direction as input

    CLR_RS; // set the mode as instruction
    SET_RW; // set to read operation
    SET_EN; // select the LCD controller

    // if the flag is high, toggle LCD controller selection
    while (0x80 == (PIND & 0x80))
    {
        delayMicroseconds(80);
        CLR_EN;
        delayMicroseconds(80);
        SET_EN;
    }

    CLR_EN; // deselect the LCD controller
    CLR_RW; // set to write operation

    DDRD = 0xFF; // change the pin directions to output
}

#if rows_4
// duplicate of checkBusy() function for the second half of the display
void checkBusy_4row()
{
    datapins = 0x80; 
    DDRD = 0x00;     

    CLR_RS;  
    SET_RW;  
    SET_EN2; 

    while (0x80 == (PIND & 0x80))
    {
        delayMicroseconds(80);
        CLR_EN2;
        delayMicroseconds(80);
        SET_EN2;
    }

    CLR_EN2; 
    CLR_RW;  

    DDRD = 0xFF; 
}
#endif

//==============================================================================

// 6800 transfer command function
void sendCommand(uint8_t command)
{
    checkBusy(); // check the busy flag
    CLR_RW;      // set to write operation
    CLR_RS;      // set the mode as instruction/command

    datapins = command; // transfer the command to the pins

    SET_EN; // select the LCD controller
    CLR_EN; // deselect the LCD controller
}

// 6800 transfer data function
void sendData(uint8_t data)
{
    checkBusy(); // check the busy flag
    CLR_RW;      // set to write operation
    SET_RS;      // set the mode as data

    datapins = data; // transfer the data to the pins

    SET_EN; // select the LCD controller
    CLR_EN; // deselect the LCD controller
}

#if rows_4
// duplicate of sendCommand() and sendData() functions for second half of display
void sendCommand_4row(uint8_t command)
{
    checkBusy_4row(); 
    CLR_RW;           
    CLR_RS;            

    datapins = command; 

    SET_EN2; 
    CLR_EN2; 
}

void sendData_4row(uint8_t data)
{
    checkBusy_4row(); 
    CLR_RW;           
    SET_RS;           

    datapins = data; 

    SET_EN2; 
    CLR_EN2; 
}
#endif

//==============================================================================

// initialize the display by transferring the ST7066U commands
void init_ST7066U()
{
    checkBusy(); // check the busy flag
    sendCommand(ST7066U_FUNCSET(1, 1, 0));
    // set 8-bit MPU mode, 2 line display and 5x11 dot format mode
    sendCommand(ST7066U_FUNCSET(1, 1, 0));
    // one more time
    sendCommand(ST7066U_DISPONOFF(1, 0, 0));
    // turn display on, cursor off and cursor blink off
    sendCommand(ST7066U_CLRDISP);
    sendCommand(ST7066U_RETHOME);
    sendCommand(ST7066U_EMS(1, 0));
    // set cursor increment and display shift to the right

#if rows_4
    // the same initialization is followed for the second half of the display
    checkBusy_4row(); 
    sendCommand_4row(ST7066U_FUNCSET(1, 1, 0));
    sendCommand_4row(ST7066U_FUNCSET(1, 1, 0));
    sendCommand_4row(ST7066U_DISPONOFF(1, 0, 0));
    sendCommand_4row(ST7066U_CLRDISP);
    sendCommand_4row(ST7066U_RETHOME);
    sendCommand_4row(ST7066U_EMS(1, 0));
#endif
}

//==============================================================================

// write our desired text to the display
void writeString(char *myString)
{
    uint8_t i = 0;
    do
    {
        sendData((uint8_t)myString[i]);
        i++;
    } while (myString[i] != NULL);
} // transfer the string contents until i reaches the end of the content

#if rows_4
// duplicate of writeString() for second half of the display
void writeString_4row(char *myString)
{
    uint8_t i = 0;
    do
    {
        sendData_4row((uint8_t)myString[i]);
        i++;
    } while (myString[i] != NULL);
} 
#endif

//==============================================================================

// setup function
void setup()
{
#if rows_4
    // define pin directions
    DDRB = 0x0F; // set pins 8, 9, 10, and 11 as outputs
    DDRD = 0xFF; // set pins 0-7 as outputs
#else
    DDRB = 0x07; // set pins 8, 9, and 10 as outputs
    DDRD = 0xFF; // set pins 0-7 as outputs
#endif

    // set an appropriate starting state for the pins
    datapins = 0;
    CLR_RW;
    CLR_EN;

#if rows_4
    CLR_EN2;
#endif

    SET_RS;
    init_ST7066U(); // initialize the display
    delay(500);
}

// loop function
void loop()
{
    sendCommand(LINE1); // write string to line 1
    writeString("****************************************");
    sendCommand(LINE2); // write string to line 2
    writeString("** Crystalfontz America, Incorporated **");

#if rows_4
    // the same line addresses apply for the second half of the display
    sendCommand_4row(LINE1);
    writeString_4row("*CFAH4004A1TMI 40 Characters x 4 Lines**");
    sendCommand_4row(LINE2);
    writeString_4row("****************************************");
#endif

    while (1);
}
