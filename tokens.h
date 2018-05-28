#ifndef tokens_h
#define tokens_h
/* tokens.h -- List of labelled tokens and stuff
 *
 * Generated from: example1.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
 * ANTLR Version 1.33MR33
 */
#define zzEOF_TOKEN 1
#define NUM 2
#define STARTC 3
#define ENDC 4
#define MOVE 5
#define IF 6
#define SPACE 7

#ifdef __USE_PROTOS
void roomba(AST**_root);
#else
extern void roomba();
#endif

#ifdef __USE_PROTOS
void position(AST**_root);
#else
extern void position();
#endif

#endif
extern SetWordType setwd1[];
