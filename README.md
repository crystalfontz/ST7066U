# Sitronix ST7066U Demonstration Code

This is Arduino sample code for any display that uses the Sitronix ST7066U controller. The data sheet for this controller is available [here](https://www.crystalfontz.com/controllers/Sitronix/ST7066U/). The code can be used for both 2 and 4 row displays.

These displays are part of the CFAH character family and operate at 5V. Please refer the display datasheet before connection to a power source. Further, a variable resistor connection is required for contrast adjustment and its connection scheme has been outlined in the datasheet of the respective part.

## Connection Guide
| Arduino | Port  | Display pin* |  Function: 8-bit parallel                |
| ------- | ----- | ------------ | ---------------------------------------- |
| Power                                                                     |
| 5V      |       | 5V           |  POWER 5V                                |
| GND     |       | GND          |  GROUND                                  |
| Control Lines                                                             |
| D8      | PORTB | RS/DI        |  Register Select                    (RS) |
| D9      | PORTB | R/W          |  Read/Write                         (RW) |
| D10     | PORTB | EN           |  Enable                             (EN) |
| D11     | PORTB | EN2          |  Enable (second half of display)   (EN2) |
| Data Lines                                                                |
| D0      | PORTD |  DB0         |  DATA BUS LINE                     (DB0) |
| D1      | PORTD |  DB1         |  DATA BUS LINE                     (DB1) |
| D2      | PORTD |  DB2         |  DATA BUS LINE                     (DB2) |
| D3      | PORTD |  DB3         |  DATA BUS LINE                     (DB3) |
| D4      | PORTD |  DB4         |  DATA BUS LINE                     (DB4) |
| D5      | PORTD |  DB5         |  DATA BUS LINE                     (DB5) |
| D6      | PORTD |  DB6         |  DATA BUS LINE                     (DB6) |
| D7      | PORTD |  DB7         |  DATA BUS LINE                     (DB7) |

* Actual pinout varies by display, consult the display's datasheet to confirm

## Display Information
Here are links to our active displays that use the Sitronix ST7066U controller:

### 8 characters by 2 rows
- [CFAH0802A-GGH-JT](https://www.crystalfontz.com/product/cfah0802agghjt)
- [CFAH0802A-NYG-JT](https://www.crystalfontz.com/product/cfah0802anygjt)
- [CFAH0802A-TMI-JT](https://www.crystalfontz.com/product/cfah0802atmijt)
- [CFAH0802A-TTI-JT](https://www.crystalfontz.com/product/cfah0802attijt)
- [CFAH0802A-YMI-JT](https://www.crystalfontz.com/product/cfah0802aymijt)
- [CFAH0802A-YYH-JT](https://www.crystalfontz.com/product/cfah0802ayyhjt)
- [CFAH0802D-NYG-JP](https://www.crystalfontz.com/product/cfah0802dnygjp)
- [CFAH0802D-YYH-JP](https://www.crystalfontz.com/product/cfah0802dyyhjp)
- [CFAH0802Z-YYH-JP](https://www.crystalfontz.com/product/cfah0802zyyhjp)

### 12 characters by 2 rows
- [CFAH1202A-NYG-JT](https://www.crystalfontz.com/product/cfah1202anygjt)
- [CFAH1202A-TMI-JT](https://www.crystalfontz.com/product/cfah1202atmijt)
- [CFAH1202A-TTI-JT](https://www.crystalfontz.com/product/cfah1202attijt)
- [CFAH1202A-YYH-JT](https://www.crystalfontz.com/product/cfah1202ayyhjt)

### 16 characters by 1 row
- [CFAH1601A-GGH-JT](https://www.crystalfontz.com/product/cfah1601agghjt)
- [CFAH1601A-NYG-JT](https://www.crystalfontz.com/product/cfah1601anygjt)
- [CFAH1601A-YYH-JT](https://www.crystalfontz.com/product/cfah1601ayyhjt)
- [CFAH1601B-TFH-ET](https://www.crystalfontz.com/product/cfah1601btfhet)
- [CFAH1601B-TMI-ET](https://www.crystalfontz.com/product/cfah1601btmiet)
- [CFAH1601B-YYH-ET](https://www.crystalfontz.com/product/cfah1601byyhet)
- [CFAH1601L-TMI-ET](https://www.crystalfontz.com/product/cfah1601ltmiet)
- [CFAH1601L-YYH-ET](https://www.crystalfontz.com/product/cfah1601lyyhet)

### 16 characters by 2 rows
- [CFAH1602A-YYH-JT](https://www.crystalfontz.com/product/cfah1602ayyhjt)
- [CFAH1602A-YYH-JTE](https://www.crystalfontz.com/product/cfah1602ayyhjte)
- [CFAH1602B-NGG-JTV](https://www.crystalfontz.com/product/cfah1602bnggjtv)
- [CFAH1602B-NYG-JT](https://www.crystalfontz.com/product/cfah1602bnygjt)
- [CFAH1602B-TMI-JT](https://www.crystalfontz.com/product/cfah1602btmijt)
- [CFAH1602B-YMI-JT](https://www.crystalfontz.com/product/cfah1602bymijt)
- [CFAH1602B-YTI-JT](https://www.crystalfontz.com/product/cfah1602bytijt)
- [CFAH1602B-YYH-JT](https://www.crystalfontz.com/product/cfah1602byyhjt)
- [CFAH1602B-YYH-JTE](https://www.crystalfontz.com/product/cfah1602byyhjte)
- [CFAH1602B-YYH-JTV](https://www.crystalfontz.com/product/cfah1602byyhjtv)
- [CFAH1602C-TMI-JT](https://www.crystalfontz.com/product/cfah1602ctmijt)
- [CFAH1602C-YYH-JT](https://www.crystalfontz.com/product/cfah1602cyyhjt)
- [CFAH1602C-YYH-JTV](https://www.crystalfontz.com/product/cfah1602cyyhjtv)
- [CFAH1602D-TMI-ET](https://www.crystalfontz.com/product/cfah1602dtmiet)
- [CFAH1602D-YTI-ET](https://www.crystalfontz.com/product/cfah1602dytiet)
- [CFAH1602D-YYH-ET](https://www.crystalfontz.com/product/cfah1602dyyhet)
- [CFAH1602J-NYG-JT](https://www.crystalfontz.com/product/cfah1602jnygjt)
- [CFAH1602J-YYH-JT](https://www.crystalfontz.com/product/cfah1602jyyhjt)
- [CFAH1602L-GGH-JT](https://www.crystalfontz.com/product/cfah1602lgghjt)
- [CFAH1602L-TGH-JT](https://www.crystalfontz.com/product/cfah1602ltghjt)
- [CFAH1602L-YYH-JT](https://www.crystalfontz.com/product/cfah1602lyyhjt)
- [CFAH1602M-TMI-ET](https://www.crystalfontz.com/product/cfah1602mtmiet)
- [CFAH1602M-TTI-ET](https://www.crystalfontz.com/product/cfah1602mttiet)
- [CFAH1602M-YYH-ET](https://www.crystalfontz.com/product/cfah1602myyhet)
- [CFAH1602O-TFH-ET](https://www.crystalfontz.com/product/cfah1602otfhet)
- [CFAH1602O-TMI-ET](https://www.crystalfontz.com/product/cfah1602otmiet)
- [CFAH1602O-YYH-ET](https://www.crystalfontz.com/product/cfah1602oyyhet)
- [CFAH1602P-TMI-ET](https://www.crystalfontz.com/product/cfah1602ptmiet)
- [CFAH1602P-YYH-ET](https://www.crystalfontz.com/product/cfah1602pyyhet)
- [CFAH1602S-YYH-ET](https://www.crystalfontz.com/product/cfah1602syyhet)
- [CFAH1602Y-NYG-ET](https://www.crystalfontz.com/product/cfah1602ynyget)
- [CFAH1602Y-YYH-ET](https://www.crystalfontz.com/product/cfah1602yyyhet)
- [CFAH1602Z-YYH-ET](https://www.crystalfontz.com/product/cfah1602zyyhet)

### 16 characters by 4 rows
- [CFAH1604A-NYG-JT](https://www.crystalfontz.com/product/cfah1604anygjt)
- [CFAH1604A1-TMI-JT](https://www.crystalfontz.com/product/cfah1604a1tmijt)
- [CFAH1604A-YYH-JT](https://www.crystalfontz.com/product/cfah1604ayyhjt)
- [CFAH1604B-NGH-ET](https://www.crystalfontz.com/product/cfah1604bnghet)
- [CFAH1604B-TMI-ET](https://www.crystalfontz.com/product/cfah1604btmiet)
- [CFAH1604B-YYH-ET](https://www.crystalfontz.com/product/cfah1604byyhet)

### 20 characters by 1 row
- [CFAH2001B-TMI-ET](https://www.crystalfontz.com/product/cfah2001btmiet)
- [CFAH2001B-YYH-ET](https://www.crystalfontz.com/product/cfah2001byyhet)

### 20 characters by 2 rows
- [CFAH2002A-NGG-JT](https://www.crystalfontz.com/product/cfah2002anggjt)
- [CFAH2002A-NYG-JT](https://www.crystalfontz.com/product/cfah2002anygjt)
- [CFAH2002A-NYG-JTV](https://www.crystalfontz.com/product/cfah2002anygjtv)
- [CFAH2002A1-TFH-JT](https://www.crystalfontz.com/product/cfah2002a1tfhjt)
- [CFAH2002A1-TMI-JT](https://www.crystalfontz.com/product/cfah2002a1tmijt)
- [CFAH2002A1-YMI-JT](https://www.crystalfontz.com/product/cfah2002a1ymijt)
- [CFAH2002A-YMI-JTV](https://www.crystalfontz.com/product/cfah2002aymijtv)
- [CFAH2002A1-YYH-JT](https://www.crystalfontz.com/product/cfah2002a1yyhjt)
- [CFAH2002A1-YYH-JTV](https://www.crystalfontz.com/product/cfah2002a1yyhjtv)
- [CFAH2002D-TMI-ET](https://www.crystalfontz.com/product/cfah2002dtmiet)
- [CFAH2002D-YYH-ET](https://www.crystalfontz.com/product/cfah2002dyyhet)
- [CFAH2002L-TFH-ET](https://www.crystalfontz.com/product/cfah2002ltfhet)
- [CFAH2002L-TMI-ET](https://www.crystalfontz.com/product/cfah2002ltmiet)
- [CFAH2002L-YYH-ET](https://www.crystalfontz.com/product/cfah2002lyyhet)
- [CFAH2002M-TMI-ET](https://www.crystalfontz.com/product/cfah2002mtmiet)
- [CFAH2002M-YYH-ET](https://www.crystalfontz.com/product/cfah2002myyhet)

### 20 characters by 4 rows
- [CFAH2004A-NYG-JT](https://www.crystalfontz.com/product/cfah2004anygjt)
- [CFAH2004A-TFH-JT](https://www.crystalfontz.com/product/cfah2004atfhjt)
- [CFAH2004A-TMI-JT](https://www.crystalfontz.com/product/cfah2004atmijt)
- [CFAH2004A-YTI-JT](https://www.crystalfontz.com/product/cfah2004aytijt)
- [CFAH2004A-YYH-JT](https://www.crystalfontz.com/product/cfah2004ayyhjt)
- [CFAH2004A-YYH-JTE](https://www.crystalfontz.com/product/cfah2004ayyhjte)
- [CFAH2004B-TFH-ET](https://www.crystalfontz.com/product/cfah2004btfhet)
- [CFAH2004B-TMI-ET](https://www.crystalfontz.com/product/cfah2004btmiet)
- [CFAH2004B-YYH-ET](https://www.crystalfontz.com/product/cfah2004byyhet)
- [CFAH2004D-TMI-ET](https://www.crystalfontz.com/product/cfah2004dtmiet)
- [CFAH2004D-YYH-ET](https://www.crystalfontz.com/product/cfah2004dyyhet)
- [CFAH2004L-NYG-ET](https://www.crystalfontz.com/product/cfah2004lnyget)
- [CFAH2004L-TMI-JT](https://www.crystalfontz.com/product/cfah2004ltmijt)
- [CFAH2004L-YYH-JT](https://www.crystalfontz.com/product/cfah2004lyyhjt)

### 24 characters by 2 rows
- [CFAH2402A-TFH-JT](https://www.crystalfontz.com/product/cfah2402atfhjt)
- [CFAH2402A-TMI-JT](https://www.crystalfontz.com/product/cfah2402atmijt)
- [CFAH2402A-YYH-JT](https://www.crystalfontz.com/product/cfah2402ayyhjt)

### 40 characters by 2 rows
- [CFAH4002A-TMI-JT](https://www.crystalfontz.com/product/cfah4002atmijt)
- [CFAH4002A-YYH-JT](https://www.crystalfontz.com/product/cfah4002ayyhjt)

### 40 characters by 4 rows
- [CFAH4004A-TFH-JT](https://www.crystalfontz.com/product/cfah4004atfhjt)
- [CFAH4004A1-YYH-JT](https://www.crystalfontz.com/product/cfah4004a1yyhjt)
- [CFAH4004A1-TMI-JT](https://www.crystalfontz.com/product/cfah4004a1tmijt)

## More information
For more inforamtion about other character LCD display offerings, please see our full list [here](https://www.crystalfontz.com/c/character-lcd-displays/21).
