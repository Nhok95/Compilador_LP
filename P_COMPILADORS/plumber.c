/*
 * A n t l r  T r a n s l a t i o n  H e a d e r
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-2001
 * Purdue University Electrical Engineering
 * With AHPCRC, University of Minnesota
 * ANTLR Version 1.33MR33
 *
 *   antlr -gt plumber.g
 *
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
#define GENAST

#include "ast.h"

#define zzSET_SIZE 8
#include "antlr.h"
#include "tokens.h"
#include "dlgdef.h"
#include "mode.h"

/* MR23 In order to remove calls to PURIFY use the antlr -nopurify option */

#ifndef PCCTS_PURIFY
#define PCCTS_PURIFY(r,s) memset((char *) &(r),'\0',(s));
#endif

#include "ast.c"
zzASTgvars

ANTLR_INFO

#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <stack>

struct STube 
{
  int length = 0;
  int diameter = 0;
};

struct TubeVector
{
  stack<STube> s;
  int maxc = 0;
};

map<string,int> mcon;
map<string,STube> mtubes;
map<string,TubeVector> mvector;

// function to fill token information
void zzcr_attr(Attrib *attr, int type, char *text) {
  if (type == DIGIT) {
    attr->kind = "intconst";
    attr->text = text;
  }
  else if (type == ID) {
    attr->kind = "ID";
    attr->text = text;
  }
  else {
    attr->kind = text;
    attr->text = "";
  }
}

// function to create a new AST node
AST* createASTnode(Attrib* attr, int type, char* text) {
  AST* as = new AST;
  as->kind = attr->kind; 
  as->text = attr->text;
  as->right = NULL; 
  as->down = NULL;
  return as;
}

/// create a new "list" AST node with one element
AST* createASTlist(AST *child) {
  AST *as=new AST;
  as->kind="list";
  as->right=NULL;
  as->down=child;
  return as;
}

/// get nth child of a tree. Count starts at 0.
/// if no such child, returns NULL
AST* child(AST *a,int n) {
  AST *c=a->down;
  for (int i=0; c!=NULL && i<n; i++) c=c->right;
  return c;
} 

/// print AST, recursively, with indentation
void ASTPrintIndent(AST *a,string s)
{
  if (a==NULL) return;
  
  cout<<a->kind;
  if (a->text!="") cout<<"("<<a->text<<")";
  cout<<endl;
  
  AST *i = a->down;
  while (i!=NULL && i->right!=NULL) {
    cout<<s+"  \\__";
    ASTPrintIndent(i,s+"  |"+string(i->kind.size()+i->text.size(),' '));
    i=i->right;
  }
  
  if (i!=NULL) {
    cout<<s+"  \\__";
    ASTPrintIndent(i,s+"   "+string(i->kind.size()+i->text.size(),' '));
    i=i->right;
  }
}

/// print AST 
void ASTPrint(AST *a)
{
  while (a!=NULL) {
    cout<<" ";
    ASTPrintIndent(a,"");
    a=a->right;
  }
}



int evaluate(AST *a) 
{
  if (a == NULL) return -1;
  if (a->kind == "CONNECTOR") 
  return evaluate(child(a,0));
  else if (a->kind == "LENGTH")
  {
    if (mtubes.find(child(a,0)->text) != mtubes.end()) 
    return mtubes[child(a,0)->text].length;
    else cout << "ERROR " << child(a,0)-> text << " no longer exists" << endl; 
    return -1;
  }
  else if (a->kind == "DIAMETER")
  {
    if (mtubes.find(child(a,0)->text) != mtubes.end())
    return mtubes[child(a,0)->text].diameter;
    else if (mcon.find(child(a,0)->text) != mcon.end())
    return mcon[child(a,0)->text];
    else cout << "ERROR " << child(a,0)-> text << " no longer exists" << endl; 
    return -1;
  }
  else if (a->kind == "intconst")
  return atoi(a->text.c_str());
  else if (a->kind == "+")
  return evaluate(child(a,0)) + evaluate(child(a,1));
  else if (a->kind == "*")
  return evaluate(child(a,0)) * evaluate(child(a,1));
  else if (a->kind == "-")
  return evaluate(child(a,0)) - evaluate(child(a,1));
  else if (a->kind == "/")
  return evaluate(child(a,0)) / evaluate(child(a,1));
}

