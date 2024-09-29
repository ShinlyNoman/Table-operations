#include <stdio.h>
int *table,length=0;
int i,sum,num1,num2;
float avg;

/*insert function*/
void insert(){
    int num;
    printf("Insert Value:");
    scanf("%d",&num);
    length++;
    if ((table=(int*)realloc(table,length*sizeof(int)))==0){
         printf("ERROR");
    }
    table[length-1]=num;
}

/*print all elements*/
void display(){
    int i;
    for(i=0;i<length;i++){
        printf(" %d\n",table[i]);
    }
}

/*sum function*/
float findsum(){
    int i;
    float sum=0.0;
    for (i=0;i<length;i++){
        sum+= table[i];
    }
    return(sum);
}

// get avg

float findavg(){
    for(i=0; i<length; i++){
        sum+= table[i];
    }
    avg = sum/length;
    return avg;
}

/*find integer*/
int findnum(int num){
    int i;
    for(i=0;i<length;i++){
        if(table[i]==num){
            return(i);
        }
    }
    return(-1);
}

/*find max number*/
int findmax(){
    int i,max=table[0];
    for(i=1;i<length;i++){
        if (table[i]>max){
            max=table[i];
        }
    }
    return(max);
}

/*find min number*/
int findmin(){
    int i, min = table[0];
    for(i=1;i<length;i++){
        if (table[i]<min){
            min=table[i];
        }
    }
    return(min);
}


/*sorting*/
void sort_function(){
    int *sort[length],*tmp,j,i;

    for(i=0;i<length;i++){
        sort[i]=&table[i];
    }
    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if(*sort[j]<*sort[i]){
                tmp=sort[i];
                sort[i]=sort[j];
                sort[j]=tmp;
            }
        }
    }
    for(i=0;i<length;i++){
        printf("%d : %d\n",i+1,*sort[i]);
    }
}

/*delete number*/
int delete_num(int num){
    int x;
    x=findnum(num);
    if (x==-1){
        return(-1);
    }
    else{
        table[x]=table[length-1];
        length--;
        table=(int*)realloc(table,length*sizeof(int));
        return(1);
    }
}

//update
void swap(int num1,int num2){
    for(i=0; i<length; i++){
        if(table[i]==num1){
            table[i]= num2;
            printf("Value updated!!\n");
            display();
        }
    }
}

int main(){
     int out,y,num;
     do{
        printf("\n");
        printf(" 0: Exit\n");
        printf(" 1: Insert number\n");
        printf(" 2: Print table\n");
        printf(" 3: Sum of elements\n");
        printf(" 4: Find number\n");
        printf(" 5: Print max number\n");
        printf(" 6: Print min number\n");
        printf(" 7: Sort table\n");
        printf(" 8: Delete number\n");
        printf(" 9: Find average number\n");
        printf(" 10: Update number\n");
        printf(" Choose your option :  ");
        scanf("%d",&y);
        switch (y){
            case 1 :{
                printf("\nInsert Numbers to table\n");
                insert();
                break;
            }
            case 2 :{
                printf("Print Table\n\n");
                display();
                break;
            }
            case 3 :{
                out=findsum();
                printf(" Sum of all numbers is : %d\n",out);
                break;
            }
            case 4 :{
                printf(" Enter number ");
                scanf("%d",&num);
                printf(" The number is  : %d",num);
                out=findnum(num);
                if(out==-1){
                    printf(" Did not find it\n");
                }
                else{
                    printf(" The number is %d  at %d",num,out+1);
                }
                break;
            }
            case 5 :{
                out=findmax();
                printf(" Max number is : %d\n",out);
                break;
            }
            case 6 :{
                out=findmin(0,table);
                printf(" Min number is : %d\n",out);
                break;
            }
            case 7 :{
                printf(" Table sorted is \n");
                sort_function();
                break;
            }
            case 8 :{
                printf(" Enter number to delete : ");
                scanf("%d",&num);
                out=delete_num(num);
                if(out==1){
                    printf("\nNumber %d has been deleted.\n",num);
                }
                else{
                    printf("\nNumber %d doesn't exist.\n",num);
                }
                break;
            }
            case 9 :{
                findavg();
                printf("The average of the values: %.2f", avg);
                break;
            }
            case 10 :{
                printf("Enter the value you want to change: ");
                scanf("%d",&num1);
                printf("Enter the new value: ");
                scanf("%d",&num2);
                swap(num1,num2);
            }
        }
    }
    while(y!=0);
 /*system("pause")*/
    exit(0);
}

