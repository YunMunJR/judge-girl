#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
int find(char* table[],char* s){
    int c=0;
    while(table[c]){
        if(!strcmp(table[c],s)){
            return c;
        }
        c++;
    }
    return -1;
}
int findexpression(char* table[],char s[501][6],int start){
    int left=1;
    start++;
    while(left!=0){
        if(find(table,s[start])==3){
            left++;
        }else if(find(table,s[start])==4){
            left--;
        }
        start++;
    }
    return start-1;
}
int judge(int f,int expression){
    if(f){
        return expression;
    }else{
        return !expression;
    }
}
int expression(char* table[],char s[501][6],int start,int end){
    if(start==end){
        if(find(table,s[start])==5){
            return 1;
        }else{
            return 0;
        }
    }
    int newstart1=start+1,newend1,newstart2,newend2=end-1;
    int f1=1,f2=1,re1,re2;
    char comp[6];
    if(find(table,s[newstart1])==0){
        while(find(table,s[newstart1])==0){
            f1=!f1;
            newstart1++;
        }
        if(find(table,s[newstart1])==3){
            newend1=findexpression(table,s,newstart1);
            newstart2=newend1+2;   
        }else if(find(table,s[newstart1])==5||find(table,s[newstart1])==6){
            newend1=newstart1;
            newstart2=newstart1+2;   
        }
        re1=judge(f1,expression(table,s,newstart1,newend1));
    }else{
        if(find(table,s[newstart1])==3){
            newend1=findexpression(table,s,newstart1);
            newstart2=newend1+2;
        }else if(find(table,s[newstart1])==5||find(table,s[newstart1])==6){
            newend1=newstart1;
            newstart2=newstart1+2;   
        }
        re1=expression(table,s,newstart1,newend1);
    }
    assert((newstart2=newend1+2)&&(!strcmp(s[newend1+1],"&&")||!strcmp(s[newend1+1],"||")));
    strcpy(comp,s[newend1+1]);
    if(find(table,s[newstart2])==0){
        while(find(table,s[newstart2])==0){
            f2=!f2;
            newstart2++;
        }
        if(find(table,s[newstart2])==3){
            newend2=findexpression(table,s,newstart2);  
        }else if(find(table,s[newstart2])==5||find(table,s[newstart2])==6){
            newend2=newstart2;    
        }
        re2=judge(f2,expression(table,s,newstart2,newend2));
    }else{
        if(find(table,s[newstart2])==3){
            newend2=findexpression(table,s,newstart2);
        }
        else if(find(table,s[newstart2])==5||find(table,s[newstart2])==6){
            newend2=newstart2;
        }
        re2=expression(table,s,newstart2,newend2);
    }
    if(!strcmp(comp,"&&")){
        return re1&&re2;
    }else{
        return re1||re2;
    }
}
int main(){
    char *table[]={"!","&&","||","(",")","true","false",NULL};
    char *st;
    char buf[2050],rec[501][6];
    int cc=0;
    while(fgets(buf,2050,stdin)){
        int left=0,c=0,invalid=0,nobracket=0;
        st=strtok(buf," \n");
        for(;st;){
            strcpy(rec[c],st);
            if(c>0){
                if(find(table,st)<0){
                    fputs("invalid\n",stdout);
                    invalid=1;
                    break;
                }else if(find(table,st)==0&&(find(table,rec[c-1])==4||find(table,rec[c-1])==5||find(table,rec[c-1])==6)){
                    fputs("invalid\n",stdout);
                    invalid=1;
                    break;
                }else if((find(table,st)==1||find(table,st)==2)&&(!(find(table,rec[c-1])==4||find(table,rec[c-1])==5||find(table,rec[c-1])==6)||nobracket)){
                    fputs("invalid\n",stdout);
                    invalid=1;
                    break;
                }else if(find(table,st)==3){
                    left++;
                    if(find(table,rec[c-1])==4||find(table,rec[c-1])==5||find(table,rec[c-1])==6){
                        fputs("invalid\n",stdout);
                        invalid=1;
                        break;
                    }
                }else if(find(table,st)==4){
                    left--;
                    if(find(table,rec[c-1])==0||find(table,rec[c-1])==1||find(table,rec[c-1])==2||find(table,rec[c-1])==3){
                        fputs("invalid\n",stdout);
                        invalid=1;
                        break;
                    }
                }else if(find(table,st)==5&&(find(table,rec[c-1])==4||find(table,rec[c-1])==6)){
                    fputs("invalid\n",stdout);
                    invalid=1;
                    break;
                }else if(find(table,st)==6&&(find(table,rec[c-1])==4||find(table,rec[c-1])==5)){
                    fputs("invalid\n",stdout);
                    invalid=1;
                    break;
                }
            }else{
                if(find(table,st)==3){
                    left++;
                }else{
                    nobracket=1;
                }
            }
            c++;
            st=strtok(NULL," \n");
        }
        if(!invalid){
            if(left!=0){
                fputs("invalid\n",stdout);
            }else{
                int f=1,start=0,end;
                for(;find(table,rec[start])==0;){
                    f=!f;
                    start++;
                }
                end=findexpression(table,rec,start);
                int result;
                result=judge(f,expression(table,rec,start,end));
                if(result){
                    fputs("true\n",stdout);
                }else{
                    fputs("false\n",stdout);
                }
            }
        }
    }
    return 0;
}