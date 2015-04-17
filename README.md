# Raspberry Pi Setup
-----------------------

## Software update
### update software
	sudo apt-get update 		*Download lijst met updates*
	sudo apt-get upgrade		*Installeer updates*

### installeren software
* Installeren Git ( om de laatste versie van wiring Pi te downloaden) <br>
* Instaleren wiringPi ( library voor het besturen van IO )

Uitvoeren:

	sudo apt-get install git	*Download en installeer git*

Download de laatste versie van wiringPi:	
	
	git clone git://git.drogon.net/wiringPi	*Download*
	cd wiringPi								*Open de directory*
	git pull origin							*Check de laatste versie*
	
Compileer de wiringPi library:

	./build									*Compileer en installeer software*
	
### Voorbeelden c++

Om de voorbeelden te compileren is `g++` nodig.
Compileer helloworld.cpp: __-o helloworld__  is de naam van de executable.

	g++ helloworld.cpp -o helloworld
	
Uitvoeren van het nieuwe programma
	
	./helloworld
	


#### Hello World:
Print informatie naar de console.

	#include <iostream>
	using namespace std; // std is de standaard namespace (cout staat hier in, anders std::cout )
	 
	int main()
	{
		// cout = Standaard output (console / terminal output )
		// endl = end of line. 
	          cout << "Hello,World!" << endl;
	          return 0;
	}
	
#### keyboard invoer lezen:

Voorbeeld applicatie om een getal in te lezen vanaf de console.

	#include <iostream>
	using namespace std;
	 
	int main()
	{
            cout << "Geef de hoogte van de kerstboom op:";
            int hoogte = 0;
            cin >> hoogte ;
			cout << "Hoogte van de boom wordt: " << hoogte << endl;
			int x,y;
		
			// boom tekenen
			for ( y = hoogte ; y > 0   ; y-- ) {
				for ( x = 0 ; x < ((y + 1)/2) ; x++ ) cout << " ";
				for ( x = 0 ; x < (hoogte -y + 1) ; x++ ) cout << "*";
				cout  << endl;
			}
	
			// stam tekenen y = stam hoogte. 
			for ( y = 0 ; y < 3 ; y++ ) {
				for ( x = 0 ; x < (hoogte/2) ; x++ )  cout << " ";
				cout << "*" << endl;
	 		}
	                return 0;
	}


### Voorbeelden c
Aansturing van i/o pinnen

	#include <stdio.h>
	#include <wiringPi.h>
	
	// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
	
	#define	LED	0
	
	int main (void)
	{
	  printf ("Raspberry Pi blink\n") ;
	
	  wiringPiSetup () ;
	  pinMode (LED, OUTPUT) ;
	
	  for (;;)
	  {
	    digitalWrite (LED, HIGH) ;	// On
	    delay (500) ;		// mS
	    digitalWrite (LED, LOW) ;	// Off
	    delay (500) ;
	  }
	  return 0 ;
	}
	
Om het programma te compileren gebruik: `gcc` 
Compileer blink.c : __-o blink__  is de naam van de executable.

	gcc -lwiringPi blink.c -o blink
	
Uitvoeren van het nieuwe programma, dit moet als super user ivm met de low level hardware toegang.
onder linux kan een commando als super user (administrator) worden uitgevoerd met sudo (Super User do)
	
	sudo ./blink
	
### Een applicatie standard starten na booten Raspberry Pi
Om een applicatie onder linux automatisch te laten starten is de makkelijkste manier deze toe te voegen aan de rc.local file. 

rc.local is een soort autoexec.bat. 

In linux is het mogelijk om een applicatie naar de achtergrond te sturen. Dit gebeurd door de applicatie te starten met een __'&'__ teken aan het einde van de regel.

Applicatie in de voorgrond.

	./blink
	
Applicatie in de achtergrond.

	./blink &
	
De applicatie toevoegen aan de rc.local


	sudo nano /etc/rc.local


Pas het bestand aan als volgt:

	#!/bin/sh -e
	#
	# rc.local
	#
	# This script is executed at the end of each multiuser runlevel.
	# Make sure that the script will "exit 0" on success or any other
	# value on error.
	#
	# In order to enable or disable this script just change the execution
	# bits.
	#
	# By default this script does nothing.
	
	# Print the IP address
	_IP=$(hostname -I) || true
	if [ "$_IP" ]; then
	  printf "My IP address is %s\n" "$_IP"
	fi
	

	# voeg onderstaande regel toe om de blink applicatie automatisch te laten starten:
	/home/pi/Programmeren/Cpp_voorbeeld/blink &
	
	exit 0
	

