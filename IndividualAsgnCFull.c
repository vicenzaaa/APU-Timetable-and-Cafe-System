#include <stdio.h>
#include <string.h>

typedef struct strtutor
{
    char tutor_id[4];
    char tutor_name[30];
    char tutor_title[30];
    char tutor_password[16];
};

typedef struct strsession
{
    char session_code[10];
    char session_title[50];
    char session_day[10];
    char session_starttime[8];
    char session_location[10];
    char session_tutorcode[4];
};

typedef struct strstudent
{
    char student_tpnumber[10];
    char student_name[50];
    char student_dob[30];
    char student_icnum[10];
    char student_address[20];
    char student_password[50];
};

typedef struct enrollstudent
{
    char studenttpnum[18];
    char sessioncode[10];
};


//HEADER
void encrypt(char s[]);
void decrypt (char s[]);
struct enrollstudent splitting_enroll(char str[100]);
struct strsession splitting_session(char str[100]);
struct strtutor splitting_tutor(char str[80]);
struct strstudent splitting_student (char str[100]);
void write_session(struct strsession session[], int n);
void write_enroll(struct enrollstudent enroll[], int ne);
void write_tutor(struct strtutor tutor[],int n);
void write_student(struct strstudent student[], int n);
void read_session (struct strsession session[], int *ns);
void read_enroll(struct enrollstudent enroll[], int *ne);
void read_tutor(struct strtutor tutor[], int *nt);
void read_student(struct strstudent student[], int *nst);
void show_enroll(struct enrollstudent enroll[], int ne);
void show_session (struct strsession session[], int ns);
void show_tutor(struct strtutor tutor[], int nt);
void show_student (struct strstudent student[], int nst);
void addtutor (struct strtutor tutor[],int *nt);
void addsession (struct strsession session[],int *ns,struct strtutor tutor[],int *nt);
void addstudent(struct strstudent student[], int *nst);
void enroll_student (struct strsession session[], int ns, struct strstudent student[],int nst,
                     struct strtutor tutor[], int nt, struct enrollstudent enroll[],int *ne);
void printrenroll(struct enrollstudent enroll[], int ne, struct strstudent student[], int nst,
                   struct strtutor tutor[],int nt, struct strsession session[], int ns);
void printlisttutor(struct strtutor tutor[],int nt, struct strsession session[], int ns);
void printstudentsession(struct enrollstudent enroll[], int ne, struct strtutor tutor[], int nt,
                         struct strsession session[], int ns, struct strstudent student[], int nst);
void enrollbystud(struct enrollstudent enroll[], int *ne, struct strstudent student[],int nst,
                  struct strtutor tutor[], int nt,struct strsession session[],int ns);
void existtablesession (struct strsession session[],int *ns);
void existtabletutor (struct strtutor tutor[],int *nt);
void update_student(struct strstudent student[], int nst, struct enrollstudent enroll[],int ne);
void update_tutor(struct strtutor tutor[], int nt,struct strsession session[], int ns);
void update_passwordTutor (struct strtutor tutor[], int nt);
void update_passwordStudent (struct strstudent student[], int nst);
void update_session(struct strsession session[],int ns,struct strtutor tutor[], int nt, struct enrollstudent enroll[], int ne);
void delete_student(struct strstudent student[], int *nst, struct enrollstudent enroll[], int *ne);
void delete_tutor(struct strtutor tutor[], int *nt, struct strsession session[], int *ns);
void delete_session(struct strsession session[], int *ns, struct enrollstudent enroll[], int *ne);

//MAIN

int main()
{
    int nextt=1;
    int homepage=-1;
    int user_type,feature1,feature2,feature3;
    struct strtutor tutor[10];
    struct strsession session[20];
    struct strstudent student[100];
    struct enrollstudent enroll[200];
    int ntutor=0;
    int nsession=0;
    int nstudent=0;
    int nenroll=0;
    int chupdate;
    int chdelete;
    read_tutor(tutor,&ntutor);
    read_student(student,&nstudent);
    read_session(session,&nsession);
    read_enroll(enroll,&nenroll);

    printf("Here are the informations that may be needed.\n\n");
    show_tutor(tutor,ntutor);
    printf("\n");
    show_student(student,nstudent);
    printf("\n");
    show_session(session,nsession);
    printf("\n");
    show_enroll(enroll,nenroll);
    printf("\n");

    while (homepage!=0){
        int cont=1;
        printf("\n");
        printf("    ------------------------------\n");
        printf("<<Homepage>>\n");
        printf("Welcome to Programming Cafe APU!\n");
        printf("Please select your role:\n");
        printf("1. Admin\n");
        printf("2. Tutor\n");
        printf("3. Student\n");
        printf("0. Exit Program\n");
        printf("Enter your role [1/2/3/0] = ");
        scanf("%d",&user_type);
        printf("\n");
        if (user_type==1){
            printf("You've logged in as an admin!\n");
            while(cont!=0){
                printf("1. Registration of Tutor\n");
                printf("2. Adding new programming cafe session\n");
                printf("3. Registration of student\n");
                printf("4. Enroll student in a session\n");
                printf("5. Listing of programming sessions and participating students\n");
                printf("6. Update Data\n");
                printf("7. Delete Data \n");
                printf("0. Back to home page\n");
                printf("Choose what you are going to do [1/2/3/4/5/6/7/0] = ");
                scanf("%d",&feature1);
                if (feature1==1){
                    addtutor(tutor,&ntutor);
                    write_tutor(tutor,ntutor);
                    nextt=1;
                }else if (feature1==2){
                    addsession(session,&nsession,tutor,&ntutor);
                    write_session(session,nsession);
                    nextt=1;
                }else if (feature1==3){
                    addstudent(student,&nstudent);
                    write_student(student,nstudent);
                    nextt=1;
                }else if (feature1==4){
                    enroll_student(session,nsession,student,nstudent,tutor,ntutor,enroll,&nenroll);
                    write_enroll(enroll,nenroll);
                    nextt=1;
                }else if (feature1==5){
                    //system("cls");
                    printrenroll(enroll, nenroll, student, nstudent, tutor, ntutor, session, nsession);
                    nextt=1;
                }else if (feature1==6){
                    printf("Which Data do you want to update?\n");
                    printf("1. Student\n");
                    printf("2. Tutor\n");
                    printf("3. Session\n");
                    //printf("4. Enrollment\n");
                    printf("[1/2/3] = ");
                    scanf("%d",&chupdate);
                    if (chupdate==1){
                        update_student(student,nstudent,enroll,nenroll);
                    }else if (chupdate==2){
                        update_tutor(tutor,ntutor,session,nsession);
                    }else if (chupdate==3){
                        update_session(session,nsession,tutor, ntutor,enroll, nenroll);
                    }else if (chupdate==4){
                        //update_enroll(enroll,&nenroll,student,&nstudent,session,&nsession);
                    }else if (chupdate<1 || chupdate >4){
                        printf("Invalid input.\n");
                    }
                }else if (feature1==7){
                    printf("Which data do you want to delete?\n");
                    printf("1. Student\n");
                    printf("2. Tutor\n");
                    printf("3. Session\n");
                    //printf("4. Enrollment\n");
                    printf("[1/2/3] = ");
                    scanf("%d",&chdelete);
                    if (chdelete==1){
                        delete_student(student,&nstudent,enroll,&nenroll);
                        //delete student
                    }else if (chdelete==2){
                        delete_tutor(tutor,&ntutor,session, &nsession);
                        //delete tutor
                    }else if (chdelete==3){
                        delete_session(session,&nsession,enroll,&nenroll);
                        //delete session
                    }else if (chdelete==4){
                        //
                    }else if (chdelete<1 || chdelete>4){
                        printf("Invalid input.\n");
                    }
                }else if (feature1==0){
                    homepage=1;
                    nextt=0;
                    cont=0;
                }
                if (nextt==1){
                    printf("Do you want to continue the program as an admin? [1.Yes / 0.No]=  ");
                    scanf("%d",&cont);
                    printf("\n");
                }
            }
            if (nextt==1){
                printf("\nDo you want to : \n");
                printf("1. Go back to home page\n");
                printf("0. Exit program\n");
                printf("[1/0] = ");
                scanf("%d",&homepage);
            }
        }else if (user_type==2){
            homepage=-1;
            int conttur=-1;
            while(conttur!=0){
                printf("1. List session that assigned to you\n");
                printf("2. Update your password\n");
                printf("0. Exit this function\n");
                printf("Choose what you are going to do [1/2/0] = ");
                scanf("%d",&feature2);
                if (feature2==1){
                    printlisttutor(tutor,ntutor,session,nsession);
                }else if (feature2==2){
                    update_passwordTutor(tutor,ntutor);
                }else if (feature2==0){
                    homepage=1;
                    conttur=0;

                }
                printf("Do you want to continue a program as tutor?\n");
                printf("1. Yes\n");
                printf("0. No\n");
                scanf("%d",&conttur);
            }
            printf("\nDo you want to : \n");
            printf("1. Go back to home page\n");
            printf("0. Exit program\n");
            printf("[1/0] = ");
            scanf("%d",&homepage);



        }else if (user_type==3){
                while (cont!=0){
                    printf("1. List session that has been enrolled to you\n");
                    printf("2. Enroll yourself to a session\n");
                    printf("3. Update your password\n");
                    printf("0. Back to homepage\n");
                    printf("Choose what you are going to do [1/2/3] = ");
                    scanf("%d",&feature3);
                    if (feature3==1){
                        printstudentsession(enroll,nenroll,tutor,ntutor,session,nsession,student,nstudent);
                        nextt = 1;
                    }else if (feature3==2){
                        enrollbystud(enroll,&nenroll,student,nstudent,tutor,ntutor,session,nsession);
                        nextt=1;
                    }else if (feature3==3){
                        update_passwordStudent(student,nstudent);
                    }else if (feature3==0){
                        homepage=1;
                        nextt=0;
                        cont=0;
                    }if (nextt==1){
                        printf("Do you want to continue the program as a student? [1.Yes / 0.No]=  ");
                        scanf("%d",&cont);
                        printf("\n");
                    }
                }if (nextt==1){
                    printf("\nDo you want to : \n");
                    printf("1. Go back to home page\n");
                    printf("0. Exit program\n");
                    printf("[1/0] = ");
                    scanf("%d",&homepage);
                }
        }else if (user_type==0){
            return 0;
        }
    }
}

