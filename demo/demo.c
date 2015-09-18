/*
 *
 * demo.c
 *
 * Copyright (c) David Mandala david.mandala@linaro.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2.0
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 *
 * This demo uses the rudimentary beginnings of the 96BoardGPIO library
 * to control real world hardware.
 * 
 * 
 * Here is a demo of running a motorized 12 vdc ball valve via a 5 vdc
 * set of relays and turning on and off said relays just because we can.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <gpio.h>
#include <unistd.h>

#define GPIO_OFFSET 23
#define NUM_PINS 8

#define GPIO_P1 23
#define GPIO_P2 24
#define GPIO_P3 25
#define GPIO_P4 26
#define GPIO_P5 27
#define GPIO_P6 28
#define GPIO_P7 29
#define GPIO_P8 30

void relay_on( int pin ){
    digitalWrite(pin, HIGH);
    printf("Relay On\n");
    usleep(800000);
}

void relay_off(int pin){
    digitalWrite(pin, LOW);
    printf("Relay Off\n");
    usleep(800000);
}

void open_valve(void){
    digitalWrite(GPIO_P7, HIGH);
    digitalWrite(GPIO_P8, HIGH);
    printf("Valve Open\n");
    sleep(3);
    digitalWrite(GPIO_P7, LOW);
    digitalWrite(GPIO_P8, LOW);

}

void close_valve(void){
    digitalWrite(GPIO_P7, HIGH);
    digitalWrite(GPIO_P8, LOW);
    printf("Valve Closed\n");
    sleep(3);
    digitalWrite(GPIO_P7, LOW);
    digitalWrite(GPIO_P8, LOW);
}


int main(){
    int x;
    int loop1, loop2;

    if (!init_96Boards_GPIO_library("dragon")){
        // Open the GPIO for use.  Do so by pin number on the 
        // Low Speed Expansion Connector. This could have been
        // done in other ways too.
        for (x=GPIO_OFFSET;x<GPIO_OFFSET+NUM_PINS;x++){
            open_GPIO_Board_pin_number(x);
            // Now set allports that we are using to out
            setup_GPIO(x, "out");
        }
        
        for (loop1 = 500;loop1;loop1--){
            open_valve();
            for( loop2 = 5;loop2;loop2--){
                for (x=GPIO_OFFSET;x<GPIO_OFFSET+6;x++){
                    relay_on(x);
                }
                for (x=GPIO_OFFSET+5;x>=GPIO_OFFSET;x--){
                    relay_off(x);
                }
            }
            for( loop2 = 5;loop2;loop2--){
                for (x=GPIO_OFFSET;x<GPIO_OFFSET+6;x++){
                    relay_on(x);
                }
                for (x=GPIO_OFFSET;x<GPIO_OFFSET+6;x++){
                    relay_off(x);
                }
            }
            close_valve();
            for( loop2 = 5;loop2;loop2--){
                for (x=GPIO_OFFSET+5;x>=GPIO_OFFSET;x--){
                    relay_on(x);
                }
                for (x=GPIO_OFFSET;x<GPIO_OFFSET+6;x++){
                    relay_off(x);
                }
            }
            for( loop2 = 5;loop2;loop2--){
                for (x=GPIO_OFFSET+5;x>=GPIO_OFFSET;x--){
                    relay_on(x);
                }
                for (x=GPIO_OFFSET+5;x>=GPIO_OFFSET;x--){
                    relay_off(x);
                }
            }
            
        }
        sleep(5);

    }
    return (0);
}
