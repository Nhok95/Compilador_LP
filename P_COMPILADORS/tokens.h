#ifndef tokens_h
#define tokens_h
/* tokens.h -- List of labelled tokens and stuff
 *
 * Generated from: plumber.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
 * ANTLR Version 1.33MR33
 */
#define zzEOF_TOKEN 1
#define TUBE 2
#define TUBEVECTOR 3
#define EQUAL 4
#define BOOLEQ 5
#define BOOLESS 6
#define BOOLGREAT 7
#define BOOLESSEQ 8
#define BOOLGREATEQ 9
#define COMA 10
#define PAR1 11
#define PAR2 12
#define MERGE 13
#define SPLIT 14
#define CONNECTOR 15
#define LENGTH 16
#define DIAMETER 17
#define OF 18
#define WHILE 19
#define ENDWHILE 20
#define AND 21
#define OR 22
#define NOT 23
#define FULL 24
#define EMPTY 25
#define PUSH 26
#define POP 27
#define PLUS 28
#define MINUS 29
#define MUL 30
#define DIV 31
#define DIGIT 32
#define ID 33
#define SPACE 34

#ifdef __USE_PROTOS
void plumber(AST**_root);
#else
extern void plumber();
#endif

#ifdef __USE_PROTOS
void ops(AST**_root);
#else
extern void ops();
#endif

#ifdef __USE_PROTOS
void asigop(AST**_root);
#else
extern void asigop();
#endif

#ifdef __USE_PROTOS
void leftop(AST**_root);
#else
extern void leftop();
#endif

#ifdef __USE_PROTOS
void asigexpr(AST**_root);
#else
extern void asigexpr();
#endif

#ifdef __USE_PROTOS
void aritexpr(AST**_root);
#else
extern void aritexpr();
#endif

#ifdef __USE_PROTOS
void term(AST**_root);
#else
extern void term();
#endif

#ifdef __USE_PROTOS
void atom(AST**_root);
#else
extern void atom();
#endif

#ifdef __USE_PROTOS
void mergexp(AST**_root);
#else
extern void mergexp();
#endif

#ifdef __USE_PROTOS
void pushpopexp(AST**_root);
#else
extern void pushpopexp();
#endif

#ifdef __USE_PROTOS
void splitop(AST**_root);
#else
extern void splitop();
#endif

#ifdef __USE_PROTOS
void parID(AST**_root);
#else
extern void parID();
#endif

#ifdef __USE_PROTOS
void splitexpr(AST**_root);
#else
extern void splitexpr();
#endif

#ifdef __USE_PROTOS
void lengexp(AST**_root);
#else
extern void lengexp();
#endif

#ifdef __USE_PROTOS
void diamexp(AST**_root);
#else
extern void diamexp();
#endif

#ifdef __USE_PROTOS
void pardim(AST**_root);
#else
extern void pardim();
#endif

#ifdef __USE_PROTOS
void whilexp(AST**_root);
#else
extern void whilexp();
#endif

#ifdef __USE_PROTOS
void whilepar(AST**_root);
#else
extern void whilepar();
#endif

#ifdef __USE_PROTOS
void boolexp(AST**_root);
#else
extern void boolexp();
#endif

#ifdef __USE_PROTOS
void boolexp2(AST**_root);
#else
extern void boolexp2();
#endif

#ifdef __USE_PROTOS
void fullemptyvec(AST**_root);
#else
extern void fullemptyvec();
#endif

#endif
extern SetWordType zzerr1[];
extern SetWordType zzerr2[];
extern SetWordType zzerr3[];
extern SetWordType setwd1[];
extern SetWordType zzerr4[];
extern SetWordType zzerr5[];
extern SetWordType zzerr6[];
extern SetWordType zzerr7[];
extern SetWordType zzerr8[];
extern SetWordType setwd2[];
extern SetWordType setwd3[];
extern SetWordType zzerr9[];
extern SetWordType zzerr10[];
extern SetWordType zzerr11[];
extern SetWordType zzerr12[];
extern SetWordType setwd4[];
