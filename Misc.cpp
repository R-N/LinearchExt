
#ifndef LINEARCHEXT_MISC_CPP
#define LINEARCHEXT_MISC_CPP

#include <cmath>
#include <stdexcept>

#include "Misc.hpp"

namespace LinearchExt{

 double Min(double a, double b){
    if (a<b)
        return a;
    return b;
}
 double Max(double a, double b){
    if (a>b)
        return a;
    return b;
}

double Abs(double x){
    return x < 0 ? -x : x;
}

double Lerp(double a, double b, double t){
    return a + (b-a) * t;
}
double MoveTowards(double a, double b, double maxDelta){
    if (b==a)
        return a;
    double absDelta = Abs(b-a);
    return a + (b-a)/absDelta * Min(maxDelta, absDelta);
}



template <typename B, typename D> bool TestDerivation(){
    try {
        DerivationTester<B, D> t;
    }catch(std::exception x){
        return false;
    }
    return true;
}


}
#endif //MAIN_CPP