//ALL FUNCTION


void encrypt(char s[])
{
    for (int i=0; i<strlen(s); i++){
        s[i]=s[i]-3; // encrypting here by substracting the value by 3
    }
}

void decrypt (char s[])
{
    int i;
    for (i=0; i<strlen(s); i++){
        s[i] = s[i]+3; //decrypting by adding back the 3
    }
}
struct enrollstudent splitting_enroll(char str[100])
{
    struct enrollstudent tempenroll;
    int position;
    const char s[2]=",";
    char *token;
    token = strtok(str,s);
    position = 1;
    while (token!=NULL){
        if (position==1){
            strcpy(tempenroll.studenttpnum,token);
            position++;
        }else if (position==2){
            token[strlen(token)-1]='\0';
            strcpy(tempenroll.sessioncode,token);
            position++;
            break;
        }
        token = strtok(NULL, s);
    }
    return tempenroll;
};
struct strsession splitting_session(char str[100])
{
    struct strsession tempsession;
    int position;
    const char s[5]=",";
    char *token;
    token = strtok(str,s);
    position = 1;
    while(token!=NULL){ //row is not empty
        if (position==1){
            strcpy(tempsession.session_code,token);
            position++;
        }else if (position==2){
            strcpy(tempsession.session_title,token);
            position++;
        }else if (position==3){
            strcpy(tempsession.session_day,token);
            position++;
        }else if (position==4){
            strcpy(tempsession.session_starttime,token);
            position++;
        }else if (position==5){
            strcpy(tempsession.session_location,token);
            position++;
        }else if (position==6){
            token[strlen(token)-1]='\0';
            strcpy(tempsession.session_tutorcode,token);
            position++;
            break;
        }
        token = strtok(NULL, s);
    }
    return tempsession;
};

struct strtutor splitting_tutor(char str[80])
{
    struct strtutor temptutor;
    int position;
    const char s[5] = ","; // constant char is comma (bcs we print every element of struct tutor with comma
    char* token;
    token = strtok(str, s);
    position = 1;
    while (token!=NULL){ // the row is not empty
        if (position==1){ // first comma
            strcpy(temptutor.tutor_id,token); // fill the temporary tutor id
            position++;
        }else if (position==2){ // second comma
            strcpy(temptutor.tutor_name,token); // fill the temporary tutor id
            position++;
        }else if (position==3){ // thrid comma
            strcpy(temptutor.tutor_title,token); // fill the temporary tutor id
            position++;
        }else if (position==4){ // fourth comma
            strcpy(temptutor.tutor_password,token); // fill the temporary tutor id
            position++;
            break;
        }
        token = strtok(NULL, s);

    }

    return temptutor;

};
struct strstudent splitting_student (char str[100])
{
    struct strstudent tempstudent;
    int position;
    const char s[7] = ","; // constant char is comma (bcs we print every element of struct tutor with comma
    char* token;
    token = strtok(str, s);
    position = 1;
    while (token!=NULL){ // the row is not empty
        if (position==1){ // first comma
            strcpy(tempstudent.student_tpnumber,token); // fill the temporary student id
            position++;
        }else if (position==2){ // second comma
            strcpy(tempstudent.student_name,token);
            position++;
        }else if (position==3){ // thrid comma
            strcpy(tempstudent.student_dob,token);
            position++;
        }else if (position==4){ // fourth comma
            strcpy(tempstudent.student_icnum,token);
            position++;
        }else if (position==5){ // fifth comma
            strcpy(tempstudent.student_address,token);
            position++;
        }else if (position==6){ // sixth comma
            token[strlen(token)-1]='\0';
            strcpy(tempstudent.student_password,token);
            position++;
            break;
        }
        token = strtok(NULL, s);

    }
    return tempstudent;

};

void write_session(struct strsession session[], int n)
{
    FILE *fsession;
    fsession = fopen("sessionlist.dat","w");
    if (fsession!=NULL)
    {
        for (int i=0; i<n; i++){
            fprintf(fsession,"%s,%s,%s,%s,%s,%s\n",session[i].session_code,session[i].session_title,session[i].session_day,
                    session[i].session_starttime,session[i].session_location,session[i].session_tutorcode);
        }
        fclose(fsession);
    }
}

void write_enroll(struct enrollstudent enroll[], int ne)
{
    FILE *fenroll;
    fenroll = fopen("enrolllist.dat","w");
    if (fenroll!=NULL){
        for (int i=0; i<ne; i++){
            fprintf(fenroll,"%s,%s\n",enroll[i].studenttpnum, enroll[i].sessioncode);
        }
        fclose(fenroll);
    }
}

void write_tutor(struct strtutor tutor[],int n)
{
    FILE* ftutor;
    ftutor = fopen("tutorlist.dat","w");
    if (ftutor!=NULL){
        for (int i=0; i<n; i++){
            fprintf(ftutor,"%s,%s,%s,%s\n",tutor[i].tutor_id,tutor[i].tutor_name,tutor[i].tutor_title,tutor[i].tutor_password);
        }
        fclose(ftutor);
    }
}
void write_student(struct strstudent student[], int n)
{
    FILE *fstudent;
    fstudent = fopen("studentlist.dat","w");
    if (fstudent!=NULL){
        for (int i=0; i<n; i++){
            fprintf(fstudent,"%s,%s,%s,%s,%s,%s\n",student[i].student_tpnumber,student[i].student_name,student[i].student_dob,student[i].student_icnum,student[i].student_address,student[i].student_password);
        }
        fclose(fstudent);
    }
}

