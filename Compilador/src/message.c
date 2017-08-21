#include "../CompilerPCH.h"
#include "../includes/message.h"

void fnWarningMessage(int iWarningType, int iSymbolExpected, int iSymbolFound, int iLineNO, char* strName )
{
	printf("%s", "[WARNING]: ");

	if (iWarningType == WARNING_CAST_MISSTMATCH)
		printf("cast missmatch in line %d. Trying to convert %s to %s.\n", iLineNO, *(g_SYMBOLS + iSymbolFound), *(g_SYMBOLS + iSymbolExpected) );
	else if (iWarningType == WARNING_VAR_DEF_NUSED)
		printf("variable %s defined in line %d but it is never used.\n", strName, iLineNO);
	else if (iWarningType == WARNING_FUNC_REDEF)
		printf("function %s redefinition in line %d.\n", strName, iLineNO);
	else if (iWarningType == WARNING_VAR_REDEF)
		printf("variable %s redefinition in line %d.\n", strName, iLineNO);
	//else if (iWarningType == WARNING_P_ND)
		//printf("procedure %s used in line %d but is not defined.\n", strName, iLineNO);
	//else if (iWarningType == WARNING_P_R)
		//printf("procedure %s redefinition.\n", strName );
	else
		printf("warning id %d is not defined.\n", iWarningType );
}


void fnErrorMessage(int iErrorType, int iTypeExpected, int iTypeFound, int iLineNO, char* strName)
{
	printf("[ERROR]:");
	if (iErrorType == ERROR_TYPE_UNK)
	{
		printf("data type unknown in line %d", iLineNO );
		if (iTypeExpected !=-1 && iTypeFound != -1)
			printf(", expexted %s or %s.", *(g_SYMBOLS + iTypeExpected), *(g_SYMBOLS + iTypeFound) );
		else if( iTypeExpected != -1 )
			printf(", expexted %s", *(g_SYMBOLS + iTypeExpected) );
	}
	else if (iErrorType == ERROR_VAR_NDEF)
		printf("variable %s used in line %d but is not defined.", strName, iLineNO );
	//else if( iErrorType == ERROR_P_ND)
		//printf("param %s used in line %d but is not defined.\n", strName, iLineNO );
	//else if (iErrorType == ERROR_P_NF)
		//printf("param %s not found in line %d.\n", strName, iLineNO );
	else if (iErrorType == ERROR_PARAM_MISSMATCH)
		printf("type missmatch with param %s in line %d expected %s but found %s.", strName, iLineNO, *(g_SYMBOLS + iTypeExpected), *(g_SYMBOLS + iTypeFound));
	else if (iErrorType == ERROR_SEMICOLON_NFOUND)
		printf("semicolon not found. Expected in line %d.", iLineNO);
	else if( iErrorType == ERROR_FUNC_NDEF)
		printf("procedure %s used in line %d but is not defined.", strName, iLineNO);
	else if( iErrorType == ERROR_FUNC_FA)
		printf("few parameters with the function %s in line %d.", strName, iLineNO );
	else if( iErrorType == ERROR_FUNC_MA)
		printf("many parameters with the function %s in line %d.", strName, iLineNO);
	else
		printf("error id %d is not defined.", iErrorType );
	printf("\n");
	exit(iErrorType);
}
