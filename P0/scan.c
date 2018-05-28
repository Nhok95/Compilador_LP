
/* parser.dlg -- DLG Description of scanner
 *
 * Generated from: calculadora.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
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
#include "antlr.h"
#include "ast.h"
#include "tokens.h"
#include "dlgdef.h"
LOOKAHEAD

void
#ifdef __USE_PROTOS
zzerraction(void)
#else
zzerraction()
#endif
{
	(*zzerr)("invalid token");
	zzadvance();
	zzskip();
}
/*
 * D L G tables
 *
 * Generated from: parser.dlg
 *
 * 1989-2001 by  Will Cohen, Terence Parr, and Hank Dietz
 * Purdue University Electrical Engineering
 * DLG Version 1.33MR33
 */

#include "mode.h"



static void act1()
{ 
		NLA = 1;
	}


static void act2()
{ 
		NLA = NUM;
	}


static void act3()
{ 
		NLA = PLUS;
	}


static void act4()
{ 
		NLA = MINUS;
	}


static void act5()
{ 
		NLA = MUL;
	}


static void act6()
{ 
		NLA = DIV;
	}


static void act7()
{ 
		NLA = PAR1;
	}


static void act8()
{ 
		NLA = PAR2;
	}


static void act9()
{ 
		NLA = WRITE;
	}


static void act10()
{ 
		NLA = ID;
	}


static void act11()
{ 
		NLA = ASIG;
	}


static void act12()
{ 
		NLA = SPACE;
    zzskip();  
	}

#define DfaStates	18
typedef unsigned char DfaState;

static DfaState st0[258] = {
  1, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 2, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 2, 18, 18, 18, 18, 18, 18, 
  18, 3, 4, 5, 6, 18, 7, 18, 8, 9, 
  9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 
  18, 18, 18, 18, 18, 18, 11, 11, 11, 11, 
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
  11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 
  11, 11, 18, 18, 18, 18, 18, 18, 11, 11, 
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
  11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 
  12, 11, 11, 11, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st1[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st2[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st3[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st4[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st5[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st6[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st7[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st8[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st9[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 9, 
  9, 9, 9, 9, 9, 9, 9, 9, 9, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st10[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 13, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st11[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st12[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 14, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 14, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st13[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st14[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 15, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 15, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st15[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 16, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 16, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st16[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 17, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};

static DfaState st17[258] = {
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 
  18, 18, 18, 18, 18, 18, 18, 18
};


DfaState *dfa[18] = {
	st0,
	st1,
	st2,
	st3,
	st4,
	st5,
	st6,
	st7,
	st8,
	st9,
	st10,
	st11,
	st12,
	st13,
	st14,
	st15,
	st16,
	st17
};


DfaState accepts[19] = {
  0, 1, 12, 7, 8, 5, 3, 4, 6, 2, 
  0, 10, 10, 11, 0, 0, 0, 9, 0
};

void (*actions[13])() = {
	zzerraction,
	act1,
	act2,
	act3,
	act4,
	act5,
	act6,
	act7,
	act8,
	act9,
	act10,
	act11,
	act12
};

static DfaState dfa_base[] = {
	0
};



#define ZZSHIFT(c) (1+c)
#define MAX_MODE 1
#include "dlgauto.h"