void read_session (struct strsession session[], int *ns)
{
    FILE *fsession;
    fsession = fopen("sessionlist.dat","r");
    if (fsession == NULL){
        existtablesession(session,ns);
        write_session(session,*ns);
    }else{
        char readstr[100];
        *ns =0;
        struct strsession one_session;
        while(fgets(readstr,100,fsession)!=NULL){
            one_session = splitting_session(readstr);
            strcpy(session[*ns].session_code,one_session.session_code);
            strcpy(session[*ns].session_title,one_session.session_title);
            strcpy(session[*ns].session_day,one_session.session_day);
            strcpy(session[*ns].session_starttime,one_session.session_starttime);
            strcpy(session[*ns].session_location,one_session.session_location);
            strcpy(session[*ns].session_tutorcode,one_session.session_tutorcode);
            (*ns)++;
        }
    }
}
void read_enroll(struct enrollstudent enroll[], int *ne)
{
    FILE *fenroll;
    fenroll = fopen("enrolllist.dat","r");
    if (fenroll==NULL){
        strcpy(enroll[*ne].studenttpnum,"TP09123");
        strcpy(enroll[*ne].sessioncode,"CPL103");
        (*ne)++;
        strcpy(enroll[*ne].studenttpnum,"TP03425");
        strcpy(enroll[*ne].sessioncode,"JAV102");
        (*ne)++;
        strcpy(enroll[*ne].studenttpnum,"TP03425");
        strcpy(enroll[*ne].sessioncode,"CPL103");
        (*ne)++;
        write_enroll(enroll,*ne);
    }else{
        char readstr[100];
        *ne=0;
        struct enrollstudent one_enroll;
        while(fgets(readstr,100,fenroll)!=NULL){
            one_enroll = splitting_enroll(readstr);
            strcpy(enroll[*ne].studenttpnum,one_enroll.studenttpnum);
            strcpy(enroll[*ne].sessioncode,one_enroll.sessioncode);
            (*ne)++;
        }
    }
}
void read_tutor(struct strtutor tutor[], int *nt)
{
    FILE *ftutor;
    ftutor = fopen("tutorlist.dat","r");
    if (ftutor==NULL){
        existtabletutor(tutor,nt);
        write_tutor(tutor,*nt);
    }else{
        char readstr[100];
        *nt =0;
        struct strtutor one_tutor;
        while(fgets(readstr,100,ftutor)!= NULL){// row is not empty
            one_tutor = splitting_tutor(readstr);
            strcpy(tutor[*nt].tutor_id,one_tutor.tutor_id); //copying the tutor id
            strcpy(tutor[*nt].tutor_name,one_tutor.tutor_name);
            strcpy(tutor[*nt].tutor_title,one_tutor.tutor_title);
            one_tutor.tutor_password[strlen(one_tutor.tutor_password)-1]='\0';
            strcpy(tutor[*nt].tutor_password,one_tutor.tutor_password);
            (*nt)++;
        }
    }
}
void read_student(struct strstudent student[], int *nst)
{
    char passw[20];
    FILE *fstudent;
    fstudent = fopen("studentlist.dat","r");
    if (fstudent==NULL)
    {
        strcpy(student[*nst].student_tpnumber,"TP09123");
        strcpy(student[*nst].student_name,"Michelle");
        strcpy(student[*nst].student_dob,"January 18 2002");
        strcpy(student[*nst].student_icnum,"C56785");
        strcpy(student[*nst].student_address,"Sri Petaling");
        strcpy(passw,"michelle98");
        encrypt(passw);
        strcpy(student[*nst].student_password,passw);
        (*nst)++;
        strcpy(student[*nst].student_tpnumber,"TP00887");
        strcpy(student[*nst].student_name,"Brandon");
        strcpy(student[*nst].student_dob,"May 28 2002");
        strcpy(student[*nst].student_icnum,"C56734");
        strcpy(student[*nst].student_address,"Puchong");
        strcpy(passw,"branddy76");
        encrypt(passw);
        strcpy(student[*nst].student_password,passw);
        (*nst)++;
        strcpy(student[*nst].student_tpnumber,"TP03425");
        strcpy(student[*nst].student_name,"Cecil");
        strcpy(student[*nst].student_dob,"December 23 2003");
        strcpy(student[*nst].student_icnum,"C56453");
        strcpy(student[*nst].student_address,"KLCC");
        strcpy(passw,"cecilll65");
        encrypt(passw);
        strcpy(student[*nst].student_password,passw);
        (*nst)++;
        strcpy(student[*nst].student_tpnumber,"TP07465");
        strcpy(student[*nst].student_name,"Peter");
        strcpy(student[*nst].student_dob,"August 20 2003");
        strcpy(student[*nst].student_icnum,"C56421");
        strcpy(student[*nst].student_address,"Awan Besar");
        strcpy(passw,"petter45");
        encrypt(passw);
        strcpy(student[*nst].student_password,passw);
        (*nst)++;
        strcpy(student[*nst].student_tpnumber,"TP09895");
        strcpy(student[*nst].student_name,"Maxi");
        strcpy(student[*nst].student_dob,"June 17 2002");
        strcpy(student[*nst].student_icnum,"C56655");
        strcpy(student[*nst].student_address,"Bukit Jalil");
        strcpy(passw,"maxximm85");
        encrypt(passw);
        strcpy(student[*nst].student_password,passw);
        (*nst)++;
        write_student(student,*nst);
    }else{
        char readstr[100];
        *nst = 0;
        struct strstudent one_student;
        while(fgets(readstr,100,fstudent)!=NULL)
        {
            one_student = splitting_student(readstr);
            strcpy(student[*nst].student_tpnumber,one_student.student_tpnumber);
            strcpy(student[*nst].student_name,one_student.student_name);
            strcpy(student[*nst].student_dob,one_student.student_dob);
            strcpy(student[*nst].student_icnum,one_student.student_icnum);
            strcpy(student[*nst].student_address,one_student.student_address);
            one_student.student_password[strlen(student[*nst].student_password)-1]='\0';
            strcpy(student[*nst].student_password,one_student.student_password);
            (*nst)++;

        }
    }
}

void show_enroll(struct enrollstudent enroll[], int ne)
{
    printf("List of the current enrollment : \n");
    for (int i=0; i<ne; i++){
        printf("%s - %s\n",enroll[i].studenttpnum,enroll[i].sessioncode);
    }
}
void show_session (struct strsession session[], int ns)
{
    printf("List of session : \n");
    for (int i=0; i<ns; i++){
        printf("%s - %s - %s - %s - %s - %s\n",session[i].session_code,session[i].session_title,session[i].session_day,
                    session[i].session_starttime,session[i].session_location,session[i].session_tutorcode);
    }
}

void show_tutor(struct strtutor tutor[], int nt)
{
    printf("List of tutor:\n");
    for(int i=0; i<nt; i++){
        printf("%s - %s - %s\n",tutor[i].tutor_id,tutor[i].tutor_name,tutor[i].tutor_title);
    }
}

void show_student (struct strstudent student[], int nst)
{
    printf("List of student : \n");
    for (int i=0; i<nst; i++){
        printf("%s - %s - %s - %s - %s\n",student[i].student_tpnumber,student[i].student_name,student[i].student_dob,
               student[i].student_icnum,student[i].student_address);
    }
}
void addtutor (struct strtutor tutor[],int *nt)
{
    printf("\n");
    int valid=-1; // valid=0-> no repetition
    char tutid[4];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Tutor ID = ");
        gets(tutid);
        valid=0;
        if (strlen(tutid)==0)
        {
            printf("Tutor ID cannot be empty.\n");
            valid=1;
        }
        for (int i=0;i<*nt; i++){
            if (strcmp(tutid,tutor[i].tutor_id)==0){
                printf("Tutor ID already exists. Enter another TutorID.\n");
                valid=1;
            }
        }
        if (valid==0){
            strcpy(tutor[*nt].tutor_id,tutid);
        }
    }
    valid = -1;
    char name[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Tutor Name = ");
        gets(name);
        valid=0;
        if (strlen(name)==0){
            printf("Tutor name cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(tutor[*nt].tutor_name,name);
        }
    }
    valid = -1;
    char title[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Tutor title = ");
        gets(title);
        valid=0;
        if (strlen(title)==0){
            printf("Tutor title cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(tutor[*nt].tutor_title,title);
        }
    }
    valid = -1;
    char pw[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Tutor's password = ");
        gets(pw);
        valid=0;
        if (strlen(pw)==0 || strlen(pw)>15){
            printf("Password cannot be empty and maximum is 15 characters\n");
            valid=1;
        }
        int totchar=0;
        int totnum=0;
        for (int i=0; i<strlen(pw); i++){
            if ((pw[i]>='a'&& pw[i]<='z')|| (pw[i]>='A' && pw[i]<='Z')){
                totchar++;
            }else if(pw[i]>='0' && pw[i]<='9'){
                totnum++;
            }
        }
        if (totchar==0 || totnum==0){
            valid=1;
            printf("Password must contain character and number.\n");
        }
        if (valid==0){
            pw[strlen(pw)]='\0';
            encrypt(pw);
            strcpy(tutor[*nt].tutor_password,pw);
        }
    }
    (*nt)++;

}

void addsession (struct strsession session[],int *ns,struct strtutor tutor[],int *nt)
{
    int valid=-1; // valid=0-> no repetition
    char code[10];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Session code = ");
        gets(code);
        valid=0;
        for (int i=0;i<*ns; i++){
            if (strcmp(code,session[i].session_code)==0){
                printf("Session code already exists. Enter another Session.\n");
                valid=1;
            }
        }
        if (valid==0){
            strcpy(session[*ns].session_code,code);
        }
    }
    valid=-1; // valid=0-> no repetition
    char titles[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Session title = ");
        gets(titles);
        valid=0;
        if (strlen(titles)==0){
            printf("Session titles cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(session[*ns].session_title,titles);
        }
    }
    valid=-1; // valid=0-> no repetition
    char day[10];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Session day = ");
        gets(day);
        valid=0;
        if (strlen(day)==0){
            printf("Session day cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(session[*ns].session_day,day);
        }
    }
    valid=-1; // valid=0-> no repetition
    char time[10];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Session time = ");
        gets(time);
        valid=0;
        if (strlen(time)==0){
            printf("Session start time cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(session[*ns].session_starttime,time);
        }
    }
    valid=-1; // valid=0-> no repetition
    char loc[10];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Session location = ");
        gets(loc);
        valid=0;
        if (strlen(loc)==0){
            printf("Session location cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(session[*ns].session_location,loc);
        }
    }
    valid=-1; // valid=0-> no repetition
    int tutchoice;
    printf("List of tutor : \n");
    for (int i=0; i<*nt; i++){
        printf("%d. Tutor ID = %s\n",i+1, tutor[i].tutor_id);
        printf("   Tutor name = %s\n",tutor[i].tutor_name);
    }
    while(valid!=0){
        fflush(stdin);
        printf("Enter tutor for this session [1/2/3/...]= ");
        scanf("%d",&tutchoice);
        if (tutchoice>=1 && tutchoice<=*nt)
        {
            valid=0;
            strcpy(session[*ns].session_tutorcode,tutor[tutchoice-1].tutor_id);
        }
        else
        {
            printf("Invalid input, input must be 1-%d\n",*nt);
            valid=1;
        }

    }
    (*ns)++;
}


void addstudent(struct strstudent student[], int *nst)
{
    printf("\n");
    int valid=-1; // valid=0-> no repetition
    char tpnum[10];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Student's TP Number = ");
        gets(tpnum);
        valid=0;
        if(strlen(tpnum)==0){
            printf("TP Number cannot be empty.\n");
            valid=1;
        }
        for (int i=0;i<*nst; i++){
            if (strcmp(tpnum,student[i].student_tpnumber)==0){
                printf("TP Number already exists. Enter another TP Number.\n");
                valid=1;
            }
        }
        if (valid==0){
            strcpy(student[*nst].student_tpnumber,tpnum);
        }
    }
    valid=-1; // valid=0-> no repetition
    char name[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Student's Name = ");
        gets(name);
        valid=0;
        if (strlen(name)==0){
            printf("Student name cannot be empty.\n");
            valid=1;
        }
        if (valid==0){
            strcpy(student[*nst].student_name,name);
        }
    }
    valid=-1;
    char dob[30];
    while(valid!=0){
        printf("Enter Student's Day of Birth = ");
        gets(dob);
        valid = 0;
        if (strlen(dob)==0){
            printf("Day of Birth cannot be empty.\n");
            valid=1;
        }
        if(valid==0){
            strcpy(student[*nst].student_dob,dob);
        }
    }
    valid=-1;
    char ic[10];
    while(valid!=0){
        printf("Enter Student's IC Number = ");
        gets(ic);
        valid = 0;
        if (strlen(ic)==0){
            printf("IC Number cannot be empty.\n");
            valid=1;
        }
        for (int i=0; i<*nst; i++){
            if (strcmp(ic,student[i].student_icnum)==0){
                printf("IC Number already exists.\n");
                valid=1;
            }
        }
        if(valid==0){
            strcpy(student[*nst].student_icnum,ic);
        }
    }
    valid=-1;
    char adr[20];
    while(valid!=0){
        printf("Enter Student's Address = ");
        gets(adr);
        valid = 0;
        if (strlen(adr)==0){
            printf("Address cannot be empty.\n");
            valid=1;
        }
        if(valid==0){
            strcpy(student[*nst].student_address,adr);
        }
    }
    valid = -1;
    char psw[50];
    while(valid!=0){
        fflush(stdin);
        printf("Enter Student's password = ");
        gets(psw);
        valid=0;
        if (strlen(psw)==0 || strlen(psw)>15){
            printf("Password cannot be empty and maximum is 15 characters\n");
            valid=1;
        }
        int totchar=0;
        int totnum=0;
        for (int i=0; i<strlen(psw); i++){
            if ((psw[i]>='a'&& psw[i]<='z')|| (psw[i]>='A' && psw[i]<='Z')){
                totchar++;
            }else if(psw[i]>='0' && psw[i]<='9'){
                totnum++;
            }
        }
        if (totchar==0 || totnum==0){
            valid=1;
            printf("Password must contain character and number.\n");
        }
        if (valid==0){
            encrypt(psw);
            strcpy(student[*nst].student_password,psw);
        }
    }
    (*nst)++;
}

