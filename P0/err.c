/*
 * A n t l r  S e t s / E r r o r  F i l e  H e a d e r
 *
 * Generated from: calculadora.g
 *
 * Terence Parr, Russell Quong, Will Cohen, and Hank Dietz: 1989-2001
 * Parr Research Corporation
 * with Purdue University Electrical Engineering
 * With AHPCRC, University of Minnesota
 * ANTLR Version 1.33MR33
 */

#define ANTLR_VERSION	13333
#include "pcctscfg.h"
#include "pccts_stdio.h"

#include <string>
#include <iostream>
using namespace std;

// struct to store information about tokens
typedef struct {
  string kind;
  string text;
} Attrib;

// function to fill token information (predeclaration)
void zzcr_attr(Attrib *attr, int type, char *text);

// fields for AST nodes
#define AST_FIELDS string kind; string text;
#include "ast.h"

// macro to create a new AST node (and function predeclaration)
#define zzcr_ast(as,attr,ttype,textt) as=createASTnode(attr,ttype,textt)
AST* createASTnode(Attrib* attr, int ttype, char *textt);
#define zzSET_SIZE 4
#include "antlr.h"
#include "ast.h"
#include "tokens.h"
#include "dlgdef.h"
#include "err.h"

ANTLRChar *zztokens[13]={
	/* 00 */	"Invalid",
	/* 01 */	"@",
	/* 02 */	"NUM",
	/* 03 */	"PLUS",
	/* 04 */	"MINUS",
	/* 05 */	"MUL",
	/* 06 */	"DIV",
	/* 07 */	"PAR1",
	/* 08 */	"PAR2",
	/* 09 */	"WRITE",
	/* 10 */	"ID",
	/* 11 */	"ASIG",
	/* 12 */	"SPACE"
};
SetWordType zzerr1[4] = {0x0,0x6,0x0,0x0};
SetWordType zzerr2[4] = {0x18,0x0,0x0,0x0};
SetWordType zzerr3[4] = {0x60,0x0,0x0,0x0};
SetWordType zzerr4[4] = {0x84,0x4,0x0,0x0};
SetWordType setwd1[13] = {0x0,0xd6,0x0,0xc8,0xc8,0xa0,0xa0,
	0x0,0xd0,0xd5,0xd5,0x0,0x0};
SetWordType setwd2[13] = {0x0,0x1,0x0,0x1,0x1,0x1,0x1,
	0x0,0x1,0x1,0x1,0x0,0x0};
