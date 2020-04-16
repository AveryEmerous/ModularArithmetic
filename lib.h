#ifndef H_LIB_H
#define H_LIB_H

int fillSet (int *& arr, int mod);

int printSet (int * arr, unsigned size);

int print2DSet (int ** arr, unsigned height, unsigned width);

int clrscr ();

int printOptions ();

int queryValue (int val);

int dec2bin (int num, bool *& bin, unsigned & size);

int fastPowerFirst(int base, int power, int mod);

int fastPowerSecond(int base, int power, int mod);

int addLeftoverRing (int mod);

int subLeftoverRing (int mod);

int multLeftoverRing (int mod);

int divLeftoverRing (int mod);

int fillSetWithRemOne (int **& arr, int mod);

bool checkPrime (int query);

bool checkField (int mod);

int inverseCalcFirst (int num, int mod);

bool primitiveRoot (int num, int mod);

int dlog (int base, int query, int mod);

#endif