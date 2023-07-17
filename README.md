# Sitronix ST7066U Demonstration Code

This is Arduino sample code for any display that uses the Sitronix ST7066U controller. The data sheet for this controller is available [here](https://www.crystalfontz.com/controllers/Sitronix/ST7066U/). The code can be used for both 2 and 4 row displays.

These displays are part of the CFAH character family and operate at 5V. Please refer the display datasheet before connection to a power source. Further, a variable resistor connection is required for contrast adjustment and its connection scheme has been outlined in the datasheet of the respective part.

## Connection Guide
```
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
```

## Display Information
Here are links to our active displays that use the Sitronix ST7066U controller:\
[CFAH0802A-GGH-JT](https://www.crystalfontz.com/product/cfah0802agghjt-8x2-character-display), 
[CFAH0802A-NYG-JT](https://www.crystalfontz.com/product/cfah0802anygjt-display-module-text-8x2), 
[CFAH0802A-TMI-JT](https://www.crystalfontz.com/product/cfah0802atmijt-lcd-8x2-character-module), 
[CFAH0802A-TTI-JT](https://www.crystalfontz.com/product/cfah0802attijt-display-module-8x2-character), 
[CFAH0802A-YMI-JT](https://www.crystalfontz.com/product/cfah0802aymijt-character-lcd-8x2), 
[ CFAH0802A-YYH-JT](https://www.crystalfontz.com/product/cfah0802ayyhjt-lcd-character-display-8x2), 
[CFAH0802D-NYG-JP](https://www.crystalfontz.com/product/cfah0802dnygjp-8x2-character-lcd), 
[CFAH0802D-YYH-JP](https://www.crystalfontz.com/product/cfah0802dyyhjp-8x2-sunlight-readable-character-lcd), 
[CFAH0802Z-YYH-JP](https://www.crystalfontz.com/product/cfah0802zyyhjp-character-display-module-8x2),
[CFAH1202A-NYG-JT](https://www.crystalfontz.com/product/cfah1202anygjt-lcd-display-alphanumeric-12x2), 
[CFAH1202A-TMI-JT](https://www.crystalfontz.com/product/cfah1202atmijt-12x2-character-lcd), 
[CFAH1202A-TTI-JT](https://www.crystalfontz.com/product/cfah1202attijt-12x2-character-lcd-display), 
[CFAH1202A-YYH-JT](https://www.crystalfontz.com/product/cfah1202ayyhjt-12x2-lcd-display-alphanumeric), 
[CFAH1601A-GGH-JT](https://www.crystalfontz.com/product/cfah1601agghjt-lcd-display-16x1-sunlight-readable), 
[CFAH1601A-NYG-JT](https://www.crystalfontz.com/product/cfah1601anygjt-16x1-character-lcd-sunlight-readable), 
[CFAH1601A-YYH-JT](https://www.crystalfontz.com/product/cfah1601ayyhjt-character-display-16x1-lcd), 
[CFAH1601B-TFH-ET](https://www.crystalfontz.com/product/cfah1601btfhet-16x1-character-display-module), 
[CFAH1601B-TMI-ET](https://www.crystalfontz.com/product/cfah1601btmiet-16x1-lcd-character-display), 
[CFAH1601B-YYH-ET](https://www.crystalfontz.com/product/cfah1601byyhet-16x1-display-module-character), 
[CFAH1601L-TMI-ET](https://www.crystalfontz.com/product/cfah1601ltmiet-large-character-display-16x1-lcd), 
[CFAH1601L-YYH-ET](https://www.crystalfontz.com/product/cfah1601lyyhet-lcd-display-16x1-sunlight-readable), 
[CFAH1602A-YYH-JT](https://www.crystalfontz.com/product/cfah1602ayyhjt-16x2-display-module-text), 
[CFAH1602A-YYH-JTE](https://www.crystalfontz.com/product/cfah1602ayyhjte-character-lcd-16x2), 
[CFAH1602B-NGG-JTV](https://www.crystalfontz.com/product/cfah1602bnggjtv-lcd-16x2-character-display), 
[CFAH1602B-NYG-JT](https://www.crystalfontz.com/product/cfah1602bnygjt-16x2-display-module-character),
[CFAH1602B-TMI-JT](https://www.crystalfontz.com/product/cfah1602btmijt-16x2-character-lcd), 
[CFAH1602B-YMI-JT](https://www.crystalfontz.com/product/cfah1602bymijt-text-display-module-16x2), 
[CFAH1602B-YTI-JT](https://www.crystalfontz.com/product/cfah1602bytijt-16x2-lcd-character-display), 
[CFAH1602B-YYH-JT](https://www.crystalfontz.com/product/cfah1602byyhjt-16x2-character-display-lcd), 
[CFAH1602B-YYH-JTE](https://www.crystalfontz.com/product/cfah1602byyhjte-character-display-16x2), 
[CFAH1602B-YYH-JTV](https://www.crystalfontz.com/product/cfah1602byyhjtv-alphanumeric-lcd-display-16x2), 
[CFAH1602C-TMI-JT](https://www.crystalfontz.com/product/cfah1602ctmijt-16x2-character-display), 
[CFAH1602C-YYH-JT](https://www.crystalfontz.com/product/cfah1602cyyhjt-character-display-16x2),
[CFAH1602C-YYH-JTV](https://www.crystalfontz.com/product/cfah1602cyyhjtv-lcd-16x2-character-display), 
[CFAH1602D-TMI-ET](https://www.crystalfontz.com/product/cfah1602dtmiet-16x2-text-display-module), 
[CFAH1602D-YTI-ET](https://www.crystalfontz.com/product/cfah1602dytiet-display-module-text-16x2), 
[CFAH1602D-YYH-ET](https://www.crystalfontz.com/product/cfah1602dyyhet-16x2-character-lcd), 
[CFAH1602J-NYG-JT](https://www.crystalfontz.com/product/cfah1602jnygjt-character-display-16x2), 
[CFAH1602J-YYH-JT](https://www.crystalfontz.com/product/cfah1602jyyhjt-lcd-display-16x2-alphanumeric), 
[CFAH1602L-GGH-JT](https://www.crystalfontz.com/product/cfah1602lgghjt-lcd-character-module-16x2), 
[CFAH1602L-TGH-JT](https://www.crystalfontz.com/product/cfah1602ltghjt-16x2-character-lcd), 
[CFAH1602L-YYH-JT](https://www.crystalfontz.com/product/cfah1602lyyhjt-character-display-16x2-lcd), 
[CFAH1602M-TMI-ET](https://www.crystalfontz.com/product/cfah1602mtmiet-character-lcd-display-16x2), 
[CFAH1602M-TTI-ET](https://www.crystalfontz.com/product/cfah1602mttiet-black-and-white-16x2-display-module), 
[CFAH1602M-YYH-ET](https://www.crystalfontz.com/product/cfah1602myyhet-16x2-character-display-module), 
[CFAH1602O-TFH-ET](https://www.crystalfontz.com/product/cfah1602otfhet-16x2-alphanumeric-lcd-display), 
[CFAH1602O-TMI-ET](https://www.crystalfontz.com/product/cfah1602otmiet-character-display-lcd-16x2), 
[CFAH1602O-YYH-ET](https://www.crystalfontz.com/product/cfah1602oyyhet-lcd-display-sunlight-16x2), 
[CFAH1602P-TMI-ET](https://www.crystalfontz.com/product/cfah1602ptmiet-character-display-16x2), 
[CFAH1602P-YYH-ET](https://www.crystalfontz.com/product/cfah1602pyyhet-display-module-16x2-character), 
[CFAH1602S-YYH-ET](https://www.crystalfontz.com/product/cfah1602syyhet-character-display-module-16x2), 
[CFAH1602Y-NYG-ET](https://www.crystalfontz.com/product/cfah1602ynyget-character-display-module-16x2), 
[CFAH1602Y-YYH-ET](https://www.crystalfontz.com/product/cfah1602yyyhet-16x2-display-module-text), 
[CFAH1602Z-YYH-ET](https://www.crystalfontz.com/product/cfah1602zyyhet-16x2-lcd-character-display), 
[CFAH1604A-NYG-JT](https://www.crystalfontz.com/product/cfah1604anygjt-lcd-display-alphanumeric-16x4), 
[CFAH1604A-TMI-JT](https://www.crystalfontz.com/product/cfah1604atmijt-character-display-16x4), 
[CFAH1604A-YYH-JT](https://www.crystalfontz.com/product/cfah1604ayyhjt-character-display-16x4), 
[CFAH1604B-NGH-ET](https://www.crystalfontz.com/product/cfah1604bnghet-character-lcd-16x4), 
[CFAH1604B-TMI-ET](https://www.crystalfontz.com/product/cfah1604btmiet-lcd-16x4-character-display), 
[CFAH1604B-YYH-ET](https://www.crystalfontz.com/product/cfah1604byyhet-16x4-character-lcd), 
[CFAH2001B-TMI-ET](https://www.crystalfontz.com/product/cfah2001btmiet-20x1-character-display-module), 
[CFAH2001B-YYH-ET](https://www.crystalfontz.com/product/cfah2001byyhet-character-lcd-20x1), 
[CFAH2002A-NGG-JT](https://www.crystalfontz.com/product/cfah2002anggjt-20x2-character-lcd), 
[CFAH2002A-NYG-JT](https://www.crystalfontz.com/product/cfah2002anygjt-display-module-text-20x2), 
[CFAH2002A-NYG-JTV](https://www.crystalfontz.com/product/cfah2002anygjtv-lcd-20x2-character-module), 
[CFAH2002A-TFH-JT](https://www.crystalfontz.com/product/cfah2002atfhjt-lcd-display-20x2-alphanumeric), 
[CFAH2002A-TMI-JT](https://www.crystalfontz.com/product/cfah2002atmijt-20x2-character-display-module), 
[CFAH2002A-YMI-JT](https://www.crystalfontz.com/product/cfah2002aymijt-character-module-lcd-20x2), 
[CFAH2002A-YMI-JTV](https://www.crystalfontz.com/product/cfah2002aymijtv-character-display-20x2), 
[CFAH2002A-YYH-JT](https://www.crystalfontz.com/product/cfah2002ayyhjt-character-20x2-display-module), 
[CFAH2002A-YYH-JTV](https://www.crystalfontz.com/product/cfah2002ayyhjtv-20x2-display-module-text), 
[CFAH2002D-TMI-ET](https://www.crystalfontz.com/product/cfah2002dtmiet-character-lcd-20x2), 
[CFAH2002D-YYH-ET](https://www.crystalfontz.com/product/cfah2002dyyhet-character-lcd-20x2), 
[CFAH2002L-TFH-ET](https://www.crystalfontz.com/product/cfah2002ltfhet-character-display-lcd-20x2), 
[CFAH2002L-TMI-ET](https://www.crystalfontz.com/product/cfah2002ltmiet-character-module-lcd-20x2), 
[CFAH2002L-YYH-ET](https://www.crystalfontz.com/product/cfah2002lyyhet-character-20x2-display-module), 
[CFAH2002M-TMI-ET](https://www.crystalfontz.com/product/cfah2002mtmiet-character-lcd-20x2), 
[CFAH2002M-YYH-ET](https://www.crystalfontz.com/product/cfah2002myyhet-20x2-character-display-module), 
[CFAH2004A-NYG-JT](https://www.crystalfontz.com/product/cfah2004anygjt-lcd-20x4-character-module), 
[CFAH2004A-TFH-JT](https://www.crystalfontz.com/product/cfah2004atfhjt-lcd-display-alphanumeric-20x4), 
[CFAH2004A-TMI-JT](https://www.crystalfontz.com/product/cfah2004atmijt-display-module-20x4-character), 
[CFAH2004A-YTI-JT](https://www.crystalfontz.com/product/cfah2004aytijt-character-display-20x4), 
[CFAH2004A-YYH-JT](https://www.crystalfontz.com/product/cfah2004ayyhjt-20x4-lcd-display-alphanumeric), 
[CFAH2004A-YYH-JTE](https://www.crystalfontz.com/product/cfah2004ayyhjte-20x4-character-display), 
[CFAH2004B-TFH-ET](https://www.crystalfontz.com/product/cfah2004btfhet-20x4-lcd-character-module), 
[CFAH2004B-TMI-ET](https://www.crystalfontz.com/product/cfah2004btmiet-20x4-character-lcd), 
[CFAH2004B-YYH-ET](https://www.crystalfontz.com/product/cfah2004byyhet-alphanumeric-20x4-lcd-display), 
[CFAH2004D-TMI-ET](https://www.crystalfontz.com/product/cfah2004dtmiet-character-display-20x4), 
[CFAH2004D-YYH-ET](https://www.crystalfontz.com/product/cfah2004dyyhet-lcd-character-display-20x4), 
[CFAH2004L-NYG-ET](https://www.crystalfontz.com/product/cfah2004lnyget-20x4-character-display), 
[CFAH2004L-TMI-JT](https://www.crystalfontz.com/product/cfah2004ltmijt-character-display-20x4),
[CFAH2004L-YYH-JT](https://www.crystalfontz.com/product/cfah2004lyyhjt-display-module-character-20x4),
[CFAH2402A-TFH-JT](https://www.crystalfontz.com/product/cfah2402atfhjt-character-display-module-24x2),
[CFAH2402A-TMI-JT](https://www.crystalfontz.com/product/cfah2402atmijt-character-lcd-24x2),
[CFAH2402A-YYH-JT](https://www.crystalfontz.com/product/cfah2402ayyhjt-text-display-module-24x2),
[CFAH4002A-TMI-JT](https://www.crystalfontz.com/product/cfah4002atmijt-text-display-module-40x2), 
[CFAH4002A-YYH-JT](https://www.crystalfontz.com/product/cfah4002ayyhjt-40x2-character-display), 
[CFAH4004A-TFH-JT](https://www.crystalfontz.com/product/cfah4004atfhjt-character-lcd-40x4),
[CFAH4004A-YYH-JT](https://www.crystalfontz.com/product/cfah4004ayyhjt-character-module-40x4-lcd),
[CFAH4004A1-TMI-JT](https://www.crystalfontz.com/product/cfah4004a1tmijt) 


For more inforamtion about other character LCD display offerings, please see our full list [here](https://www.crystalfontz.com/c/character-lcd-displays/21).