int wcount(char *s) {
        int i,k=0;
        gets(s);
        int n=strlen(s);
        for(i=0;i<n;i++)
        if (s[i]==" ") k++;
        return k;
} 
        