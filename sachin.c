//
//  sachin.c
//  reliability
//
//  Created by Letian Chen on 05/03/2024.
//

#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <stdlib.h>

#ifndef epsilon
#define epsilon (0.1)
#endif

#ifndef w
#define w (0.1)
#endif

#ifndef count
#define count (10000)
#endif

#ifndef K
#define K (0.3)
#endif

#ifndef r0
#define r0 (10.)
#endif

//#ifndef SEED
//#define SEED (wcore*1000UL)
//#endif

double rand_uniform() {
    return rand() / (RAND_MAX + 1.0);
}

double rand_normal() {
    double u = rand_uniform();
    double v = rand_uniform();
    return sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
}



int main() {
    int i;
    double T,x,reset_jump;
    srand(103); // 初始化随机数生成器
    double x_0 = 0.;
    double dt = 0.0001;
    double dx =0.;
    double D = 0.5;
    double k = pow((K), 2) * D * 2;
    printf("%f \n",k);
    double mfpt = 0.;
    
    for(double r =0.;r<r0;r+=0.1)
    {
        mfpt = 0.;
        reset_jump = r*dt;
        for (i = 0; i < count; i++) {
            T = 0.;
            x = x_0;
            while (x < 0.5) {
                if (rand_uniform() < reset_jump) { // r*dt
                    x = x_0;
                } else {
                    dx = (-k + epsilon * sin(w * T)) * x * dt + sqrt(2 * D * dt) *gsl_rng_uniform(rng);
                    x += dx;
                }
                T += dt;
            }
            // mfpt += T / count;
            mfpt += T;
        }
        mfpt = mfpt / count;
        printf("%f %f %f %f %f %d\n", r, mfpt);
        fflush(stdout);
    }
    return 0;
}
















//int main() {
//    int i;
//    double T,x,reset_jump;
////    rng = gsl_rng_alloc(gsl_rng_taus);
////    gsl_rng_set(rng, SEED);
//    srand(103); // 初始化随机数生成器
//    double x_0 = 0.5;
////    double r = 10.;
//    double dt = 0.0001;
//    double dx =0.;
////    double w = 0;
//    double D = 0.5;
////    double K = 0.7393;
////    double count=10000;
//    double k = pow((K / x_0), 2) * D * 2;
//    printf("%f \n",k);
////    double epsilon = 0.1;
//    double mfpt = 0;
//    for(double r =0.;r<r0;r+=0.5)
//    {
//        mfpt = 0;
//        reset_jump = r*dt;
//        for (i = 0; i < count; i++) {
//            T = 0.;
//            x = x_0;
//            while (x > 0) {
//                if (rand_uniform() < reset_jump) { // 这里是对应于 r*dt，但因为r=0，所以这个条件永远为假
//                    x = x_0;
//                } else {
//                    dx = (-k - epsilon * cos(w * T)) * x * dt + sqrt(2 * D * dt) * rand_normal();
//                    //                dx = (-k + epsilon * sin(w * T)) * x * dt + sqrt(2 * D * dt) *gsl_rng_uniform(rng);
//                    x += dx;
//                }
//                T += dt;
//            }
//            // mfpt += T / count;
//            mfpt += T;
//        }
//        mfpt = mfpt / count;
//        printf("%f %f %f %f %f %d\n", r, mfpt, epsilon, w, K, count);
//        fflush(stdout); // 强制刷新输出缓冲区
//    }
//    return 0;
//}
