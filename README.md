avr-pumpkin
===========

Jack-o-Lantern pimp-up with Light&amp;Sound&amp;ATtiny

Background
----------

My 7-year old particiates in a school contest for the best carved pumpkin. We made a simple Jack-o-Lantern with witchy hair and I tought that it's not enough to win the contest. Reading daily dose of the [Hack-a-day](http://hackaday.com) I've stumbled upon [AVR Halloween pumpkin](http://hackaday.io/project/3165) and realised that by making something in that spirit was the way to go!

Unfotunately, my trusted local parts supplier [AVT](http://sklep.avt.pl/) was short on PIR sensors, so I had to go for something simpler. Anyway, it was for a first-graders competition...

Parts
-----

The build has two functions:

  - sound - created by a MCU driving a piezo buzzer with a rectangular signal of changing frequency,
  - light - 4 red LEDs driven by a PWM signal synchronized with the sound.
  
MCU is an Atmel ATtiny45 in DIP package (tiny25 or even 13 would be enough, but 45 was what I had in a drawer). Buzzer control consumes Timer0 in CTC (clear on timer compare) mode, LED uses Timer1 in PWM mode. Maybe there's some clever way to use just one timer (and then there would be opportunity to get an ATtiny4 to work) but I not know of any. We were short on time also.

Power is supplied by a 9V battery powering LEDs direclty and an ATtiny with a help of 7805. There's also a 2N700 N-MOSFET used to drive 9V powered LEDs with 5V powered MCU.

As the whole beast wold be inside pumpkin (which I think is not an ideal enviroment for elecronics) we needed an enclosure. The only candidate I've found in my treasury was ["Barkleys Mints"](http://www.barkleysmints.com/) tin (like Altoids). This was the first time I've used the stuff and I must say I'm very pleased with the outcome. I should eat more of it!

Building my contraption on a breadboard and programming an AVR took about 2 hours. Another 2 or 3 took building everything in a final shape. I did some last-minute amendments to the software next day, put some comments, drew schematics in Eagle and here we are on the Github!

Pics or GTFO!
-------------

Sure: [Photos + videos](https://plus.google.com/photos/105671517547848869064/albums/6074564632052942449?authkey=CI6kq8fPtpLN-wE).


Files
-----

In the "eagle" directory there are schematics. No PCB, because I built it on a piece of a proto-board.
`main.c` is the only AVR code. Some comments are missing, I'll add them soon.


