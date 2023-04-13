#ifndef MATH
#define MATH

#ifndef MAXTAM
#define MAXTAM 5
#endif

typedef struct mat{
	double m[MAXTAM][MAXTAM];
	int tamx, tamy;
	int id;
} mat_tipo;

#endif