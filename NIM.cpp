//NIM dabs október 1997
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

//Þetta fall á að birta stöðu allra eldspýtnahrúgna (hrúgur í fleirtölu eignarfalli)
void birta( int* hruga );

//Þetta fall á að reikna út hversu margar eldspýtur eru eftir í hrúgunum:
int samtals( int* hruga );

//Þetta fall lætur tölvuna gera:
void tolva( int* hruga );

//Þetta fall lætur notandann gera:
void notandi( int* hruga );

//Þetta fall birtir reglurnar í spilinu:
void hjalp( );

//Þetta fall spilar spilið:
void spila( );

//Ég leyfi mér að nota eina víðværa breytu af því að forritið notar alltaf
//mismargar hrúgur í hvert og eitt skipti:
int hrugufjoldi;

//Hér byrjar aðalforritið:
int main( )
{
	int val;
	do
	{
		cout << endl << endl << endl;
		cout << "                Main Display " << endl << endl;
		cout << "                      1. Play NIM" << endl;
		cout << "                      2. Show rules of NIM" << endl;
		cout << "                      3. Quit " << endl << endl;
		cout << "                      Choose 1, 2 or 3:" << endl << endl;
		cin >> val;
		switch ( val )
		{
		case 1:
			spila( );
			break;
		case 2:
			hjalp( );
			break;
		case 3:
			break;
		}
	}
	while ( val != 3 );

	return 0;
}

void spila( )
{
	int hruga[ 10 ];
	cout << "*-------------------------------------------------------*" << endl;
	cout << "                   Lets Play NIM!!" << endl;
	cout << "*-------------------------------------------------------*" << endl;
	cout << endl << endl;
	cout << "Choose how many Piles to play. " << endl;
	//cout << "Press any key: " << endl;

	srand( time( 0 ) );

	hrugufjoldi = ( (rand( ) % 8 ) + 2 );
	cout << "Now we play with " << hrugufjoldi << " Piles. " << endl;

	for ( int i = 0; i < hrugufjoldi; i++ )
	{
		hruga[ i ]=( ( rand( ) % 14 ) + 1 );
	}

	cout << endl;
	birta ( hruga );

	do
	{
		notandi( hruga );
		birta( hruga );
		tolva( hruga );
		birta( hruga );
	}
	while ( samtals( hruga ) );
}

void hjalp( )
{
	cout << "              About NIM " << endl << endl;
	cout << "The game NIM originates from Asia where it was" << endl;
	cout << "played with small stones.  These are the rules: " << endl;
	cout << "Contestants but any number of sticks in a pile " << endl;
	cout << "(They can decide how many piles and how many " << endl;
	cout << "sticks in every pile) and then they swich turn on " << endl;
	cout << "taking sicks out of a pile.  They can " << endl;
	cout << "can take one, few or all from one pile " << endl;
	cout << "but they can only take sticks form  " << endl;
	cout << "one pile at a time.  The one that takes the last stick " << endl;
	cout << "From the last pile.  Good luck! " << endl << endl;
	cout << "* This game was translated to english by: "<< endl;
	cout << "Agust Einarsson." << endl;
	getchar( );
}

void birta( int* hruga )
{
	if( !samtals( hruga ) )
	{
		return;
	}
	cout << "                         Pile no.: ";
	for (int i = 0; i < hrugufjoldi; i++ )
	{
		cout << " " << (i + 1) << "  ";
	}

	cout << endl << endl;
	cout << "Number of sticks in each pile is: ";
	for ( int c = 0; c < hrugufjoldi; c++ )
	{
		if( hruga[c] < 10 )
		{
			cout << " " << hruga[ c ] << "  ";
		}
		else
		{
			cout << hruga[ c ] << "  ";
		}
	}
	cout << endl << endl;
}

void notandi( int* hruga )
{
	if ( samtals( hruga ) == 0 )
	{
		return;
	}
	int eldspytur;
	int hrugunumer;
	do
	{
		cout << "Type number of sticks you want to take: ";
		cin >> eldspytur;
		cout << endl;
		if( eldspytur < 1 )
		{
			cout << "You must take atleast one, try again. " << endl << endl;
			continue;
		}
		cout << "Type wich pile to take from: ";
		cin  >> hrugunumer;
		if( hrugunumer > hrugufjoldi )
		{
			cout << "There is no pile with that number.  Choose again." <<endl<<endl;
			continue;
		}
		if( eldspytur > hruga[ (hrugunumer) - 1 ] )
		{
			cout <<"There are not that many sticks in the pile. Choose again."<<endl<<endl;
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] || eldspytur < 1 );

	hruga[ hrugunumer - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "Congratulation, you won!" << endl << endl;
		cout << "Choose an option... " << endl;
		getchar( );
	}
	cout << endl;
}

void tolva( int* hruga )
{
	if( samtals( hruga ) == 0 )
	{
		return;
	}

	int eldspytur;
	int hrugunumer;

	do
	{
		eldspytur = ( ( rand( ) % 14 ) + 1 );
		hrugunumer = ( ( rand( ) % hrugufjoldi ) + 1 );
		if( eldspytur > hruga[(hrugunumer)-1] )
		{
			continue;
		}
	}
	while ( eldspytur > hruga[ (hrugunumer) - 1 ] );

	if ( eldspytur > 1 )
	{
		cout << "      I take " << eldspytur << " sticks from pile no. ";
	}
	else
	{
		cout << "      I take " << eldspytur << " sticks from pile no. ";
	}
	cout << hrugunumer << "." << endl;

	hruga[ (hrugunumer) - 1 ] -= eldspytur;
	if( !samtals( hruga ) )
	{
		cout << endl << "I won.  Better luck next time!" << endl << endl;
		cout << "Choose an option...   " << endl;
		getchar( );
	}
	cout << endl;
}

int samtals( int* hruga )
{
	int samtala = 0;
	for( int i = 0; i < hrugufjoldi; i++ )
	{
		samtala += hruga[ i ];
	}

	return samtala;
}
