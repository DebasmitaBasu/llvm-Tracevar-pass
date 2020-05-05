#include<stdio.h>
#include<stdlib.h>

	int main()
	{
		int *a;
                
                int i,c;

                struct SS{
                 int ID;
                 int age;
                };
                
                struct SS *b;
                
                a = (int*)malloc(10*sizeof(int));

                //if (a == 0){
		//	printf("Error in malloc allocating space\n");
		//	return 1;
		//}

                //a[4]=100;
                // Get the elements of the array 
                //for (i = 0; i < 10; ++i)
                     
                a[5] = a[4] + 1;    //a-load,store
                           
  
                // Print the elements of the array 
                // for (i = 0; i < 10; ++i)
                //    printf("%d, ", a[i]); 
       

                //b = (struct SS *)malloc(sizeof(struct SS));
                
                b = (struct SS *)malloc(sizeof(struct SS));
                //b->ID=112682239;
                
                c = b->ID; // b is loaded here
 
                //free(a);
                //free(b);

		return 0;
	}
