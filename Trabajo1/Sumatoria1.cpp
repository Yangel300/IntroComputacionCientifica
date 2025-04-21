#include <iostream>
#include <cmath>

typedef float Real;

Real sum1(int k);
Real sum2(int k);
Real sum3(int k);
Real error(Real term1, Real term2);


int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 25000; k++) {
        std::cout << k << "\t" << sum1(2*k-1) << "\t"<< sum2(k) << "\t" <<sum3(k)<<"\t"<<error(sum1(2*k-1),sum3(k))<<"\t"<< error(sum2(k),sum3(k))<<"\n";
    }

    return 0;
}


Real sum1(int k){
    Real suma=0.0;
    for (int i=1;i<k;i++){
        Real term4=pow(-1,i)*(i/(i+1.0));
        suma+=term4;
    }
    return suma;    
}

Real sum2(int k){
    Real suma=0.0;
    for (int i=1;i<k;i++){
        Real term1=2.0*i/(2.0*i+1.0);
        Real term2=(2.0*i-1.0)/(2.0*i);
        suma=suma+term1-term2;
    }
    return suma;
}

Real sum3(int k){
    Real suma=0.0;
    for (int i=1;i<k;i++){
        Real term=1.0/(2*i*(2*i+1.0));
        suma+=term;
    }
    return suma;
}

Real error(Real term1, Real term2){
    Real error=fabs((term1-term2)/term2);
    return error;
}
