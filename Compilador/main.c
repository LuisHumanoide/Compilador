#include "./includes/CompilerPCH.h"
#include <conio.h>

int main( int argc, char** argv )
{
	initCompiler( );
	char* filename;
	/**
	if( argc > 0 )
	{
		for ( int i = 0; i < argc; ++i )
			printf( "%s\n", argv[ i ] );
		return 0;
	}
	*/
	//Example... a.exe "Test\test7.txt" > out.txt
	if( argc > 1 )
		filename = argv[ 1 ];
	else
		filename = "Test/testCodeGen.c";

	g_sourceFD = fopen( filename, "r" );
	
	if( g_sourceFD != NULL )
	{
		fnOpenFileToWrite( "testfile.txt" );
		fnInitScanner( );    // Incializar el scanner
		fnReadCharacter( );  // Leer el primer carácter
		fnGetSymbol( );      // Obtener el primer token
		fnParser( );         // Iniciar el parser
		
		fnCloseFile( );
		fclose( g_sourceFD ); // Cerrar el archivo
	}
	else
	{
		printf( "Could not open input file: " );
		printf( "\"%s\"\n", filename );
		exit( 1 );
	}

	/*fnPrintTable( GLOBAL_TABLE );
	fnPrintTable( LOCAL_TABLE );*/
	
	fnUninitializeScanner( );
	fnResetSymbolTables( );

	printf( "\n\n Press any key to exit..." );
	_getch( );
	return 0;
}
