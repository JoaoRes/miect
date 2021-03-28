
int op=0;

int isValid(int array[], int size){
    int res;

    for(int i = 0; i< size-1;i++){
            op+=1;
            if(array[i+1]-array[i]==1){
                res = 1;            
            }else{
                res = 0;
                break;
            }
    }

    return res;
}


int main(void){
    int array[] ={1, 3, 4, 5, 5, 6, 7, 7, 8, 9};
    int x;
    for(int i = 0; i< 10; i++){
        x = isValid(array, 10);
        printf("%d %d %d", array[i], x, op);
    }

    
    return 0;
}