void enroll_student (struct strsession session[], int ns, struct strstudent student[],int nst,
                     struct strtutor tutor[], int nt, struct enrollstudent enroll[],int *ne)
{
    printf("\n");
    int valid=-1;
    int cont=-1;
    int chsession;
    char chstudent[10];
    while (valid!=0){
        printf("List of the session : \n");
        for (int i=0; i<ns; i++){
            printf("%d. %s - %s - %s\n",i+1,session[i].session_code,session[i].session_title,session[i].session_tutorcode);
        }
        printf("Choose session [1/2/3/...] = ");
        scanf("%d",&chsession);
        if (chsession>=1 && chsession<=ns)
        {
                cont=1;
                printf("Enter student's TP Number you want to be enroll in session %s.\n",session[chsession-1].session_code);
                while(cont!=0){
                    printf("Student's TP Number = ");
                    scanf("%s",&chstudent);
                    valid=-1;
                    for (int i=0; i<nst; i++){
                        if (strcmp(chstudent,student[i].student_tpnumber)==0){
                            valid=0;
                            strcpy(enroll[*ne].studenttpnum,chstudent);
                            strcpy(enroll[*ne].sessioncode,session[chsession-1].session_code);
                            (*ne)++;
                        }
                    }
                    if (valid==0){
                        printf("Student with TP Number %s has successfully added to session %s\n",chstudent,session[chsession-1].session_code);
                    }else{
                        printf("TP Number does not exist.\n");
                    }
                    printf("Do you want to continue enroll student in this session? [1. Yes - 0. No] = ");
                    scanf("%d",&cont);
                }
                printf("Do you want to change the session for enrolling the students? [1. Yes - 0.No] = ");
                scanf("%d",&valid);
            }
            else
            {
                printf("Invalid input, input must be 1-%d\n",ns);
                valid=1;
            }
        }

}
void printrenroll(struct enrollstudent enroll[], int ne, struct strstudent student[], int nst,
                   struct strtutor tutor[],int nt, struct strsession session[], int ns)
{
    int position_student;
    int position_tutor;
    int position_session;
    printf("Student's Name\t\tSession code\tTutor code\tTutor Name\t\tSession Location\n");
    printf("------------------------------------------------------------------------------------------------");
    printf("\n");
    for (int i=0; i<ne; i++){
        position_student=-1;
        position_tutor=-1;
        position_session=-1;
        for (int j=0; j<nst; j++){
            if (strcmp(enroll[i].studenttpnum,student[j].student_tpnumber)==0){
                position_student = j;
            }
        }
        char tutorcode[4];
        for (int j=0; j<ns; j++){
            if (strcmp(enroll[i].sessioncode,session[j].session_code)==0){
                position_session = j;
                strcpy(tutorcode,session[position_session].session_tutorcode);
            }
        }
        for (int j=0; j<nt; j++){
            if (strcmp(tutorcode,tutor[j].tutor_id)==0){
                position_tutor = j;
            }
        }
        printf("%-20s%10s%13s%22s%23s",student[position_student].student_name,session[position_session].session_code,session[position_session].session_tutorcode,
               tutor[position_tutor].tutor_name,session[position_session].session_location);
        printf("\n");
    }
}

void printlisttutor(struct strtutor tutor[],int nt, struct strsession session[], int ns)
{
    int cont=-1;
    int tutor_position;
    int valid=-1;
    int validpw=-1;
    char tutorcode[5];
    char tutpassw[20];
    while (cont!=0){
        fflush(stdin);
        printf("Enter your tutor code : ");
        gets(tutorcode);
        for (int i=0; i<nt; i++){
            if (strcmp(tutorcode,tutor[i].tutor_id)==0){
                valid =0;
                tutor_position = i;
            }
        }
        if (valid==0){
            fflush(stdin);
            printf("Enter password : ");
            gets(tutpassw);
            encrypt(tutpassw);
            if (strcmp(tutpassw,tutor[tutor_position].tutor_password)==0){
                validpw =0;
            }
            if (validpw==0){
                printf("You've logged in as a tutor %s\n",tutorcode);
                printf("Here is list of session assigned to you:\n");
                printf("Session code\t    Session title\tSession day\tSession Start time\tSession Location\n");
                printf("------------------------------------------------------------------------------------------------\n");
                for (int i=0; i<ns; i++){
                    if (strcmp(tutorcode,session[i].session_tutorcode)==0){
                        printf("%-13s%21s%14s%14s%25s",session[i].session_code,session[i].session_title,
                                session[i].session_day,session[i].session_starttime,session[i].session_location);
                        printf("\n");
                    }
                }

            }else{
                printf("Invalid password\n");
            }
        }else{
            printf("Tutor code does not exists.\n");
        }
        validpw=-1;
        printf("\n Do you want to:\n");
        printf("1. Continue as tutor\n");
        printf("0. Back to homepage\n");
        printf("[1/0] ? = ");
        scanf("%d",&cont);
    }
}
//DISINI BENERIN
void printstudentsession(struct enrollstudent enroll[], int ne, struct strtutor tutor[], int nt,
                         struct strsession session[], int ns, struct strstudent student[], int nst)
{
    char checktp[20];
    char checkpw[20];
    char tpnum[20];
    int position_student;
    int position_sessiontp;
    int position_tutor;
    int position_sessionloc;
    int valid=0;
    int validpw=-1;
    int enterpw=-1;
    int validtp=-1;
    int validtppw=-1;
    int cont=-1;
    while(cont!=0){
        fflush(stdin);
        printf("Enter TP Number to check your session : ");
        gets(checktp);
        validtp=-1;
        for (int i=0; i<ne; i++){
            if (strcmp(checktp,enroll[i].studenttpnum)==0){
                validtp=0;
            }
        }
        if (validtp==0){
            printf("Enter your password : ");
            gets(checkpw);
            encrypt(checkpw);
            validtppw=-1;
            for (int i=0; i<nst; i++){
                if (strcmp(checktp,student[i].student_tpnumber)==0 &&
                    strcmp(checkpw,student[i].student_password)==0){
                        validtppw = 0;
                }
            }
            if (validtppw!=0){
                printf("Invalid password.\n");
            }else{
                printf("Session list for student %s : \n",checktp);
                printf("Session Code\t Tutor Code \t Tutor name\t Session Location\n");
                for (int i=0; i<ne; i++){
                    valid = -1;
                    if (strcmp(checktp,enroll[i].studenttpnum)==0){
                        valid=0;
                        strcpy(tpnum,checktp);
                        position_sessiontp=i;
                    }
                    if (valid==0){
                        for (int j=0; j<nst; j++){
                            if (strcmp(tpnum,student[j].student_tpnumber)==0){
                                position_student=j;
                            }
                            if (strcmp(checkpw,student[position_student].student_password)==0){
                                validpw=0;
                            }
                        }
                        char tutorcode[4];
                        if (validpw==0){
                            for (int j=0; j<ns; j++){
                                if (strcmp(enroll[position_sessiontp].sessioncode,session[j].session_code)==0){
                                    position_sessionloc = j;
                                    strcpy(tutorcode,session[j].session_tutorcode);
                                }
                            }for (int j=0; j<nt; j++){
                                if (strcmp(tutorcode,tutor[j].tutor_id)==0){
                                    position_tutor = j;
                                }
                            }
                            printf("%-10s%10s%20s%17s\n",session[position_sessionloc].session_code,tutor[position_tutor].tutor_id,
                            tutor[position_tutor].tutor_name,session[position_sessionloc].session_location);
                        }
                    }
                }
            }
        }else{
            printf("TP Number does not exists in any enrolled session\n");
        }
        printf("\n Do you want to continue see the list student's session?:\n");
        printf("1. Yes\n");
        printf("0. No\n");
        printf("[1/0] ? = ");
        scanf("%d",&cont);
    }
}

