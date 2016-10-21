/* yeah it generates fizzbuzz */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
  int length;
  if(argc > 1){
    length = atoi(argv[1]);
  }else{
    length = 100;
  }
  FILE *out = fopen("fizzbuzz.c","w");
  fprintf(out,"#include<stdio.h>\n\nint main(void){\n\tfor(int i = 0;i<%d;i++){\n\tif(i%%15 == 0)\n\t\tprintf(\"fizzbuzz\\n\");\n\telse if(i%%5 == 0)\n\t\tprintf(\"fizz\\n\");\n\telse if(i%%3 == 0)\n\t\tprintf(\"buzz\\n\");\n\telse\n\t\tprintf(\"%%d\\n\",i);\n\t}\n\treturn 0;\n}",length);
  fclose(out);
  system("cc fizzbuzz.c -o fizzbuzz");
  system("./fizzbuzz");
  return 0;
}