void evaluateasig(AST *a, STube &auxt) 
{
  if (a == NULL) return;
  else if (a->kind == "TUBE")
  {
    auxt.length = evaluate(child(a,0));
    auxt.diameter = evaluate(child(a,1));
  }
}

void evaluatecopy(AST *a, int &auxl, int &auxd)
{
  if (a == NULL) return;
  else if (a->kind == "ID") 
  {
    if (mtubes.find(a->text) != mtubes.end())
    {
      auxl = mtubes[a->text].length;
      auxd = mtubes[a->text].diameter;
    }
    else if (mcon.find(a->text) != mcon.end())
    {
      auxl = -1;
      auxd = mcon[a->text];
    }
    else cout << "ERROR: " << a->text << " no longer exists" << endl;
  }
}

void evaluatevector(AST *a, TubeVector &auxtv)
{
  if (a == NULL) return;
  else if (a->kind == "TUBEVECTOR")
  auxtv.maxc = evaluate(child(a,0));
}

bool evaluatesplit(AST *a, STube &auxt1, STube &auxt2)
{
  if (a == NULL) return false;
  else if (a->kind == "SPLIT")
  {
    if (mtubes.find(child(a,0)->text) != mtubes.end())
    {
      string id = child(a,0)->text;
      auxt1.length = mtubes[id].length/2;
      auxt2.length = mtubes[id].length/2 + mtubes[id].length%2;
      
            auxt1.diameter = mtubes[id].diameter;
      auxt2.diameter = mtubes[id].diameter;
      
            mtubes.erase (id);
      return true;
    }
    else 
    {
      cout << "ERROR: " << child(a,0)->text << " no longer exists" << endl;
      return false;
    }
  }
}

STube evaluateMerge(AST *a, bool &b, map<string,bool>& st1, map<string,bool>& sc2)
{
  STube mergetube;
  if (a == NULL){
    cout << "null pointer (merge)" << endl;
  }
  else if (a->kind == "ID")  
  {
    if (mtubes.find(a->text) != mtubes.end())
    return mtubes[a->text];
    else if (mcon.find(a->text) != mcon.end()) 
    cout << "ERROR: expects a tube, receives a connector(" << a->text << ")" << endl;  
    else cout << "ERROR: " << a->text << " no longer exists" << endl;
    b = false;
    STube sret; 
    return sret;
  }
  else if (a->kind == "MERGE")
  {
    if (mcon.find(child(a,1)->text) != mcon.end())
    { //existeix conector
      auto it = sc2.find(child(a,1)->text);
      if ( it == sc2.end())
      {//no existeix el conector
        sc2[child(a,1)->text] = true;   
        mergetube.diameter = mcon[child(a,1)->text];
        
                STube s1 = evaluateMerge(child(a,0), b, st1, sc2);
        
                if (b) 
        {
          if (s1.diameter == mcon[child(a,1)-> text]){
            auto it = st1.find(child(a,0)->text);
            if (it == st1.end()) //no repetido
            {
              if (child(a,0)->kind == "ID") 
              st1[child(a,0)->text] = true;
              mergetube.length += s1.length;
              
                            STube s2 = evaluateMerge(child(a,2), b, st1, sc2);
              if (b) 
              {
                if (s2.diameter == mcon[child(a,1)-> text])
                {
                  auto it = st1.find(child(a,2)->text);
                  if (it == st1.end())
                  {
                    if (child(a,2)->kind == "ID") 
                    st1[child(a,2)->text] = true;
                    mergetube.length += s2.length;
                  }
                  else 
                  {
                    cout << "ERROR: connector " 
                    << child(a,1)->text<< " already used" << endl;
                    b = false;
                  }
                }
                else
                {
                  cout << "ERROR: Unmatch diameter between "
                  << child(a,1)->text
                  << " and "<< child(a,2)->text 
                  << endl;
                  b = false;
                }
              }
            }
          }
          else 
          {
            cout << "ERROR: Unmatch diameter between "
            << child(a,1)->text
            << " and "<< child(a,0)->text 
            << endl;
            b = false;
          }
        }
      }
      else 
      {
        cout << "ERROR: connector " << child(a,1)->text<< " already used" << endl;
        b = false;
      }
    }
    else if (mtubes.find(child(a,1)->text) != mtubes.end())
    {
      cout << "ERROR: expects a connector, receives a tube(" << child(a,1)->text << ")" << endl;  
      b = false;
    }
    else 
    {
      cout << "ERROR: " << child(a,1)->text << " no longer exists" << endl;
      b = false;
    }
    
        return mergetube;
  }
}

