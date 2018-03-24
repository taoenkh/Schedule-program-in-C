
#include <stdio.h>
#include<string.h>
struct class{
    char name[15];
    char quarter[15];
    char preq[5][15];
    int preqn;


};

void setNone(char*x[],int size){
    int i = 0;
    for (;i<size;i++){
        x[i] = "None";
    }
}

struct schedule{
    char name[15];
    int year;
    char quarter[2];
};

int find(char num [], char arr[][20],int size){
    int result = 0;
    int i = 0;
    for (;i<size;i++){
        if (!strcmp(arr[i],num)){
            result = 1;
            break;
        }
    }
    return result;
}
int finds(char num [], struct schedule arr[],int size){
    int result = 0;
    int i = 0;
    for (;i<size;i++){
        if (!strcmp(arr[i].name,num)){
            result = 1;
            break;
        }
    }
    return result;
}


void strcsetnull(struct schedule x[], int size){
    int i = 0;
    for (;i<size;i++){
        strcpy(x[i].name, "None");
    }

}
void insertn(char y[],char *x[],int size){
    if(size == 0){
        x[0] = y;
    }
    int i = 0;
    for (;i<size;i++){
        if (!strcmp(x[i] ,"None")){
            x[i] = y;
            break;
        }

    }
}


int main(int argc,char*argv[]) {

    FILE* file;
    FILE* f2;
    FILE* f3;
    char*cname = argv[1];
    char*pname = argv[2];
    char *rname = argv[3];
    struct schedule sd[20];
    struct class aclass[100];
    int z = 0;
    for (; z < 20; z++) {

        aclass[z].preqn = 0;
        int x = 0;
        for ( ; x < 5; x++)
            strcpy(aclass[z].preq[x], "None1");
    }
    char line [200];

    char input[100];
    file = fopen(cname, "r");

    char*n;
    int num = 0;
    while (fgets(line,100,file)!= NULL){
        char tempc[30][30];
        int index = 0;
        n = strtok(line, " \n");
        while (n!=NULL) {
            strcpy(tempc[index],n);
            n = strtok(NULL, " \n");
            index++;
        }
        //printf("%s temp1\n",tempc[1]);
        strcpy(aclass[num].name,tempc[0]);
        strcpy(aclass[num].quarter,tempc[1]);

        num++;
    }
//    for (int i = 0;i<num;i++){
//        printf("%s  %s\n",aclass[i].name,aclass[i].quarter);
//    }
    char withpreq[15][20];

    f2 = fopen(pname,"r");
    int num1 = 0;
    char* cls;
    char* prereq;
    // printf("%s\n","here");
    while (fgets(line,1000,f2)!= NULL){
        //   printf("%s\n","here1");
        char temp[30][30];
        // printf("%s\n","here2");
        int index =0;
        prereq = strtok(line," \n");
        while (prereq!= NULL){
            strcpy(temp[index],prereq);
            prereq = strtok(NULL," \n");
            index++;

        }

        strcpy(withpreq[num1],temp[0]);
        int j = 0;
        for (;j<num;j++){

            if (!strcmp(aclass[j].name,temp[0])){
                aclass[j].preqn = index-1;
                int i = 0;
                for (;i<index-1;i++){
                    strcpy(aclass[j].preq[i],temp[i+1]);


                }
            }
        }
        num1++;

    }
    char*d[15];
    int i= 0;
    for (; i<num1;i++){
        d[i] = withpreq[i];
    }

//    for (int i = 0; i<num1;i++){
//        printf("%s l\n",withpreq[i]);
//    }

    char requirement[num][15];

    //scanf("%s",rname);
    f3 = fopen(rname,"r");
    int num2 = 0;
    char *n1;
    char totake[20][20];
    int cc = 0;
    for (;cc < 20; cc++)
        strcpy(totake[cc],"None");
    while (fscanf(f3, "%s", totake[num2]) != EOF)
        num2++;
    char *req2[num2];
    int i1= 0;
    for ( ;i1<num2;i1++){
        req2[i1] = requirement[i1];
    }

//    for (int i = 0;i<num;i++){
//        printf("req = %s\n",aclass[i].name);
//    }

    int numtotake = 0;







    int cmpcount = 0;
//    printf("%d\n", strcmp(class_to_take[numtotake], "empty"));
    while (strcmp(totake[numtotake], "None") != 0){
        int ja = 0;
        for(; ja < num; ja++) {
            if (!strcmp(aclass[ja].name, totake[numtotake]) ){
                int na = 0;
                for(; na < 5; na++) {
                    int n2 = 0;
                    for (; n2 < 20; n2++) {
                        if((strcmp(aclass[ja].preq[na], totake[n2])!= 0  && strcmp(totake[n2],"None")!=0  && strcmp(aclass[ja].preq[na], "None1")!=0 )){
                            cmpcount++;
                        }
                    }

                    if (cmpcount == num2){
                        strcpy(totake[num2], aclass[ja].preq[na]);
                        num2++;
                    }
                    cmpcount = 0;

                }
            }
        }
        numtotake++;

    }
    int sameq = 0;
    int year = 1;
    struct schedule taken[20];
    strcsetnull(taken,20);
    char*totake1[numtotake];
    setNone(totake1,numtotake);
    int sizet = 0;
    int counter = 0;
    char tempar[20][20];

    int countimg = 0;
    while(sizet!=numtotake&& year <10) {
        //printf("%d %d\n",sizet,numtotake);
       // printf("ddsada\n");
        int q = 1;
        for (; q < 4; q++) {
            int crs = 0;

            for (;crs<num;crs++){

                if (find(aclass[crs].name,totake,numtotake) !=0){
                    int tp = 0;
                    int j = 0;
                    for (;j<aclass[crs].preqn;j++){
                        int x = 0;
                        for (; x<sizet;x++){
                           // printf("%d  %d\n",sizet,numtotake);
                            if (!strcmp(aclass[crs].preq[j],taken[x].name)){
                                tp++;
                            }
                        }
                    }
                    //printf("tp %d  preq%d %s \n",tp,aclass[i].preqn,aclass[i].name);
                    if ((tp == aclass[crs].preqn) && ((aclass[crs].quarter[0]-'0')==q )){
                        if (finds(aclass[crs].name,taken,sizet) == 0){
                            //Handling the for loop taking both preq and the course
                            int nx = 0;
                            for (; nx < 5; nx++) {
                                int n2 = 0;
                                for (; n2 < 5; n2++) {
                                    if (!strcmp(aclass[crs].preq[nx], tempar[n2])) {
                                        //printf("%s %s \n", aclass[crs].preq[nx], tempar[n2]);
                                        sameq = 1;
                                    }
                                }
                            }

                            if (sameq == 0) {
                                strcpy(taken[sizet].name, aclass[crs].name);
                                //printf("name and namd %s %s \n",taken[sizet].name,aclass[i].name);
                                strcpy(taken[sizet].quarter, aclass[crs].quarter);
                                strcpy(tempar[countimg],aclass[crs].name);
                                taken[sizet].year = year;
                                insertn(taken[sizet].name, totake1, sizet);
                                countimg++;
                                sizet++;
                            }
                            sameq = 0;
                            //printf("%dsize,%snm  \n",i,aclass[i].name);



                        }


                    }
                }
            }
            countimg = 0;
            int ti = 0;
            for (;ti<20;ti++){
                strcpy(tempar[ti],"None");
            }


        }
        year++;

    }
    int prt = 1;
    for (;prt<year;prt++){
        int pq = 0;
        for(;pq<4;pq++){
            int prted = 0;
            int p = 0;
            for (;p < sizet;p++) {
                if ((taken[p].year == prt) && (taken[p].quarter[0] - '0' == pq)) {
                    if (prted ==0 ) {
                        printf("%d %d ", prt, pq);
                    }
                    printf("%s ", taken[p].name);
                    prted = 1;
                }
            }if (prted == 1)
                printf("\n");



        }

    }

}
