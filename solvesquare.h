#ifndef SOLVESQUARE_H
#define SOLVESQUARE_H

enum {
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    SS_INF_NROOTS = 8,
};

int solveSquare(double, double, double, double*, double*);

#endif // SOLVESQUARE_H
