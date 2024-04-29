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
