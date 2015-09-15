#96BoardGPIO Demo Program  
##Overview  

This is a quick demo that can run on a DragonBoard 410c, HiKey or Bubblegum Board.
These boards meet the CE specification of the 96Boards.org 

This demo program uses the 96BoardsGPIO shared library to work across all
96board CE 64bit boards without a recompile or any source code changes.  So
you must first install the shared library from
https://github.com/96boards/96BoardsGPIO/ and then the demo will compile and
run as expected.

The demo will drive 8 GPIO lines to control 8 5VDC relays and in turn they
will control a 12VDC exectricly driven ball valve.  The demo will cycle the
relays in differnt patterns and open and close the ball valve periodically.

One of the cool things about the 96Boards CE project is that all of the
boards us the same pins for the Low Speed Expansion Connector so you can
plug any expansion board into any 96Board and it will connect electrically
BUT there is a issue where GPIO is concerned.  Different SoC's have
different GPIO pins.  So even though electrically the pins are in the same
place it takes differnt code to enable and use the GPIO on pins 23 - 34. 
Not so fun.

The 96BoardGPIO library trys to abstract the info so that you can just
tell it what board you are using and what pins you want to use and the
library does the rest.  

##Install the source code  
So to install the library and test it with the example blink code you need
to do the following:

**git clone https://github.com/???? 

cd 96Boardsdemo/demo  
make  
sudo ./demo  

The code so far has been tested on a Dragonboard 410 c where it is known to
work very well.

##License

This library (96BoardsGPIO) is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2.0 of the
License.

This library is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public 
License along with this library; if not, write to the Free Software 
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