bool evaluateWhile (AST *a)
{
  if (a == NULL)
  return false;
  else if (a->kind == "AND")
  return evaluateWhile(child(a,0)) and evaluateWhile(child(a,1)); 
  else if (a->kind == "OR")
  return evaluateWhile(child(a,0)) or evaluateWhile(child(a,1)); 
  else if (a->kind == ">")
  return evaluate(child(a,0)) > evaluate(child(a,1)); 
  else if (a->kind == ">=")
  return evaluate(child(a,0)) >= evaluate(child(a,1)); 
  else if (a->kind == "==")
  return evaluate(child(a,0)) == evaluate(child(a,1)); 
  else if (a->kind == "<")
  return evaluate(child(a,0)) < evaluate(child(a,1)); 
  else if (a->kind == "<=")
  return evaluate(child(a,0)) <= evaluate(child(a,1)); 
  else if (a->kind == "FULL")
  return mvector[child(a,0)->text].s.size() == mvector[child(a,0)->text].maxc;
  else if (a->kind == "EMPTY")
  return mvector[child(a,0)->text].s.empty();
  else if (a->kind == "NOT")
  return !evaluateWhile(child(a,0));
}

//Funciones del vector;
void pushTube(AST *a1, AST *a2)
{
  if (mvector.find(a1->text) != mvector.end())
  {
    if (mtubes.find(a2->text) != mtubes.end())
    {
      if (mvector[a1->text].s.size() < mvector[a1->text].maxc)
      {
        mvector[a1->text].s.push(mtubes[a2->text]);
        mtubes.erase(a2->text);
      }
      else cout << "ERROR: TUBEVECTOR " << a1->text << " is full" << endl;
      
        }
    else cout << "ERROR: " << a2->text << " no longer exists" << endl;
  }
  else cout << "ERROR: " << a1->text << " no longer exists" << endl;
}

STube popTube(AST *a1)
{
  STube taux;
  taux.length = -1;
  if (mvector.find(a1->text) != mvector.end())
  {
    if (!mvector[a1->text].s.empty()){
      taux = mvector[a1->text].s.top();
      mvector[a1->text].s.pop();
    }
    else cout << "ERROR: TUBEVECTOR " << a1->text << " is empty" << endl;
  }
  else cout << "ERROR: " << a1->text << " no longer exists" << endl;
  return taux;
}


