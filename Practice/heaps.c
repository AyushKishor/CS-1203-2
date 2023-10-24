
void swap(int *xp,int *yp){
    int temp = xp;
    xp = yp;
    yp = temp;
}


int main(){
    int x = 5;
    int y = 10;
    swap(&x,&y);
    printf("%d\n",x);
    printf("%d\n",y);
    return 0;
}