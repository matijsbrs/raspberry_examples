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
 