void execute(AST *a) 
{
  if (a == NULL)
  return;
  else if (a->kind == "=") 
  {
    if (child(a,0)->kind == "ID" && child(a,1)->kind == "ID") //SPLIT o Copia
    {
      if (child(a,2)!=NULL) //SPLIT
      {
        STube t1;STube t2;
        if (evaluatesplit(child(a,2),t1,t2))
        {
          mtubes[child(a,0)->text] = t1;
          mtubes[child(a,1)->text] = t2;
        }
      }
      else
      {
        int auxl, auxd;
        evaluatecopy(child(a,1), auxl, auxd); 
        if (auxl >= 0 and auxd >= 0) //COPY TUBE
        {
          STube tcop;
          tcop.length = auxl;
          tcop.diameter = auxd;
          
                  mtubes[child(a,0)->text] = tcop;
        }
        else if (auxd >= 0)//COPY CONNECTOR
        mcon[child(a,0)->text] = auxd;
      }
    }
    else
    {
      if (child(a,1)->kind == "CONNECTOR")
      {
        int cond;
        if ((cond = evaluate(child(a,1))) >= 0) 
        mcon[child(a,0)->text] = cond;
        else cout << "ERROR : invalid expressions in " << child(a,0)->text << endl;
      }
      else if (child(a,1)->kind == "TUBE")
      {
        STube t;
        
              evaluateasig(child(a,1), t);
        if (t.length >= 0 and t.diameter >= 0)
        mtubes[child(a,0)->text] = t;
        
              else cout << "ERROR : invalid expressions in " << child(a,0)->text << endl;
      }
      else if (child(a,1)->kind == "TUBEVECTOR")
      {
        TubeVector vt;
        evaluatevector(child(a,1), vt);
        if (vt.maxc >= 1)
        mvector[child(a,0)->text] = vt;
        else cout << "ERROR : invalid size in " << child(a,0)->text << endl; 
      }
      else 
      {
        bool mbool = true;
        map<string,bool> auxTubs;
        map<string,bool> auxCons;
        STube mergetube = evaluateMerge(child(a,1), mbool, auxTubs, auxCons);
        if (mbool) 
        {
          for (auto it = auxTubs.begin(); it !=  auxTubs.end(); it++)
          mtubes.erase (it->first);
          
                  for (auto it = auxCons.begin(); it != auxCons.end(); it++)
          mcon.erase (it->first);
          
                  mtubes[child(a,0)->text] = mergetube;
        }
      }
    }
  }
  else if (a->kind == "LENGTH") 
  {
    string s = child(a,0)->text;
    if (mtubes.find(s) != mtubes.end()) 
    cout << "LENGTH " << s << " " << mtubes[s].length << endl;
    else cout << "ERROR: " << s << " no longer exists" << endl; 
    
  }
  else if (a->kind == "DIAMETER") 
  {
    string s = child(a,0)->text;
    if (mtubes.find(s) != mtubes.end())
    cout << "DIAMETER " << s << " " << mtubes[s].diameter << endl;
    else cout << "ERROR: " << s << " no longer exists" << endl; 
  }
  else if (a->kind == "PUSH")
  {
    pushTube(child(a,0), child(a,1));
  }
  else if (a->kind == "POP")
  {
    STube taux = popTube(child(a,0));
    if (taux.length >= 0)
    mtubes[child(a,1)->text] = taux;
  }
  else if (a->kind == "WHILE")
  {
    while (evaluateWhile(child(a,0)))
    execute(child( child(a,1) ,0));
  }
  
  execute(a->right);
}

void PrintMaps()
{
  cout << endl <<  "RESULTAT: " << endl <<"--------------"<<endl;
  
    cout << "CONNECTORS: " << endl;
  for (auto itc = mcon.begin(); itc != mcon.end(); itc++)
  cout << itc->first << " d: " << itc->second << endl; 
  
    
  cout << endl << "TUBES: " << endl;
  
    for (auto it = mtubes.begin(); it != mtubes.end(); it++)
  cout << it->first << " = l:" << it->second.length << " d: " << it->second.diameter << endl; 
  
    cout << endl << "TUBEVECTORS: " << endl;
  
    for (auto it = mvector.begin(); it != mvector.end(); it++)
  {
    cout << it->first << ":";
    if (it->second.s.empty()) cout << " EMPTY" << endl;
    else 
    {
      cout << endl;
      while (!it->second.s.empty())
      {
        cout << "     l:" << it->second.s.top().length;
        cout << "     d:" << it->second.s.top().diameter << endl;
        it->second.s.pop();
      }
    }
  }
  cout <<"--------------"<<endl;
}


int main() 
{
  mcon.clear();
  mtubes.clear();
  mvector.clear();
  
    AST *root = NULL;
  ANTLR(plumber(&root), stdin);
  ASTPrint(root);
  execute(child(root,0));
  
    PrintMaps();
}

