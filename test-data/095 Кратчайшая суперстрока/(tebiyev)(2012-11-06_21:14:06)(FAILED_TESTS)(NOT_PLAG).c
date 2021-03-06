#include <stdio.h>
#include <string.h>

int strnlen(char *s, int k){
        return strlen(s);
}

int rep(char *p1, char *p2){
	int l, i, c=0;
	char *s1, *s2;
	if (strnlen(p1,50)>strnlen(p2,50))
		l=strnlen(p2,50);
	else
		l=strnlen(p1,50);
	printf("\trep: P1=%s, P2=%s\n\n",p1,p2);
	s1=malloc(l*sizeof(char));
	s2=malloc(l*sizeof(char));
	printf("\trep: P1=%s, P2=%s\n\n",p1,p2);
	for (i=1; i<l && c==0 ; i++){
		strncpy(s1,p1+strnlen(p1,50)-l+i,50);
		strncpy(s2,p2,l-i);
		s2[l-i]=0;
		if (strcmp(s1,s2)==0)
			c=l-i;
	}
	free(s1);
	free(s2);
	return c;
}

void comp_rec(int sn, int sc, int n, short *b, int *sum, int *max, char **P){
	int i,j; short bb;printf("\tcomp_rec(sn=%d,sc=%d,...)\n",sn,sc);					//
	if (sc!=-1 && sc!=n-1) {
		b[sc+1]=b[sc]&~(1<<sn); goto g1; g1b:; ////
		
		
	}
	for (i=0; i<n && sc<n; i++){
		goto g2; g2b:////
		if (b[sc+1]==(b[sc+1]|(1<<i))){
			goto g3; g3b:////
			if (sc>0){
				sum[sc]=sum[sc-1]+rep(P[sn],P[i]);goto g5;g5b:;////
				printf("\n\t%s\n\t%s\n\n",P[sn],P[i]);//
			}
			goto g4; g4b:////
			comp_rec(i,sc+1,n,b,sum,max,P);
		}
	}
	if (sum[sc]>*max)
		*max=sum[sc];
	return;

g1:
	for(j=0,bb=b[sc+1];j<n;j++)
		printf("%d",bb%2),bb/=2;
	printf("\n");
goto g1b;

g2:
	printf("b=");
	for(j=0,bb=b[sc+1];j<n;j++)
		printf("%d",bb%2),bb/=2;
	printf("\n  ");
	for(j=0,bb=1<<i;j<n;j++)
		printf("%d",bb%2),bb/=2;
	printf("\n");
goto g2b;

g3:
	printf(".sc=%d, sn=%d, i=%d\n",sc,sn,i);
goto g3b;

g4:
	printf("i=%d, sc+1=%d",i,sc+1);
goto g4b;

g5:
	printf("..sum[sc=%d]=%d = sum[sc-1=%d]=%d + rep(P[sn=%d],P[i=%d])=",sc,sum[sc],sc-1,sum[sc-1],sn,i);
	//printf("%d\n",rep(P[sn],P[i]));
goto g5b;
}

int main(){
	int n, i, *sum, max;
	char **P;
	short *b;
	max=0;
	//scanf("%d\n",&n);
		n=3;
	b=malloc(n*sizeof(short));
	b[0]=(1<<n)-1;
	sum=malloc(n*sizeof(int));
	sum[0]=0;
	P=malloc(n*sizeof(char*));
	/*for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
		*/P[0]="qwer"; P[1]="wert"; P[2]="erty";
	comp_rec(-1,-1,n,b,sum,&max,P);
	max*=-1;
	printf("max1=%d\n",max);
	for (i=0; i<n; i++)
		max+=strnlen(P[i],50);
	printf("max=%d\n",max);
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	free(b);
	free(sum);
	return 0;
}
