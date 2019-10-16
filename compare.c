# include<stdio.h>
# include<math.h>
int main(void){
   double df, ddf, rho;
   double a, b, x;
   a = 1.0;
   b = 3.0;
   printf("x = ");
   scanf("%lf", &x);
   printf("y = %f\n", 3 * sqrt(1.0 - x * x));
   df = (b * x) / (1.0 * a * sqrt(a * a - x * x));
   //ddf = a / (1.0 * b * sqrt(a * a - x * x)*(a * a - x * x));
   ddf = (b / (a * sqrt(a * a - x * x))) * (1.0 + ((x * x) / (a * a - x * x)));
   rho = (sqrt(fabs(1.0 + df * df))*(fabs(1.0 + df * df))) / fabs(1.0 * ddf);

   printf("a = %f, b = %f\n", a, b);
   printf("x = %f\n", x);
   printf("radius = %23.15e\n", 1.0/rho);

   return 0;
}