void
#ifdef __USE_PROTOS
plumber(AST**_root)
#else
plumber(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    while ( (setwd1[LA(1)]&0x1) ) {
      ops(zzSTR); zzlink(_root, &_sibling, &_tail);
      zzLOOP(zztasp2);
    }
    zzEXIT(zztasp2);
    }
  }
  (*_root)=createASTlist(_sibling);
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd1, 0x2);
  }
}

void
#ifdef __USE_PROTOS
ops(AST**_root)
#else
ops(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==ID) ) {
      asigop(zzSTR); zzlink(_root, &_sibling, &_tail);
    }
    else {
      if ( (LA(1)==PAR1) ) {
        splitop(zzSTR); zzlink(_root, &_sibling, &_tail);
      }
      else {
        if ( (LA(1)==LENGTH) ) {
          lengexp(zzSTR); zzlink(_root, &_sibling, &_tail);
        }
        else {
          if ( (LA(1)==DIAMETER) ) {
            diamexp(zzSTR); zzlink(_root, &_sibling, &_tail);
          }
          else {
            if ( (LA(1)==WHILE) ) {
              whilexp(zzSTR); zzlink(_root, &_sibling, &_tail);
            }
            else {
              if ( (setwd1[LA(1)]&0x4) ) {
                pushpopexp(zzSTR); zzlink(_root, &_sibling, &_tail);
              }
              else {zzFAIL(1,zzerr1,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
            }
          }
        }
      }
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd1, 0x8);
  }
}

void
#ifdef __USE_PROTOS
asigop(AST**_root)
#else
asigop(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  leftop(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzmatch(EQUAL); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  asigexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd1, 0x10);
  }
}

void
#ifdef __USE_PROTOS
leftop(AST**_root)
#else
leftop(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd1, 0x20);
  }
}

void
#ifdef __USE_PROTOS
asigexpr(AST**_root)
#else
asigexpr(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==TUBE) ) {
      zzmatch(TUBE); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
      aritexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
      aritexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
    }
    else {
      if ( (LA(1)==TUBEVECTOR) ) {
        zzmatch(TUBEVECTOR); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
        zzmatch(OF);  zzCONSUME;
        aritexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
      }
      else {
        if ( (LA(1)==CONNECTOR) ) {
          zzmatch(CONNECTOR); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
          aritexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
        }
        else {
          if ( (LA(1)==MERGE) ) {
            mergexp(zzSTR); zzlink(_root, &_sibling, &_tail);
          }
          else {
            if ( (LA(1)==ID) ) {
              zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
            }
            else {zzFAIL(1,zzerr2,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
          }
        }
      }
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd1, 0x40);
  }
}

void
#ifdef __USE_PROTOS
aritexpr(AST**_root)
#else
aritexpr(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  term(zzSTR); zzlink(_root, &_sibling, &_tail);
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    while ( (setwd1[LA(1)]&0x80) ) {
      {
        zzBLOCK(zztasp3);
        zzMake0;
        {
        if ( (LA(1)==PLUS) ) {
          zzmatch(PLUS); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
        }
        else {
          if ( (LA(1)==MINUS) ) {
            zzmatch(MINUS); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
          }
          else {zzFAIL(1,zzerr3,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
        }
        zzEXIT(zztasp3);
        }
      }
      term(zzSTR); zzlink(_root, &_sibling, &_tail);
      zzLOOP(zztasp2);
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x1);
  }
}

void
#ifdef __USE_PROTOS
term(AST**_root)
#else
term(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  atom(zzSTR); zzlink(_root, &_sibling, &_tail);
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    while ( (setwd2[LA(1)]&0x2) ) {
      {
        zzBLOCK(zztasp3);
        zzMake0;
        {
        if ( (LA(1)==MUL) ) {
          zzmatch(MUL); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
        }
        else {
          if ( (LA(1)==DIV) ) {
            zzmatch(DIV); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
          }
          else {zzFAIL(1,zzerr4,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
        }
        zzEXIT(zztasp3);
        }
      }
      atom(zzSTR); zzlink(_root, &_sibling, &_tail);
      zzLOOP(zztasp2);
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x4);
  }
}

void
#ifdef __USE_PROTOS
atom(AST**_root)
#else
atom(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  if ( (LA(1)==DIGIT) ) {
    zzmatch(DIGIT); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  }
  else {
    if ( (LA(1)==LENGTH) ) {
      lengexp(zzSTR); zzlink(_root, &_sibling, &_tail);
    }
    else {
      if ( (LA(1)==DIAMETER) ) {
        diamexp(zzSTR); zzlink(_root, &_sibling, &_tail);
      }
      else {zzFAIL(1,zzerr5,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x8);
  }
}

void
#ifdef __USE_PROTOS
mergexp(AST**_root)
#else
mergexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(MERGE); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==ID) ) {
      zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
    }
    else {
      if ( (LA(1)==MERGE) ) {
        mergexp(zzSTR); zzlink(_root, &_sibling, &_tail);
      }
      else {zzFAIL(1,zzerr6,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
    }
    zzEXIT(zztasp2);
    }
  }
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==ID) ) {
      zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
    }
    else {
      if ( (LA(1)==MERGE) ) {
        mergexp(zzSTR); zzlink(_root, &_sibling, &_tail);
      }
      else {zzFAIL(1,zzerr7,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x10);
  }
}

