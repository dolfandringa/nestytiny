#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>


#define LED PB1

int main() {
    int i;

    DDRB = 1 << LED;

    //wdt_enable(WDTO_1S); // enable 1s watchdog timer


    PORTB = 0;
    
    while(1) {
        //wdt_reset();

        for(i = 0; i<250; i++) { // wait 1 s
            //wdt_reset(); // keep the watchdog happy
            _delay_ms(2);
        }
        PORTB ^= 1<<LED;
    }
        
    return 0;
}