void enrollbystud(struct enrollstudent enroll[], int *ne, struct strstudent student[],int nst,
                  struct strtutor tutor[], int nt,struct strsession session[],int ns)
{
    int chsession;
    int valid=-1;
    int validpw=-1;
    char entertpnum[20];
    char enterpw[20];
    int pos_stud;
    int gotoenroll=-1;
    fflush(stdin);
    printf("Enter your TP Number : ");
    gets(entertpnum);
    valid=-1;
    for (int i=0; i<nst; i++){
        if (strcmp(entertpnum,student[i].student_tpnumber)==0){
            valid=0;
            pos_stud=i;
        }
    }
    if (valid==0){
        printf("Enter password : ");
        gets(enterpw);
        encrypt(enterpw);
        if (strcmp(enterpw,student[pos_stud].student_password)==0){
            validpw=0;
        }
        if (validpw==0){
            printf("List of session available : \n");
            for (int j=0; j<ns; j++){
                printf("%d. %s - %s - %s\n",j+1,session[j].session_code,session[j].session_title,session[j].session_tutorcode);
            }
            printf("Choose session you want to be enrolled in [1/2/3/.../%d] = ",ns);
            scanf("%d",&chsession);
            if (chsession>=1 && chsession<=ns){
                strcpy(enroll[*ne].studenttpnum,entertpnum);
                strcpy(enroll[*ne].sessioncode,session[chsession-1].session_code);
                (*ne)++;
                write_enroll(enroll,*ne);
                printf("Successfully enrolled you in session %s!\n",session[chsession-1].session_code);
                printf("Enrolled list now : \n");
                for (int j=0; j<*ne; j++){
                    printf("%s - %s\n",enroll[j].studenttpnum,enroll[j].sessioncode);
                }
            }
            else{
                printf("Input invalid. Number 1-%d only\n",ns);
            }
        }else if (validpw!=0){
            printf("Invalid password\n");
        }
    }else if (valid!=0){
        printf("TP Number does not exists.\n");
    }
}

void existtablesession (struct strsession session[],int *ns)
{
     strcpy(session[*ns].session_code,"PYP101");
     strcpy(session[*ns].session_title,"Python Programming");
     strcpy(session[*ns].session_day,"Saturday");
     strcpy(session[*ns].session_starttime,"9.00am");
     strcpy(session[*ns].session_location,"C-01-01");
     strcpy(session[*ns].session_tutorcode,"T01");
     (*ns)++;
     strcpy(session[*ns].session_code,"JAV102");
     strcpy(session[*ns].session_title,"Java Programming");
     strcpy(session[*ns].session_day,"Sunday");
     strcpy(session[*ns].session_starttime,"9.00am");
     strcpy(session[*ns].session_location,"C-01-02");
     strcpy(session[*ns].session_tutorcode,"T02");
     (*ns)++;
     strcpy(session[*ns].session_code,"CPL103");
     strcpy(session[*ns].session_title,"C Programming");
     strcpy(session[*ns].session_day,"Saturday");
     strcpy(session[*ns].session_starttime,"2.00pm");
     strcpy(session[*ns].session_location,"C-01-03");
     strcpy(session[*ns].session_tutorcode,"T03");
     (*ns)++;
     strcpy(session[*ns].session_code,"WEB104");
     strcpy(session[*ns].session_title,"Web Development");
     strcpy(session[*ns].session_day,"Sunday");
     strcpy(session[*ns].session_starttime,"9.00am");
     strcpy(session[*ns].session_location,"C-01-04");
     strcpy(session[*ns].session_tutorcode,"T04");
     (*ns)++;
     strcpy(session[*ns].session_code,"CSP105");
     strcpy(session[*ns].session_title,"C Sharp Programming");
     strcpy(session[*ns].session_day,"Monday");
     strcpy(session[*ns].session_starttime,"7.00pm");
     strcpy(session[*ns].session_location,"C-01-05");
     strcpy(session[*ns].session_tutorcode,"T05");
     (*ns)++;
}

void existtabletutor (struct strtutor tutor[],int *nt)
{
    char pww[16];
    strcpy(tutor[*nt].tutor_id,"T01");
    strcpy(tutor[*nt].tutor_name,"Albert");
    strcpy(tutor[*nt].tutor_title,"Web Development");
    strcpy(pww,"albert18");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
    strcpy(tutor[*nt].tutor_id,"T02");
    strcpy(tutor[*nt].tutor_name,"Amad");
    strcpy(tutor[*nt].tutor_title,"C Sharp Programming");
    strcpy(pww,"amadd88");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
    strcpy(tutor[*nt].tutor_id,"T03");
    strcpy(tutor[*nt].tutor_name,"Steve");
    strcpy(tutor[*nt].tutor_title,"Python Programming");
    strcpy(pww,"stevencurry11");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
    strcpy(tutor[*nt].tutor_id,"T04");
    strcpy(tutor[*nt].tutor_name,"Jack");
    strcpy(tutor[*nt].tutor_title,"Computer Mathematics");
    strcpy(pww,"aguss33");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
    strcpy(tutor[*nt].tutor_id,"T05");
    strcpy(tutor[*nt].tutor_name,"John");
    strcpy(tutor[*nt].tutor_title,"Database");
    strcpy(pww,"johnny99");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
    strcpy(tutor[*nt].tutor_id,"T06");
    strcpy(tutor[*nt].tutor_name,"Gabriel");
    strcpy(tutor[*nt].tutor_title,"System Design");
    strcpy(pww,"gabb12");
    encrypt(pww);
    strcpy(tutor[*nt].tutor_password,pww);
    (*nt)++;
}