void
#ifdef __USE_PROTOS
pushpopexp(AST**_root)
#else
pushpopexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==PUSH) ) {
      zzmatch(PUSH); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
    }
    else {
      if ( (LA(1)==POP) ) {
        zzmatch(POP); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
      }
      else {zzFAIL(1,zzerr8,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
    }
    zzEXIT(zztasp2);
    }
  }
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x20);
  }
}

void
#ifdef __USE_PROTOS
splitop(AST**_root)
#else
splitop(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  parID(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzmatch(EQUAL); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  splitexpr(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x40);
  }
}

void
#ifdef __USE_PROTOS
parID(AST**_root)
#else
parID(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(PAR1);  zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(COMA);  zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(PAR2);  zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd2, 0x80);
  }
}

void
#ifdef __USE_PROTOS
splitexpr(AST**_root)
#else
splitexpr(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(SPLIT); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x1);
  }
}

void
#ifdef __USE_PROTOS
lengexp(AST**_root)
#else
lengexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(LENGTH); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  pardim(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x2);
  }
}

void
#ifdef __USE_PROTOS
diamexp(AST**_root)
#else
diamexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(DIAMETER); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  pardim(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x4);
  }
}

void
#ifdef __USE_PROTOS
pardim(AST**_root)
#else
pardim(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(PAR1);  zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(PAR2);  zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x8);
  }
}

void
#ifdef __USE_PROTOS
whilexp(AST**_root)
#else
whilexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(WHILE); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
  whilepar(zzSTR); zzlink(_root, &_sibling, &_tail);
  plumber(zzSTR); zzlink(_root, &_sibling, &_tail);
  zzmatch(ENDWHILE);  zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x10);
  }
}

void
#ifdef __USE_PROTOS
whilepar(AST**_root)
#else
whilepar(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  zzmatch(PAR1);  zzCONSUME;
  boolexp(zzSTR); zzlink(_root, &_sibling, &_tail);
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    while ( (LA(1)==OR) ) {
      zzmatch(OR); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
      boolexp(zzSTR); zzlink(_root, &_sibling, &_tail);
      zzLOOP(zztasp2);
    }
    zzEXIT(zztasp2);
    }
  }
  zzmatch(PAR2);  zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x20);
  }
}

void
#ifdef __USE_PROTOS
boolexp(AST**_root)
#else
boolexp(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  boolexp2(zzSTR); zzlink(_root, &_sibling, &_tail);
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    while ( (LA(1)==AND) ) {
      zzmatch(AND); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
      boolexp2(zzSTR); zzlink(_root, &_sibling, &_tail);
      zzLOOP(zztasp2);
    }
    zzEXIT(zztasp2);
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd3, 0x40);
  }
}

