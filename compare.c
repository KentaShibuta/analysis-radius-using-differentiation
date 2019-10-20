# include<stdio.h>
# include<math.h>
int main(void){
   int nnode = 1001;
   double data[nnode][2];
   // 楕円曲線上の座標をファイルから読み込み，各座標における曲率を算出する
   FILE *fp;
   char file_name[100] = "楕円_a_1_b_3_0_01刻み_2.csv";

   printf(">>> read the %s\n", file_name);
    if((fp = fopen(file_name, "r")) == NULL) {
        perror("can't open file");
        return -1;
   }

   int i;

   for(i=0; i<nnode; i++){
      fscanf(fp, "%lf,%lf", &data[i][0], &data[i][1]);
   }

   fclose(fp);

   //double df, ddf, rho;
   double df, ddf;
   double rho[nnode];
   //double a, b, x;
   double a, b;
   a = 1.0;
   b = 3.0;
   //printf("x = ");
   //scanf("%lf", &x);
   for(i=0; i<nnode; i++){
      printf("y = %f\n", 3 * sqrt(1.0 - data[i][0] * data[i][0]));
      df = (b * data[i][0]) / (1.0 * a * sqrt(a * a - data[i][0] * data[i][0]));
      ddf = (b / (a * sqrt(a * a - data[i][0] * data[i][0]))) * (1.0 + ((data[i][0] * data[i][0]) / (a * a - data[i][0] * data[i][0])));
      rho[i] = (sqrt(fabs(1.0 + df * df))*(fabs(1.0 + df * df))) / fabs(1.0 * ddf);
   }

   //printf("a = %f, b = %f\n", a, b);
   //printf("x = %f\n", data[i][0]);
   //printf("radius = %23.15e\n", 1.0/rho);
   
   for(i=0; i<nnode; i++){
      printf("%d , x = % 23.15e, radius = %23.15e\n",i, data[i][0], 1.0/rho[i]);
   }

   // ファイルに書き出す

   printf("file name >>>\n");
   scanf("%s", file_name);
   sprintf(file_name, "%s.csv", file_name);
   if((fp = fopen(file_name, "w")) == NULL) {
      perror("can't open file");
      return -1;
   }

   for(i=0; i<nnode; i++){
      printf("%d , x = % 23.15e, radius = %23.15e\n",i, data[i][0], 1.0/rho[i]);
   }
   fprintf(fp, "nnode, x, y, radius\n");
   for(i=0; i<nnode; i++){
      fprintf(fp, "%d, %23,15e, %23,15e, %23,15e\n", i, data[i][0], data[i][1], 1.0/rho[i]);
   }
   fclose(fp);
   return 0;
}
