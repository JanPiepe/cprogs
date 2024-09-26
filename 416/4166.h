#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef jfp
#define jfp

typedef struct JFP_Calculator
{
    char _eingabe[1024];
    char _oper;
    float _zahl1;
    float _zahl2;
    float _output;
} jfp_calc;

void jfp_c_divideEingabe(jfp_calc* jfp_c);
bool jfp_c_isOper( jfp_calc* jfp_c, char oper);
void jfp_c_setOper(jfp_calc* jfp_c, char oper);

void jfp_c_addieren(jfp_calc* jfp_c)       {jfp_c->_output = jfp_c->_zahl1 + jfp_c->_zahl2;};
void jfp_c_subtrahieren(jfp_calc* jfp_c)   {jfp_c->_output = jfp_c->_zahl1 - jfp_c->_zahl2;};
void jfp_c_multiplizieren(jfp_calc* jfp_c) {jfp_c->_output = jfp_c->_zahl1 * jfp_c->_zahl2;};
void jfp_c_dividieren(jfp_calc* jfp_c)     {jfp_c->_output = jfp_c->_zahl1 / jfp_c->_zahl2;};


void jfp_c_setEingabe(jfp_calc* jfp_c, char eingabe[1024]) {strncpy(jfp_c->_eingabe, eingabe, 1024);}; // TODO:JFP Testen!!!

float jfp_c_getZahl1(jfp_calc* jfp_c)   {return jfp_c->_zahl1;};
float jfp_c_getZahl2(jfp_calc* jfp_c)   {return jfp_c->_zahl2;};
float jfp_c_getOutput (jfp_calc* jfp_c) {return jfp_c->_output;};
char  jfp_c_getOper (jfp_calc* jfp_c)   {return jfp_c->_oper;};

void  jfp_c_setZahl1(jfp_calc* jfp_c, float z1) {jfp_c->_zahl1 = z1;};
void  jfp_c_setZahl2(jfp_calc* jfp_c, float z1) {jfp_c->_zahl1 = z1;};
#endif //jfp