void update_student(struct strstudent student[], int nst, struct enrollstudent enroll[],int ne)
{
    int cont=-1;
    int validtp=-1;
    int updatestud;
    int valid=-1;
    char checktp[10];
    int position_student;
    int position_inEnroll;
    char newtpnum[20];
    char newname[20];
    char newdob[20];
    char newaddress[20];
    char newicnum[20];
    fflush(stdin);
    printf("Enter Student's TP Number = ");
    gets(checktp);
    valid=-1;
    for (int i=0; i<nst; i++){
        if (strcmp(checktp,student[i].student_tpnumber)==0){
            valid=0;
            position_student=i;
        }
    }
    if (valid==0){
        while (cont!=0){
            //updating data
            printf("Which type of %s data do you want to update?\n",student[position_student].student_tpnumber);
            printf("1. TP Number\n");
            printf("2. Name\n");
            printf("3. Day of Birth\n");
            printf("4. IC Number\n");
            printf("5. Address\n");
            printf("Enter your choice [1/2/3/4/5] = ");
            //fflush(stdin);
            scanf("%d",&updatestud);
            int conttp;
            conttp=-1;
            if (updatestud==1){
                while (conttp!=0){
                    fflush(stdin);
                    int suretp=-1;
                    printf("Enter New TP Number = ");
                    gets(newtpnum);
                    validtp=-1;
                    for (int i=0; i<nst; i++){
                        if (strcmp(newtpnum,student[i].student_tpnumber)==0){
                            validtp=1; // new tp number exists
                            break;
                        }else{
                            validtp=0;
                        }
                    }
                    if (validtp==0){ // new tp number not in student data
                        printf("Are you sure you want to update %s into %s?\n",checktp,newtpnum);
                        printf("1. Yes, I'm sure\n");
                        printf("0. No, cancel updating TP Number\n");
                        scanf("%d",&suretp);
                        conttp=0;
                        if (suretp==1){
                            strcpy(student[position_student].student_tpnumber,newtpnum);
                            write_student(student,nst);
                            for (int i=0; i<ne; i++){
                                if (strcmp(checktp,enroll[i].studenttpnum)==0){
                                    position_inEnroll=i;
                                    strcpy(enroll[position_inEnroll].studenttpnum,newtpnum);
                                    write_enroll(enroll,ne);
                                }
                            }
                            printf("New TP Number %s is successfully updated for student %s\n",
                                   student[position_student].student_tpnumber,student[position_student].student_name);
                        }
                            printf("1. Go back to Update Student page\n");
                            printf("0. Exit from this function\n");
                            scanf("%d",&cont);
                    }else{
                        printf("Sorry, New TP Number already exists. Try another TP Number!\n");
                        printf("Do you want to continue entering New TP Number?\n");
                        printf("1. Yes.\n0.No\n");
                        scanf("%d",&conttp);
                    }
                }
            }else if (updatestud==2){
                //int validnum;
                fflush(stdin);
                int surename=-1;
                printf("Enter New Name = ");
                gets(newname);
                printf("Are you sure you want to update %s into %s?\n",student[position_student].student_name,newname);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Name\n");
                scanf("%d",&surename);
                if (surename==1){
                    strcpy(student[position_student].student_name,newname);
                    write_student(student,nst);
                    printf("New Name is successfully updated for student %s become %s\n",
                                   student[position_student].student_tpnumber,student[position_student].student_name);
                }
                printf("1. Go back to Update Student page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updatestud==3){
                fflush(stdin);
                int suredob=-1;
                printf("Enter New Day of Birth = ");
                gets(newdob);
                printf("Are you sure you want to update %s into %s?\n",student[position_student].student_dob,newdob);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Day of Birth\n");
                scanf("%d",&suredob);
                if (suredob==1){
                    strcpy(student[position_student].student_dob,newdob);
                    write_student(student,nst);
                    printf("New Day of Birth is successfully updated for student %s become %s\n",
                                   student[position_student].student_tpnumber,student[position_student].student_dob);
                }
                printf("1. Go back to Update Student page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updatestud==4){
                int conticnum=-1;
                int sureicnum=-1;
                while (conticnum!=0){
                    fflush(stdin);
                    //printf("Masuk ke while\n");
                    int sureicnum=-1;
                    printf("Enter New IC Number = ");
                    gets(newicnum);
                    int validicnum=-1;
                    for (int i=0; i<nst; i++){
                        if (strcmp(newicnum,student[i].student_icnum)==0){
                            validicnum=1; // new ic num exists
                            break;
                        }else{
                            validicnum=0;
                        }
                    }
                    if (validicnum==0){ // new ic num not in student data
                        printf("Are you sure you want to update %s into %s?\n",student[position_student].student_icnum,newicnum);
                        printf("1. Yes, I'm sure\n");
                        printf("0. No, cancel updating IC Number\n");
                        scanf("%d",&sureicnum);
                        conticnum=0;
                        if (sureicnum==1){
                            strcpy(student[position_student].student_icnum,newicnum);
                            write_student(student,nst);
                            printf("New IC Number %s is successfully updated for student %s\n",
                                   student[position_student].student_icnum,student[position_student].student_tpnumber);
                        }
                            printf("1. Go back to Update Student page\n");
                            printf("0. Exit from this function\n");
                            scanf("%d",&cont);
                    }else{
                        printf("Sorry, New IC Number already exists. Try another IC Number!\n");
                        printf("Do you want to continue entering New IC Number?\n");
                        printf("1. Yes.\n");
                        printf("0. No\n");
                        scanf("%d",&conticnum);
                    }
                }
            }else if (updatestud==5){
                int sureadr=-1;
                fflush(stdin);
                printf("Enter New Day of Birth = ");
                gets(newaddress);
                printf("Are you sure you want to update %s into %s?\n",student[position_student].student_address,newaddress);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Address\n");
                scanf("%d",&sureadr);
                if (sureadr==1){
                    strcpy(student[position_student].student_address,newaddress);
                    write_student(student,nst);
                    printf("New Address is successfully updated for student %s become %s\n",
                                   student[position_student].student_tpnumber,student[position_student].student_address);
                }
                printf("1. Go back to Update Student page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }
        }
    }else{
        printf("TP Number does not exists.\n");
    }
}

void update_tutor(struct strtutor tutor[], int nt,struct strsession session[], int ns)
{
    int cont=-1;
    int validid=-1;
    int updatetut;
    int valid=-1;
    char checkid[10];
    int position_tutor,position_inSession;
    char newtutid[20];
    char newtutname[20];
    char newtuttitle[50];
    fflush(stdin);
    printf("Enter Tutor's ID = ");
    gets(checkid);
    valid=-1;
    for (int i=0; i<nt; i++){
        if (strcmp(checkid,tutor[i].tutor_id)==0){
            valid=0;
            position_tutor=i;
            printf("tutor position = %d\n",position_tutor);
        }
    }
    if (valid==0){
        while(cont!=0){
            printf("Which type of %s data do you want to update?\n",tutor[position_tutor].tutor_id);
            printf("1. Tutor ID\n");
            printf("2. Name\n");
            printf("3. Title\n");
            printf("Enter your choice [1/2/3] = ");
            scanf("%d",&updatetut);
            int contid;
            contid=-1;
            if (updatetut==1){
                while (contid!=0){
                    fflush(stdin);
                    int sureid=-1;
                    printf("Enter New Tutor ID = ");
                    gets(newtutid);
                    validid=-1;
                    for (int i=0; i<nt; i++){
                        if (strcmp(newtutid,tutor[i].tutor_id)==0){
                            validid=1; // new tutor id exists
                            break;
                        }else{
                            validid=0;
                        }
                    }
                    if (validid==0){ // new tutor id not in tutor data
                        printf("Are you sure you want to update %s into %s?\n",checkid,newtutid);
                        printf("1. Yes, I'm sure\n");
                        printf("0. No, cancel updating Tutor ID\n");
                        scanf("%d",&sureid);
                        contid=0;
                        if (sureid==1){
                            strcpy(tutor[position_tutor].tutor_id,newtutid);
                            write_tutor(tutor,nt);
                            for (int i=0; i<ns; i++){
                                if (strcmp(checkid,session[i].session_tutorcode)==0){
                                    position_inSession=i;
                                    strcpy(session[position_inSession].session_tutorcode,newtutid);
                                    write_session(session,ns);
                                }
                            }
                            printf("New Tutor ID %s is successfully updated for tutor %s\n",
                                   tutor[position_tutor].tutor_id,tutor[position_tutor].tutor_name);
                        }
                        printf("1. Go back to Update tutor page\n");
                        printf("0. Exit from this function\n");
                        scanf("%d",&cont);
                    }else{
                        printf("Sorry, New Tutor ID already exists. Try another Tutor ID!\n");
                        printf("Do you want to continue entering New Tutor ID?\n");
                        printf("1. Yes.\n0.No\n");
                        scanf("%d",&contid);
                    }
                }
            }else if (updatetut==2){
                int surename=-1;
                fflush(stdin);
                printf("Enter New Name = ");
                gets(newtutname);
                printf("Are you sure you want to update %s into %s?\n",tutor[position_tutor].tutor_name,newtutname);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Name\n");
                scanf("%d",&surename);
                if (surename==1){
                    strcpy(tutor[position_tutor].tutor_name,newtutname);
                    write_tutor(tutor,nt);
                    printf("New Name is successfully updated for tutor %s become %s\n",
                                   tutor[position_tutor].tutor_id,tutor[position_tutor].tutor_name);
                }
                printf("1. Go back to update Tutor page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updatetut==3){
                int suretit=-1;
                fflush(stdin);
                printf("Enter New Title = ");
                gets(newtuttitle);
                printf("Are you sure you want to update %s into %s?\n",tutor[position_tutor].tutor_title,newtuttitle);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Name\n");
                scanf("%d",&suretit);
                if (suretit==1){
                    strcpy(tutor[position_tutor].tutor_title,newtuttitle);
                    write_tutor(tutor,nt);
                    printf("New Title is successfully updated for tutor %s become %s\n",
                                   tutor[position_tutor].tutor_id,tutor[position_tutor].tutor_title);
                }
                printf("1. Go back to Update Tutor page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }
        }
    }else{
        printf("Tutor ID does not exist.\n");
    }
}

void update_passwordTutor (struct strtutor tutor[], int nt)
{
    char newpasswordTutor[20];
    char checkTutorID[20];
    char oldpassword[20];
    int position_tutor;
    int TutIDExist=-1;
    int cont=-1;
    int contUpdate=-1;
    int proceedToUpdatePassword=-1;
    while(contUpdate!=0){
        cont=-1;
        fflush(stdin);
        printf("Enter your Tutor ID = ");
        gets(checkTutorID);
        TutIDExist=-1;
        for (int i=0; i<nt; i++){
            if (strcmp(checkTutorID,tutor[i].tutor_id)==0){
                TutIDExist=1;
                position_tutor=i;
            }
        }
        if (TutIDExist==1){
            while(cont!=0){
                fflush(stdin);
                printf("Enter your old password = ");
                gets(oldpassword);
                encrypt(oldpassword);
                if (strcmp(oldpassword,tutor[position_tutor].tutor_password)==0){
                    proceedToUpdatePassword=1;
                }
                if (proceedToUpdatePassword==1){
                    int valid=-1;
                    valid = -1;
                    while(valid!=0){
                        fflush(stdin);
                        printf("Enter New password = ");
                        gets(newpasswordTutor);
                        valid=0;
                        if (strlen(newpasswordTutor)==0 || strlen(newpasswordTutor)>15){
                            printf("Password cannot be empty and maximum is 15 characters\n");
                            valid=1;
                        }
                        int totchar=0;
                        int totnum=0;
                        for (int i=0; i<strlen(newpasswordTutor); i++){
                            if ((newpasswordTutor[i]>='a'&& newpasswordTutor[i]<='z')|| (newpasswordTutor[i]>='A' && newpasswordTutor[i]<='Z')){
                                totchar++;
                            }else if(newpasswordTutor[i]>='0' && newpasswordTutor[i]<='9'){
                                totnum++;
                            }
                        }
                        if (totchar==0 || totnum==0){
                            valid=1;
                            printf("Password must contain character and number.\n");
                        }
                        if (valid==0){
                            encrypt(newpasswordTutor);
                            strcpy(tutor[position_tutor].tutor_password,newpasswordTutor);
                            write_tutor(tutor,nt);
                            printf("New password is successfully updated for tutor %s\n",
                                    tutor[position_tutor].tutor_id);
                            printf("Do you want to update password again?\n");
                            printf("1. Yes, update password again\n");
                            printf("0. No\n");
                            printf("[1/0] = ");
                            scanf("%d",&contUpdate);
                            cont=0;

                        }

                    }
                }else{
                printf("Incorrect password\n");
                printf("Do you want to enter old password again?\n");
                printf("1. Yes\n");
                printf("0. No\n");
                printf("[1/0] = ");
                scanf("%d",&cont);
                }
            }
        }else{
            printf("Tutor ID does not exist.\n");
            printf("Do you want to enter TutorID again?\n");
            printf("1. Yes, enter Tutor ID again\n");
            printf("0. No, go back to home page\n");
            printf("[1/0] = ");
            scanf("%d",&contUpdate);
        }

    }

}

void update_passwordStudent (struct strstudent student[], int nst)
{
    char newpasswordStudent[20];
    char checkStudentTP[20];
    char oldpassword[20];
    int position_student;
    int TPnumExist=-1;
    int cont=-1;
    int contUpdate=-1;
    int proceedToUpdatePassword=-1;
    while(contUpdate!=0){
        cont=-1;
        fflush(stdin);
        printf("Enter your TP Number = ");
        gets(checkStudentTP);
        TPnumExist=-1;
        for (int i=0; i<nst; i++){
            if (strcmp(checkStudentTP,student[i].student_tpnumber)==0){
                TPnumExist=1;
                position_student=i;
            }
        }
        if (TPnumExist==1){
            while(cont!=0){
                fflush(stdin);
                printf("Enter your old password = ");
                gets(oldpassword);
                encrypt(oldpassword);
                proceedToUpdatePassword=-1;
                if (strcmp(oldpassword,student[position_student].student_password)==0){
                    proceedToUpdatePassword=1;
                }
                if (proceedToUpdatePassword==1){
                    int valid;
                    valid = -1;
                    while(valid!=0){
                        fflush(stdin);
                        printf("Enter New password = ");
                        gets(newpasswordStudent);
                        valid=0;
                        if (strlen(newpasswordStudent)==0 || strlen(newpasswordStudent)>15){
                            printf("Password cannot be empty and maximum is 15 characters\n");
                            valid=1;
                        }
                        int totchar=0;
                        int totnum=0;
                        for (int i=0; i<strlen(newpasswordStudent); i++){
                            if ((newpasswordStudent[i]>='a'&& newpasswordStudent[i]<='z')|| (newpasswordStudent[i]>='A' && newpasswordStudent[i]<='Z')){
                                totchar++;
                            }else if(newpasswordStudent[i]>='0' && newpasswordStudent[i]<='9'){
                                totnum++;
                            }
                        }
                        if (totchar==0 || totnum==0){
                            valid=1;
                            printf("Password must contain character and number.\n");
                        }
                        if (valid==0){
                            encrypt(newpasswordStudent);
                            strcpy(student[position_student].student_password,newpasswordStudent);
                            write_student(student,nst);
                            printf("New password is successfully updated for student %s\n",
                                    student[position_student].student_tpnumber);
                            printf("Do you want to update password again?\n");
                            printf("1. Yes, update password again\n");
                            printf("0. No\n");
                            printf("[1/0] = ");
                            scanf("%d",&contUpdate);
                            cont=0;

                        }

                    }
                }else{
                printf("Incorrect password\n");
                printf("Do you want to enter old password again?\n");
                printf("1. Yes\n");
                printf("0. No\n");
                printf("[1/0] = ");
                scanf("%d",&cont);
                }
            }
        }else{
            printf("TP Number does not exist.\n");
            printf("Do you want to enter TP Number again?\n");
            printf("1. Yes, enter TP Number again\n");
            printf("0. No, go back to home page\n");
            printf("[1/0] = ");
            scanf("%d",&contUpdate);
        }

    }

}


void update_session(struct strsession session[],int ns,struct strtutor tutor[], int nt, struct enrollstudent enroll[], int ne)
{
    int cont=-1;
    int validcode=-1;
    int updateses;
    int valid=-1;
    char checkcode[10];
    int position_session;
    int position_inEnroll;
    char newsesCode[20];
    char newsesTitle[20];
    char newsesDay[20];
    char newsesTime[20];
    char newsesLoc[20];
    char newsesTutorCode[20];
    fflush(stdin);
    printf("Enter Session Code = ");
    gets(checkcode);
    valid=-1;
    for (int i=0; i<ns; i++){
        if (strcmp(checkcode,session[i].session_code)==0){
            valid=0;
            position_session=i;
        }
    }
    if (valid==0){
        while (cont!=0){
           printf("Which type of %s data do you want to update?\n",session[position_session].session_code);
            printf("1. Session Code\n");
            printf("2. Session Title\n");
            printf("3. Session Day\n");
            printf("4. Session Start Time\n");
            printf("5. Session Location\n");
            printf("6. Session Tutor\n");
            printf("Enter your choice [1/2/3/4/5/6] = ");
            scanf("%d",&updateses);
            int contses;
            int contInpTut;
            contInpTut=-1;
            contses=-1;
            if (updateses==1){
                while (contses!=0){
                    fflush(stdin);
                    int surecode=-1;
                    printf("Enter Session code = ");
                    gets(newsesCode);
                    validcode=-1;
                    for (int i=0; i<ns; i++){
                        if (strcmp(newsesCode,session[i].session_code)==0){
                            validcode=1; // new session code exists
                            break;
                        }else{
                            validcode=0;
                        }
                    }
                    if (validcode==0){ // new session code not in tutor data
                        printf("Are you sure you want to update %s into %s?\n",checkcode,newsesCode);
                        printf("1. Yes, I'm sure\n");
                        printf("0. No, cancel updating Session Code\n");
                        scanf("%d",&surecode);
                        contses=0;
                        if (surecode==1){
                            strcpy(session[position_session].session_code,newsesCode);
                            write_session(session,ns);
                            for (int i=0; i<ne; i++){
                                if (strcmp(checkcode,enroll[i].sessioncode)==0){
                                    position_inEnroll = i;
                                    strcpy(enroll[position_inEnroll].sessioncode,newsesCode);
                                    write_enroll(enroll,ne);
                                }
                            }
                            printf("New Session Code %s is successfully updated!\n",
                                   session[position_session].session_code);
                        }
                        printf("1. Go back to Update session page\n");
                        printf("0. Exit from this function\n");
                        scanf("%d",&cont);
                    }else{
                        printf("Sorry, New Session Code already exists. Try another Session Code!\n");
                        printf("Do you want to continue entering New Session Code?\n");
                        printf("1. Yes.\n0.No\n");
                        scanf("%d",&contses);
                    }
                }
            }else if (updateses==2){
                int surecode=-1;
                char oldTitle[50];
                fflush(stdin);
                printf("Enter New Title = ");
                gets(newsesTitle);
                printf("Are you sure you want to update %s into %s?\n",session[position_session].session_title,newsesTitle);
                strcpy(oldTitle,session[position_session].session_title);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Title\n");
                scanf("%d",&surecode);
                if (surecode==1){
                    strcpy(session[position_session].session_title,newsesTitle);
                    write_session(session,ns);
                    printf("New Title is successfully updated from %s become %s\n",
                                   oldTitle,session[position_session].session_title);
                }
                printf("1. Go back to Update Session page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updateses==3){
                int surecode=-1;
                char oldSesDay[20];
                fflush(stdin);
                printf("Enter New Day = ");
                gets(newsesDay);
                printf("Are you sure you want to update %s into %s?\n",session[position_session].session_day,newsesDay);
                strcpy(oldSesDay,session[position_session].session_day);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Day\n");
                scanf("%d",&surecode);
                if (surecode==1){
                    strcpy(session[position_session].session_day,newsesDay);
                    write_session(session,ns);
                    printf("New Day is successfully updated for session %s become %s\n",
                                   session[position_session].session_code,session[position_session].session_day);
                }
                printf("1. Go back to Update Session page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }
            else if (updateses==4){
                int surecode=-1;
                fflush(stdin);
                printf("Enter New Start Time = ");
                gets(newsesTime);
                printf("Are you sure you want to update %s into %s?\n",session[position_session].session_starttime,newsesTime);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Start Time\n");
                scanf("%d",&surecode);
                if (surecode==1){
                    strcpy(session[position_session].session_starttime,newsesTime);
                    write_session(session,ns);
                    printf("New Start Time is successfully updated for session %s become %s\n",
                                   session[position_session].session_code,session[position_session].session_starttime);
                }
                printf("1. Go back to Update Session page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updateses==5){
                int surecode=-1;
                fflush(stdin);
                printf("Enter New Location = ");
                gets(newsesLoc);
                printf("Are you sure you want to update %s into %s?\n",session[position_session].session_location,newsesLoc);
                printf("1. Yes, I'm sure\n");
                printf("0. No, cancel updating Location\n");
                scanf("%d",&surecode);
                if (surecode==1){
                    strcpy(session[position_session].session_location,newsesLoc);
                    write_session(session,ns);
                    printf("New Location is successfully updated for session %s become %s\n",
                                   session[position_session].session_code,session[position_session].session_location);
                }
                printf("1. Go back to Update Session page\n");
                printf("0. Exit from this function\n");
                scanf("%d",&cont);
            }else if (updateses==6){
                char checktutor[20];
                int position_tutorSes;
                int surecode=-1;
                int validtut=-1;
                while (contInpTut!=0){
                    fflush(stdin);
                    printf("Enter New Tutor for this session = ");
                    gets(checktutor);
                    for (int i=0; i<nt; i++){
                        if (strcmp(checktutor,tutor[i].tutor_id)==0){
                            validtut=0;
                            position_tutorSes=i;
                            strcpy(newsesTutorCode,tutor[position_tutorSes].tutor_id);
                        }
                    }
                    if (validtut==0){
                        printf("Are you sure you want to update %s into %s?\n",session[position_session].session_tutorcode,newsesTutorCode);
                        printf("1. Yes, I'm sure\n");
                        printf("0. No, cancel updating Tutor\n");
                        scanf("%d",&surecode);
                        if (surecode==1){
                            strcpy(session[position_session].session_tutorcode,newsesTutorCode);
                            write_session(session,ns);
                            printf("New Tutor is successfully updated for session %s become %s\n",
                                           session[position_session].session_code,session[position_session].session_tutorcode);
                        }
                        printf("1. Go back to Update Session page\n");
                        printf("0. Exit from this function\n");
                        scanf("%d",&cont);
                        if (cont==0){
                            contInpTut=0;
                        }
                    }else{
                        printf("Tutor ID does not exist. Try another Tutor ID.\n");
                        printf("Do you want to continue entering New Tutor ID?\n");
                        printf("1. Yes.\n");
                        printf("0. No\n");
                        scanf("%d",&contInpTut);
                    }
                }
            }
        }
    }else{
        printf("Session Code does not exist.\n");
    }
}

void delete_student(struct strstudent student[], int *nst, struct enrollstudent enroll[], int *ne)
{
    int existInEnroll;
    int contDelete=-1;
    char deletetp[20];
    int position_student;
    while (contDelete!=0){
        fflush(stdin);
        printf("Enter TP Number of students that you want their data to be deleted = ");
        gets(deletetp);
        existInEnroll=-1;
        for (int i=0; i<*ne; i++){
            if (strcmp(deletetp,enroll[i].studenttpnum)==0){
                existInEnroll=1;
            }
        }
        if (existInEnroll!=1)
        {
            int valid=-1;
            for (int i=0; i<*nst; i++){
                if (strcmp(deletetp,student[i].student_tpnumber)==0){
                    valid=0;
                    position_student=i;
                }
            }
            if (valid==0){
                for (int i=position_student; i<(*nst)-1; i++){
                    printf("i= %d\n",i);
                    student[i]=student[i+1];
                }
                (*nst)--;
                write_student(student,*nst);
                printf("Data has been deleted\n");

            }else{
                contDelete=-1;
                printf("Data of %s cannot be found and cannot be deleted.\n",deletetp);
            }
            printf("Do you want to continue deleting data of student?\n");
            printf("1. Yes continue deleting data\n");
            printf("0. No, go back to home page\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);
        }else{
            printf("Data cannot be deleted since it is currently on enrollment list.\n");
            printf("Do you want to continue this function?\n");
            printf("1. Yes, continue delete data.\n");
            printf("0. No, exit from this function.\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);
        }

    }
}

void delete_tutor(struct strtutor tutor[], int *nt, struct strsession session[], int *ns)
{
    int existInSession;
    int contDelete=-1;
    char deleteID[20];
    int position_tutor;
    while (contDelete!=0){
        fflush(stdin);
        printf("Enter Tutor ID that you want their data to be deleted = ");
        gets(deleteID);
        existInSession=-1;
        for (int i=0; i<*ns; i++){
            if (strcmp(deleteID,session[i].session_tutorcode)==0){
                existInSession=1;
            }
        }
        if (existInSession!=1)
        {
            int valid=-1;
            for (int i=0; i<*nt; i++){
                if (strcmp(deleteID,tutor[i].tutor_id)==0){
                    valid=0;
                    position_tutor=i;
                }
            }
            if (valid==0){
                for (int i=position_tutor; i<(*nt)-1; i++){
                    tutor[i]=tutor[i+1];
                }
                (*nt)--;
                write_tutor(tutor,*nt);
                printf("Data has been deleted\n");
            }else{
                printf("Data of %s cannot be found and cannot be deleted.\n",deleteID);

            }
            contDelete=-1;
            printf("Do you want to continue deleting data of tutor?\n");
            printf("1. Yes continue deleting data\n");
            printf("0. No, go back to home page\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);
        }else{
            printf("Data cannot be deleted since it is currently on session list.\n");
            printf("Do you want to continue this function?\n");
            printf("1. Yes, continue delete data.\n");
            printf("0. No, exit from this function.\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);
        }

    }
}
void delete_session(struct strsession session[], int *ns, struct enrollstudent enroll[], int *ne)
{
    int existInEnroll;
    int contDelete=-1;
    char deleteSesCode[20];
    int position_session;
    while (contDelete!=0){
        fflush(stdin);
        printf("Enter Session Code that you want the data to be deleted = ");
        gets(deleteSesCode);
        existInEnroll=-1;
        for (int i=0; i<*ne; i++){
            if (strcmp(deleteSesCode,enroll[i].sessioncode)==0){
                existInEnroll=1; //
            }
        }
        if (existInEnroll!=1)
        {
            int valid=-1;
            for (int i=0; i<*ns; i++){
                if (strcmp(deleteSesCode,session[i].session_code)==0){
                    valid=0;
                    position_session=i;
                }
            }
            if (valid==0){
                for (int i=position_session; i<(*ns)-1; i++){
                    session[i]=session[i+1];
                }
                (*ns)--;
                write_session(session,*ns);
                printf("Data has been deleted\n");
            }else{
                printf("Data of %s cannot be found and cannot be deleted.\n",deleteSesCode);
            }
            contDelete=-1;
            printf("Do you want to continue deleting data of session?\n");
            printf("1. Yes continue deleting data\n");
            printf("0. No, go back to home page\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);

        }else{
            printf("Data cannot be deleted since it is currently on Enrollment list.\n");
            printf("Do you want to continue this function?\n");
            printf("1. Yes, continue delete data.\n");
            printf("0. No, exit from this function.\n");
            printf("[1/0] = ");
            scanf("%d",&contDelete);
        }

    }
}









