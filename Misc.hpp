
#ifndef LINEARCHEXT_MISC_HPP
#define LINEARCHEXT_MISC_HPP
#include <cmath>

namespace LinearchExt{

static double deg2Rad = 0.5 / M_PI;
static double rad2Deg = 2 * M_PI;

 double Min(double, double);
 double Max(double, double);

double Abs(double);

double Lerp(double, double, double);
double MoveTowards(double, double, double);



template <typename B, typename D> class DerivationTester{
    B b;
    D d;
public :
    DerivationTester(){
        (void)static_cast<B*>((D*)0);

    }
};

template <typename B, typename D> bool TestDerivation();
}
#endif
