#pragma once
/************************************************
*				SCANNER FUNCTIONS				*
*************************************************/

void fnInitScanner();

void fnReadCharacter();
int fnGetSymbol();
char fnFindNextCharacter();

int fnIsCharacterWhitespace();
int fnIsCharacterNewLine();
int fnIsCharacterLetter();
int fnIsCharacterDigit();
int fnIsCharacterLetterOrDigitOrUnderscore();
int fnISCharacterNotDoubleQuoteOrNewLineOrEOF();

int fnIdentifierStringMatch(char* keyword);
int fnIdentifierOrKeyword();

void fnSyntaxErrorMessage(char* message);
void fnsyntaxErrorCharacter(char expected);
void fnLog();
