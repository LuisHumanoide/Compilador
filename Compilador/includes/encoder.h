/********************************************************************
	file:		encoder.h
	date:		2017/08/06
	author: 	Luis Escutia
	Contact:	escutialuis93@gmail.com

	Purpose:	Codificar instrucciones.
********************************************************************/

#pragma once
/** 
*	Desc: funci�n para codificar una instrucci�n usando registros.
*	@Param opcode es un entero para identificar el operador utilizado.
*	@Param rs es el registro donde se guardara el valor.
*	@Param rt carga el valor correspondiente al registro enviado.
*	@Param rd carga el valor correspondiente al registro enviado.
*	@Param function la funci�n a realizar con el operador
*	@Return regresa la instrucci�n a realizar codificada en un entero.
*/
int encodeRFormat( int opcode, int rs, int rt, int rd, int function );

/**
*	Desc: funci�n para codificar una instrucci�n.
*	@Param opcode es un entero para identificar el operador utilizado.
*	@Param rs es el registro donde se guardara el valor.
*	@Param rt carga el valor correspondiente al registro enviado.
*	@Param immediate carga el valor estatico enviado.
*	@Return regresa la instrucci�n a realizar codificada en un entero.
*/
int encodeIFormat( int opcode, int rs, int rt, int immediate );

// TODO: para que es el instr_index?
/**
*	Desc: funci�n para codificar una instrucci�n.
*	@Param opcode es un entero para identificar el operador utilizado.
*	@Param instr_index 
*	@Return regresa la instrucci�n a realizar codificada en un entero.
*/
int encodeJFormat( int opcode, int instr_index );