void
#ifdef __USE_PROTOS
boolexp2(AST**_root)
#else
boolexp2(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  if ( (LA(1)==NOT) ) {
    zzmatch(NOT); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
    fullemptyvec(zzSTR); zzlink(_root, &_sibling, &_tail);
  }
  else {
    if ( (setwd3[LA(1)]&0x80) ) {
      fullemptyvec(zzSTR); zzlink(_root, &_sibling, &_tail);
    }
    else {
      if ( (setwd4[LA(1)]&0x1) ) {
        {
          zzBLOCK(zztasp2);
          zzMake0;
          {
          if ( (LA(1)==LENGTH) ) {
            lengexp(zzSTR); zzlink(_root, &_sibling, &_tail);
          }
          else {
            if ( (LA(1)==DIAMETER) ) {
              diamexp(zzSTR); zzlink(_root, &_sibling, &_tail);
            }
            else {zzFAIL(1,zzerr9,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
          }
          zzEXIT(zztasp2);
          }
        }
        {
          zzBLOCK(zztasp2);
          zzMake0;
          {
          {
            zzBLOCK(zztasp3);
            zzMake0;
            {
            if ( (LA(1)==BOOLEQ) ) {
              zzmatch(BOOLEQ); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
            }
            else {
              if ( (LA(1)==BOOLESS) ) {
                zzmatch(BOOLESS); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
              }
              else {
                if ( (LA(1)==BOOLGREAT) ) {
                  zzmatch(BOOLGREAT); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
                }
                else {
                  if ( (LA(1)==BOOLESSEQ) ) {
                    zzmatch(BOOLESSEQ); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
                  }
                  else {
                    if ( (LA(1)==BOOLGREATEQ) ) {
                      zzmatch(BOOLGREATEQ); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
                    }
                    else {zzFAIL(1,zzerr10,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
                  }
                }
              }
            }
            zzEXIT(zztasp3);
            }
          }
          zzmatch(DIGIT); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
          zzEXIT(zztasp2);
          }
        }
      }
      else {
        if ( (LA(1)==PAR1) ) {
          zzmatch(PAR1);  zzCONSUME;
          boolexp(zzSTR); zzlink(_root, &_sibling, &_tail);
          {
            zzBLOCK(zztasp2);
            zzMake0;
            {
            while ( (LA(1)==OR) ) {
              zzmatch(OR); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
              boolexp(zzSTR); zzlink(_root, &_sibling, &_tail);
              zzLOOP(zztasp2);
            }
            zzEXIT(zztasp2);
            }
          }
          zzmatch(PAR2);  zzCONSUME;
        }
        else {zzFAIL(1,zzerr11,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
      }
    }
  }
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd4, 0x2);
  }
}

void
#ifdef __USE_PROTOS
fullemptyvec(AST**_root)
#else
fullemptyvec(_root)
AST **_root;
#endif
{
  zzRULE;
  zzBLOCK(zztasp1);
  zzMake0;
  {
  {
    zzBLOCK(zztasp2);
    zzMake0;
    {
    if ( (LA(1)==FULL) ) {
      zzmatch(FULL); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
    }
    else {
      if ( (LA(1)==EMPTY) ) {
        zzmatch(EMPTY); zzsubroot(_root, &_sibling, &_tail); zzCONSUME;
      }
      else {zzFAIL(1,zzerr12,&zzMissSet,&zzMissText,&zzBadTok,&zzBadText,&zzErrk); goto fail;}
    }
    zzEXIT(zztasp2);
    }
  }
  zzmatch(PAR1);  zzCONSUME;
  zzmatch(ID); zzsubchild(_root, &_sibling, &_tail); zzCONSUME;
  zzmatch(PAR2);  zzCONSUME;
  zzEXIT(zztasp1);
  return;
fail:
  zzEXIT(zztasp1);
  zzsyn(zzMissText, zzBadTok, (ANTLRChar *)"", zzMissSet, zzMissTok, zzErrk, zzBadText);
  zzresynch(setwd4, 0x4);
  }
}
